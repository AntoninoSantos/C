#include <stdio.h>

int converterHorasParaSegs(int h, int m, int s){
  return h*3600+m*60+s;
}


void converterSegundosParaHora(int total, int *h, int *m,int *s){
  *h=total/3600;
  *m=(total-*h*3600)/60;
  *s=total-*h*3600-*m*60;
}



int main() {
  int he, me,se, hs, ms,ss, hi, mi, si;
  printf("Digite a hora de entrada: (HH:MM:SS)\n");
  scanf("%d:%d:%d", &he,&me,&se);
  printf("Digite a hora de saida: (HH:MM:SS)\n");
  scanf("%d:%d:%d", &hs,&ms,&ss);

  int totalSegE=converterHorasParaSegs(he,me,se);
  int totalSegS=converterHorasParaSegs(hs,ms,ss);

  int total=totalSegS-totalSegE;
  converterSegundosParaHora(total, &hi, &mi, &si);
  printf("intervalo: %d:%d:%d", hi,mi,si);


  return 0;
}