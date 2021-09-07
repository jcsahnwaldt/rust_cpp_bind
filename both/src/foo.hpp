#ifndef FOO_HPP
#define FOO_HPP

#include <cstdarg>
#include <cstdint>
#include <cstdlib>
#include <ostream>
#include <new>

struct VTable {
  void (* const drop_in_place)(void*);
  const uintptr_t size_of;
  const uintptr_t align_of;
};

template<class Obj, class Fns>
struct Dyn {
  Obj* const self;
  Fns* const fns;
};

struct FooObj;

struct FooFns {
  VTable metadata;
  void (* const foo)(const FooObj *self);
};

struct FooDyn: Dyn<FooObj, FooFns> {
  void foo() const { fns->foo(self); }
};

struct Bar {
  int32_t i;
  void foo() const;
};

struct Baz {
  int32_t j;
  void foo() const;
};

extern "C" {

void Bar_foo(const Bar *self);

void Baz_foo(const Baz *self);

const Bar *get_bar();

const Baz *get_baz();

FooDyn get_foo_bar();

FooDyn get_foo_baz();

} // extern "C"

void Bar::foo() const { Bar_foo(this); }

void Baz::foo() const { Baz_foo(this); }

#endif // FOO_HPP
