#include <stdio.h>

int main(void) {
  int idade;
  int EC;

  printf("digite estado civil:\n");
  scanf("%d", &EC);//valor ou zero ou 1 para solteiro ou casado
  printf("digite a sua idade:\n");
  scanf("%d", &idade);


switch (EC) {
  case 0:
    if(idade<25){
      printf("g1");break;
    }
    else{
      printf("g2");break;
    }
  case 1:
    if(idade<34){
      printf("g3");break;
    }
    else{
      printf("g4");break;
    }

  }
  return 0;
}