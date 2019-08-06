#include <stdio.h>

void Identificar_Vetor (int v[], int n) {
  int aux;
  for (aux = 0; aux < n; aux ++) {
    scanf("%d", &v[aux]);
  }
}

int Verificar_2_Vetores_Segundo_Subsequencia (int v1[], int n1, int v2[], int n2) {
  int aux, aux_2, aux_3, v_resposta[n1-1], n_resposta = 0;
  for ( aux = aux_2 = 0 ; aux < n1 ; aux++ ) {
    if (v1[aux]==v2[aux_2]) {
      for ( aux_2 = 1 ; aux_2 < n2 ; aux_2++ ) {
        if (v1[aux+aux_2]!=v2[aux_2]) {
          printf("Nao!\n");
          return 0;
        }
      }
    }
  }
  printf("Sim!\n");
}

int main () {
  int n,n_2;
  scanf("%d", &n);
  int v[n-1];
  Identificar_Vetor (v,n);
  scanf("%d", &n_2);
  int v_2[n_2-1];
  Identificar_Vetor (v_2,n_2);
  Verificar_2_Vetores_Segundo_Subsequencia (v, n, v_2, n_2);
  return 0;
}
