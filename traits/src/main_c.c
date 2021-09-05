#include "foo.h"

#include <stdio.h>

int main(void) {
  FooDyn bar = get_bar();
  printf("C: bar.self: %p bar.fns->foo: %p\n", bar.self, bar.fns->foo);
  printf("C: bar.fns->foo(bar.self):\n");
  bar.fns->foo(bar.self);

  FooDyn baz = get_baz();
  printf("C: baz.self: %p baz.fns->foo: %p\n", baz.self, baz.fns->foo);
  printf("C: baz.fns->foo(baz.self):\n");
  baz.fns->foo(baz.self);
}
