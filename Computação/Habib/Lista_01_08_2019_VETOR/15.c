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

void Juntar_2_Vetores_Mesmo_Comprimento (int v1[], int v2[], int n) {
  int aux, Vetor_Resposta[2*n];
  for ( aux = 0 ; aux < n ; aux++ ) {
    Vetor_Resposta[aux] = v1[aux];
  }
  for (aux = 0 ; aux < n ; aux++) {
    Vetor_Resposta[n+aux] = v2[aux];
  }
  Mostrar_Vetor (Vetor_Resposta, 2*n);
}

int main () {
  int n;
  scanf("%d", &n);
  int v_1[n-1],v_2[n-1];
  Identificar_Vetor (v_1,n);
  Identificar_Vetor (v_2,n);
  Juntar_2_Vetores_Mesmo_Comprimento (v_1, v_2, n);

  return 0;
}
