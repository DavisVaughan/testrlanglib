#include <rlang.hpp>
#include <stdlib.h> // for NULL
#include <stdbool.h>
#include <R_ext/Rdynload.h>
#include <R_ext/Visibility.h>

r_obj* ffi_is_double(r_obj* x);

r_obj* ffi_init_library(r_obj* ns) {
  r_init_library(ns);
  return r_null;
}

extern "C" {

static const R_CallMethodDef CallEntries[] = {
  {"ffi_is_double", (DL_FUNC) &ffi_is_double, 1},
  {"ffi_init_library", (DL_FUNC) &ffi_init_library, 1},
  {NULL, NULL, 0}
};

attribute_visible void R_init_testrlanglib(DllInfo *dll) {
  R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
}

}
