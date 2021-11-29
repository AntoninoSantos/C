#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	
	int n, j, i, cont, vec[n];
	
	printf("Quantos numeros pretende inserir no vetor? \n");
	scanf("%d", &n);
	system("cls");
	cont = 0;
	
	for (i = 0; i < n; i++){
		
		printf("Insira o numero da posicao %d. \n", i);
		scanf("%d", &vec[n]);
		
		if (vec[i] < 0){
			
			for (j = i; j < n - 1; j++){
				
				vec[j] =  vec[j+1];
				
			}
			
			cont++;
			i--;
			
		}
		
		system("cls");
		
	}
	
	for (n = 0; n < i; n++){
		
		printf("Numeros nao negativos: %d \n", vec[j]);
		
	}
	
}
