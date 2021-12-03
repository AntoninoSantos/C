#include <stdio.h>

int main(void) {
  

  float nota;
  int aluno;
  int i;
  int contagem;

  contagem=0;

  printf("Quantos alunos tem a turma:\n");
  scanf("%d", &aluno);
  
  for(i=0; i<aluno; i++){
    printf("digite a nota do aluno:\n");
    scanf("%f", &nota);
    if(nota<=9.5){
      contagem=contagem+1;
    }
  }

  printf("o total de negativas é: %d", contagem);



  return 0;
}