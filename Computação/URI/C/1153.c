#include <stdio.h>

int main () {

  int N, aux, resultado;
  scanf("%d", &N);
  for ( aux = 0, resultado = 1 ; aux < N ; aux++ ) {
    resultado *= ( N - aux );
  }
  printf("%d\n", resultado);

  return 0;
}
