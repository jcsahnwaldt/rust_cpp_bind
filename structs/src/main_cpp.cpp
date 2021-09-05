#include "foo.hpp"

#include <iostream>

int main() {
  Foo f {1};
  std::cout << "C++: " << &f << "\n";
  foo(&f);
  f.foo();
}
