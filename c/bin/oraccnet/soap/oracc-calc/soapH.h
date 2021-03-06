/* soapH.h
   Generated by gSOAP 2.8.17r from ocalc.h

Copyright(C) 2000-2013, Robert van Engelen, Genivia Inc. All Rights Reserved.
The generated code is released under one of the following licenses:
GPL or Genivia's license for commercial use.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
*/

#ifndef soapH_H
#define soapH_H
#include "soapStub.h"
#ifdef __cplusplus
extern "C" {
#endif
#ifndef WITH_NOIDREF
SOAP_FMAC3 void SOAP_FMAC4 soap_markelement(struct soap*, const void*, int);
SOAP_FMAC3 int SOAP_FMAC4 soap_putindependent(struct soap*);
SOAP_FMAC3 int SOAP_FMAC4 soap_getindependent(struct soap*);
#endif
SOAP_FMAC3 void *SOAP_FMAC4 soap_getelement(struct soap*, int*);
SOAP_FMAC3 int SOAP_FMAC4 soap_putelement(struct soap*, const void*, const char*, int, int);
SOAP_FMAC3 int SOAP_FMAC4 soap_ignore_element(struct soap*);

SOAP_FMAC3 const char ** SOAP_FMAC4 soap_faultcode(struct soap *soap);

#ifndef SOAP_TYPE_byte
#define SOAP_TYPE_byte (3)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_byte(struct soap*, char *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_byte(struct soap*, const char*, int, const char *, const char*);
SOAP_FMAC3 char * SOAP_FMAC4 soap_in_byte(struct soap*, const char*, char *, const char*);

SOAP_FMAC3 int SOAP_FMAC4 soap_put_byte(struct soap*, const char *, const char*, const char*);

#ifndef soap_write_byte
#define soap_write_byte(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_byte(soap, data),0) || soap_put_byte(soap, data, "byte", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 char * SOAP_FMAC4 soap_get_byte(struct soap*, char *, const char*, const char*);

#ifndef soap_read_byte
#define soap_read_byte(soap, data) ( soap_begin_recv(soap) || !soap_get_byte(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif


#ifndef SOAP_TYPE_int
#define SOAP_TYPE_int (1)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_int(struct soap*, int *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_int(struct soap*, const char*, int, const int *, const char*);
SOAP_FMAC3 int * SOAP_FMAC4 soap_in_int(struct soap*, const char*, int *, const char*);

SOAP_FMAC3 int SOAP_FMAC4 soap_put_int(struct soap*, const int *, const char*, const char*);

#ifndef soap_write_int
#define soap_write_int(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_int(soap, data),0) || soap_put_int(soap, data, "int", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 int * SOAP_FMAC4 soap_get_int(struct soap*, int *, const char*, const char*);

#ifndef soap_read_int
#define soap_read_int(soap, data) ( soap_begin_recv(soap) || !soap_get_int(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif


#ifndef SOAP_TYPE_double
#define SOAP_TYPE_double (7)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_double(struct soap*, double *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_double(struct soap*, const char*, int, const double *, const char*);
SOAP_FMAC3 double * SOAP_FMAC4 soap_in_double(struct soap*, const char*, double *, const char*);

SOAP_FMAC3 int SOAP_FMAC4 soap_put_double(struct soap*, const double *, const char*, const char*);

#ifndef soap_write_double
#define soap_write_double(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_double(soap, data),0) || soap_put_double(soap, data, "double", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 double * SOAP_FMAC4 soap_get_double(struct soap*, double *, const char*, const char*);

#ifndef soap_read_double
#define soap_read_double(soap, data) ( soap_begin_recv(soap) || !soap_get_double(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif


#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Fault
#define SOAP_TYPE_SOAP_ENV__Fault (25)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_SOAP_ENV__Fault(struct soap*, struct SOAP_ENV__Fault *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_SOAP_ENV__Fault(struct soap*, const struct SOAP_ENV__Fault *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_SOAP_ENV__Fault(struct soap*, const char*, int, const struct SOAP_ENV__Fault *, const char*);
SOAP_FMAC3 struct SOAP_ENV__Fault * SOAP_FMAC4 soap_in_SOAP_ENV__Fault(struct soap*, const char*, struct SOAP_ENV__Fault *, const char*);

SOAP_FMAC3 int SOAP_FMAC4 soap_put_SOAP_ENV__Fault(struct soap*, const struct SOAP_ENV__Fault *, const char*, const char*);

#ifndef soap_write_SOAP_ENV__Fault
#define soap_write_SOAP_ENV__Fault(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_SOAP_ENV__Fault(soap, data),0) || soap_put_SOAP_ENV__Fault(soap, data, "SOAP-ENV:Fault", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 struct SOAP_ENV__Fault * SOAP_FMAC4 soap_get_SOAP_ENV__Fault(struct soap*, struct SOAP_ENV__Fault *, const char*, const char*);

#ifndef soap_read_SOAP_ENV__Fault
#define soap_read_SOAP_ENV__Fault(soap, data) ( soap_begin_recv(soap) || !soap_get_SOAP_ENV__Fault(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif


#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Reason
#define SOAP_TYPE_SOAP_ENV__Reason (24)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_SOAP_ENV__Reason(struct soap*, struct SOAP_ENV__Reason *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_SOAP_ENV__Reason(struct soap*, const struct SOAP_ENV__Reason *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_SOAP_ENV__Reason(struct soap*, const char*, int, const struct SOAP_ENV__Reason *, const char*);
SOAP_FMAC3 struct SOAP_ENV__Reason * SOAP_FMAC4 soap_in_SOAP_ENV__Reason(struct soap*, const char*, struct SOAP_ENV__Reason *, const char*);

SOAP_FMAC3 int SOAP_FMAC4 soap_put_SOAP_ENV__Reason(struct soap*, const struct SOAP_ENV__Reason *, const char*, const char*);

#ifndef soap_write_SOAP_ENV__Reason
#define soap_write_SOAP_ENV__Reason(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_SOAP_ENV__Reason(soap, data),0) || soap_put_SOAP_ENV__Reason(soap, data, "SOAP-ENV:Reason", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 struct SOAP_ENV__Reason * SOAP_FMAC4 soap_get_SOAP_ENV__Reason(struct soap*, struct SOAP_ENV__Reason *, const char*, const char*);

#ifndef soap_read_SOAP_ENV__Reason
#define soap_read_SOAP_ENV__Reason(soap, data) ( soap_begin_recv(soap) || !soap_get_SOAP_ENV__Reason(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif


#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Detail
#define SOAP_TYPE_SOAP_ENV__Detail (21)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_SOAP_ENV__Detail(struct soap*, struct SOAP_ENV__Detail *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_SOAP_ENV__Detail(struct soap*, const struct SOAP_ENV__Detail *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_SOAP_ENV__Detail(struct soap*, const char*, int, const struct SOAP_ENV__Detail *, const char*);
SOAP_FMAC3 struct SOAP_ENV__Detail * SOAP_FMAC4 soap_in_SOAP_ENV__Detail(struct soap*, const char*, struct SOAP_ENV__Detail *, const char*);

SOAP_FMAC3 int SOAP_FMAC4 soap_put_SOAP_ENV__Detail(struct soap*, const struct SOAP_ENV__Detail *, const char*, const char*);

#ifndef soap_write_SOAP_ENV__Detail
#define soap_write_SOAP_ENV__Detail(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_SOAP_ENV__Detail(soap, data),0) || soap_put_SOAP_ENV__Detail(soap, data, "SOAP-ENV:Detail", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 struct SOAP_ENV__Detail * SOAP_FMAC4 soap_get_SOAP_ENV__Detail(struct soap*, struct SOAP_ENV__Detail *, const char*, const char*);

#ifndef soap_read_SOAP_ENV__Detail
#define soap_read_SOAP_ENV__Detail(soap, data) ( soap_begin_recv(soap) || !soap_get_SOAP_ENV__Detail(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif


#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Code
#define SOAP_TYPE_SOAP_ENV__Code (19)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_SOAP_ENV__Code(struct soap*, struct SOAP_ENV__Code *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_SOAP_ENV__Code(struct soap*, const struct SOAP_ENV__Code *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_SOAP_ENV__Code(struct soap*, const char*, int, const struct SOAP_ENV__Code *, const char*);
SOAP_FMAC3 struct SOAP_ENV__Code * SOAP_FMAC4 soap_in_SOAP_ENV__Code(struct soap*, const char*, struct SOAP_ENV__Code *, const char*);

SOAP_FMAC3 int SOAP_FMAC4 soap_put_SOAP_ENV__Code(struct soap*, const struct SOAP_ENV__Code *, const char*, const char*);

#ifndef soap_write_SOAP_ENV__Code
#define soap_write_SOAP_ENV__Code(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_SOAP_ENV__Code(soap, data),0) || soap_put_SOAP_ENV__Code(soap, data, "SOAP-ENV:Code", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 struct SOAP_ENV__Code * SOAP_FMAC4 soap_get_SOAP_ENV__Code(struct soap*, struct SOAP_ENV__Code *, const char*, const char*);

#ifndef soap_read_SOAP_ENV__Code
#define soap_read_SOAP_ENV__Code(soap, data) ( soap_begin_recv(soap) || !soap_get_SOAP_ENV__Code(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif


#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Header
#define SOAP_TYPE_SOAP_ENV__Header (18)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_SOAP_ENV__Header(struct soap*, struct SOAP_ENV__Header *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_SOAP_ENV__Header(struct soap*, const struct SOAP_ENV__Header *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_SOAP_ENV__Header(struct soap*, const char*, int, const struct SOAP_ENV__Header *, const char*);
SOAP_FMAC3 struct SOAP_ENV__Header * SOAP_FMAC4 soap_in_SOAP_ENV__Header(struct soap*, const char*, struct SOAP_ENV__Header *, const char*);

SOAP_FMAC3 int SOAP_FMAC4 soap_put_SOAP_ENV__Header(struct soap*, const struct SOAP_ENV__Header *, const char*, const char*);

#ifndef soap_write_SOAP_ENV__Header
#define soap_write_SOAP_ENV__Header(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_SOAP_ENV__Header(soap, data),0) || soap_put_SOAP_ENV__Header(soap, data, "SOAP-ENV:Header", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 struct SOAP_ENV__Header * SOAP_FMAC4 soap_get_SOAP_ENV__Header(struct soap*, struct SOAP_ENV__Header *, const char*, const char*);

#ifndef soap_read_SOAP_ENV__Header
#define soap_read_SOAP_ENV__Header(soap, data) ( soap_begin_recv(soap) || !soap_get_SOAP_ENV__Header(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif


#endif

#ifndef SOAP_TYPE_ocalc__sqrt
#define SOAP_TYPE_ocalc__sqrt (17)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_ocalc__sqrt(struct soap*, struct ocalc__sqrt *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_ocalc__sqrt(struct soap*, const struct ocalc__sqrt *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_ocalc__sqrt(struct soap*, const char*, int, const struct ocalc__sqrt *, const char*);
SOAP_FMAC3 struct ocalc__sqrt * SOAP_FMAC4 soap_in_ocalc__sqrt(struct soap*, const char*, struct ocalc__sqrt *, const char*);

SOAP_FMAC3 int SOAP_FMAC4 soap_put_ocalc__sqrt(struct soap*, const struct ocalc__sqrt *, const char*, const char*);

#ifndef soap_write_ocalc__sqrt
#define soap_write_ocalc__sqrt(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_ocalc__sqrt(soap, data),0) || soap_put_ocalc__sqrt(soap, data, "ocalc:sqrt", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 struct ocalc__sqrt * SOAP_FMAC4 soap_get_ocalc__sqrt(struct soap*, struct ocalc__sqrt *, const char*, const char*);

#ifndef soap_read_ocalc__sqrt
#define soap_read_ocalc__sqrt(soap, data) ( soap_begin_recv(soap) || !soap_get_ocalc__sqrt(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif


#ifndef SOAP_TYPE_ocalc__sqrtResponse
#define SOAP_TYPE_ocalc__sqrtResponse (16)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_ocalc__sqrtResponse(struct soap*, struct ocalc__sqrtResponse *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_ocalc__sqrtResponse(struct soap*, const struct ocalc__sqrtResponse *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_ocalc__sqrtResponse(struct soap*, const char*, int, const struct ocalc__sqrtResponse *, const char*);
SOAP_FMAC3 struct ocalc__sqrtResponse * SOAP_FMAC4 soap_in_ocalc__sqrtResponse(struct soap*, const char*, struct ocalc__sqrtResponse *, const char*);

SOAP_FMAC3 int SOAP_FMAC4 soap_put_ocalc__sqrtResponse(struct soap*, const struct ocalc__sqrtResponse *, const char*, const char*);

#ifndef soap_write_ocalc__sqrtResponse
#define soap_write_ocalc__sqrtResponse(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_ocalc__sqrtResponse(soap, data),0) || soap_put_ocalc__sqrtResponse(soap, data, "ocalc:sqrtResponse", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 struct ocalc__sqrtResponse * SOAP_FMAC4 soap_get_ocalc__sqrtResponse(struct soap*, struct ocalc__sqrtResponse *, const char*, const char*);

#ifndef soap_read_ocalc__sqrtResponse
#define soap_read_ocalc__sqrtResponse(soap, data) ( soap_begin_recv(soap) || !soap_get_ocalc__sqrtResponse(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif


#ifndef SOAP_TYPE_ocalc__sub
#define SOAP_TYPE_ocalc__sub (14)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_ocalc__sub(struct soap*, struct ocalc__sub *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_ocalc__sub(struct soap*, const struct ocalc__sub *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_ocalc__sub(struct soap*, const char*, int, const struct ocalc__sub *, const char*);
SOAP_FMAC3 struct ocalc__sub * SOAP_FMAC4 soap_in_ocalc__sub(struct soap*, const char*, struct ocalc__sub *, const char*);

SOAP_FMAC3 int SOAP_FMAC4 soap_put_ocalc__sub(struct soap*, const struct ocalc__sub *, const char*, const char*);

#ifndef soap_write_ocalc__sub
#define soap_write_ocalc__sub(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_ocalc__sub(soap, data),0) || soap_put_ocalc__sub(soap, data, "ocalc:sub", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 struct ocalc__sub * SOAP_FMAC4 soap_get_ocalc__sub(struct soap*, struct ocalc__sub *, const char*, const char*);

#ifndef soap_read_ocalc__sub
#define soap_read_ocalc__sub(soap, data) ( soap_begin_recv(soap) || !soap_get_ocalc__sub(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif


#ifndef SOAP_TYPE_ocalc__subResponse
#define SOAP_TYPE_ocalc__subResponse (13)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_ocalc__subResponse(struct soap*, struct ocalc__subResponse *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_ocalc__subResponse(struct soap*, const struct ocalc__subResponse *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_ocalc__subResponse(struct soap*, const char*, int, const struct ocalc__subResponse *, const char*);
SOAP_FMAC3 struct ocalc__subResponse * SOAP_FMAC4 soap_in_ocalc__subResponse(struct soap*, const char*, struct ocalc__subResponse *, const char*);

SOAP_FMAC3 int SOAP_FMAC4 soap_put_ocalc__subResponse(struct soap*, const struct ocalc__subResponse *, const char*, const char*);

#ifndef soap_write_ocalc__subResponse
#define soap_write_ocalc__subResponse(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_ocalc__subResponse(soap, data),0) || soap_put_ocalc__subResponse(soap, data, "ocalc:subResponse", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 struct ocalc__subResponse * SOAP_FMAC4 soap_get_ocalc__subResponse(struct soap*, struct ocalc__subResponse *, const char*, const char*);

#ifndef soap_read_ocalc__subResponse
#define soap_read_ocalc__subResponse(soap, data) ( soap_begin_recv(soap) || !soap_get_ocalc__subResponse(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif


#ifndef SOAP_TYPE_ocalc__add
#define SOAP_TYPE_ocalc__add (11)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_ocalc__add(struct soap*, struct ocalc__add *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_ocalc__add(struct soap*, const struct ocalc__add *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_ocalc__add(struct soap*, const char*, int, const struct ocalc__add *, const char*);
SOAP_FMAC3 struct ocalc__add * SOAP_FMAC4 soap_in_ocalc__add(struct soap*, const char*, struct ocalc__add *, const char*);

SOAP_FMAC3 int SOAP_FMAC4 soap_put_ocalc__add(struct soap*, const struct ocalc__add *, const char*, const char*);

#ifndef soap_write_ocalc__add
#define soap_write_ocalc__add(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_ocalc__add(soap, data),0) || soap_put_ocalc__add(soap, data, "ocalc:add", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 struct ocalc__add * SOAP_FMAC4 soap_get_ocalc__add(struct soap*, struct ocalc__add *, const char*, const char*);

#ifndef soap_read_ocalc__add
#define soap_read_ocalc__add(soap, data) ( soap_begin_recv(soap) || !soap_get_ocalc__add(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif


#ifndef SOAP_TYPE_ocalc__addResponse
#define SOAP_TYPE_ocalc__addResponse (10)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_ocalc__addResponse(struct soap*, struct ocalc__addResponse *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_ocalc__addResponse(struct soap*, const struct ocalc__addResponse *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_ocalc__addResponse(struct soap*, const char*, int, const struct ocalc__addResponse *, const char*);
SOAP_FMAC3 struct ocalc__addResponse * SOAP_FMAC4 soap_in_ocalc__addResponse(struct soap*, const char*, struct ocalc__addResponse *, const char*);

SOAP_FMAC3 int SOAP_FMAC4 soap_put_ocalc__addResponse(struct soap*, const struct ocalc__addResponse *, const char*, const char*);

#ifndef soap_write_ocalc__addResponse
#define soap_write_ocalc__addResponse(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_ocalc__addResponse(soap, data),0) || soap_put_ocalc__addResponse(soap, data, "ocalc:addResponse", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 struct ocalc__addResponse * SOAP_FMAC4 soap_get_ocalc__addResponse(struct soap*, struct ocalc__addResponse *, const char*, const char*);

#ifndef soap_read_ocalc__addResponse
#define soap_read_ocalc__addResponse(soap, data) ( soap_begin_recv(soap) || !soap_get_ocalc__addResponse(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif


#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_PointerToSOAP_ENV__Reason
#define SOAP_TYPE_PointerToSOAP_ENV__Reason (27)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_PointerToSOAP_ENV__Reason(struct soap*, struct SOAP_ENV__Reason *const*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_PointerToSOAP_ENV__Reason(struct soap*, const char *, int, struct SOAP_ENV__Reason *const*, const char *);
SOAP_FMAC3 struct SOAP_ENV__Reason ** SOAP_FMAC4 soap_in_PointerToSOAP_ENV__Reason(struct soap*, const char*, struct SOAP_ENV__Reason **, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_PointerToSOAP_ENV__Reason(struct soap*, struct SOAP_ENV__Reason *const*, const char*, const char*);

#ifndef soap_write_PointerToSOAP_ENV__Reason
#define soap_write_PointerToSOAP_ENV__Reason(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_PointerToSOAP_ENV__Reason(soap, data),0) || soap_put_PointerToSOAP_ENV__Reason(soap, data, "SOAP-ENV:Reason", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 struct SOAP_ENV__Reason ** SOAP_FMAC4 soap_get_PointerToSOAP_ENV__Reason(struct soap*, struct SOAP_ENV__Reason **, const char*, const char*);

#ifndef soap_read_PointerToSOAP_ENV__Reason
#define soap_read_PointerToSOAP_ENV__Reason(soap, data) ( soap_begin_recv(soap) || !soap_get_PointerToSOAP_ENV__Reason(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif


#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_PointerToSOAP_ENV__Detail
#define SOAP_TYPE_PointerToSOAP_ENV__Detail (26)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_PointerToSOAP_ENV__Detail(struct soap*, struct SOAP_ENV__Detail *const*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_PointerToSOAP_ENV__Detail(struct soap*, const char *, int, struct SOAP_ENV__Detail *const*, const char *);
SOAP_FMAC3 struct SOAP_ENV__Detail ** SOAP_FMAC4 soap_in_PointerToSOAP_ENV__Detail(struct soap*, const char*, struct SOAP_ENV__Detail **, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_PointerToSOAP_ENV__Detail(struct soap*, struct SOAP_ENV__Detail *const*, const char*, const char*);

#ifndef soap_write_PointerToSOAP_ENV__Detail
#define soap_write_PointerToSOAP_ENV__Detail(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_PointerToSOAP_ENV__Detail(soap, data),0) || soap_put_PointerToSOAP_ENV__Detail(soap, data, "SOAP-ENV:Detail", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 struct SOAP_ENV__Detail ** SOAP_FMAC4 soap_get_PointerToSOAP_ENV__Detail(struct soap*, struct SOAP_ENV__Detail **, const char*, const char*);

#ifndef soap_read_PointerToSOAP_ENV__Detail
#define soap_read_PointerToSOAP_ENV__Detail(soap, data) ( soap_begin_recv(soap) || !soap_get_PointerToSOAP_ENV__Detail(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif


#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_PointerToSOAP_ENV__Code
#define SOAP_TYPE_PointerToSOAP_ENV__Code (20)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_PointerToSOAP_ENV__Code(struct soap*, struct SOAP_ENV__Code *const*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_PointerToSOAP_ENV__Code(struct soap*, const char *, int, struct SOAP_ENV__Code *const*, const char *);
SOAP_FMAC3 struct SOAP_ENV__Code ** SOAP_FMAC4 soap_in_PointerToSOAP_ENV__Code(struct soap*, const char*, struct SOAP_ENV__Code **, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_PointerToSOAP_ENV__Code(struct soap*, struct SOAP_ENV__Code *const*, const char*, const char*);

#ifndef soap_write_PointerToSOAP_ENV__Code
#define soap_write_PointerToSOAP_ENV__Code(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_PointerToSOAP_ENV__Code(soap, data),0) || soap_put_PointerToSOAP_ENV__Code(soap, data, "SOAP-ENV:Code", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 struct SOAP_ENV__Code ** SOAP_FMAC4 soap_get_PointerToSOAP_ENV__Code(struct soap*, struct SOAP_ENV__Code **, const char*, const char*);

#ifndef soap_read_PointerToSOAP_ENV__Code
#define soap_read_PointerToSOAP_ENV__Code(soap, data) ( soap_begin_recv(soap) || !soap_get_PointerToSOAP_ENV__Code(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif


#endif

#ifndef SOAP_TYPE_PointerTodouble
#define SOAP_TYPE_PointerTodouble (8)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_PointerTodouble(struct soap*, double *const*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_PointerTodouble(struct soap*, const char *, int, double *const*, const char *);
SOAP_FMAC3 double ** SOAP_FMAC4 soap_in_PointerTodouble(struct soap*, const char*, double **, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_PointerTodouble(struct soap*, double *const*, const char*, const char*);

#ifndef soap_write_PointerTodouble
#define soap_write_PointerTodouble(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_PointerTodouble(soap, data),0) || soap_put_PointerTodouble(soap, data, "double", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 double ** SOAP_FMAC4 soap_get_PointerTodouble(struct soap*, double **, const char*, const char*);

#ifndef soap_read_PointerTodouble
#define soap_read_PointerTodouble(soap, data) ( soap_begin_recv(soap) || !soap_get_PointerTodouble(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif


#ifndef SOAP_TYPE__QName
#define SOAP_TYPE__QName (5)
#endif

#define soap_default__QName(soap, a) soap_default_string(soap, a)

SOAP_FMAC3 void SOAP_FMAC4 soap_serialize__QName(struct soap*, char *const*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out__QName(struct soap*, const char*, int, char*const*, const char*);
SOAP_FMAC3 char * * SOAP_FMAC4 soap_in__QName(struct soap*, const char*, char **, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_put__QName(struct soap*, char *const*, const char*, const char*);

#ifndef soap_write__QName
#define soap_write__QName(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize__QName(soap, data),0) || soap_put__QName(soap, data, "byte", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 char ** SOAP_FMAC4 soap_get__QName(struct soap*, char **, const char*, const char*);

#ifndef soap_read__QName
#define soap_read__QName(soap, data) ( soap_begin_recv(soap) || !soap_get__QName(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif


#ifndef SOAP_TYPE_string
#define SOAP_TYPE_string (4)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_string(struct soap*, char **);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_string(struct soap*, char *const*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_string(struct soap*, const char*, int, char*const*, const char*);
SOAP_FMAC3 char * * SOAP_FMAC4 soap_in_string(struct soap*, const char*, char **, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_string(struct soap*, char *const*, const char*, const char*);

#ifndef soap_write_string
#define soap_write_string(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_string(soap, data),0) || soap_put_string(soap, data, "byte", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 char ** SOAP_FMAC4 soap_get_string(struct soap*, char **, const char*, const char*);

#ifndef soap_read_string
#define soap_read_string(soap, data) ( soap_begin_recv(soap) || !soap_get_string(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif


#ifdef __cplusplus
}
#endif

#endif

/* End of soapH.h */
