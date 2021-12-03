#include <stdio.h>

int main(void) {
  int n;
  int soma;
  float media;
  int cont;

  soma=0;
  cont=0;

  printf("introduza o nr pretendido:\n");
  scanf("%d", &n);

  while(n!=0){
    cont=cont+1;
    soma=soma+n;
    scanf("%d", &n);
  }

  media=soma/cont;

  printf("a soma é :\n");
  printf("%d", soma);
  printf(" ");
  printf("a media é :\n");
  printf("%0.2f", media);
  printf(" ");


  return 0;
}