#ifndef PHP_MAPI_H
#define PHP_MAPI_H 1

// from openchange
#include "utils/mapitest/mapitest.h"
#include "utils/openchange-tools.h"
#include "libmapi/mapidefs.h"
//#include "libmapi/libmapi_private.h"
//#include "libmapi/mapi_nameid.h"
#include "talloc.h"

#define PHP_MAPI_VERSION "1.0"
#define PHP_MAPI_EXTNAME "mapi"

#define PROFILE_RESOURCE_NAME "Profile"
#define SESSION_RESOURCE_NAME "Session"

PHP_MINIT_FUNCTION(mapi);
PHP_MSHUTDOWN_FUNCTION(mapi);


struct entry_w_mem_ctx {
  void* entry;
  TALLOC_CTX* mem_ctx;
};

struct mapi_context* mapi_context_init(char *profdb);
void mapi_context_dtor(void *mapi_ctx);
static struct mapi_profile* get_profile_ptr(TALLOC_CTX* mem_ctx,  struct mapi_context* mapi_ctx, char* opt_profname);
void entry_w_mem_ctx_res_dtor(zend_rsrc_list_entry *rsrc TSRMLS_DC);

extern zend_module_entry mapi_module_entry;
#define phpext_mapi_ptr &mapi_module_entry

#define EXPECTED_MAPI_OBJECTS 32

#endif
