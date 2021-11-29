#include <stdio.h>

int main(){
	int exesc, exoral, nota, aprov = 10;
	printf("Escreva a nota do exame escrito. \n");
	scanf("%d", &exesc);
	system("cls");
	printf("Escreva a nota do exame oral: \n");
	scanf("%d", &exoral);
	system("cls");
	exesc = exesc * 0.70;
	exoral = exoral * 0.30;
	nota = exesc + exoral;
	if (nota >= aprov) {
		printf("O aluno foi aprovado. \n ");
	}
	else {
		printf("O aluno foi reprovado. \n");
	}
}
