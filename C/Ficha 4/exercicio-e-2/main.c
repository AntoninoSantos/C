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
 int n, dif;
 printf("quantos elementos tem o vector?\n");
 scanf("%d", &n);
 int vec[n];

 lerVector(n, vec);
 dif=abs(vec[0]-vec[1]);

 for(int i=1;i<n-1;i++){
   if(abs(vec[i]-vec[i+1])>dif){
     dif=abs(vec[i]-vec[i+1]);
   }
 }

 printf("a maior diferença é: %d", dif);

   return 0;
}