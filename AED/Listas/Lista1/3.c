//Projete uma função recursiva que receba um número inteiro n e calcule o somatório dos números entre 0 e n.
#include <stdio.h>

int SomaNaZero (int n){
  if (n>0)
    return n + SomaNaZero(n-1);
  return n;
}

int main() {
  int n;
  scanf("%d", &n);
  printf("%d\n", SomaNaZero(n));
  return 0;
}
