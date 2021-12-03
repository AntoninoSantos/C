#include <stdio.h>




int main() {


  int mat[100][100];
  int linha,coluna,i,j;

  printf("introduz o nr de linhas:\n");
  scanf("%d", &linha);

  printf("introduz o nr de colunas:\n");
  scanf("%d", &coluna);
  

  if(linha==coluna){
    printf("a matriz é quadrada \n");
  }
  else{
    printf("a matriz nao é quadrada");
  }
  





  
  


  return 0;
}