#include <stdio.h>

int main(){
	int cont=0;
	printf("Qual a frase? \n");
	char frase[100];
	fflush(stdin); scanf("%[^\n]s", &frase); fflush(stdin);
	if (frase == 'a' || frase == 'e' || frase == 'i' || frase == 'o' || frase == 'u'){
		cont++;
	}
	printf("Existem %d vogais na frase %s ", cont, frase);
}
