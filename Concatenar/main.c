#include <stdio.h>

int main()
{
    char aa[100], bb[100];
      printf("\nPrimeira Frase: ");
      gets(aa);   
      printf("\nSegunda frase para concatenar: ");
      gets(bb);   
    char *a = aa;
    char *b = bb;
    while(*a)  
    {
        a++;    
    }
    while(*b)  
    {
        *a = *b;
        b++;
        a++;
    }
    *a = '\0'; 
      printf("\n\n\nFrase final: %s ", aa);
    return 0;
}