#include <stdio.h>

#define MAX 100

void lerConsumosElect(int n, float consumos[n])
{
  int i;
  for(i=0; i<n; i++) {
    printf("Consumo da habitação %d: ", (i+1));
    scanf("%f",&consumos[i]);
  }
}
//n: passagem por valor; *soma, *media: passagem por referência
void calcSomaMedia(int n, float consumos[n], float *soma, float *media){
  int i;
  for(i=0; i<n; i++) {
    *soma+=consumos[i];
  }
  *media=*soma/n;
}

int main() {
  int n;
  float consumos[MAX];

  float soma=0, media;
  do{
    printf("Quantas habitações?\n");
    scanf("%d", &n);
  }while(n<2 || n>MAX);
  
  lerConsumosElect(n, consumos);
  calcSomaMedia(n, consumos, &soma, &media);
  printf("Soma %f, Media %f\n", soma, media);
  return 0;
}