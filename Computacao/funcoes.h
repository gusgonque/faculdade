int Soma_Divisores (int x) {
  int aux_soma, i;
  for ( i = 1, aux_soma = 0 ; i <= x ; i++ )
    aux_soma += ( x % i == 0 ) ? i : 0;
  return aux_soma;
}

int Fatorial(int n){
   if (n>0)
      return n*Fatorial(n-1);
   else
      return 1;
}

int Permutacao(int n){
  return Fatorial(n);
}

int Arranjo(int n, int p){
  if (p>1)
      return n*Arranjo(n-1,p-1);
   else
      return n;
}

int Combinacao(int n, int p){
   return Arranjo(n,p)/Fatorial(p);
}
