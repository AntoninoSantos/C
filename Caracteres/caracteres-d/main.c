#include <stdio.h>
#include <ctype.h>
#include <string.h>

int indexFirst(char texto[], char C){
  int i=0;
  for(i=0;texto[i]!='\0';i++){
    if(C==texto[i]){
      printf("o index da posição é %d", i);break;
    }
  }
  return 0;
 }





int main(void) {
  
  char frase[100], car;
  printf("qual é a frase?\n");
  fgets(frase, 100, stdin);
  //getchar();
  printf("qual o caracter?\n");
  scanf("%c", &car);
  printf("car:%c.\n", car);
  //fflush(stdin);
  int cont=indexFirst(frase, car);





  return 0;
}