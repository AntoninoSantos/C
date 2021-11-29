#include <stdio.h>
#include <stdlib.h>

int main(){
	int n, i, vec[n];
	printf("Quantas posicoes tem o vetor? \n");
	scanf("%d", &n);
	system("cls");
	for (i = 0; i < n; i = i + 1){
		printf("Elemento %d: ", i);
		scanf("%d", &vec[i]);
		system("cls");
	}
	system("cls");
	for (i = n - 1; i >= 0; i = i - 1){
		printf("%d, ", vec[i]);
	}
}
