#include <stdio.h>
#include <stdlib.h>

int main(){
	int ini, fim, aux;
	printf("Escreva o numero de inicio. \n");
	scanf("%d", &ini);
	system("cls");
	printf("Escreva o numero final. \n");
	scanf("%d", &fim);
	system("cls");
	if (ini > fim){
		aux = ini;
		ini = fim;
		fim = aux;
	}
	if (aux % 2 != 0){
		aux + 1;
	}
	for (aux = ini; aux <= fim; aux = aux + 2){
			printf("%d, ", aux);
	}
}
