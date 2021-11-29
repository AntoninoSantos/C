#include <stdio.h>
#include <stdlib.h>

int main(){
	float percent, superior;
	int cont, max, idade, alunos, i;
	cont = 0;
	printf("Qual e a idade maxima? \n");
	scanf("%d", &max);
	system("cls");
	printf("Qual e o numero de alunos? \n");
	scanf("%d", &alunos);
	i = alunos;
	while (i != 0){
		system("cls");
		printf("Escreva a idade. \n");
		scanf("%d", &idade);
		if (idade > max){
			cont = cont + 1;
		}
		i = i - 1;
	}
	system("cls");
	superior = cont / alunos;
	percent = superior * 100;
	printf("A percentagem de alunos com idade superior ao maximo definido e: %.2f \n", percent);
}
