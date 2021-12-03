#include <stdio.h>
#include <stdlib.h>

void lerVector(int n, int *v){
  for(int i=0; i<n; i++){
    printf("Vec[%d]=", i);scanf("%d", &v[i]);
  }
}

void mostrarVector(int n, int *v){
  printf("Vector: |");
  for(int i=0; i<n; i++){
    printf(" %d |", v[i]);
  }
}

int main() {

  int n, cont, soma;
  float media;
  printf("quantos elementos tem o vector?\n");
  scanf("%d", &n);

  int vec[n];
  lerVector(n, vec);

  cont=0;
  soma=0;

  int i;
  for(i=0;i<n;i++){
    if(vec[i]%2!=0){
      cont++;
      soma=soma+vec[i];
    }
  }
  
  media=(float)soma/cont;
  printf("a media dos elementos impares é: %.1f", media);

  return 0;
}