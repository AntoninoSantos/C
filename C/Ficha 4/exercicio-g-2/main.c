#include <stdio.h>

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

int main(void) {
  int n;
  printf("quantos elementos tem o  vector?\n");
  scanf("%d", &n);
  int vec[n];
  lerVector(n, vec);
  int cont;
  cont=0;
  for(int i=0; i<n; i++){
    if(vec[i]%3==0){
      cont++;
    }
  }
  printf("a quantidsde de numeros multiplos de 3 é: %d", cont);


  return 0;
}