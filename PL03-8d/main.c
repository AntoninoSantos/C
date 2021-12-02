#include <stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
  int i, count = 0;
  char carac,texto[30] = "ATEC escola de formação";
  printf("Valor da variavel texto =   %s\n",texto);
  printf("Insira um caracter: ");
  scanf("%c", &carac);
  for (i=0; i<30; i++){
  if(carac == texto[i])
  {
    printf("Valor do elemento %d da string = %c\n",i, texto[i]);
    count++;
    break;
  }
    }
      if(count == 0){
      printf("Não encontrou!");
    }
  return 0;
}