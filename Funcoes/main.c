#include <stdio.h>

void lerVector(int n, float vec[], int min, int max){
  for(int i=0; i<n; i++){
    do{
      printf("Nota (0-20): \n");
      scanf("%f", &vec[i]);
    }while(vec[i]<min || vec[i]>max);
  }
}

void mostrarVector(int n, float vec[]){
  printf("VECTOR: | ");
  for(int i=0; i<n; i++){
    printf("%.1f | ", vec[i]);
  }
  printf("\n");
}

float calcMedia(int n, float vec[]){
  float soma=0;
  for(int i=0; i<n; i++){
    soma += vec[i];
  }
  return soma/n;
}

int contaNrAlunosNotaSupValor(int n, float vec[], float valor){
  int cont=0;
  for(int i=0; i<n; i++)
    if(vec[i]>valor) cont++; 
  return cont;
}

int main() {
  int n;
  printf("N: ");
  scanf("%d", &n);
  float notas[n];
  lerVector(n, notas, 0, 20);
  mostrarVector(n, notas);
  float m = calcMedia(n, notas);
  printf("Media: %.1f\n", m);
  int cont = contaNrAlunosNotaSupValor(n, notas, m);
  printf("Existem %d alunos com nota sup à media", cont);
  return 0;
}