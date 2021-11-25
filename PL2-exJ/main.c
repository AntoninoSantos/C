#include <stdio.h>

int main() {
  //PL1 - exH
  int num;
  do{
    printf("Digite um número de 3 dígitos:\n");
    scanf("%d", &num);
  }while(num<100 || num>999);
  int unid = num % 10;
  int dez = (num / 10) % 10;
  //int cent = ((num / 10) / 10) % 10;
  int cent = num / 100;
  printf("Unidades: %d\nDezenas: %d\nCentenas: %d\n", unid, dez, cent);
  
  //PL2-exI
  int numero;
  printf("Digite um número:\n");
  scanf("%d", &numero);
  if(numero % 2 == 0){
    printf("PAR\n");
  }
  else{
    printf("IMPAR\n");
  }
  return 0;
}