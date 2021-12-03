#include <stdio.h>

int main(void) {
  
  int n1,n2;
  printf("quantos elementos do vec1?\n");
  scanf("%d", &n1);
  
  int vec1[n1];
  for(int i=0; i<n1; i++){
    printf("vec1[%d]=", i);
    scanf("%d",&vec1[i]);
}
  printf("quantos elementos do vec2?\n");
  scanf("%d", &n2);
  int vec2[n2];
  for(int i=0; i<n2; i++){
    printf("vec2[%d]=", i);
    scanf("%d",&vec2[i]);
}
  for(int i=0; i<n1; i++){
    int flag=0;
    for(int j=0; j<i; j++){
      if(vec1[i]==vec1[j]){
        flag=1;
        break;
      }
    }
    if(flag==0){
      for(int j=0; j<n2; j++){
        if(vec1[i]==vec2[j])
        {
          printf("%d, ", vec1[i]);
          break;//j=n2;
        }
      }
    }
  }
  
  return 0;
}