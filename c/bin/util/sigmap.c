#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <locale.h>
#include <wchar.h>
#include <ctype.h>
#include "fname.h"
#include "atflocale.h"

static char *CGI_decode_url(const char *p);
const char *lang = NULL, *project = NULL, *map_proj = NULL;

static void
print_hdr(void)
{
  puts("Content-type: text/html; charset=utf-8\n");
  fflush(stdout);
}

static void
try_map(char *sig,char *map_file,const char*projlang)
{
  char *s, buf[1024];
  FILE *map = fopen(map_file,"r");
  while ((s = fgets(buf,1024,map)))
    {
      char*tab = strchr(s,'\t'), *doll;
      *tab = '\0';
#if 0
      if (*s != '{' && (doll = strchr(s, ']')))
	{
	  if ((doll = strchr(doll, '$')))
	    *doll = '\0';
	}
#endif
      if (!strcmp(s,sig))
	{
#if 1
	  char html[1024];
	  ++tab;
	  tab[strlen(tab)-1] = '\0';
	  sprintf(html,"/usr/local/oracc/www/%s/cbd/%s/%s.html",map_proj,lang,tab);
#else
	  char html[1024],*at,*percent,projlang_tmp[128];
	  ++tab;
	  tab[strlen(tab)-1] = '\0';
	  at = strchr(s,'@');
	  ++at;
	  percent = strchr(at,'%');
	  if (lang)
	    {
	      *percent++ = '\0';
	      sprintf(projlang_tmp,"%s/cbd/%s",at,lang);
	    }
	  else
	    {
	      sprintf(projlang_tmp,"%s",projlang);
	    }
	  sprintf(html,"/usr/local/oracc/www/%s/%s.html",projlang_tmp,tab);
#endif

#if SIGMAP_DEBUG
	  printf("<html><body><p>%s => %s</p></body></html>",sig,html);
	  return 0;
#else
	  if (!access(html,R_OK))
	    execlp("/bin/cat","cat",html,(char*)NULL);
	  else
	    {
	      printf("<html><head><meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\"/></head><body><p>Signature %s points to non-existent HTML file %s</p><p>map file=%s; projlang=%s</p></body></html>",sig,html,map_file,lang);
	      exit(1);
	    }
#endif
	}
    }
  fprintf(stderr,"sigmap: %s: no sig %s\n", map_file, sig);
}

static int
hex(int digit) {
    switch(digit) {

    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
        return digit - '0';

    case 'A': case 'B': case 'C': case 'D': case 'E': case 'F':
        return 10 + digit - 'A';

    case 'a': case 'b': case 'c': case 'd': case 'e': case 'f':
        return 10 + digit - 'a';

    default:
        return -1;
    }
}

char *
CGI_decode_url(const char *p) {
    char *out;
    int i, k, L, R;

    if (p == 0) {
        return 0;
    }
    out = (char *)malloc(strlen(p) + 1);
    for (i = k = 0; p[i] != 0; i++) {
        switch(p[i]) {

        case '+':
            out[k++] = ' ';
            continue;

        case '%':
            if ((L = hex(p[i + 1])) >= 0 &&
                (R = hex(p[i + 2])) >= 0)
            {
                out[k++] = (L << 4) + R;
                i += 2;
                continue;
            }
            break;
        }
        out[k++] = p[i];
    }
    out[k] = 0;
    return out;
}

static const char *
find_pos(const char *sig)
{
  static char buf[5];
  const char *p = NULL;
  if ((p = strstr(sig, "}::")))
    {
    }
  else
    {
      const char *epos;
      p = strstr(sig, "//");
      while (*p && ']' != *++p)
	;
      if (!*p)
	return NULL;
      ++p;
      if ((epos = strchr(p, '\'')))
	{
	  if (epos - p < 5)
	    {
	      strncpy(buf,p,epos-p);
	      buf[epos-p] = '\0';
	    }
	  else
	    *buf = 'X';
	}
      else
	{
	  char *bufp = buf;
	  while (isalpha(*p) && bufp - buf < 5)
	    *bufp++ = *p++;
	  *bufp = '\0';
	}
    }
  return buf;
}

