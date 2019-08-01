#include <stdio.h>

void Quant_Prox_Ant_Par (int v[], int n) {
  int aux, resultado;
  for (aux = 0; aux < n; aux ++) {
    scanf("%d", &v[aux]);
  }
  for (aux = 1, resultado = 0; aux < n-1; aux ++) {
    resultado += !(v[aux-1]%2) && !(v[aux+1]%2);
  }
  printf("%d\n", resultado);
}

int main () {
  int n;
  scanf("%d", &n);
  int v[n-1];
  Quant_Prox_Ant_Par (v, n);
}
