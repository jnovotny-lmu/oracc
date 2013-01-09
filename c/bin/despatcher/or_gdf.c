#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "resolver.h"

#if 0
static int
gdf_id(const char *id)
{
  if (id && strlen(id) > 2 && *id++ == 'i' && *id++ == 'd')
    while (*id && isdigit(*id))
      ++id;
  else
    return 0;
  return !*id;
}
#endif

void
or_gdf(void)
{
#if 1
  if (_is_ncname(elements[0]))
#else
  if (gdf_id(elements[0]))
#endif
    {
      char *dataset = NULL, *tmp = NULL, *exe, *exedot;
      if ((dataset = strrchr(project, '/')))
	{
	  extern const char *oodroot;
	  tmp = malloc(strlen(oodroot) + strlen(project) + strlen(dataset) + 7);
	  sprintf(tmp, "%s/%s%s.xml", oodroot, project, dataset);
	  exe = malloc(strlen(tmp)+1);
	  strcpy(exe, tmp);
	  exedot = strrchr(exe, '.');
	  strcpy(exedot+1, "sh");
	  if (!access(exe, R_OK|X_OK))
	    {
	      execl("/bin/sh", "sh", exe, elements[0], NULL);
	      do404();
	    }
	  else
	    {
	      if (elements[1] && !strcmp(elements[1], "xml"))
		{
		  print_hdr_xml();
		  execl("/bin/sh", "sh", "/usr/local/oracc/bin/gdf-entry.sh", tmp, elements[0], "xml", NULL);
		}
	      else if (!elements[1] || !strcmp(elements[1], "html"))
		{
		  print_hdr();
		  execl("/bin/sh", "sh", "/usr/local/oracc/bin/gdf-entry.sh", tmp, elements[0], NULL);
		}
	    }
	}
    }
  do404();
}