#ifndef FOO_HPP
#define FOO_HPP

#include <cstdint>

// https://github.com/rust-lang/rust/blob/master/library/core/src/ptr/metadata.rs
struct VTable {
  void (*drop_in_place)(void*);
  uintptr_t size_of;
  uintptr_t align_of;
};

struct Foo;

struct FooFns {
  VTable metadata;
  void (*foo)(Foo*);
};

struct FooDyn {
  Foo* self;
  FooFns* fns;
  void foo() { this->fns->foo(this->self); }
};

extern "C" {

FooDyn get_bar(void);
FooDyn get_baz(void);

void foo(void);

} // extern "C"

#endif // FOO_HPP
