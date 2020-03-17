#include <stdio.h>

void Crescimento_Populacional ( int pop_a, float cres_a, int pop_b, float cres_b) {
  int aux_cont_anos, aux_pop_final_a, aux_pop_final_b;
  for ( aux_cont_anos = 0 , aux_pop_final_a = pop_a , aux_pop_final_b = pop_b ; (aux_cont_anos <= 100) && (aux_pop_final_a <= aux_pop_final_b) ; aux_cont_anos++) {
    aux_pop_final_a *= ( ( 100.0 + cres_a ) / 100.0 );
    aux_pop_final_b *= ( ( 100.0 + cres_b ) / 100.0 );
  }
  if ( aux_cont_anos > 100 )
    printf("Mais de 1 seculo.\n");
  else
    printf("%d anos.\n", aux_cont_anos);
}

int main () {
  int populacao_a, populacao_b, num_casos, i;
  float crescimento_a, crescimento_b;
  scanf("%d", &num_casos);
  for ( i = 0 ; i < num_casos ; i++ ) {
    scanf("%d %d %f %f", &populacao_a, &populacao_b, &crescimento_a, &crescimento_b);
    Crescimento_Populacional (populacao_a,crescimento_a,populacao_b,crescimento_b);
  }
  return 0;
}
