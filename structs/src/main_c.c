#include "lib.h"

#include <stdio.h>

static Foo c_foo(Foo f) {
  printf("Hello C World: %d\n", f.i);
  return (Foo){.i = f.i + 1};
}

int main(void) {
  Foo f = {1};
  f = c_foo(f);
  f = rs_foo(f);
}
