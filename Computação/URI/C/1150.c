#include <stdio.h>

int main () {
  int X, Z, num_numeros, soma_numeros;
  scanf("%d", &X);
  scanf("%d", &Z);
  while ( X >= Z )
    scanf("%d", &Z);
  for ( num_numeros = 0, soma_numeros = 0 ; Z > soma_numeros ; num_numeros++ ) {
    soma_numeros += X + num_numeros;
  }
  printf("%d\n", num_numeros);
  return 0;
}
