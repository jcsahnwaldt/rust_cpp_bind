#ifndef FOO_HPP
#define FOO_HPP

#include <cstdarg>
#include <cstdint>
#include <cstdlib>
#include <ostream>
#include <new>

struct Foo {
  int32_t i;
  void inc(int32_t i);
  int32_t get() const;
};

extern "C" {

void inc(Foo *self, int32_t i);

int32_t get(const Foo *self);

void rs_foo(Foo *f);

} // extern "C"

void Foo::inc(int32_t i) { ::inc(this, i); }
int32_t Foo::get() const { return ::get(this); }

#endif // FOO_HPP
