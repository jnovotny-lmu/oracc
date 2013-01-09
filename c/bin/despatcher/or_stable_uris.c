/* Resolver for published URI patterns in Oracc: we either exec,
   return a response to requester, or leave the elements array
   unchanged
 */
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "resolver.h"

int patterns_debug = 0;

const char *component_names[] = { "none", "resource", "selection", "view", "format", "ui" };
const char *resource_names[]  = { "none", "PQX", "word", "entity", "language", "keyword", "list" };
const char *selection_names[] = { "none", "full", "cat", "translit", "translation", "facing", 
				  "image", "thumb", "photo", "line", "detail",
				  "score", "block", 
				  "sign", "vals", "homophones", "compounds", "container", "contained"
};
const char *view_names[]      = { "none", "cuneified", "proofing", "project" };
const char *format_names[]    = { "none", "catf", "csv", "html", "oatf", "rdf", "tei", "txt", "xml" };
const char *ui_names[]        = { "none", "mini" };

typedef void(handler)(struct component *);

static void wrd_handler(struct component *);
static void ent_handler(struct component *);
static void lng_handler(struct component *);
static void key_handler(struct component *);
static void lst_handler(struct component *);

struct component *have_component[C_UI+1];

handler *resource_handlers[] =
{
  NULL, &pqx_handler, &wrd_handler, &ent_handler, &lng_handler, &key_handler, &lst_handler
};

void
show_components(struct component *components)
{
  int i = 0;
  for (i = 0; i < nelements; ++i)
    {
      const char *type = component_names[components[i].type];
      const char *name = NULL;
      switch (components[i].type)
	{
	case C_RES:
	  name = resource_names[components[i].value];
	  break;
	case C_VIEW:
	  name = view_names[components[i].value];
	  break;
	case C_SEL:
	  name = selection_names[components[i].value];
	  break;
	case C_FORMAT:
	  name = format_names[components[i].value];
	  break;
	case C_UI:
	  name = ui_names[components[i].value];
	  break;
	case C_NONE:
	  name = "(none)";
	  break;
	}
      fprintf(stderr, "%s = %s/%s\n", elements[i], type, name);
    }
}

static void
wrd_handler(struct component *components)
{
  if (patterns_debug)
    show_components(components);
  else if (project)
    {
      print_hdr();
      execl("/usr/bin/perl", "perl", "/usr/local/oracc/bin/cfgwview.plx", project, components[0].text, NULL);
      do404();      
    }
  else
    {
      find(NULL, make_find_phrase("wrd", elements[0], 1));
    }
}
static void 
ent_handler(struct component *components)
{
  if (patterns_debug)
    show_components(components);
  else
    {
      char *tmp = malloc(strlen(components[0].text)+strlen("phrase=&clip=6")+1);
      sprintf(tmp,"phrase=%s&clip=6", components[0].text);
      setenv("QUERY_STRING", tmp, 1);
      execl("/var/local/oracc/www/cgi-bin/estseek.cgi", "/var/local/oracc/www/cgi-bin/estseek.cgi", NULL);
      do404();
    }
}
static void 
lng_handler(struct component *components)
{
  if (patterns_debug)
    show_components(components);
  else if (project)
    {
#if 1
      execl("/usr/bin/perl", "perl", "/usr/local/oracc/bin/p2-pager.plx", 
	    "-p", cgi_arg("project", project), 
	    "-p", cgi_arg("glossary", elements[0]),
	    NULL);
      perror("execl failed");
      exit(1);
#else
      char *tmp = malloc(strlen(project) + strlen(elements[0]) 
			 + strlen("/var/local/oracc/www//cbd//overview.html") + 1);
      sprintf(tmp, "/var/local/oracc/www/%s/cbd/%s/overview.html", project, elements[0]);
      cat_html_file(tmp);
#endif
    }
  else
    find(NULL, make_find_phrase("gls", elements[0], 1));
}

static void 
key_handler(struct component *components)
{
  if (!strcmp(components[0].text, "find"))
    find(project, NULL);
  else if (!strcmp(components[0].text, "corpus"))
    corpus();
  else if (!strcmp(components[0].text, "statistics"))
    statistics();
}
static void 
lst_handler(struct component *components)
{
  show_components(components);
  list(components[0].text);
}

static int
res_is_lang(const char *e)
{
  if (e)
    {
      const char *x = NULL;
      if (strlen(e) == 3)
	{
	  while (*e && *e >= 'a' && *e <= 'z')
	    ++e;
	  return *e == '\0';
	}
      else if (strlen(e) == 12 && (x = strstr(e, "-x-")))
	{
	  while (e < x && *e >= 'a' && *e <= 'z')
	    ++e;
	  e = x + 3;
	  while (*e && *e >= 'a' && *e <= 'z')
	    ++e;	  
	  return *e == '\0';
	}
    }
  return 0;
}

/* This is not a true test for entity type, but it is enough
   to know that we can pass on the symbol to the entity handler */
static int
res_is_entity(const char *e)
{
  if (e)
    {
      if (isupper(*e) || *e > 127)
	++e;
      return *e;
    }
  return 0;
}

/* Note that res_is_lang must be called before res_is_list */
static int
res_is_list(const char *e)
{
  if (e)
    {
      while (*e && (isalnum(*e) || '-' == *e || '_' == *e))
	++e;
      return *e == 0;
    }
  return 0;
}

