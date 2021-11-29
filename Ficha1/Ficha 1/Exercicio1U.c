#include <stdio.h>
#include <stdlib.h>

int main(){
	int num, maior, par, impar;
	impar = 0;
	par = 0;
	maior = 0;
	printf("Escreva um numero. \n");
	scanf("%d", &num);
	system("cls");
	while (impar != 5){
		printf("Escreva um numero. \n");
		scanf("%d", &num);
		system("cls");
		if (num % 2 != 0){
			impar = impar + 1;	
		}
		else{
			par = par + 1;
			maior = num;
		}
	}
	if (par != 0){
		printf("O maior numero par sera %d \n", maior);
	}
	else{
		printf("Nao escreveu um numero par. \n");
	}
}
