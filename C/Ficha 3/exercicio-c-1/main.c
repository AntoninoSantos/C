#include <stdio.h>

int main(void) {
  
  int x;
  int y;
  int aux;
  int i;

  printf("digite o primeiro numero:\n");
  scanf("%d", &x);

  printf("digite o segundo numero:\n");
  scanf("%d", &y);

  if(x>y){
    aux=x;
    x=y;
    y=aux;
  }

  if(x%2!=0){
    x=x+1;
  }
  printf("Os nrº pares são:\n");

  for(i=x; i<=y;i+=2){
    printf("%d", i);
    printf(" ");

  }

  return 0;
}