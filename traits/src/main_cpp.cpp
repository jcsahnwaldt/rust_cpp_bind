#include "foo.hpp"

#include <iostream>
#include <type_traits>

static_assert(std::is_standard_layout<FooFns>::value, "FooFns must have standard layout");
static_assert(std::is_standard_layout<FooDyn>::value, "FooDyn must have standard layout");

int main() {
  FooDyn bar = get_bar();
  std::cout << "C++: bar.self: " << bar.self << " bar.fns->foo: " << (void*)bar.fns->foo << "\n";
  std::cout << "C++: bar.fns->foo(bar.self):\n";
  bar.fns->foo(bar.self);
  std::cout << "C++: bar.foo():\n";
  bar.foo();

  FooDyn baz = get_baz();
  std::cout << "C++: baz.self: " << baz.self << " baz.fns->foo: " << (void*)baz.fns->foo << "\n";
  std::cout << "C++: baz.fns->foo(baz.self):\n";
  baz.fns->foo(baz.self);
  std::cout << "C++: baz.foo():\n";
  baz.foo();
}
