#include <stdio.h>
#include <stdlib.h>

int main(){
	float medio, credito;
	printf("Qual o saldo medio? \n");
	scanf("%f", &medio);
	system("cls");
	if (medio >= 0 && medio <= 200){
		credito = 0;
	}
	else {
		if (medio >= 201 && medio <= 400){
			credito = medio * 0.20;
		}
		else {
			if (medio >= 401 && medio <= 600){
				credito = medio * 0.30;
			}
			else {
				if (medio >= 601){
				credito = medio * 0.40;
				}
				else {
					if (medio < 0){
					printf("Escreveu um saldo incorreto. \n");
					}
				}
	
			}
		}
	}
	printf("O saldo medio e %.2f \n", medio);
	printf("O credito sera %.2f \n", credito);
}
