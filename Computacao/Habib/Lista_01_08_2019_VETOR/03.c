#include <stdio.h>

void Inverter_Vetor (int v[], int n) {
  int aux;
  for (aux = 0; aux < n; aux ++) {
    scanf("%d", &v[aux]);
  }
  for (aux = 0; aux < ( n/2 ); aux ++) {
    v[aux] += v[n-1-aux];
    v[n-1-aux] = v[aux] - v[n-1-aux];
    v[aux] -= v[n-1-aux];
  }
  for (aux = n; aux > 0; aux --) {
    printf("%d\n", v[n-aux]);
  }
}

int main () {
  int n;
  scanf("%d", &n);
  int v[n-1];
  Inverter_Vetor (v, n);
}
