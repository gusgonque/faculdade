#include <stdio.h>

void Identificar_Vetor (int v[], int n) {
  int aux;
  for (aux = 0; aux < n; aux ++) {
    scanf("%d", &v[aux]);
  }
}

void Verificar_2_Vetores_Mesmos_Elementos (int v1[], int v2[], int n) {
  int aux, aux_2, resposta;
  for ( aux = resposta = 0 ; aux < n ; aux++ ) {
    for ( aux_2 = 0 ; aux_2 < n ; aux_2++ ) {
      if (v1[aux]==v2[aux_2]) {
        resposta++;
        break;
      }
    }
  }
  if (resposta==n)
    printf("Iguais.\n");
  else
    printf("Nao iguais.\n");
}

int main () {
  int n;
  scanf("%d", &n);
  int v[n-1], v_2[n-1];
  Identificar_Vetor (v,n);
  Identificar_Vetor (v_2,n);
  Verificar_2_Vetores_Mesmos_Elementos (v, v_2, n);
  return 0;
}
