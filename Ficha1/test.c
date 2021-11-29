#include <stdio.h>
#include <string.h>

struct Cliente {

char nome[100];
char morada[50];
long telefone;

};

main() {
	
struct Cliente x, y;
strcpy(x.nome, "Antonio Silva");
strcpy(x.morada, "R. Da Circunvalacao, nr 155");
x.telefone = 122334455;
y = x;
printf("Nome %s\n", y.nome);
printf("Morada %s\n", y.morada);
printf("Telefone %ld\n", y.telefone);

}
