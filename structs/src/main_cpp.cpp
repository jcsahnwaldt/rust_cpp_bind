#include "foo.hpp"

#include <iostream>

static Foo cpp_foo(Foo f) {
  std::cout << "Hello C World: " << f.i << "\n";
  return {f.i + 1};
}

int main() {
  Foo f{1};
  f = cpp_foo(f);
  f = rs_foo(f);
}
