#include <stdio.h>

int main() {
  int soma=0, n;
  printf("Qual o N:\n");
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    float nota;
    printf("Qual a nota:\n");
    scanf("%f", &nota);
    soma += nota;
  }
  float media=(float)soma/n;
  printf("A média é: %.2f", media);
  return 0;
}