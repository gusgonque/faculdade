#include <stdio.h>

void Crescimento_Populacional (int pop_a,int  pop_b, float cres_a, float cres_b) {
  int aux_tempo_anos, aux_pop_a, aux_pop_b;
  for ( aux_tempo_anos = 0, aux_pop_a = pop_a, aux_pop_b = pop_b ; (aux_pop_a <= aux_pop_b)||(aux_tempo_anos<=100) ; aux_tempo_anos++ ) {
    aux_pop_a *= ((100.0 + cres_a) / 100.0);
    aux_pop_b *= ((100.0 + cres_b) / 100.0);
  }
  if (aux_tempo_anos <= 100)
    printf("%d anos.\n", aux_tempo_anos);
  else
    printf("Mais de 1 seculo.\n");
}


int main () {
  int pop_a, pop_b, num_casos, i;
  float cres_a, cres_b;
  scanf("%d", &num_casos);
  for ( i = 0 ; i < num_casos ; i++ ) {
    scanf("%d %d %f %f", &pop_a, &pop_b, &cres_a, &cres_b);
    Crescimento_Populacional (pop_a,pop_b,cres_a,cres_b);
  }
  return 0;
}
