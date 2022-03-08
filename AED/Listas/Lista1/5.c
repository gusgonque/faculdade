/*
Projete uma função recursiva para calcular o fatorial exponencial de um inteiro n, calculado segundo
a fórmula: fatexp(n) = n^((n−1)^((n−2)...))
*/
#include <stdio.h>

// Elevar(x,y) => x^y
int Elevar(int x, int y){
  if (y>1)
    return x * Elevar(x, y-1);
  return x;
}

int FatExp (int n){
  if (n>1)
    return Elevar(n, FatExp(n-1));
  return n;
}

int main() {
  int n;
  scanf("%d", &n);
  printf("%d\n", FatExp(n));
  return 0;
}
