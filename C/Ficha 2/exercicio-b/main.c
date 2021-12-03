#include <stdio.h>

int main(void) {
  
  float exescrito;
  float exoral;

  printf("digite nota de exame escrito:\n");
  scanf("%f", &exescrito);
  printf("digite nota de exame oral:\n");
  scanf("%f", &exoral);

  if((exescrito*0.7)+(exoral*0.3)>9.5){
    printf("aluno aprovado");
  }
  else{
    printf("aluno reprovado");
  } 
    return 0;
}