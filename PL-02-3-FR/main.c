#include <stdio.h>
#include <math.h>

void calcFR(int a, int b, int c, float *r1, float *r2){

  float delta=pow(b,2)*4*a*c;
  if(a!=0 && delta>=0){
    *r1=(-b+sqrt(delta)) / (2*a);
    *r2=(-b-sqrt(delta)) / (2*a);
  }
}

int main() {
  int a, b, c;
  float raiz1=0, raiz2=0;
  
  printf("A: "); scanf("%d", &a);
  printf("B: "); scanf("%d", &b);
  printf("C: "); scanf("%d", &c);
  
  calcFR(a, b, c, &raiz1, &raiz2);
  printf("Raiz1: %.1f\nRaiz2: %.1f", raiz1, raiz2);
  return 0;
}