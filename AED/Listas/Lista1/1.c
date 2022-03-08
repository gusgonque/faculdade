//Projete uma função recursiva que receba um número inteiro n e imprima todos os inteiros entre 0 e n em ordem crescente.
#include <stdio.h>

int EntreZeroeN (int n){
  if (n>0) {
    printf("%d\n", EntreZeroeN(n-1));
    return n;
  }
}

int main() {
  int n;
  scanf("%d", &n);
  printf("%d\n", EntreZeroeN(n));
  return 0;
}
