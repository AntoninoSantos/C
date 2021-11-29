#include <stdio.h>
#include <stdlib.h>

int main(){
	float sal, salnovo, dif;
	int cod;
	printf("Qual e o seu salario de momento? \n");
	scanf("%f", &sal);
	system("cls");
	printf("Insira o codigo do seu cargo?\n");
	scanf("%d", &cod);
	switch(cod){
		case 101:
			salnovo = sal + (sal * 0.25);
			break;
		case 102:
			salnovo = sal + (sal * 0.20);
			break;
		case 103:
			salnovo = sal + (sal * 0.15);
			break;
		default:
			salnovo = sal + (sal * 0.10);
	}
	dif = salnovo - sal;
	system("cls");
	printf("O seu salario antigo era %.2f \n", sal);
	printf("O seu salario novo sera %.2f \n", salnovo);
	printf("A diferenca entre os dois e %.2f \n", dif);
}
