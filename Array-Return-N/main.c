#include <stdio.h>
#include <stdlib.h>

#define TAM 3

int main()
{
   int n, ciclos;
    int array[TAM] = {2};

    printf("Quantos numeros quer receber: ");
    scanf(" %d", &ciclos);

    for (int i = 0; i < ciclos; i++)
    {
        printf("Introduza um inteiro: ");
        scanf(" %d", &n);

        for (int j = 0; j < TAM; j++)
        {
            if (n > array[j])
            {
                int valor = array[j];

                array[j] = n;

                n = valor;
            }
        }
    }

    printf("Os maiores numeros foram: ");

    for (int i = 0; i < TAM; i++)
    {
        printf("[%d]", array[i]);
    }
}