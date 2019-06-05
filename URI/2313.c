#include <stdio.h>
int maior_2 (int a, int b) {
  return (a > b) ? a : b;
}
int menor_2 (int a, int b) {
  return (a < b) ? a : b;
}
int main () {
  int a, b, c, x, y, z;
  scanf("%d %d %d", &a, &b, &c);
  x = maior_2 (a, maior_2 (b, c));
  z = menor_2 (a, menor_2 (b, c));
  y = a+b+c-x-z;
  if (x < (y + z)) {
    if (x == y && y == z) {
      printf("Valido-Equilatero\n");
    }
    else {
      if ((x != y) && (y != z) && (z != x)) {
        printf("Valido-Escaleno\n");
      }
      else {
        printf("Valido-Isoceles\n");
      }
    }
    if ((x * x) == (y * y) + (z * z)) {
      printf("Retangulo: S\n");
    }
    else
      printf("Retangulo: N\n");
  }
  else {
    printf ("Invalido\n");
  }
  return 0;
}
