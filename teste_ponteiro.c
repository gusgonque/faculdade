#include <stdio.h>

void ordem_decres (int *a, int *b, int *c){
  int aux_a, aux_b, aux_c;
  aux_a = (*a > ((*b > *c)? *b : *c))? *a : ((*b > *c)? *b : *c);
  aux_c = (*a < ((*b < *c)? *b : *c))? *a : ((*b < *c)? *b : *c);
  aux_b = *a + *b + *c - aux_a - aux_c;
  *a = aux_a;
  *b = aux_b;
  *c = aux_c;
}

int main () {
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  ordem_decres(&a, &b, &c);
  printf("%d %d %d\n", a, b, c);
  return 0;
}
