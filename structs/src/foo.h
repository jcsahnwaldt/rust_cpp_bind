#ifndef FOO_H
#define FOO_H

#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct Foo {
  int32_t i;
} Foo;

void foo(const struct Foo *self);

const struct Foo *get_foo(void);

#endif /* FOO_H */
