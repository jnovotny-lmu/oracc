#include <sys/types.h>
#include <sys/stat.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "resolver.h"

const char *docroot = "/var/local/oracc/www";
const char *project = NULL;
const char *query_string = NULL;
const char *script_url = NULL;
const char *oodroot = "/usr/local/oracc/ood";
const char *xmlroot = "/usr/local/oracc/xml";

const char **elements;
int elements_used = 0;
int nelements;
int debug = 0;

static void decompose_script_url(const char *su);

int
main(int argc, char *argv[]) 
{
  if (!(script_url = getenv("SCRIPT_URL")))
    {
      fputs("oracc-resolver: SCRIPT_URL not set. Stop.\n", stderr);
      exit(1);
    }
  else
    {
      const char *env_docroot = NULL;
      setlocale(LC_ALL, LOCALE);
      setenv("ORACC", "/usr/local/oracc", 1);
      decompose_script_url(script_url);
      if (elements[0] && legacy(elements[0], strlen(elements[0])))
	{
	  char *tmp = malloc(strlen("/or")+strlen(script_url)+2);
	  if (project)
	    {
	      const char *su = script_url + strlen(project) + 1;
	      if ('/' == *su)
		++su;
	      sprintf(tmp, "/or/%s", su);
	    }
	  else
	    {
	      if ('/' == *script_url)
		++script_url;
	      sprintf(tmp, "/or/%s", script_url);
	    }
	  script_url = tmp;
	  nelements = elements_used = 0;
	  free(elements);
	  elements = NULL;
	  decompose_script_url(script_url);
	}
      query_string = getenv("QUERY_STRING");
      unsetenv("SCRIPT_URL");
      unsetenv("QUERY_STRING");
      if ((env_docroot = (char*)getenv("DOCUMENT_ROOT")))
	docroot = env_docroot;
      fprintf(stderr,
	      "oracc-resolver: SCRIPT_URL=%s; project=%s; QUERY_STRING=%s\n",
	      script_url, project, query_string);
    }

  if (nelements == 0)
    {
      if (project)
	{
	  nelements = elements_used = 0;
	  free(elements);
	  elements = NULL;
	  decompose_script_url("/corpus");
	}
      else
	cat_index_html("/");
    }

  if (!project || !strcmp(elements[0], "or"))
    or_builtins();

  if (project && strstr(project, "/data/"))
    or_gdf();
  else
    uri_patterns();
  
  do404();
}

/* Return NULL if script_url does not start with a project;
   the first character of the non-project part of script_url
   otherwise.  This char is '\0' if script_url is only a
   project name. */
static char *
find_project(char *script_url)
{
  char *tmp = script_url+strlen(script_url), *dir_end = NULL, *buf, save = '\0';
  struct stat st_buf;

  buf = malloc(strlen(xmlroot) + strlen(script_url) + 1);
  while (tmp > script_url)
    {
      int ok = 0;
      sprintf(buf,"%s%s",xmlroot,script_url);
      ok = (!stat(buf,&st_buf) && (st_buf.st_mode & S_IFDIR));
      if (!ok)
	{
	  sprintf(buf,"%s%s",oodroot,script_url);
	  ok = (!stat(buf,&st_buf) && (st_buf.st_mode & S_IFDIR));
	}
      if (ok)
	{
	  dir_end = tmp;
	  break;
	}
      else
	{
	  *tmp-- = save;
	  while (tmp > script_url)
	    {
	      --tmp;
	      if ('/' == *tmp)
		{
		  save = '/';
		  *tmp = '\0';
		  break;
		}
	    }
	}
    }
  free(buf);
  if (dir_end && script_url[1])
    {
      project = script_url+1;
      setenv("ORACC_PROJECT", project, 1);
      if (save)
	++dir_end;
      return dir_end;
    }
  else
    {
      if (save)
	*tmp = save;
      return NULL;
    }
}

static void
decompose_script_url(const char *su)
{
  char *p, *start, *su_copy;
  int i = 2; /* +1 for the initial / which is now \0, and +1 for the
		terminating NULL */

  su_copy = malloc(strlen(su)+1);
  start = p = strcpy(su_copy,su);
  if (*p)
    {
      char *post_project = find_project(p);
      if (post_project)
	start = p = post_project;
      else
	start = p + 1; /* skip leading / on start */
      while (*p)
	{
	  if (*p == '/')
	    ++i;
	  ++p;
	}
      elements = malloc(i * sizeof(char*));
      for (nelements = 0, p = start; *p; )
	{
	  elements[nelements++] = p;
	  while (*p && '/' != *p)
	    ++p;
	  if (*p)
	    *p++ = '\0';
	  else
	    break;
	}
      elements[nelements] = NULL;
    }
  else
    elements = NULL;
}