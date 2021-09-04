#include "foo.h"

#include <stdio.h>

static Foo c_foo(Foo f) {
  printf("Hello C World: %d\n", get_i(&f));
  set_i(&f, get_i(&f) + 1);
  return f;
}

int main(void) {
  Foo f = {1};
  f = rs_foo(f);
  f = c_foo(f);
}
