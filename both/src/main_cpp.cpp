#include "foo.hpp"

#include <iostream>
#include <stdio.h>

int main() {
  std::cout << "Hello C++!\n";
  FooDyn bar = get_bar();
  std::cout << "bar: " << &bar << "\n";
  std::cout << "bar.self: " << bar.self << " *bar.self: " << *(int*)bar.self << " bar.fns: " << bar.fns << " bar.fns->foo: " << (void*)bar.fns->foo << "\n";
  bar.fns->foo(bar.self);
  bar.foo();
  FooDyn baz = get_baz();
  std::cout << "baz: " << &baz << "\n";
  std::cout << "baz.self: " << baz.self << " *baz.self: " << *(int*)baz.self << " baz.fns: " << baz.fns << " baz.fns->foo: " << (void*)baz.fns->foo << "\n";
  baz.fns->foo(baz.self);
  baz.foo();
  foo();
}
