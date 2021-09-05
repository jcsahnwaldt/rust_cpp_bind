#include "foo.hpp"

#include <iostream>

int main() {
  const Foo *f = get_foo();
  std::cout << "C++: f: " << f << "\n";
  printf("C++: foo(f):\n");
  foo(f);
  printf("C++: f->foo():\n");
  f->foo();
}
