#ifndef LIB_HPP
#define LIB_HPP

#include <cstdarg>
#include <cstdint>
#include <cstdlib>
#include <ostream>
#include <new>

struct Foo {
  int32_t i;
};

extern "C" {

Foo rs_foo(Foo f);

} // extern "C"

#endif // LIB_HPP
