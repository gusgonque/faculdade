#include <stdio.h>

void Quant_Prox_Maior (int v[], int n) {
  int aux, resultado;
  for (aux = 0; aux < n; aux ++) {
    scanf("%d", &v[aux]);
  }
  for (aux = 1, resultado = 0; aux < n; aux ++) {
    resultado += (v[aux]>v[aux-1]);
  }
  printf("%d\n", resultado);
}

int main () {
  int n;
  scanf("%d", &n);
  int v[n-1];
  Quant_Prox_Maior (v, n);
  return 0;
}
