#include <stdio.h>
#include <stdlib.h>

void lerVector(int n, int *v){
  for(int i=0; i<n; i++){
    printf("Vec[%d]=", i);scanf("%d", &v[i]);
  }
}

void mostrarVector(int n, int *v){
  printf("Vector: |");
  for(int i=0; i<n; i++){
    printf(" %d |", v[i]);
  }
}
void contagem(int n, int cont){
  cont=0;
  cont=cont+1;
}





int main(void) {

  int cont, cont2,cont3, soma;
  float media;
cont=0;
cont2=0;
cont3=0;
soma=0;
media=0;
int vec[10];

for(int i=0; i<10; i++){
    printf("vec[%d]=", i);
    scanf("%d",&vec[i]);

  if(vec[i]%3==0 || vec[i]%5==0){
    cont3++;
  }
  if(vec[i]<0){
    cont++;
  }else if(vec[i]>0){
    soma=soma+vec[i];
    cont2++;
    media=soma/cont2;
  } 
}

printf("o nr de valores multiplos sao: %d ", cont3);
printf("o nr de valores negativos sao: %d ", cont);
printf("o a media dos positivos é: %.1f ", media);



  return 0;
}