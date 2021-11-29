#include <stdio.h>

int main(){
	float base, altura, area;
	printf("Base do triangulo: \n");
	scanf("%f", &base);
	printf("Altura do triangulo: \n");
	scanf("%f", &altura);
	area = (float)(base * altura) / 2;
	printf("A area do triangulo e: %.2f \n", area);
	system("pause");
	return(0);
}