static char *
find_lang(const char *sig)
{
  static char buf[128];
  const char *p = strchr(sig, '%');
  if (p)
    {
      const char *c = strchr(++p, ':');
      if (c - p < 128)
	{
	  strncpy(buf, p, c-p);
	  buf[c-p] = '\0';
	}
      else
	fprintf(stderr, "sigmap: lang too long (%s)\n", p);
    }
  else
    *buf = '\0';
  return buf;
}

static char *
find_proj(const char *sig)
{
  static char buf[128];
  const char *at = strchr(sig, '@');
  if (at)
    {
      const char *p = strchr(++at, '%');
      if (p - at < 128)
	{
	  strncpy(buf, at, p-at);
	  buf[p-at] = '\0';
	}
      else
	fprintf(stderr, "sigmap: lang too long (%s)\n", p);
    }
  else
    *buf = '\0';
  return buf;
}

static char *
make_map(const char *sig, const char *argproj)
{
  const char *pos = find_pos(sig);
  const char *proj = argproj;
  char *mapbuf = NULL;

  if (!proj)
    proj = find_proj(sig);
  
  if (strlen(pos) == 2 && pos[1] == 'N')
    lang = "qpn";

  map_proj = proj;
  mapbuf = malloc(12+(2*strlen(lang))+strlen(proj)+strlen(oracc_home()));
  sprintf(mapbuf, "%s/bld/%s/%s/%s.map", oracc_home(), proj, lang, lang);
  return mapbuf;
}

int
main(int argc, char **argv)
{
  char *map = NULL;
  char *sig = argv[2], *usig, *msig;
  wchar_t *wsig = NULL;
  size_t nwchar = 0, i;
  char *locale = NULL;

  project = argv[1];
  
  print_hdr();
  if ((locale = setlocale(LC_ALL, LOCALE)))
    fprintf(stderr, "locale=%s\n", locale);
  else
    fprintf(stderr, "setlocale(LC_ALL, \"en_GB\") failed\n");

  usig = CGI_decode_url(sig);

  /* fprintf(stderr,"sig: %s\nusig: %s\n", sig, usig); */

  wsig = malloc((strlen(usig)+1) * sizeof(wchar_t));
  nwchar = mbstowcs(wsig, usig, strlen(usig)+1);

  if (*wsig != 0x2623)
    {
      fprintf(stderr,"sigmap: signature with no biohazard symbol\n");
      printf("<html><head><meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\"/></head><body><p>No HTML file found for signature %s</p></body></html>",
	     argv[1]);
      fflush(stdout);
      return 0;
    }

  ++wsig; /* skip biohazard symbol */
  --nwchar;
  for (i=0; i < nwchar; ++i)
    {
      switch(wsig[i])
	{
	case 0xb1:
	  wsig[i] = L'+';
	  break;
	case 0xb4:
	  wsig[i] = L'\'';
	  break;
	case 0x20e5:
	  wsig[i] = L'\\';
	  break;
	}
    }
  msig = malloc(2*strlen(usig)+1);

  wcstombs(msig, wsig, 2*strlen(usig));

#if 0
  fprintf(stderr,"msig: %s\n", msig);
  exit(1);
#endif

  /* my $map1 = "/usr/local/oracc/bld/$project/$lang/$lang.map"; # try the local project/lang first */

  lang = find_lang(msig);
  map = make_map(msig, project);
  try_map(msig, map, lang);
  map = make_map(msig, NULL);
  try_map(msig, map, lang);

#if 0

  /* else map = make_map(NULL, msig) and use project from sig */
  if (strcmp(argv[3], "-"))
    {
      if (strcmp(argv[2],argv[3]))
	try_map(argv[1],argv[3],NULL,argv[5]);
    }
#endif

  printf("<html><head><meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\"/></head><body><p>No HTML file found for signature %s in project %s</p></body></html>",
	 msig, project);
  fflush(stdout);
  return 1;
}

int major_version = 1, minor_version = 0;
const char *usage_string = "sigmap";
const char *prog = "sigmap";
void help(void) { }
void opts(void) { }