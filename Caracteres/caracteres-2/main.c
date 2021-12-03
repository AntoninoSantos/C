#include <stdio.h>
#include <string.h>
#include <ctype.h>


int contaNrCar(char texto[], int cont){
  int i=0;
  cont=0;
  for(i=0;texto[i]!='\0';i++){
      if(texto[i]=='a' || texto[i]=='A' || texto[i]=='e' || texto[i]=='E' || texto[i]=='i' || texto[i]=='I' || texto[i]=='o' || texto[i]=='O' || texto[i]=='u' || texto[i]=='U'){
        cont++;
      }
   }
  return cont;
 }





int main(void) {

  char frase[100],i;
  printf("qual é a frase?\n");
  fgets(frase, 100, stdin);
  

  int cont=contaNrCar(frase, cont);
  printf("existem %d vogais em %s.\n", cont, frase);
  


  




  return 0;
}