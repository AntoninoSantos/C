#include <stdio.h>

int main(void) {
  float nota;
  int aluno;
  int soma;
  float media;
  int i;

  printf("Quantos alunos tem a turma?\n");
  scanf("%d", &aluno);

  soma=0;

  for(i=0; i<aluno; i++){
    printf("Escrever uma nota:\n");
    scanf("%f", &nota);
    soma=soma+nota;
  }






  media=soma/aluno;

  printf(" a media aritmetica da turma é: %2.2f", media);



  return 0;
}