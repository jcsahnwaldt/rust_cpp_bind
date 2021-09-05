#include "foo.hpp"

#include <iostream>
#include <type_traits>

static_assert(std::is_standard_layout<FooFns>::value, "FooFns must have standard layout");
static_assert(std::is_standard_layout<FooDyn>::value, "FooDyn must have standard layout");

int main() {
  const Bar* bar = get_bar();
  std::cout << "C++: bar: " << bar << " Bar_foo: " << (void*)Bar_foo << "\n";
  std::cout << "C++: Bar_foo(bar):\n";
  Bar_foo(bar);
  std::cout << "C++: bar->foo():\n";
  bar->foo();
  FooDyn foo_bar = get_foo_bar();
  std::cout << "C++: foo_bar.self: " << foo_bar.self << " foo_bar.fns->foo: " << (void*)foo_bar.fns->foo << "\n";
  std::cout << "C++: foo_bar.fns->foo(foo_bar.self):\n";
  foo_bar.fns->foo(foo_bar.self);
  std::cout << "C++: foo_bar.foo():\n";
  foo_bar.foo();

  const Baz* baz = get_baz();
  std::cout << "C++: baz: " << baz << " Baz_foo: " << (void*)Baz_foo << "\n";
  std::cout << "C++: Baz_foo(baz):\n";
  Baz_foo(baz);
  std::cout << "C++: baz->foo():\n";
  baz->foo();
  FooDyn foo_baz = get_foo_baz();
  std::cout << "C++: foo_baz.self: " << foo_baz.self << " foo_baz.fns->foo: " << (void*)foo_baz.fns->foo << "\n";
  std::cout << "C++: foo_baz.fns->foo(foo_baz.self):\n";
  foo_baz.fns->foo(foo_baz.self);
  std::cout << "C++: foo_baz.foo():\n";
  foo_baz.foo();
}
