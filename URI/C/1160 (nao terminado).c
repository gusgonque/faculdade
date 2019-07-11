#include <stdio.h>

int main () {

  int pop_a, pop_b, quant_anos, aux_a, aux_b, num_casos;
  float cres_a, cres_b;
  scanf("%d", &num_casos);
  while (num_casos > 0) {
    scanf("%d %d %f %f", &pop_a, &pop_b, &cres_a, &cres_b);
    for ( quant_anos = 0, aux_a = pop_a, aux_b = pop_b ; aux_b >= aux_a ; quant_anos++ ) {
      aux_a *= (100.0 + cres_a) / 100.0;
      aux_b *= (100.0 + cres_b) / 100.0;
      if (quant_anos > 100) {
        printf("Mais de 1 seculo.\n");
        break;
        }
    }
    if (quant_anos <= 100)
      printf("%d anos.\n", quant_anos);
    num_casos--;
  }

  return 0;
}
