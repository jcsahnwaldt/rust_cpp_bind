#include "foo.hpp"

#include <iostream>

static void c_foo(Foo* f) {
  std::cout << "Hello C World: " << get_i(f) << "\n";
  set_i(f, get_i(f) + 1);
}

static void cpp_foo(Foo* f) {
  std::cout << "Hello C++ World: " << f->get_i() << "\n";
  f->set_i(f->get_i() + 1);
}

int main() {
  Foo f{1};
  rs_foo(&f);
  c_foo(&f);
  cpp_foo(&f);
}
