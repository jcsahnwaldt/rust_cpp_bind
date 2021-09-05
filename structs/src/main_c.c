#include "foo.h"

#include <stdio.h>

int main(void) {
  const struct Foo *f = get_foo();
  printf("C: %p\n", f);
  foo(f);
}
