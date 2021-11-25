#include <stdio.h>

int main(void) {
  int a=3;
  int *x = &a;
  printf("a: %d\n", *x);
  printf("a: %d\n", &x);
  return 0;
}