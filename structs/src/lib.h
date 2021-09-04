#ifndef LIB_H
#define LIB_H

#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct Foo {
  int32_t i;
} Foo;

struct Foo rs_foo(struct Foo f);

#endif /* LIB_H */
