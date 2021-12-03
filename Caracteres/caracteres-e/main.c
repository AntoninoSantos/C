#include <stdio.h>
#include <ctype.h>
#include <string.h>

void conteudo(char texto[],int n1, int n2,  char var[]){
  int i=0;
  int aux;
  if(n1>n2){
      aux=n1;
      n1=n2;
      n2=aux;
  }
  int x;
  x=0;
  for(i=n1;i<=n2;i++){
    var[x]=texto[i];
    x++;
  } 
  var[x]='\0';
 }

int main() {

  char frase[100];
  int n1, n2;
  printf("qual é a frase?\n");
  fgets(frase, 100, stdin);
  //getchar();
  printf("qual o n1?\n");
  scanf("%d", &n1);
  printf("qual o n2?\n");
  scanf("%d", &n2);
  //fflush(stdin);
  char var[n2-n1];
  conteudo(frase, n1, n2, var);
  printf("%s %d %d %s \n", frase, n1, n2, var);
  
  

  return 0;
}