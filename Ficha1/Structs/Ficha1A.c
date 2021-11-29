#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Pessoa {
	
	char Nome[255];
	char Morada[255];
	long int Telefone;
	
} Pessoa;


void main(){
	
	Pessoa pessoas[5];
	int i;
	
	for (i = 1; i <= 5; i++){
		fflush(stdin);
		printf("Escreva o nome da pessoa %d. \n", i);
		scanf("%s", &pessoas[i].Nome);
		system("cls");
		fflush(stdin);
		printf("Escreva a morada da pessoa %d. \n", i);
		scanf("%s", &pessoas[i].Morada);
		fflush(stdin);
		system("cls");
		printf("Escreva o numero de telefone da pessoa %d. \n", i);
		scanf("%d", &pessoas[i].Telefone);
		system("cls");
	}
	
	for (i = 1; i <= 5; i++){
		printf("A %d pessoa tem o nome %s e vive na morada %s com o telefone %d. \n", i, pessoas[i].Nome, pessoas[i].Morada, pessoas[i].Telefone);
	}
	
}
