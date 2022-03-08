#include <stdio.h>

int Inversao_Recursivo (int a, int b) {
  if (b>0)
    return Inversao_Recursivo((a*10)+(b%10),b/10);
  return a;
}

int main() {
  int x, y;

  printf("Entre com um numero inteiro a ser invertido.\n");
  scanf("%d", &x);
  y = Inversao_Recursivo(0, x);
  printf("O inverso de %d eh igual a %d.\n", x, y);

  return 0;
}
