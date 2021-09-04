#ifndef FOO_H
#define FOO_H

#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct Foo {
  int32_t i;
} Foo;

void set_i(struct Foo *self, int32_t i);

int32_t get_i(const struct Foo *self);

struct Foo rs_foo(struct Foo f);

#endif /* FOO_H */
