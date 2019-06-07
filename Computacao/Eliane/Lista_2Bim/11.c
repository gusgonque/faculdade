#include <stdio.h>

void encriptografia_numero_letra (int x) {
  int aux_divisao, aux_resto;
  for (aux_divisao = x, aux_resto; aux_divisao > 0; aux_divisao /= 10) {
    aux_resto = aux_divisao % 10;
    printf("%c", (aux_resto  + 65));
  }
  printf("\n");
}

int main () {
  int num;
  scanf ("%d", &num);
  for (num; num >= 0; scanf ("%d", &num)) {
    encriptografia_numero_letra(num);
  }
  return 0;
}
