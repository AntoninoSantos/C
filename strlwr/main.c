#include <stdio.h>
#include <string.h>
#include<ctype.h>

char *strlwr(char *str)
{
  unsigned char *p = (unsigned char *)str;
  while (*p) {
     *p = tolower((unsigned char)*p);
      p++;
  }
  return str;
}

int main(void) {
  char t1[50];
  printf("Frase: \n");
  fflush(stdin);
  fgets(t1, 50, stdin);
  fflush(stdin);

  strlwr(t1);
  printf("Frase 1: %s\n", t1);

  return 0;
}