#include <stdio.h>

int main () {
  int aux_contador, n, i;
  scanf("%d", &n);
  for ( aux_contador = 97, i = 0 ; n > 0 ; n--, i++) {
    printf("%c\n", aux_contador + i);
  }
  return 0;
}
