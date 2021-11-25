#include <stdio.h>
#include <stdlib.h>

#define TAM_V1 10
#define TAM_V2 20

int main(int argc, char **argv) {
    int n = 10;

    int v1[TAM_V1];
    int v2[TAM_V2];

    int i = 0;

    int vet1[3];
    int vet2[7];
    int vet3[10];

    printf("Inserir valores para o Vetor 1: \n");
    for ( i = 0; i < 3; i++ ){
        scanf( "%d", &vet1[i] );
        }

    printf("Inserir valores para o Vetor 2: \n");
    for ( i = 0; i < 7; i++ ){
        scanf( "%d", &vet2[i] );
        }

    for ( i = 0; i < 3; i++ ){
        vet3[i] = vet1[i];
        }

    for ( i = 0; i < 7; i++ ){
        vet3[i] = vet2[i];
        }

    printf("Vetor 3 em random: \n\n");
    for ( i = 0; i < 10; i++ ){
        printf( "%d \n", vet3[i] );
        }
        return 0;

}