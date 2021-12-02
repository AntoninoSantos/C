#include <stdio.h>
#include<stdlib.h>
#include<string.h>

int conta_char(char* str, char c)
{
	int n = 0;
	int buf = 0;
	while(str[n] != 0)
	{
		if(str[n] == c)
		{
			buf++;
		}
		n++;
	}
	return buf;
}

int main(){
char frase[20];
char c;
printf("Inserir Frase:\n");
fgets(frase, 20, stdin);
printf("Caracter:\n");
scanf("%c",&c);

printf("O numero de ocorrencias do caractere inserido e: %d\n",conta_char(frase, c));
system("pause");
return 0;
}