#include "foo.hpp"

#include <iostream>

int main() {
  const Foo *f = get_foo();
  std::cout << "C++: " << f << "\n";
  foo(f);
  f->foo();
}
