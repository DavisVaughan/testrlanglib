test_init_library <- function(ns) {
  .Call(ffi_init_library, ns)
}

.onLoad <- function(libname, pkgname) {
  test_init_library(ns_env())
}
