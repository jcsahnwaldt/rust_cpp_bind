#ifndef FOO_HPP
#define FOO_HPP

#include <cstdarg>
#include <cstdint>
#include <cstdlib>
#include <ostream>
#include <new>

struct Foo {
  int32_t i;
  void foo() const;
};

extern "C" {

void foo(const Foo *self);

const Foo *get_foo();

} // extern "C"

void Foo::foo() const { ::foo(this); }

#endif // FOO_HPP
