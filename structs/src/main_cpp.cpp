#include "foo.hpp"

#include <iostream>

static Foo c_foo(Foo f) {
  std::cout << "Hello C World: " << f.i << "\n";
  return {f.i + 1};
}

static Foo cpp_foo(Foo f) {
  std::cout << "Hello C++ World: " << f.get_i() << "\n";
  f.set_i(f.get_i() + 1);
  return f;
}

int main() {
  Foo f{1};
  f = rs_foo(f);
  f = c_foo(f);
  f = cpp_foo(f);
}
