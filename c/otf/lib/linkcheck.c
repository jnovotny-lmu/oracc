#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "hash.h"
#include "pool.h"
#include "warning.h"

#define hash_lookup(keyp,tablep) hash_find(tablep,keyp)

extern Hash_table *label_table;
extern int check_and_register(const char *id, int set_ok);
extern int check_pname(const char *id,const unsigned char *name);
extern void define_labels_symbol(const char *sym, const char*idp);
extern void load_labels(const char*idp);
extern int check_links;
extern int pnames;
extern int sym_warning;

static const char *
scan_pair(const char *line)
{
  static char xidbuf[8];
  int i = 1;
  *xidbuf = *line++;
  while (isdigit(*line) && i < 8)
    xidbuf[i++] = *line++;
  if (i == 7)
    {
      xidbuf[7] = '\0';
      if (*xidbuf == 'P')
	{
	  if (check_and_register(xidbuf,0))
	    return NULL;
	}
      while (isspace(*line))
	++line;
      if ('=' != *line || !isspace(line[1]))
	{
	  warning("malformed link: protocol: expected '= '");
	  return NULL;
	}
      ++line;
      while (isspace(*line))
	++line;
      if (*line)
	{
	  if (pnames && 'P' == *xidbuf)
	    (void)check_pname(xidbuf,(const unsigned char *)line);
	  return xidbuf;
	}
      else
	{
	  warning("malformed link: protocol: expected text name");
	  return NULL;
	}
    }
  else
    {
      xidbuf[i] = '\0';
      vwarning("%s: malformed ID in link: protocol", xidbuf);
      return NULL;
    }
}

/* We have to treat line as const here because it is included
   in the output */
void
link_check_protocol(const char *line)
{
  const char *idp;

  while (isspace(*line))
    ++line;
  if (!strncmp(line,"def",3))
    {
      line += 3;
      while (isspace(*line))
	++line;
      if (*line)
	{
	  char symbuf[10];
	  int i = 0;
	  while (*line && !isspace(*line) && i < 10)
	    symbuf[i++] = *line++;
	  if (i == 10)
	    {
	      symbuf[9] = '\0';
	      vwarning("malformed link: protocol: symbol '%s' too long (max 9 characters)", symbuf);
	    }
	  else
	    {
	      symbuf[i] = '\0';
	      while (isspace(*line))
		++line;
	      if ('=' == *line && isspace(line[1]))
		{
		  line += 2;
		  while (isspace(*line))
		    ++line;
		  idp = scan_pair(line);
		  if (idp)
		    {
		      idp = (char*)pool_copy((unsigned char*)idp);
		      define_labels_symbol(symbuf,idp);
		      if (check_links)
			load_labels(idp);
		    }
		}
	      else
		warning("malformed link: protocol: expected ' = ' after def's symbol");
	    }
	}
      else
	warning("malformed link: protocol: expected symbol (e.g., 'A')");
    }
  else if (!strncmp(line,"parallel", 8) || !strncmp(line,"source",6))
    {
      int is_source = *line == 's';
      line += (is_source ? 6 : 8);
      while (isspace(*line))
	++line;
      if (*line == 'P' || *line == 'Q' || *line == 'X')
	(void)scan_pair(line);
      else
	vwarning("bad link: %s: expected P-id or Q-id (or X-id)", 
		 is_source ? "source" : "parallel");
    }
  else
    {
      char ebuf[10];
      int i = 0;
      while (*line && i < 10)
	ebuf[i++] = *line++;
      ebuf[i] = '\0';
      vwarning("bad link: protocol '%s' (expected def, source or parallel)", ebuf);
    }
}

void
link_check(const char *line)
{
  char buf[10];
  int i = 0;

  line += 2;
  while (isspace(*line))
    ++line;
  while (*line && !isspace(*line) && i < 10)
    buf[i++] = *line++;
  if (i == 10)
    {
      buf[9] = '\0';
      vwarning("link symbol '%s' too long (max 9 characters)",buf);
    }
  else
    {
      char buf2[20];
      const char *idp;
      buf[i] = '\0';
      sprintf(buf2,"%s#%s",textid,buf);
      if (NULL != (idp = hash_lookup((unsigned char *)buf2,label_table)))
	{
	  while (isspace(*line))
	    ++line;
	  if (*line)
	    {
	      if (*line != '?')
		{
		  /* we cheat in fieldchars and include ? */
		  static const char *fieldchars = "\"#|~?";
		  const char *endp = line + strlen(line);
		  while (strchr(fieldchars,endp[-1]))
		    --endp;
		  if (*endp)
		    {
		      if (isspace(endp[-1]))
			while (isspace(endp[-1]))
			  --endp;
		      else
			warning("space required before query and field designators");
		    }
		  if (endp - line > 119) /* need 8 chars for 'Pxxxxxx:' */
		    warning("malformed link: absurdly long label");
		  else if (check_links)
		    {
		      const char *defp = hash_lookup((unsigned char *)idp,label_table);
		      if ('1' == *defp)
			{
			  char labelbuf[128];
			  /* const char *lidp; */
			  strcpy(labelbuf,idp);
			  strcat(labelbuf,":");
			  strncat(labelbuf,line,endp-line);
			  if (!hash_lookup((unsigned char*)labelbuf,label_table))
			    vwarning("link not found (%s => %s)",buf,labelbuf);
			}
		    }
		}
	      else
		{
		  if (line[1])
		    warning("malformed link: nothing permitted after '?'");
		}
	    }
	  else
	    {
	      warning("malformed link: use, e.g., '>>A ?' as placeholder");
	    }
	}
      else if (!sym_warning++)
	vwarning("link symbol '%s' not defined",buf);
    }
}