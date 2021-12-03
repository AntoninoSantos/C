#include <stdio.h>

int main(void) {
  float valorapagar;
  float valorDado; //assumir que é superior ao valor a pagar//
  float troco;
  float gorjeta;
  float trocoreal;
  
  printf("digite qual o valor a pagar:\n");
  scanf("%f", &valorapagar);
  printf("digite qual o valor dado:\n");
  scanf("%f", &valorDado);

  troco=valorDado-valorapagar;
  gorjeta=troco*0.10;
  trocoreal=troco-gorjeta;

  printf("o troco real é: %0.2f", trocoreal);


  return 0;
}