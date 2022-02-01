#ifndef RLANG_RLANG_HPP
#define RLANG_RLANG_HPP

#include <cmath>
#include <exception>
using std::isfinite;

extern "C" {
#ifdef __clang__
# pragma clang diagnostic push
# pragma clang diagnostic ignored "-Wkeyword-macro"
#endif

#define class klass

#ifdef __clang__
# pragma clang diagnostic pop
#endif

#include <rlang.h>

#undef class
}

static inline
r_no_return
void rcc_abort(const char* fn) {
 try {
  throw;
 } catch (const std::exception& err) {
   r_abort(err.what());
 } catch (...) {
   r_obj* call = KEEP(r_call(r_sym(fn)));
   (r_stop_internal)("", -1, call, "Caught unknown C++ exception.");
 }
}

#endif
