#include "foo.h"

#include <stdio.h>

static void c_foo(Foo* f) {
  inc(f, 2);
  printf("C: %d\n", get(f));
}

int main(void) {
  Foo f = get_foo();
  rs_foo(&f);
  c_foo(&f);
}
