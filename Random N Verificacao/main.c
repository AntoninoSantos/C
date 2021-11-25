#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
    int numeros;
    srand(time(NULL));

    do
    {
        printf("Introduza um numero: ");
        scanf(" %d", &numeros);
    } while (numeros < 1);

    for (int i = 0; i < numeros; i++)
    {
        int aleatorio = rand() % 100 + 1;

        printf("Numero sorteado: %d\n", aleatorio);

        switch (aleatorio)
        {
        case 3:
            printf("Saiu o 3!\n");
            break;

        case 7:
            printf("Numero da sorte!\n");
            break;

        case 13: 
            printf("Numero do azar\n");
            break;
        }

        if (aleatorio > 50)
        {
            printf("Numero maior que 50\n");
        }

        if (aleatorio < 50)
        {
            printf("Numero menor que 50\n");
        }
        
        printf("\n");
    }

}