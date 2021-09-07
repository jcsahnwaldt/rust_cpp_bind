#ifndef FOO_H
#define FOO_H

#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

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

struct FooDyn get_bar(void);

struct FooDyn get_baz(void);

#endif /* FOO_H */
