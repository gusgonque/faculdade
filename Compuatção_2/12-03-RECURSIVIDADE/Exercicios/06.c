#include <stdio.h>

int InvertVet_Recursivo (int x[], int t, int p) {
  if (p<t/2){

    return x[t-1] + InvertVet_Recursivo(x, t-1);
  }
  return x[0];
}

int main() {

  int t;
  printf("Entre com o tamanho do vetor de inteiros a ser invertido.\n");
  scanf("%d", &t);

  int x[t];
  printf("Entre com o vetor.\n");
  for (int i = 0; i < t; i++)
    scanf("%d", &x[i]);

  int y;
  y = InvertVet_Recursivo(x, t, 0);
  printf("A soma eh igual a %d.\n",y);

  return 0;
}
