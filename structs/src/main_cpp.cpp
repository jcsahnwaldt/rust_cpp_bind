#include "foo.hpp"

#include <iostream>

static void c_foo(Foo* f) {
  inc(f, 2);
  std::cout << "C: " << get(f) << "\n";
}

static void cpp_foo(Foo* f) {
  f->inc(3);
  std::cout << "C++: " << f->get() << "\n";
}

int main() {
  Foo f = get_foo();
  rs_foo(&f);
  c_foo(&f);
  cpp_foo(&f);
}
