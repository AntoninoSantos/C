#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct amigo {
	
	char nome[255];
	char sexo[1];
	int ano;
	
} amigo;





void amizade(){
	
	amigo amigos[100];
	int i, result;
	char comp[3] = "fim";

	for (i = 1; i <= 100; i++){
		
		system("cls");
		fflush(stdin);
		printf("Escreva o nome do(a) %d amigo(a). \n", i);
		scanf("%s", &amigos[i].nome);
		result = strcmp(amigos[i].nome, comp);
		if (result == 0){
			break;
		}
		fflush(stdin);
		printf("Escreva o sexo do(a) %d amigo(a). \n", i);
		scanf("%s", &amigos[i].sexo);
		fflush(stdin);
		printf("Escreva o ano de nascimento do(a) %d amigo(a). \n", i);
		scanf("%d", &amigos[i].ano);
		
	}
	
	system("cls");
	printf("Qual o(a) amigo(a) que pretende consultar? \n");
	scanf("%d", &i);
	system("cls");
	printf("Numero: %d \n", i);
	printf("Nome: %s \n", amigos[i].nome);
	printf("Sexo: %s \n", amigos[i].sexo);
	printf("Ano: %d \n", amigos[i].ano);
	
}


int main(){
	
	amizade();
	
}
