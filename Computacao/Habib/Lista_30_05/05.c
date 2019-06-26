#include <stdio.h>
#include <ctype.h>

int main () {
  int aux_contador, n, i;
  scanf("%d", &n);
  for ( i = 0 ; n > 0 ; n--, i++) {
    printf("%c\n", (i%2==0) ? 97+i : 65+i );
  }
  return 0;
}
