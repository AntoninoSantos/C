#include <stdio.h>

int main(){
	int num1, num2, div;
	printf("Numero 1: \n");
	scanf("%d", &num1);
	printf("Numero 2: \n");
	scanf("%d", &num2);
	div = num1 / num2;
	printf("Valor da divisao: %d \n", div);
	system("pause");
	return(0);
}
