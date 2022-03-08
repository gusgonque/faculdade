/*
Projete uma função recursiva que receba um número inteiro n e calcule seu superfatorial (sf), onde o
superfatorial de n é o produto dos n primeiros fatoriais. Assim, por exemplo sf(5) = 1! × 2! × 3! ×
4! × 5! = 34560
*/
#include <stdio.h>

int Fatorial(int n){
  if (n>1)
    return n * Fatorial(n-1);
  return n;
}

int Superfatorial (int n){
  if (n>0)
    return Fatorial(n) * Superfatorial(n-1);
  return Fatorial(n);
}

int main() {
  int n;
  scanf("%d", &n);
  printf("%d\n", Superfatorial(n));
  return 0;
}
