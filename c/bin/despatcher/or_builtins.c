#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "resolver.h"

static void as_handler(const char *session);
static void atf(void);
static void datestamp(void);
static void itemmain(const char *session, const char *list);
static void itemside(const char *session, const char *list);
static void legacy_urls(void);
static void outline(const char *session, const char *list);
static void results(const char *session, const char *list);
static void rpc(void);
static void sig(const char *sig);
static void xforms_handler(void);
static void xis(const char *xlang, const char *xid);
static char *xml_read_sans_content_length(size_t *lenp);
static int xml_content(const char *ct);
static char *xml_docelem(const char *xml);
static void xml_handler(char *xml, size_t len);
static char *xml_value(const char *xml, const char *tag);

typedef void(builtin)(const char *,const char *);
builtin *builtins_handlers[] =
{
  NULL, NULL, NULL, NULL, NULL, NULL, 
  itemmain, itemside, outline, results, NULL, NULL, NULL, xis
};

void
or_builtins(void)
{
  if (elements[0] && !strcmp(elements[0], "or"))
    {
      struct builtinstab *builtinsp = NULL;
      if (elements[1] && (builtinsp = builtins(elements[1], strlen(elements[1]))))
	{
	  switch (builtinsp->type)
	    {
	    case B_DOC:
	      if (elements[2] && !strcmp(elements[2], "find"))
		find("doc", query_string);
	      else
		do404();
	      break;
	    case B_FIND:	      
	      find(project, query_string);
	      break;
	    case B_XFORMS:
	      xforms_handler();
	      break;
	    case B_AS:
	      as_handler(elements[2]);
	      break;
	    case B_ATF:
	      atf();
	      break;
	    case B_RPC:
	      rpc();
	      break;
	    case B_DATESTAMP:
	      datestamp();
	      break;
	    case B_SIG:
	      sig(elements[2]);
	      break;
	    case B_ITEMMAIN:
	    case B_ITEMSIDE:
	    case B_OUTLINE:
	    case B_RESULTS:
	    case B_XIS:
	      builtins_handlers[builtinsp->type](elements[2], elements[3]);
	      break;
	    }
	}
      do404();
    }
  else if (!strcmp(elements[0], "cgi-bin") 
	   && elements[1])
    {
      if (!strcmp(elements[1], "rpc")
	  || !strcmp(elements[1], "rpc.plx"))
	{
	  rpc();
	  do404();
	}
      else if (!strcmp(elements[1], "cuneify"))
	{
	  setenv("QUERY_STRING", query_string, 1);
	  cuneify();
	  do404();
	}
    }
  return;
}

static void
as_handler(const char *session)
{
  sed_project("/usr/local/oracc/www/p2/as-base.xml", session);
}

static void
atf(void)
{
  execl("/usr/bin/perl", "perl", "/usr/local/oracc/bin/atf.plx", "atf.plx", NULL);
  do404();
}

/* Not static because or_pqx.c needs it */
void
cuneify(void)
{
  execl("/usr/bin/perl", "perl", "/usr/local/oracc/bin/cuneify.plx", NULL);
  do404();
}

static void
datestamp()
{
#define TM_MAX 256
  char tmbuf[TM_MAX];
  time_t t = time(NULL);
  struct tm *gmt = gmtime(&t);
  strftime(tmbuf, TM_MAX, "<date>%Y-%m-%dT%H:%M:%S%z</date>", gmt);
  print_hdr_xml();
  fputs(tmbuf, stdout);
  exit(0);
}

void
find(const char *project, const char *phrase)
{
  if (project)
    setenv("ORACC_PROJECT", project, 1);
  setenv("QUERY_STRING", make_find_phrase(NULL,phrase,0), 1);
  execl("/usr/local/oracc/www/cgi-bin/estseek.cgi", "/usr/local/oracc/www/cgi-bin/estseek.cgi", NULL);
  do404();
}

const char *
make_find_phrase(const char *xkey, const char *phrase, int uncomma)
{
  char *p = NULL, *space = "";

  if (!phrase)
    return xkey ? xkey : "";

  if (strstr(phrase, "phrase="))
    return phrase;

  if (!xkey)
    xkey = "";
  else
    space = " ";
  p = malloc(strlen("phrase=")+strlen(xkey)+strlen(space)+strlen(phrase)+3);
  sprintf(p, "phrase=%s%s%s", xkey, space, phrase);
  if (uncomma)
    {
      char *c = p;
      while (*c)
	if (*c == ',')
	  *c++ = '|';
	else
	  ++c;
    }
  return p;
}

static void
itemmain(const char *session, const char *list)
{
  static char buf[1024];
  sprintf(buf,"/var/tmp/oracc/pager/%s/%s/itemmain.html",session,list);
  cat_file(buf);
}

static void
itemside(const char *session, const char *list)
{
  static char buf[1024];
  sprintf(buf,"/var/tmp/oracc/pager/%s/%s/itemside.html",session,list);
  cat_file(buf);
}

static void
outline(const char *session, const char *list)
{
  static char buf[1024];
  sprintf(buf,"/var/tmp/oracc/pager/%s/%s/outline.html",session,list);
  cat_file(buf);
}

static void
results(const char *session, const char *list)
{
  static char buf[1024];
  sprintf(buf,"/var/tmp/oracc/pager/%s/%s/results.html",session,list);
  cat_file(buf);
}

static void
rpc(void)
{
  execl("/usr/bin/perl", "perl", "/usr/local/oracc/bin/rpc.plx", NULL);
  do404();
}

