#include <stdio.h>

int main(){
	int num1, ant, suc;
	printf("Escreva o numero: \n");
	scanf("%d", &num1);
	ant = num1 - 1;
	suc = num1 + 1;
	printf("Valor antecedente: %d \n", ant);
	printf("Valor sucessor: %d \n", suc);
	system("pause");
	return(0);
}
