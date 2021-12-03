#include <stdio.h>

int main(void) {
  
int i;
int unidades;
int dezenas;
int centenas;
int resultado;

printf("digite um nr de 3 digitos:\n");
scanf("%i", &i);

unidades=i%10;
resultado=i/10;
dezenas=resultado%10;
centenas=resultado/10;

printf("%i", centenas);
printf(" ") ;
printf("%i", dezenas) ;
printf(" ") ;
printf("%i", unidades) ;



  return 0;
}