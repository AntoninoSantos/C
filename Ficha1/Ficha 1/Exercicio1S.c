#include <stdio.h>
#include <stdlib.h>

int main(){
	float num, soma, media;
	int cont;
	soma = 0;
	cont = 0;
	printf("Escreva um numero. \n");
	scanf("%f", &num);
	soma = soma + num;
	cont = cont + 1;
	while (num != 0){
		system("cls");
		printf("Escreva um numero. \n");
		scanf("%f", &num);
		soma = soma + num;
		if (num != 0){
			cont = cont + 1;
		}
	}
	system("cls");
	media = soma / cont;
	printf("A soma dos numeros sera %.2f \n", soma);
	printf("A media dos numeros sera %.2f \n", media);
}
