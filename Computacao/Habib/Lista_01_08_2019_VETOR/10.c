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

int Indice_Maior_Elemento (int v[], int n) {
  int aux, Maior_Indice;
  for (aux = 1, Maior_Indice = 0; aux < n ; aux++) {
    if (v[aux] > v[Maior_Indice]){
      Maior_Indice = aux;
    }
  }
  return Maior_Indice;
}

void Vetor_Excluir_Maior_Elemento (int v[], int *n) {
  int aux;
  for ( aux = Indice_Maior_Elemento (v,*n) ; aux < *n-1 ; aux++ ) {
    v[aux] = v[aux+1];
  }
  *n-=1;
}

int main () {
  int n;
  scanf("%d", &n);
  int v[n-1];
  Identificar_Vetor (v,n);
  Vetor_Excluir_Maior_Elemento (v,&n);
  Mostrar_Vetor (v,n);
  return 0;
}
