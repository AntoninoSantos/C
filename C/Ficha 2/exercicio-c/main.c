#include <stdio.h>

int main(void) {
  
  float salsemanal;
  float nhoras;
  float nhorasxtra;


  printf("inserir o nr de horas:\n");
  scanf("%f", &nhoras);

  if(nhoras<=36){
    printf("vai receber: %0.2f", (nhoras*7.5));
  }
  else{
    nhorasxtra=nhoras-36;
    printf("vai receber: %0.2f",(nhoras-nhorasxtra)*7.5);
    printf(" ");
    printf("e vai receber das horas extra: %0.2f", nhorasxtra*10);
  }


  return 0;
}