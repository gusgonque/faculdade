#include <stdio.h>

void Identificar_Vetor (int v[], int n) {
  int aux;
  for (aux = 0; aux < n; aux ++) {
    scanf("%d", &v[aux]);
  }
}

int Indice_Menor_Elemento (int v[], int n) {
  int aux, Menor_Indice;
  for (aux = 1, Menor_Indice = 0; aux < n ; aux++) {
    if (v[aux] < v[Menor_Indice]){
      Menor_Indice = aux;
    }
  }
  return Menor_Indice;
}

int main () {
  int n;
  scanf("%d", &n);
  int v[n-1];
  Identificar_Vetor (v,n);
  printf("%d\n", Indice_Menor_Elemento(v,n));
  return 0;
}
