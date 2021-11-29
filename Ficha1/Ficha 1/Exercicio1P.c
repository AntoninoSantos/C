#include <stdio.h>
#include <stdlib.h>

int main(){
	int alunos, cont;
	float media, total, nota;
	total = 0;
	cont = 0;
	printf("Qual e o numero de alunos? \n");
	scanf("%d", &alunos);
	while (cont != alunos){
		system("cls");
		printf("Qual a nota do aluno? \n");
		scanf("%f", &nota);
		total = total + nota;
		cont = cont + 1;
	}
	media = total / alunos;
	printf("A media dos alunos sera %.2f \n", media);
}
