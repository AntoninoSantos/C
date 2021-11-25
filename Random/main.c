#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int main(void) {
  srand (time(NULL));
  int valor1 = rand() % 6 + 1;
  printf("Valor: %d\n", valor1);
  int valor2 = rand() % 6 + 1;
  printf("Valor: %d\n", valor2);

  if(valor1==valor2){
    printf("Double\n");
  }
  
  int i;
  for(i=0; i<10; i++){
    if(i==3){
      continue;
    }
    printf("%d\n", i);
  }
  return 0;
}