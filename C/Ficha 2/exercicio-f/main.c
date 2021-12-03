#include <stdio.h>

int main(void) {
  float saldomedio;
  float valmax;

  printf("digite saldo medio:\n");
  scanf("%f", &saldomedio);

  
  if(saldomedio<200){
      printf("valor do saldo medio é: %0.2f", saldomedio);
      printf(" ");
      printf("e nao recebe nenhum credito");
  }
  else{
    if(saldomedio>201 && saldomedio<400){
      printf("valor do saldo medio é: %0.2f", saldomedio);
      printf(" ");
      printf("e o valor maximo de credito é: %0.2f", saldomedio*0.2);
    }
    else{ 
        if(saldomedio>401 && saldomedio<600){
        printf("valor do saldo medio é: %0.2f", saldomedio);
        printf(" ");
        printf("e o valor maximo de credito é: %0.2f", saldomedio*0.3);
        }
        else{
          printf("valor do saldo medio é: %0.2f", saldomedio);
        printf(" ");
        printf("e o valor maximo de credito é: %0.2f", saldomedio*0.4);
        }
      }
    }



  return 0;
}