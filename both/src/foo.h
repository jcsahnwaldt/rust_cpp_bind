#ifndef FOO_H
#define FOO_H

#include <stdint.h>

// https://github.com/rust-lang/rust/blob/master/library/core/src/ptr/metadata.rs
typedef struct VTable {
  void (* const drop_in_place)(void*);
  const uintptr_t size_of;
  const uintptr_t align_of;
} VTable;

typedef struct FooObj FooObj;

typedef struct FooFns {
  VTable metadata;
  void (* const foo)(const struct FooObj *self);
} FooFns;

typedef struct FooDyn {
  struct FooObj* const self;
  struct FooFns* const fns;
} FooDyn;

typedef struct Bar {
  int32_t i;
} Bar;

typedef struct Baz {
  int32_t j;
} Baz;

void Bar_foo(const struct Bar *self);

void Baz_foo(const struct Baz *self);

const struct Bar *get_bar(void);

const struct Baz *get_baz(void);

struct FooDyn get_foo_bar(void);

struct FooDyn get_foo_baz(void);

#endif // FOO_H
