#include <stdio.h>

int main(void) {
  
  int cargo;
  float salario;
  float novSalario;
  float diff;

  //cargo= 101(gerente), 102(engenheiro), 103(tecnico)
  //gerente= 25% aumento, engenheiro= 20% aumento,tecnico=10 % aumento, resto=10% aumento) 

  printf("Insira o cargo do funcionário:\n");
  scanf("%d", &cargo);

  printf("insira o ordenado do funcionário\n");
  scanf("%f", &salario);

  switch(cargo){
    case 101 :
      novSalario=salario*1.25;
      diff=novSalario-salario;
      printf("o salario antigo é: %0.2f", salario);
      printf(" ");
      printf("o salario novo é: %0.2f", novSalario);
      printf(" ");
      printf("a diferença é: %0.2f", diff);break;
    case 102 :
      novSalario=salario*1.20;
      diff=novSalario-salario;
      printf("o salario antigo é: %0.2f", salario);
      printf(" ");
      printf("o salario novo é: %0.2f", novSalario);
      printf(" ");
      printf("a diferença é: %0.2f", diff);break;
    case 103 :
      novSalario=salario*1.15;
      diff=novSalario-salario;
      printf("o salario antigo é: %0.2f", salario);
      printf(" ");
      printf("o salario novo é: %0.2f", novSalario);
      printf(" ");
      printf("a diferença é: %0.2f", diff);break;
    default:
      novSalario=salario*1.10;
      diff=novSalario-salario;
      printf("o salario antigo é: %0.2f", salario);
      printf(" ");
      printf("o salario novo é: %0.2f", novSalario);
      printf(" ");
      printf("a diferença é: %0.2f", diff);break;
  }
  return 0;
}