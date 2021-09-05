#include "foo.h"

#include <stdio.h>

int main(void) {
  const struct Foo *f = get_foo();
  printf("C: f: %p\n", f);
  printf("C: foo(f):\n");
  foo(f);
}
