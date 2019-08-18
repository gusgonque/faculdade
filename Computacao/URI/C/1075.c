#include <stdio.h>

int main () {
  int N, contador;
  scanf("%d", &N);
  for ( contador = 1; contador <= 10000 ; contador++ ) {
    if (contador % N == 2)
      printf("%d\n", contador);
    }
  return 0;
}
