#include <rlang.hpp>

r_obj* ffi_is_double(r_obj* x) {
  return r_lgl(r_typeof(x) == R_TYPE_double);
}
