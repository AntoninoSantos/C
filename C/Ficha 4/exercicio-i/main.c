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

int main(void) {
  int n1;
  printf("quantos elementos tem o vector 1?\n");
  scanf("%d", &n1);
  int vec1[n1];

  lerVector(n1, vec1);


  int n2;
  printf("quantos elementos tem o vector 2?\n");
  scanf("%d", &n2);
  int vec2[n2];

  lerVector(n2, vec2);
  int cont;
  cont=0;

  for(int i=0;i<n1;i++){
    for(int j=0;j<i;j++){
      if(vec1[i]==vec1[j]){
        cont++;
        j=i;
      }
    }
      if(cont==0){
        for(int k=0;k<n2; k++){
          if(vec1[i]==vec2[k]){
            printf("vec= %d", vec1[i]);
        }
      }
    }
  }


  return 0;
}