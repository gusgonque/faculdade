int Soma_Divisores (int x) {
  int aux_soma, i;
  for ( i = 1, aux_soma = 0 ; i <= x ; i++ )
    aux_soma += ( x % i == 0 ) ? i : 0;
  return aux_soma;
}

int Fatorial (int x) {
  int fat, i;
  for(fat = x, i = 1; i < x; i--)
    fat *= i;
  return fat;
}
