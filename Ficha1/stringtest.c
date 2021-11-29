#include <stdio.h>

int main(){
	printf("Qual a frase? \n");
	char frase[100], car;
	fflush(stdin); scanf("%[^\n]s", &frase); fflush(stdin);	
	fflush(stdin); scanf("%c", &car); fflush(stdin);
	int i, cont = 0;
	for (i = 0; frase[i] != '\0'; i++){
		if (frase[i] == car){
			cont++;
		}
	}
	printf("Existem %d %c na frase %s ", cont, car, frase);
}
