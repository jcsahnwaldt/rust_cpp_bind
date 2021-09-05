#ifndef FOO_H
#define FOO_H

#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct Foo {
  int32_t i;
} Foo;

void inc(struct Foo *self, int32_t i);

int32_t get(const struct Foo *self);

void rs_foo(struct Foo *f);

struct Foo get_foo(void);

#endif /* FOO_H */
