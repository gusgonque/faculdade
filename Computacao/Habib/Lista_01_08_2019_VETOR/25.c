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

void Separar_2_Vetores_Elementos_Segundo (int v1[], int n1, int v2[], int n2) {
  int aux, aux_2, v_resposta[n1-1], n_resposta = 0;
  for ( aux = 0 ; aux < n1 ; aux++ ) {
    for ( aux_2 = 0 ; aux_2 < n2 ; aux_2++ ) {
      if (v1[aux]==v2[aux_2]) {
        break;
      }
    }
    if (v1[aux]!=v2[aux_2]) {
      v_resposta[n_resposta] = v1[aux];
      n_resposta++;
    }
  }
  Mostrar_Vetor (v_resposta,n_resposta);
}

int main () {
  int n,n_2;
  scanf("%d", &n);
  int v[n-1];
  Identificar_Vetor (v,n);
  scanf("%d", &n_2);
  int v_2[n_2-1];
  Identificar_Vetor (v_2,n_2);
  Separar_2_Vetores_Elementos_Segundo (v, n, v_2, n_2);
  return 0;
}
