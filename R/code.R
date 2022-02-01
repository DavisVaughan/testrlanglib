test_is_double <- function(x) {
  .Call(ffi_is_double, x)
}
