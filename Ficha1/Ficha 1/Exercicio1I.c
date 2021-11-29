#include <stdio.h>

int main(){
	int num;
	printf("Escreva o numero pretendido: \n");
	scanf("%d", &num);
	if (num == 0){
			printf("O numero e neutro. \n");
	}
	else{
		if (num %2 == 0) {
		printf("O numero e par. \n");
		} else {
		if (num %2 != 0){
			printf("O numero e impar. \n");
			}
		}
	}
}
