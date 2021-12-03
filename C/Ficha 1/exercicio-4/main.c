#include <stdio.h>

int main(void) {
  

  int n;
  int ant;
  int suc;

  printf("digite um nr: \n");
  scanf("%d", &n);
  ant=n-1;
  suc=n+1;

  printf(" o antecessor é: %2d", ant) ;
  printf(" o sucessor é: %2d", suc) ;


  return 0;
}