#include <stdio.h>

int main(void) {
  
  int idadeUser;
  int idadeAluno;
  int nAlunos;
  int i;
  int cont;
  float percent;

  cont=0;

  do{
    printf("Quantos alunos sao?:\n");
    scanf("%d", &nAlunos);
  }while(nAlunos<1);

  do{
    printf("Defina a idade pretendida:\n");
    scanf("%d", &idadeUser);
  }while(idadeUser<0 || idadeUser>100);

  for(i=0; i<nAlunos;i++){
    printf("qual a idade do aluno?:\n");
    scanf("%d", &idadeAluno); 
    if(idadeAluno>idadeUser){
      cont++;
    }
  }

  percent=(cont*100)/nAlunos;

  printf("A percentagem de alunos com idade superior é:\n");
  printf("%0.2f", percent);

  return 0;
}