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

extern "C" {

FooDyn get_bar();

FooDyn get_baz();

} // extern "C"

#endif // FOO_HPP
