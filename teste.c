#include <stdio.h>
int maior_2 (int a, int b) {
  return (a > b) ? a : b;
}
int menor_2 (int a, int b) {
  return (a < b) ? a : b;
}
int main () {
  int a, b, c, aux_a, aux_b, aux_c;
  scanf("%d %d %d", &a, &b, &c);
  aux_a = maior_2 (a, maior_2 (b, c));
  aux_c = menor_2 (a, menor_2 (b, c));
  aux_b = a+b+c-aux_a-aux_c;
  printf("%d %d %d\n", aux_a, aux_b, aux_c);
  return 0;
}
