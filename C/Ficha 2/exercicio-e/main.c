#include <stdio.h>

int main(void) {

int dia;

printf("digite o dia:\n");
scanf("%d", &dia);

switch(dia){
  case 1:
    printf("o dia é domingo");break;
  case 2:
    printf("o dia é segunda");break;
  case 3:
    printf("o dia é terca");break;
  case 4:
    printf("o dia é quarta");break;
  case 5:
    printf("o dia é quinta");break;
  case 6:
    printf("o dia é sexta");break;
  case 7:
    printf("o dia é sabado");break;
  default: NULL;
  }



  return (0);
}