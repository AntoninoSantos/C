#include <stdio.h>

int main(){
	float trocoini, trocoef, trocogorj, gorjeta;
	gorjeta = 0.10;
	printf("Troco inicial: \n");
	scanf("%f", &trocoini);
	trocogorj = (float)trocoini * gorjeta;
	trocoef = (float)trocoini - trocogorj;
	printf("O troco apos gorjeta e: %.2f \n", trocoef);
	system("pause");
	return(0);
}
