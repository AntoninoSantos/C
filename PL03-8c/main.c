#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int i=0, k=0;
    char str[20],str2[20];

fgets(str, 20, stdin);
for(i=0; str[i]!= '\0'; i++){
    if(str[i]==' ')
      str[i]='.';
}
printf("%s",str2);
return 0;
}