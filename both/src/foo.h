#ifndef FOO_H
#define FOO_H

#include <stdint.h>

// https://github.com/rust-lang/rust/blob/master/library/core/src/ptr/metadata.rs
typedef struct VTable {
  void (*drop_in_place)(void*);
  uintptr_t size_of;
  uintptr_t align_of;
} VTable;

typedef struct Foo Foo;

typedef struct FooFns {
  VTable metadata;
  void (*foo)(Foo*);
} FooFns;

typedef struct FooDyn {
  Foo* self;
  FooFns* fns;
} FooDyn;

FooDyn get_bar(void);
FooDyn get_baz(void);

void foo(void);

#endif /* FOO_H */
