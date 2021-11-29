#include <stdio.h>

int main(){
	float preco, iva, priva;
	iva = 0.25;
	printf("Preco da mercadoria: \n");
	scanf("%f", &preco);
	priva = (float)preco * iva;
	priva = (float)preco + priva;
	printf("O preco da mercadoria com IVA e: %.2f \n", priva);
	system("pause");
	return(0);
}
