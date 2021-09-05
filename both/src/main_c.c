#include "foo.h"

#include <stdio.h>

int main(void) {
  printf("Hello C!\n");

  const Bar* bar = get_bar();
  printf("C: bar: %p Bar_foo: %p\n", bar, Bar_foo);
  Bar_foo(bar);
  FooDyn foo_bar = get_foo_bar();
  printf("C: foo_bar.self: %p foo_bar.fns->foo: %p\n", foo_bar.self, foo_bar.fns->foo);
  foo_bar.fns->foo(foo_bar.self);

  const Baz* baz = get_baz();
  printf("C: baz: %p Baz_foo: %p\n", baz, Baz_foo);
  Baz_foo(baz);
  FooDyn foo_baz = get_foo_baz();
  printf("C: foo_baz.self: %p foo_baz.fns->foo: %p\n", foo_baz.self, foo_baz.fns->foo);
  foo_baz.fns->foo(foo_baz.self);

  run_rs();
}
