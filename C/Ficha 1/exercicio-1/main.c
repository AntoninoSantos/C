#include <stdio.h>

int main(void) {
  int n1;
  int n2;

  printf("digite n1:\n");
  scanf("%d", &n1);
  printf("digite n2:\n");
  scanf("%d", &n2);
  int prod;

  prod=n1*n2;

  printf("o produto é: %.2d", prod);


  return 0;
}