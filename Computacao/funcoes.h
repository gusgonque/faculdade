int Soma_Divisores (int x) {
  int aux_soma, i;
  for ( i = 1, aux_soma = 0 ; i <= x ; i++ )
    aux_soma += ( x % i == 0 ) ? i : 0;
  return aux_soma;
}
