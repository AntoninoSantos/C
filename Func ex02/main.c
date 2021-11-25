#include <stdio.h>

void lerHora(int *h, int *m, int *s){
  printf("Hora: ");
  scanf("%d", &*h);
  printf("Minuto: ");
  scanf("%d", &*m);
  printf("Segundo: ");
  scanf("%d", &*s);
}
int HoraSegundo(int h, int m, int s){
  return h*3600+m*60+s;
}
void HoraSegundos(int totSeg, int *h, int *m, int *s){
  *h=totSeg/3600;
  totSeg=totSeg-(*h*3600);
  *m=totSeg/60;
  *s=totSeg-(*m*60);
}
int main(void) {
  int he, me, se, hs, ms, ss, hi, mi, si;
  printf("Hora de entrada:\n");
  lerHora(&he, &me, &se);
  printf("Hora de saída:\n");
  lerHora(&hs, &ms, &ss);
  int totSegHEnt = HoraSegundo(he, me, se);
  int totSegHSai = HoraSegundo(hs, ms, ss);
  int dif = totSegHSai - totSegHEnt;
  HoraSegundos(dif, &hi, &mi, &si);
  printf("%d:%d:%d", hi, mi, si);
  return 0;
}