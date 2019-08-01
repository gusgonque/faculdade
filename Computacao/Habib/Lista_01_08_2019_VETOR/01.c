#include <stdio.h>

void soma_vetores (int v[], int n) {
  int aux, soma;
  for (aux = 0, soma = 0; aux < n; aux++) {
    scanf("%d", &v[aux]);
    soma += v[aux];
  }
  printf("%d\n", soma);
}

int main () {
  int n;
  scanf("%d", &n);
  int v[n-1];
  soma_vetores (v, n );
}
