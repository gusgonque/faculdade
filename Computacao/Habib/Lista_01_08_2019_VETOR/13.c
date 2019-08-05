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

void Vetor_Excluir_Elemento (int v[], int *n, int Indice) {
  int aux;
  for ( aux = Indice ; aux < *n-1 ; aux++ ) {
    v[aux] = v[aux+1];
  }
  *n-=1;
}

void Vetor_Excluir_Elementos_Repitidos (int v[], int *n) {
  int aux, aux_2;
  for ( aux = 0 ; aux < *n ; aux++ ) {
    for ( aux_2 = 0 ; aux_2 < *n ; aux_2++ ) {
      if ( v[aux] == v[aux_2] ) {
        Vetor_Excluir_Elemento (v,n,aux_2);
        aux = aux_2 = 0;
      }
    }
  }
}

int main () {
  int n;
  scanf("%d", &n);
  int v[n-1];
  Identificar_Vetor (v,n);
  Vetor_Excluir_Elementos_Repitidos (v,&n);
  Mostrar_Vetor (v,n);
  return 0;
}