static void
sig(const char *sig)
{
  fprintf(stderr, "oracc-despatcher: project=`%s'; literal sig=`%s'\n", project, query_string);
  execl("/usr/local/oracc/bin/sigmap", "sigmap", project, query_string, NULL);
  perror("execl failed");
}

static void
xis(const char *xlang, const char *xid)
{
  mode = "minimal";
  execl("/usr/bin/perl", "perl", "/usr/local/oracc/bin/p2-pager.plx", 
	"-p", cgi_arg("project", project), 
	"-p", cgi_arg("xis-lang", xlang),
	"-p", cgi_arg("xis-id", xid),
	"-p", cgi_arg("mode", mode),
	NULL);
  perror("execl failed");
  exit(1);
}

/* All XForms handling from here on */
static void
xforms_handler(void)
{
  const char *content_type = getenv("CONTENT_TYPE"), *content_length;
  char *xml = NULL;
  size_t len = 0;
  if (content_type && xml_content(content_type))
    {
      if ((content_length = getenv("CONTENT_LENGTH")))
	{
	  if ((len = atoi(content_length)) > 0)
	    {
	      xml = malloc(len+1);
	      if (fread(xml, 1, len, stdin) == len)
		xml_handler(xml, len);
	      else
		do404();
	    }
	}
      else
	{
	  /* Bloody Safari */
	  xml = xml_read_sans_content_length(&len);
	  if (len)
	    xml_handler(xml, len);
	  else
	    do404();
	}
    }
  else
    do404();
  exit(1);
}

static void
xml_handler(char *xml, size_t len)
{
  char *xml_type = NULL;
  
  /* skip XML decl / PIs */
  while (*xml && xml[0] == '<' && xml[1] == '?')
    {
      xml += 2;
      while (*xml && xml[0] != '?' && xml[1] != '>')
	++xml;
      xml += 2;
      while (isspace(*xml))
	++xml;
    }

  xml_type = xml_docelem(xml);
  fprintf(stderr, "oracc-despatcher: xml_type=%s\n", xml_type);
  if (!strcmp(xml_type, "browse")
      || !strcmp(xml_type, "pager")
      || !strcmp(xml_type, "search"))
    {
      char *session = xml_value(xml, "session");
      if (session)
	{
	  char *out = malloc(1 + strlen("/var/tmp/oracc/pager//.xml") +
			     strlen(session)+strlen(xml_type));
	  char *prg = malloc(1 + strlen("/usr/local/oracc/bin/p2-.plx"));
	  sprintf(out, "/var/tmp/oracc/pager/%s/%s.xml", session, xml_type);
	  sprintf(prg, "/usr/local/oracc/bin/p2-%s.plx", xml_type);
	  fprintf(stderr, "writing to %s", out);
	  FILE *x = fopen(out, "w");
	  xml[len] = 0;
	  fwrite(xml, 1, len, x);
	  fclose(x);
	  fprintf(stderr, "calling %s %s", prg, out);
	  unsetenv("SCRIPT_URL");
	  execl(prg, xml_type, out, NULL);
	  perror("execl failed");
	  exit(1);
	}
      else
	do404();
    }
  else
    do404();
}

static char *
xml_docelem(const char *xml)
{
  const char *start, *end;
  char *buf;
  int len;

  /* FireFox strips <browse xmlns=""> to <browse> but others
     don't */
  if ('<' == *xml)
    {
      start = xml+1;
      for (end = start; *end && !isspace(*end) && '>' != *end; ++end)
	;
      len = end-start;
      buf = malloc(1 + len);
      strncpy(buf, start, len);
      buf[len] = '\0';
      return buf;
    }
  else
    return NULL;
}

static char * 
xml_value(const char *xml, const char *tag)
{
  const char *t = xml, *e = NULL, *v = NULL, *v_end = NULL;
  while (t && (t = strstr(t, tag)))
    {
      if (t[-1] == '<')
	{
	  e = t + strlen(tag);
	  if (*e == '>' || (*e == '/' && *++e == '>'))
	    {
	      v = e + 1;
	      break;
	    }
	}
      else
	t = strchr(t, '>');
    }
    if (v)
      {
	while (e && (e = strstr(e, tag)))
	  {
	    if ('/' == e[-1] && '<' == e[-2])
	      {
		if (e[strlen(tag)] == '>')
		  {
		    v_end = e - 2;
		    break;
		  }
	      }
	    else
	      e = strchr(e, '>');
	  }
	if (v_end)
	  {
	    char *ret = malloc(1 + v_end - v);
	    strncpy(ret, v, v_end - v);
	    ret[v_end - v] = '\0';
	    return ret;
	  }
      }    
    return NULL;
}

static int
xml_content(const char *ct)
{
  return strstr(ct, "application/xml") != NULL;
}

/* We define XML_BUF_MAX to a size far larger than
   any reasonable use of the Oracc 2 XForms--even
   the largest Advanced Search should fit easily
   in 10k.  If it doesn't, someone is probably up
   to no good, so we bounce them.
   
   99.99% of instances sent over the wire will be
   less than 2K.
 */
#define XML_BUF_BLOCK 2048
#define XML_BUF_MAX  10240
static char *
xml_read_sans_content_length(size_t *lenp)
{
  char *xml = malloc(XML_BUF_BLOCK);
  size_t alloced = XML_BUF_BLOCK;
  size_t used = 0;
  int ch = 0;
  while (EOF != ((ch = getchar())))
    {
      if (used == alloced)
	{
	  if (alloced == XML_BUF_MAX)
	    {
	      free(xml);
	      do404();
	    }
	  xml = realloc(xml, alloced += XML_BUF_BLOCK);
	}
      xml[used++] = ch;
    }
  xml[used] = '\0';
  *lenp = used;
}
