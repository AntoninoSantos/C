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
 printf("quantos elementos tem o vector?\n");
 scanf("%d", &n);
 int vec[n];

 lerVector(n, vec);

  int pmaior, pmenor;
  pmaior=0;
  pmenor=0;
  for(int i=0; i<n;i++){
    if(vec[i]>vec[pmaior]){
      pmaior=i;
    }
    else{
      if(vec[i]<vec[pmenor]){
        pmenor=i;
      }
    }
  }
  
  
  printf("O maior elemento é: %d na posição %d.\n",vec[pmaior] ,pmaior);
  printf(" ");
  printf("O menor elemento é: %d na posição %d.\n", vec[pmenor], pmenor);



  return 0;
}