#include <stdio.h>

int main(void) {
  
  float valTotal;
  float valLido;
  
  printf("indique o valor da mercadoria:\n");
  scanf("%f", &valLido);

  valTotal=valLido*1.23;

  printf("o valor total com iva é: %0.2f", valTotal);
  
  return 0;
}