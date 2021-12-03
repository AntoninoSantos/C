#include <stdio.h>
#include <string.h>
#include <ctype.h>

int contaNrCar(char texto[]){
  int i=0;
  for(i=0;texto[i]!='\0';i++){
    if(texto[i]==' '){
      texto[i]='.';
    }
   }
  return 0;
 }



int main(void) {
  
  char frase[100];
  printf("qual é a frase?\n");
  fgets(frase, 100, stdin);

  contaNrCar(frase);
  printf("%s.\n", frase);



  return 0;
}