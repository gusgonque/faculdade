#include <stdio.h>

void fibonacci (int x) {
  int aux1, aux2, aux3, aux_contador;
  for ( aux1=0, aux2=1, aux3=1, aux_contador=0; aux_contador < x ; aux_contador ++ ) {
    printf ("%d ", aux3);
    aux3 = aux2 + aux1;
    aux1 = aux2;
    aux2 = aux3;
  }
  printf("\n");
}

int main () {
  int num_numeros;
  scanf("%d", &num_numeros);
  for (  ; num_numeros>=0 ; scanf("%d", &num_numeros)) {
    fibonacci(num_numeros);
  }
  return 0;
}
