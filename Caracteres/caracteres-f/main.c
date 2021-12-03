#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int indexFirst(char texto[]){
  int i=0;
  int val;
  val=0;
  for(i=0;texto[i]!='\0';i++){   
    val=atoi(texto);
  }
    

  return val;
 }




int main(void) {
  
  char frase[100], car;
  printf("qual é a frase?\n");
  fgets(frase, 100, stdin);
  //getchar();
  
  //fflush(stdin);
  int cont=contaNrCar(frase, car, cont);
  printf("existem %d %c em %s.\n", cont, car, frase);

  return 0;
}