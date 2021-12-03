#include <stdio.h>

int main(void) {

  int maior;
  int n;
  int cont;
  int flag;
        
  printf("digite um numero:\n");
  scanf("%d", &n);
  maior=-1;
  cont=0;
  
  do{
    if(n%2!=0){
      cont++;
    }
    else{
      if(n>maior || maior%2!=0){
        maior=n;
      }
    }
  }while(cont<5);

  if(maior==-1){
    printf("nao foram introduzidos nrs pares");
  }
  else{
    printf("o maior nr é\n");
    printf("%d", maior);
  }


  return 0;
}