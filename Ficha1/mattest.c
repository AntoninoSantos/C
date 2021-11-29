#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void verificadiagonal(int l, int c, int mat[l][c], int n, int vec[n]){
	
	printf("Quantas linhas e colunas pretende ter na matriz? \n");
	scanf("%d", n);
	l = n;
	c = n;
	
	for (l = 1; l <= n; l++){
		
		for (c = 1; c <= n; c++){
		
			printf("Escreva o numero da posicao (%d)(%d)", l, c);
			scanf("%d", &mat[l][c]);
		
		}
		
		
	}
	
	
	
}


