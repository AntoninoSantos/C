#include <stdio.h>

int main() {
	int num1, num2, prod;
	printf("Numero 1: \n");
	scanf("%d", &num1);
	printf("Numero 2: \n");
	scanf("%d", &num2);
	prod = num1 * num2;
	printf("Produto: %d \n", prod);
	system("pause");
	return(0);
}
