#include <stdio.h>
#include <stdlib.h>

int main(){
	int n, i, vec[n], nmaior = 0, pmaior, nmenor = 1000, pmenor;
	printf("Quantas posicoes tem o vetor? \n");
	scanf("%d", &n);
	system("cls");
	for (i = 0; i < n; i = i + 1){
		printf("Elemento %d: ", i);
		scanf("%d", &vec[i]);
		system("cls");
		if (nmaior < vec[i]){
			nmaior = vec[i];
			pmaior = i;
		}
		if (nmenor > vec[i]){
			nmenor = vec[i];
			pmenor = i;
		}
	}
	system("cls");
	printf("O numero maior foi %d", nmaior, ", na posicao %d", pmaior, " \n");
	printf("O numero menor foi %d", nmenor, ", na posicao %d", pmenor, " \n");
}
