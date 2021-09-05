#include "foo.hpp"

#include <iostream>
#include <stdio.h>

int main() {
  FooDyn bar = get_bar();
  std::cout << "bar: " << &bar << "\n";
  printf("bar.foo: %p *bar.foo: %d bar.fns: %p bar.fns->foo: %p\n", bar.foo, *(int*)bar.foo, bar.fns, bar.fns->foo);
  bar.fns->foo(bar.foo);
  FooDyn baz = get_baz();
  printf("baz: %p\n", &baz);
  printf("baz.foo: %p *baz.foo: %d baz.fns: %p baz.fns->foo: %p\n", baz.foo, *(int*)baz.foo, baz.fns, baz.fns->foo);
  baz.fns->foo(baz.foo);
  foo();
}
