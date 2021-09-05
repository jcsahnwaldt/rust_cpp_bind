#include "foo.h"

#include <stdio.h>

static void c_foo(Foo* f) {
  inc(f, 2);
  printf("Hello C World: %d\n", get(f));
}

int main(void) {
  Foo f = {0};
  rs_foo(&f);
  c_foo(&f);
}
