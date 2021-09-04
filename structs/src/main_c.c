#include "foo.h"

#include <stdio.h>

static void c_foo(Foo* f) {
  printf("Hello C World: %d\n", get_i(f));
  set_i(f, get_i(f) + 1);
}

int main(void) {
  Foo f = {1};
  rs_foo(&f);
  c_foo(&f);
}
