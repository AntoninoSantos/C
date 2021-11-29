#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct aluno {
	
	char Nome[256];
	int Numero;
	int Nota1;
	int Nota2;
	int Nota_prat;
	int Nota_exame;
	int Nota_final;
	int Nota_freq;
	
} tipo_aluno;


int main(){
	
	tipo_aluno alunos[100];
	int n, ler_alunos(tipo_aluno alunos[]), i, j;
	
	n = ler_aluno(alunos);
	
	printf("Quantos alunos deseja inserir? \n");
	scanf("%d", n);
	
	void dados_aluno(){
		
		for (i = 1; i <= n; i++){
		
			fflush(stdin);
			printf("Escreva o nome do aluno %d. \n", i);
			scanf("%d", &tipo_aluno[i].Nome);
			printf("Escreva o numero do aluno %d. \n", i);
			scanf("%d", &tipo_aluno[i].Numero);
		
			for (j = 1; j <= n; j++){
			
				printf("Escreva a nota do primeiro teste. \n");
				scanf("%d", &atipo_aluno[i].Nota1);
				printf("Escreva a nota do segundo teste. \n");
				scanf("%d", &tipo_aluno[i].Nota2);
				printf("Escreva a nota do trabalho pratico. \n");
				scanf("%d", &tipo_aluno[i].Nota_prat);
				printf("Escreva a nota do exame. \n");
				scanf("%d", &tipo_aluno[i].Nota_exame);
			
			}
			
		}
		
	}
	
	
	void calcular_nota_final(){
	
		alunos[i].Nota_freq = 0.15 * alunos[i].Nota1 + 0.45 * alunos[i].Nota2 + 04 * alunos[i].Nota_prat;
	
		if (alunos[i].Nota_freq < 8 || alunos[i].Nota_exame < 8){
		
			alunos[i].Nota_final = -1;
		
		}
	
		else {
		
			tipo_aluno[i].Nota_final = 0.5 * alunos[i].Nota_freq + 0.5 * alunos[i].Nota_exame;
		
		}
	
	}
	
	void nota_final_aluno(){
	
		for (i = 1; i <= n; i++){
		
			printf("%s", tipo_aluno[i].Nome);
			printf("%d", tipo_aluno[i].Numero);
			printf("%d", tipo_aluno[i].Nota_final);
		
		}
	
	}
	
	void pauta(){
	
		for (i = 1; i <= n; i++){
		
			printf("Nota final do aluno %s, %d. \n", tipo_aluno[i].Nome, tipo_aluno[i].Nota_final);
		
		}
	
	}
	
}

