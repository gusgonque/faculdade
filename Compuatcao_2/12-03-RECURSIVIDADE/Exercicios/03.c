#include <stdio.h>

int SomaVet_Recursivo (int x[], int t) {
  if (t>1)
    return x[t-1] + SomaVet_Recursivo(x, t-1);
  return x[0];
}

int main() {

  int t;
  printf("Entre com o tamanho do vetor de inteiros a ser somado.\n");
  scanf("%d", &t);

  int x[t];
  printf("Entre com o vetor.\n");
  for (int i = 0; i < t; i++)
    scanf("%d", &x[i]);

  int y;
  y = SomaVet_Recursivo(x, t);
  printf("A soma eh igual a %d.\n",y);

  return 0;
}
