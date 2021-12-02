#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int conta_vogais(const char * s)
{
	int i, num = 0;
	char vogais[10] = "AaEeIiOoUu";

	while (*s)
	{
		for (i=0; i<10; i++)
			if (*s == vogais[i])
				num++;
		s++;
	}
	return num;
}

int main(){

char frase[20];

printf("Inserir frase:\n");

fgets(frase, 20, stdin);

printf("O numero de vogais e: %d",conta_vogais(frase));

return 0;

}