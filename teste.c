#include <stdio.h>
#include <stdlib.h>

int main() {
  int *x = malloc(sizeof(int));

  printf("*x = %d\n", *x);
  printf("x = %d\n", x);
  printf("&x = %d\n", &x);
  printf("*&x = %d\n", *&x);

  free(x);
  x = NULL;

  return 0;
}
