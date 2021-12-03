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


int main() {
  
  int n, cont;
  printf("quantos elementos tem o vector?\n");
  scanf("%d", &n);
  int vec[n];

  lerVector(n, vec);
  cont=0;
  for(int i=1; i<n-1;i++){
    if(vec[i]>vec[i-1]&&vec[i]>vec[i+1]){
      cont=cont+1;
    }
  }

  printf("a quantidade de valores maiores que os seus pares sao: %d", cont);

    


  return 0;
}