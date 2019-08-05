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

int Indice_Menor_Elemento (int v[], int n) {
  int aux, Indice_Auxiliar;
  for (aux = 1, Indice_Auxiliar = 0; aux < n ; aux++) {
    if (v[aux] < v[Indice_Auxiliar]){
      Indice_Auxiliar = aux;
    }
  }
  return Indice_Auxiliar;
}

void Vetor_Trocar_Valores (int v[], int n, int Indice_1, int Indice_2) {
  int aux = 0;
  aux = v[Indice_1];
  v[Indice_1] = v[Indice_2];
  v[Indice_2] = aux;
}

void Vetor_Odrem_Decrescente (int v[], int n) {
  int aux, Indice_Auxiliar;
  for (aux = n; aux > 0; aux --) {
    Indice_Auxiliar = Indice_Menor_Elemento (v, aux);
    Vetor_Trocar_Valores (v, n, (aux-1), Indice_Auxiliar);
  }
}

int main () {
  int n;
  scanf("%d", &n);
  int v[n-1];
  Identificar_Vetor (v,n);
  Vetor_Odrem_Decrescente (v, n);
  Mostrar_Vetor (v,n);
  return 0;
}
