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

void Juntar_2_Vetores (int v1[], int n1, int v2[], int n2) {
  int aux, Vetor_Resposta[n1+n2];
  for ( aux = 0 ; aux < n2 ; aux++ ) {
    Vetor_Resposta[aux] = v2[aux];
  }
  for (aux = 0 ; aux < n1 ; aux++) {
    Vetor_Resposta[n2+aux] = v1[aux];
  }
  Mostrar_Vetor (Vetor_Resposta, n1+n2);
}

int main () {
  int n,n_2;
  scanf("%d", &n);
  int v[n-1],v_2[n-1];
  Identificar_Vetor (v,n);
  scanf("%d", &n_2);
  Identificar_Vetor (v_2,n_2);
  Juntar_2_Vetores (v, n, v_2, n_2);
  return 0;
}
