#include <stdio.h>
#include "funcoes.h"


int main () {
  long int x,y,r;
  while (1) {
    scanf("%d %d", &x,&y);
    r = Combinacao(x,y);
    printf("%d\n", r);
  }
  return 0;
}