static int
res_is_key(const char *e)
{
  return !strcmp(e, "corpus")
    || !strcmp(e, "find")
    || !strcmp(e, "statistics");
}

static int
res_is_word(const char *e)
{
  int left_square = 0;
  int found = 0;
  while (*e)
    {
      if ('[' == *e)
	++left_square;
      else if (']' == *e)
	{
	  if (left_square)
	    found = 1;
	  --left_square;
	}
      ++e;
    }
  if (found && !left_square)
    return 1;
  return 0;
}

static int
res_six_digits(const char *d)
{
  int i;
  for (i = 0; isdigit(d[i]); ++i)
    if (!isdigit(d[i]))
      return 0;
  return i == 6;
}

static int 
res_is_pqx(const char *e, int *count)
{
  int c = 1;
  while (*e)
    {
      if (('P' == *e || 'Q' == *e || 'X' == *e)
	  && res_six_digits(e+1))
	{
	  e += 7;
	  if (',' == *e)
	    {
	      ++c;
	      ++e;
	    }
	  else
	    break;
	}
      else
	break;
    }
  if (count)
    *count = c;
  return '\0' == *e;
}

/* Care is needed with the order here because the keys look
   like list resources */

static int
pat_is_resource(struct component *cp)
{
  if (!have_component[C_RES])
    {
      cp->value = R_NONE;
      if (res_is_pqx(cp->text, &cp->count))
	{
	  cp->value = R_PQX;
	  cp->replace = map_PQX(cp->text, cp->count);
	}      
      else if (res_is_word(cp->text))
	cp->value = R_WORD;
      else if (res_is_key(cp->text))
	cp->value = R_KEY;
      else if (res_is_lang(cp->text))
        cp->value = R_LANG;
      else if (res_is_list(cp->text))
	cp->value = R_LIST;
      else if (res_is_entity(cp->text))
	cp->value = R_ENTITY;

      if (cp->value)
	{
	  cp->type = C_RES;
	  have_component[C_RES] = cp;
	  return 1;
	}
    }
  return 0;
}

static int
pat_is_selection(struct component *cp)
{
  if (!have_component[C_SEL])
    {
      struct seltab *st = selections(cp->text,strlen(cp->text));
      if (st)
	{
	  cp->type = C_SEL;
	  cp->value = st->val;
	  have_component[C_SEL] = cp;
	  return 1;
	}
    }
  return 0;
}

static int
pat_is_view(struct component *cp)
{
  if (!have_component[C_VIEW])
    {
      if (!strcmp(cp->text, "cuneified"))
	cp->value = V_CUNEIFIED;
      else if (!strcmp(cp->text, "proofing"))
	cp->value = V_PROOFING;
      else if (!strcmp(cp->text, "view"))
	cp->value = V_PROJECT;

      if (cp->value)
	{
	  cp->type = C_VIEW;
	  have_component[C_VIEW] = cp;
	  return 1;
	}
    }
  return 0;
}

static int
pat_is_format(struct component *cp)
{
  if (!have_component[C_FORMAT])
    {
      if (!strcmp(cp->text, "catf"))
	cp->value = F_CATF;
      else if (!strcmp(cp->text, "csv"))
	cp->value = F_CSV;
      else if (!strcmp(cp->text, "html"))
	cp->value = F_HTML;
      else if (!strcmp(cp->text, "rdf"))
	cp->value = F_RDF;
      else if (!strcmp(cp->text, "tei"))
	cp->value = F_TEI;
      else if (!strcmp(cp->text, "txt"))
	cp->value = F_TXT;
      else if (!strcmp(cp->text, "xml"))
	cp->value = F_XML;
      
      if (cp->value)
	{
	  cp->type = C_FORMAT;
	  have_component[C_FORMAT] = cp;
	  return 1;
	}
    }
  return 0;
}

static int
pat_is_ui(struct component *cp)
{
  if (!strcmp(cp->text, "mini"))
    {
      have_component[C_UI] = cp;
      cp->type = C_UI;
      cp->value = U_MINI;
      return 1;
    }
  else
    {
      cp->type = C_NONE;
      cp->value = U_NONE;
      return 0;
    }
}

static int
component_type(struct component *cp)
{
  int ret = C_NONE;
  (ret = pat_is_resource(cp))
    || (ret = pat_is_selection(cp))
    || (ret = pat_is_view(cp))
    || (ret = pat_is_format(cp))
    || (ret = pat_is_ui(cp));

  if (!ret && have_component[C_VIEW])
    {
      if (have_component[C_VIEW]->value == V_PROJECT)
	{
	  cp->value = V_PROJECT_TYPE;
	  ret = 1;
	}
    }

  return ret;
}

void
uri_patterns(void)
{
  struct component *components = calloc(1+nelements, sizeof(struct component));
  int i;

  for (i = 0; i < nelements; ++i)
    {
      components[i].index = i;
      components[i].text = elements[i];
      if (!component_type(&components[i]))
	break;
    }

  /* If we didn't parse the whole thing it may be a different type of
     URI, so just silently return */
  if (i < nelements)
    return;
  else if (components[0].type)
    resource_handlers[components[0].value](components);
  else
    do404();

  /* We can only get here if the resource_handler exec failed */
  exit(1);
}