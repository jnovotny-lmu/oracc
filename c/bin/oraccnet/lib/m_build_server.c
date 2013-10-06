#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <xmlrpc-c/base.h>
#include <xmlrpc-c/server.h>
#include <xmlrpc-c/server_cgi.h>
#include "oraccnet.h"

static xmlrpc_value *build_method(xmlrpc_env *const envP,
			       xmlrpc_value *const paramArrayP, 
			       void *serverInfo,
			       void *callInfo
			       );

struct xmlrpc_method_info3 build_server_info =
{
  "build",
  build_method,
  NULL,
  0,
  "s:",
  "return the build for the session given in the request"
};

static xmlrpc_value *
build_method(xmlrpc_env *const envP,
	  xmlrpc_value *const paramArrayP, 
	  void *serverInfo,
	  void *callInfo
	  )
{
  const char *addr = getenv("REMOTE_ADDR");
  char *session = NULL;
  xmlrpc_value *s = NULL, *s_ret = NULL, *exec_ret = NULL, *status = NULL;
  struct call_info *cip, *cip_clone;
  struct file_data *zipfile = NULL;

  xmlrpc_array_read_item(envP, paramArrayP, 0, &s);
  dieIfFaultOccurred(envP);
  session = sesh_init(envP, s, 1);
  trace();
  cip = callinfo_unpack(envP, s);
  cip->clientIP = addr;
  fprintf(stderr, "build_method: session=%s; cip->session=%s\n", session, cip->session);
  cip_clone = callinfo_clone(cip);
  fprintf(stderr, "build_method: session=%s; cip->session=%s\n", session, cip->session);
  cip_clone->files = NULL;
  cip_clone->methodargs = NULL;
  s_ret = callinfo_pack(envP, cip_clone);
  zipfile = file_find(cip, "zip");
  if (zipfile)
    {
      file_save(cip, varoracc);
      callinfo_append_arg(cip, NULL, NULL, cip->session);
      fprintf(stderr, "build_method: session=%s; cip->session=%s\n", session, cip->session);
      if ((status = status_set(envP, cip, "started")) != NULL)
	{
	  exec_ret = status;
	  goto RET;
	}
      exec_ret = request_exec(envP, "/usr/local/oracc/www/cgi-bin/oracc-build-server.sh", "oracc-build-server.sh", cip);
    }
  else
    {
      trace();
      exec_ret = request_error(envP, "oracc-xmlrpc: build: can't find input file (what=zip). Stop", NULL);
    }

 RET:
  
  xmlrpc_struct_set_value(envP, exec_ret, "callinfo", s_ret);
  trace();
  return exec_ret;
}
