#include <stdio.h>

int main(){
	int num1, num2, num3;
	float med;
	printf("Numero 1: \n");
	scanf("%d", &num1);
	printf("Numero 2: \n");
	scanf("%d", &num2);
	printf("Numero 3: \n");
	scanf("%d", &num3);
	med = (float)(num1 + num2 + num3) / 3;
	printf("A media e: %.2f \n", med);
	system("pause");
	return(0);
}
