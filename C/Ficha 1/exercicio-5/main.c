#include <stdio.h>

int main(void) {
  
  float base;
  float altura;
  float area;

  printf("digite base:\n");
  scanf("%f", &base);
  printf("digite altura:\n");
  scanf("%f", &altura);
  area=(base*altura)/2;

  printf("a area é: %0.2f", area);


  return 0;
}