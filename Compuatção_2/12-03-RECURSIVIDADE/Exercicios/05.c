#include <stdio.h>

int CalcElev_Recursivo (int x, int y) {
  if (y>1)
    return x * CalcElev_Recursivo(x, y-1);
  return x;
}

int main() {

  int x, y;
  printf("Entre com X e Y para realizar o calculo X^Y.\n");
  scanf("%d %d", &x, &y);

  int r;
  r = CalcElev_Recursivo(x,y);
  printf("O resultado eh igual a %d.\n", r);

  return 0;
}
