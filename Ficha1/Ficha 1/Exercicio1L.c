#include <stdio.h>
#include <stdlib.h>

int main(){
	int estciv, idade;
	printf("Escreva 0 se for solteiro ou 1 se for casado. \n");
	scanf("%d", &estciv);
	printf("Qual a sua idade? \n");
	scanf("%d", &idade);
	system("cls");
	switch(estciv){
		case 0:
			if (idade < 25){
				printf("Pertence ao grupo I. \n");
				break;
			}
			else{
				printf("Pertence ao grupo II. \n");
				break;
			}
		case 1:
			if (idade < 25){
				printf("Pertence ao grupo III. \n");
				break;
			}
			else{
				printf("Pertence ao grupo IV. \n");
				break;
			}
		default:
			printf("Inseriu dados incorretos. \n");
	}
}
