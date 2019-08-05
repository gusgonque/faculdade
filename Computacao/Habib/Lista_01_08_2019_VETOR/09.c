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

void Vetor_Trocar_Valores (int v[], int n, int Indice_1, int Indice_2) {
  int aux = 0;
  aux = v[Indice_1];
  v[Indice_1] = v[Indice_2];
  v[Indice_2] = aux;
}

void Vetor_Troca_2a2 (int v[], int n) {
  int aux;
  if (!(n%2))
    for (aux = 0; aux < n ; aux +=2) {
      Vetor_Trocar_Valores (v, n, aux, aux+1);
    }
  else
    for (aux = 0; aux < n-1 ; aux +=2) {
      Vetor_Trocar_Valores (v, n, aux, aux+1);
    }
}

int main () {
  int n;
  scanf("%d", &n);
  int v[n-1];
  Identificar_Vetor (v,n);
  Vetor_Troca_2a2 (v, n);
  Mostrar_Vetor (v,n);
  return 0;
}
