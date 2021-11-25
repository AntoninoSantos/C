#include <stdio.h>

void lerVector(int n, int vec[n]){
  int i;
  printf("Leitura do Vector\n");
  for(i=0; i<n; i++){
    printf("vec[%d]:", i);
    scanf("%d", &vec[i]);
  }
}

float calcMedVec(int n, int vec[n]){
  int i, soma=0;
  float media;
  for(i=0; i<n; i++){
    soma+=vec[i];
  }
  media= (float)soma/n;
  return media;
}

void mostrarVector(int n, int vec[n]){
  int i;
  printf("Vector\n");
  for(i=0; i<n; i++){
    printf("[%d] ", vec[i]);
  }
}

int main(void) {
  int n, i;
  printf("N:\n");
  scanf("%d", &n);
  int vec[n];

  lerVector(n, vec);
  float media=calcMedVec(n, vec);
  printf("Média: %.2f\n", media);
  mostrarVector(n, vec);

  return 0;
}