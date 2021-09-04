#ifndef FOO_HPP
#define FOO_HPP

#include <cstdarg>
#include <cstdint>
#include <cstdlib>
#include <ostream>
#include <new>

struct Foo {
  int32_t i;
  void set_i(int32_t i);
  int32_t get_i() const;
};

extern "C" {

void set_i(Foo *self, int32_t i);

int32_t get_i(const Foo *self);

void rs_foo(Foo *f);

} // extern "C"

void Foo::set_i(int32_t i) { ::set_i(this, i); }
int32_t Foo::get_i() const { return ::get_i(this); }

#endif // FOO_HPP
