#include <stdio.h>
#include <math.h>

void encriptografia_numero_letra (int x) {
  int aux_x = x, contador_divisoes = 0, aux_divisao, aux_resto;

  for (contador_divisoes, aux_x; aux_x > 0; aux_x / 10) {
    contador_divisoes ++;
  }// dividindo x para saber qual o numero de posicoes.

  for (aux_divisao = pow (10, contador_divisoes), aux_x = x, contador_divisoes, aux_resto = x; contador_divisoes >= 0; contador_divisoes --) {
    aux_x /= aux_divisao;
    printf("%c", (aux_x + 65));
    aux_x = aux_resto % aux_divisao;
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
