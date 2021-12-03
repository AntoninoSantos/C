#include <stdio.h>
#include <stdlib.h>
//declarar a função/assinatura
int absoluto(int n){
  if(n<0){
    n=n*-1;
  }
  return n;
}

//função pow
void calcExp(int base, int exp){
  int res=1;
  for(int i=0; i<=exp;i++){
    res=res*base;
  }
}
//ler/mostrar vector


void lerVector(int n, int *v){
  for(int i=0; i<n; i++){
    printf("vec[%d=", i);scanf("%d", &v[i]); 
  }
}

void mostrarVector(int n, int *v){
  printf("Vector: |");
  for(int i=0; i<n; i++){
    printf("vec[%d]=", i);
  }
}
  

int main(void) {
  int n;
  printf("qual o n?"); scanf("%d", &n);
  int vec[n];

  lerVector(n, vec);
  
  return 0;
}

//exemplo do helder//

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

float calcMedia(int n, int *v){
  float soma=0;
  for(int i=0; i<n; i++){
    soma += v[i];
  }
  return soma/n;
}

int main() {
  int n;
  printf("Qual o N?");scanf("%d", &n);
  int vec[n];

  lerVector(n, vec);
  float media=calcMedia(n, vec);
  printf("Média: %.2f.\n",media);
  mostrarVector(n, vec);
  return 0;
}