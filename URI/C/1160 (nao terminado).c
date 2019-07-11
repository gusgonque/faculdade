#include <stdio.h>

int main () {

  int pop_a, pop_b, quant_anos, aux_a, aux_b, num_casos, i;
  float cres_a, cres_b;
  scanf("%d", &num_casos);
  for ( i = 0 ; i < num_casos ; i++ ) {
    scanf("%d %d %f %f", &pop_a, &pop_b, &cres_a, &cres_b);
    for ( quant_anos = 0, aux_a = pop_a, aux_b = pop_b ; aux_b >= aux_a ; quant_anos++ ) {
      aux_a *= ((100.0 + cres_a) / 100.0);
      aux_b *= ((100.0 + cres_b) / 100.0);
      if (quant_anos > 100) {
        printf("Mais de 1 seculo.\n");
        }
    }
    if (quant_anos <= 100)
      printf("%d anos.\n", quant_anos);
  }

  return 0;
}
