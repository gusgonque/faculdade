#include <stdio.h>

int main () {
  int aux_contador;
  aux_contador = 122;
  for ( aux_contador ; aux_contador >= 97 ; aux_contador--) {
    printf("%c\n", aux_contador);
  }
  return 0;
}
