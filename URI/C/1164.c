#include <stdio.h>

int Soma_Divisores (int x) {
  int aux_soma, i;
  for ( i = 1, aux_soma = 0 ; i < x ; i++ )
    aux_soma += ( x % i == 0 ) ? i : 0;
  return aux_soma;
}

int main () {
  int num, num_casos, i;
  scanf("%d", &num_casos);
  for ( i = 0 ; i < num_casos ; i++ ) {
    scanf("%d", &num);
    if (Soma_Divisores(num) == num)
      printf("%d eh perfeito\n", num);
    else
      printf("%d nao eh perfeito\n", num);
  }
  return 0;
}
