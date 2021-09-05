#include "foo.h"

#include <stdio.h>

int main(void) {
  printf("Hello C!\n");
  FooDyn bar = get_bar();
  printf("bar: %p\n", &bar);
  printf("bar.self: %p *bar.self: %d bar.fns: %p bar.fns->foo: %p\n", bar.self, *(int*)bar.self, bar.fns, bar.fns->foo);
  bar.fns->foo(bar.self);
  FooDyn baz = get_baz();
  printf("baz: %p\n", &baz);
  printf("baz.self: %p *baz.self: %d baz.fns: %p baz.fns->foo: %p\n", baz.self, *(int*)baz.self, baz.fns, baz.fns->foo);
  baz.fns->foo(baz.self);
  foo();
}
