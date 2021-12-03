#include <stdio.h>

int main(void) {
  int n;

  printf("quantos elementos do vector?\n");
  scanf("%d", &n);

  int vec[n];
  for(int i=0; i<n; i++){
    printf("vec[%d]=", i);
    scanf("%d", &vec[i]);
  }
  for(int i=n-1; i>=0; i--){
    printf("vec[%d]= ", i);
    printf("%d", vec[i]);
    printf(" ");
  }
  return 0;
}