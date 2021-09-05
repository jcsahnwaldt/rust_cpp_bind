#ifndef FOO_HPP
#define FOO_HPP

#include <cstdint>

// https://github.com/rust-lang/rust/blob/master/library/core/src/ptr/metadata.rs
struct VTable {
  void (*drop_in_place)(void*);
  uintptr_t size_of;
  uintptr_t align_of;
};

template<class T, class Fns>
struct Dyn {
  T* self;
  Fns* fns;
};

struct Foo;

struct FooFns: VTable {
  void (*foo)(Foo*);
};

struct FooDyn: Dyn<Foo, FooFns> {
  void foo() { fns->foo(self); }
};

extern "C" {

FooDyn get_bar(void);
FooDyn get_baz(void);

void foo(void);

} // extern "C"

#endif // FOO_HPP
