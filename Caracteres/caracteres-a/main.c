#include <stdio.h>
#include<string.h>
#include <ctype.h>

int contaNrCar(char texto[], char car, int cont){
  int i=0;
  char car2;
  cont=0;
  for(i=0;texto[i]!='\0';i++){
    if (isupper(car)){
        car2=tolower(car);
      }else
          car2=toupper(car);
    if(car==texto[i] || car2==texto[i] ){
       cont++; 
      }
   }
  return cont;
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
  int cont=contaNrCar(frase, car, cont);
  printf("existem %d %c em %s.\n", cont, car, frase);


  return 0;
}