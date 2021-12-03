#include <stdio.h>


int main() {
  int mat1[100][100], mat2[100][100];
  int linha, coluna, i, j;

  printf("insere o nr de linhas:\n");
  scanf("%d", &linha);
  printf("insere o nr de colunas:\n");
  scanf("%d", &coluna);

  printf("insere a matriz:\n");

  for(i=0;i<2;i++){
    for(j=0;j<2;j++){
      scanf("%d",&mat1[i][j]);
      }
      printf("\n");
    }
  for(i=0;i<2;i++){
    for(j=0;j<2;j++){
      printf("%d\t",mat1[i][j]);
    }
    printf("\n");
  }


  printf("insere o nr de linhas da matriz 2:\n");
  scanf("%d", &linha);
  printf("insere o nr de colunas:\n");
  scanf("%d", &coluna);

  printf("insere a matriz:\n");

  for(i=0;i<2;i++){
    for(j=0;j<2;j++){
      scanf("%d",&mat1[i][j]);
      }
      printf("\n");
    }
  for(i=0;i<2;i++){
    for(j=0;j<2;j++){
      printf("%d\t",mat1[i][j]);
    }
    printf("\n");
  }

  


  return 0;
}