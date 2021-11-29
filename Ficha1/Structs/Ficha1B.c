#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct TAluno {
	
	char Nome[255];
	int Matricula;
	char Curso[100];
	
} TAluno;


int main(){
	
	TAluno alunos[5];
	int i, j;
	char nome[50], temp[50];
	
	for (i = 1; i <= 5; i++){
		
		fflush(stdin);
		printf("Escreva o nome do aluno %d. \n", i);
		scanf("%s", &alunos[i].Nome);
		system("cls");
		fflush(stdin);
		printf("Escreva a matricula do aluno %d. \n", i);
		scanf("%d", &alunos[i].Matricula);
		fflush(stdin);
		system("cls");
		printf("Escreva o curso do aluno %d. \n", i);
		scanf("%s", &alunos[i].Curso);
		system("cls");
		
	}
	
	for(i = 1; i <= 5; i++){
		
        for(j = i; j <= 5; j++){
        	
        	if(strcmp(alunos[i].Nome, nome[j]) > 0){
            	strcpy(temp, alunos[i].Nome);
            	strcpy(alunos[i].Nome, nome[j]);
            	strcpy(nome[j], temp);
			}
			
		}
		
	}
	
	for(j = 1; j <= 5 ; j++){
		
    	printf("%s \n", nome[j]);
    	
	}
	
}
