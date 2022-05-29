#include <stdio.h>

int Soma_Recursivo (int x) {
  if (x>1)
    return x + Soma_Recursivo(x-1);
  return 1;
}

int main() {

  int x;
  printf("Entre com um numero para ser realizada a soma de 1 ate o numero.\n");
  scanf("%d", &x);

  int y;
  y = Soma_Recursivo(x);
  printf("A soma eh igual a %d.\n", y);

  return 0;
}
