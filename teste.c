#include <stdio.h>

int main () {
  int a,b;
  scanf("%d", &a);
  for (a, b=a; a>=0; b+=a){
    scanf("%d", &a);
  }
  printf("%d\n", b);
  return 0;
}
