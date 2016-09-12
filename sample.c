#include "php_sample.h"
/*
  1. include zend extension api and spl extensions
*/
#include <zend_exceptions.h>
#include "ext/spl/spl_exceptions.h"

#define SAMPLE_NS "sample"

/*
  2. throw the exception
 */
PHP_FUNCTION(sample_trigger_exception)
{
    zend_throw_exception_ex(
        spl_ce_LogicException, 42, "Sample Exception Message"
    );
}

const zend_function_entry php_sample_functions[] = {
  ZEND_NS_NAMED_FE(SAMPLE_NS, trigger, ZEND_FN(sample_trigger_exception), NULL)
  PHP_FE_END
};

zend_module_entry sample_module_entry = {
  STANDARD_MODULE_HEADER,
  PHP_SAMPLE_EXTNAME,
  php_sample_functions, /* Functions */
  NULL, /* MINIT */
  NULL, /* MSHUTDOWN */
  NULL, /* RINIT */
  NULL, /* RSHUTDOWN */
  NULL, /* MINFO */
  PHP_SAMPLE_EXTVER,
  STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_SAMPLE
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#endif
ZEND_GET_MODULE(sample)
#endif
