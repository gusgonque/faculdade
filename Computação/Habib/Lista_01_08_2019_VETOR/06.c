#include <stdio.h>

void Identificar_Vetor (int v[], int n) {
  int aux;
  for (aux = 0; aux < n; aux ++) {
    scanf("%d", &v[aux]);
  }
}

void Maior_Indice (int v[], int n) {
  int aux, Maior_Indice;
  for (aux = 1, Maior_Indice = 0; aux < n ; aux++) {
    if (v[aux] > v[Maior_Indice]){
      Maior_Indice = aux;
    }
  }
  printf("%d\n", Maior_Indice);
}


int main () {
  int n;
  scanf("%d", &n);
  int v[n-1];
  Identificar_Vetor(v,n);
  Maior_Indice (v, n);
  return 0;
}
