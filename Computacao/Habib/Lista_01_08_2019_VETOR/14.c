#include <stdio.h>

void Identificar_Vetor (int v[], int n) {
  int aux;
  for (aux = 0; aux < n; aux ++) {
    scanf("%d", &v[aux]);
  }
}

void Soma_2_Vetores_Mesmo_Comprimento (int v1[], int v2[], int n) {
  int aux, soma;
  for ( aux = 0, soma = 0 ; aux < n ; aux++ ) {
    soma += v1[aux] * v2[aux];
  }
  printf("%d\n", soma);
}

int main () {
  int n;
  scanf("%d", &n);
  int v_1[n-1],v_2[n-1];
  Identificar_Vetor (v_1,n);
  Identificar_Vetor (v_2,n);
  Soma_2_Vetores_Mesmo_Comprimento (v_1,v_2,n);
  return 0;
}
