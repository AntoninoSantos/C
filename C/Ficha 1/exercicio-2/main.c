#include <stdio.h>
#include <stdlib.h>

int main(void) {

  int n1;
  int n2;
  int n3;

  printf("digite n1:\n");
  scanf("%d", &n1);
  printf("digite n2:\n");
  scanf("%d", &n2);
  printf("digite n3:\n");
  scanf("%d", &n3);
  
  int soma;
  soma=n1+n2+n3;

  int media;

  media=soma/3;

  printf("a média é: %2d", media);
  
  return 0;
}