#include "lib.h"

#include <stdio.h>
#include <stdint.h>

static int32_t c_foo(int32_t i) {
  printf("Hello C World: %d\n", i);
  return i + 1;
}

int main(void) {
  int32_t i = 1;
  i = c_foo(i);
  i = rs_foo(i);
}
