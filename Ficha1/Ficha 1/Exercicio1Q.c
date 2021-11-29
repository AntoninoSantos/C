#include <stdio.h>
#include <stdlib.h>

int main(){
	int alunos, neg, cont;
	float nota;
	neg = 0;
	cont = 0;
	printf("Escreva o numero de alunos. \n");
	scanf("%d", &alunos);
	while (cont != alunos){
		system("cls");
		printf("Escreva a nota do aluno. \n");
		scanf("%f", &nota);
		if (nota < 10){
			neg = neg + 1;
		}
		cont = cont + 1;
	}
	printf("O total de negativas foi %d \n", neg);
}
