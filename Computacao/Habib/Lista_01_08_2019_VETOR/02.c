#include <stdio.h>

void Mostrar_Vetor_Invertido (int v[], int n) {
  int aux;
  for (aux = 0; aux < n; aux ++) {
    scanf("%d", &v[aux]);
  }
  for (aux = n; aux > 0; aux --) {
    printf("%d\n", v[aux-1]);
  }
}

int main () {
  int n;
  scanf("%d", &n);
  int v[n-1];
  Mostrar_Vetor_Invertido (v, n);
  return 0;
}
