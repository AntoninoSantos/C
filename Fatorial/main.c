#include <stdio.h>

int main() 
{
  int n, i, nfat;    
  
  printf("Inserir numero positivo: \n");
  scanf("%d", &n);
  
  nfat = 1;
  for (i = n; i > 1; i--){
    nfat = nfat * i;
    }
  
  printf("O valor de %d!= %d\n", n, nfat);
  return 0;
}