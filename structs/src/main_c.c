#include "foo.h"

#include <stdio.h>

int main(void) {
  Foo f = {1};
  printf("C: %p\n", &f);
  foo(&f);
}
