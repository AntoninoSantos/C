#include <stdio.h>

int main(void) {
  
  int i;

  printf("digite um nr:\n");
  scanf("%d", &i);

  if(i%2==0){
    printf("o nr é par");
  }
  else{
    printf("o nr é impar");
  }
  return 0;
}