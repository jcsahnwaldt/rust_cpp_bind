#include "foo.hpp"

#include <iostream>
#include <stdio.h>

int main() {
  std::cout << "Hello C++!\n";

  FooDyn foo_bar = get_foo_bar();
  std::cout << "C++: foo_bar.self: " << foo_bar.self << " foo_bar.fns->foo: " << (void*)foo_bar.fns->foo << "\n";
  foo_bar.fns->foo(foo_bar.self);
  foo_bar.foo();
  const Bar* bar = get_bar();
  std::cout << "C++: bar: " << bar << " Bar_foo: " << (void*)Bar_foo << "\n";
  Bar_foo(bar);
  bar->foo();

  FooDyn foo_baz = get_foo_baz();
  std::cout << "C++: foo_baz.self: " << foo_baz.self << " foo_baz.fns->foo: " << (void*)foo_baz.fns->foo << "\n";
  foo_baz.fns->foo(foo_baz.self);
  foo_baz.foo();
  const Baz* baz = get_baz();
  std::cout << "C++: baz: " << baz << " Baz_foo: " << (void*)Baz_foo << "\n";
  Baz_foo(baz);
  baz->foo();

  run_rs();
}
