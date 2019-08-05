#include <stdio.h>

void Identificar_Vetor (int v[], int n) {
  int aux;
  for (aux = 0; aux < n; aux ++) {
    scanf("%d", &v[aux]);
  }
}

void Mostrar_Vetor (int v[], int n) {
  int aux;
  for (aux = 0; aux < n; aux ++) {
    printf("%d\n", v[aux]);
  }
}

int Maior_Indice (int v[], int n) {
  int aux, Maior_Indice;
  for (aux = 1, Maior_Indice = 0; aux < n ; aux++) {
    if (v[aux] > v[Maior_Indice]){
      Maior_Indice = aux;
    }
  }
  return Maior_Indice;
}

void Maior_Vetor_Primeiro (int v[], int n) {
  int aux;
  aux = Maior_Indice (v, n);
  v[aux] += v[0];
  v[0] = v[aux] - v[0];
  v[aux] -= v[0];
}

int main () {
  int n;
  scanf("%d", &n);
  int v[n-1];
  Identificar_Vetor (v,n);
  Maior_Vetor_Primeiro (v, n);
  Mostrar_Vetor (v,n);
  return 0;
}
