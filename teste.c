#include <stdio.h>
#include <math.h>

int maior_de_2 (int x, int y) {
  return (x > y)? x : y;
}

int menor_de_2 (int x, int y) {
  return (x < y)? x : y;
}

int main () {
  int a, b;
  scanf("%d %d", &a, &b);
  printf("%d\n",maior_de_2 (a, b));
  printf("%d\n",menor_de_2 (a, b));
}
