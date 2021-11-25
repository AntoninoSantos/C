#include <stdio.h>
#include <math.h>

//tipoDadosRET nomeFunc(tipoDados parâmetros){}
int calcExp(int b, int e){ //declaração
  //implementação 
  int i, res=1;
  for(i=0; i<e; i++){
    res=res*b;
  }
  return res;
}

void calcFR(int a, int b, int c, float *r1, float *r2){
  //Função incompleta (a nível Math): validar valores
  //*: apontador para um end. de mem.
  *r1=(-b+sqrt(pow(b,2)-4*a*c))/2*a;
  *r2=(-b-sqrt(pow(b,2)-4*a*c))/2*a;
}

int main() {
  
  int base, exp, result, i;

  printf("Qual a base?\n");
  scanf("%d", &base);
  printf("Qual o expoente?\n");
  scanf("%d", &exp);

  result = calcExp(base, exp);
  //passagem de parâmetros por valor

  printf("Resultado: %d\n", result);
  
  int a, b, c;
  float r1, r2;

  printf("Qual o A?\n");
  scanf("%d", &a);
  printf("Qual o B?\n");
  scanf("%d", &b);
  printf("Qual o C?\n");
  scanf("%d", &c);

  calcFR(a, b, c, &r1, &r2);
  //&: endereço de memória da variável
  //passagem de parâmetros por valor (a, b, c)
  //passagem de parâmetros por referência (r1, r2)

  printf("Raiz 1: %.2f\n", r1);
  printf("Raiz 2: %.2f\n", r2);
  return 0;
}

  