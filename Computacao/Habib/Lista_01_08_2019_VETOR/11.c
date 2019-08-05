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

void Vetor_Excluir_Primeiro_e_Ultimo_Elemento (int v[], int *n) {
  int aux;
  for ( aux = 0 ; aux < *n-1 ; aux++ ) {
    v[aux] = v[aux+1];
  }
  *n-=2;
}

int main () {
  int n;
  scanf("%d", &n);
  int v[n-1];
  Identificar_Vetor (v,n);
  Vetor_Excluir_Primeiro_e_Ultimo_Elemento (v,&n);
  Mostrar_Vetor (v,n);
  return 0;
}
