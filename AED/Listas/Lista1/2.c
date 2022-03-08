//Projete uma função recursiva que receba um número inteiro n e imprima todos os inteiros entre 0 e n em ordem decrescente.
#include <stdio.h>

int EntreNeZero (int n, int i){
  if (i!=n) {
    printf("%d\n", EntreNeZero(n, i+1));
    return i;
  }
}

int main() {
  int n;
  scanf("%d", &n);
  printf("%d\n", EntreNeZero(n, 0));
  return 0;
}
