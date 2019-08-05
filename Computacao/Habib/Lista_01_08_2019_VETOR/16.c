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

void Juntar_2_Vetores_Mesmo_Comprimento_Intercalando (int v1[], int v2[], int n) {
  int aux, Vetor_Resposta[2*n], aux_2;
  for ( aux = 0, aux_2 = 0 ; aux < 2*n ; aux+=2 ) {
    Vetor_Resposta[aux] = v1[aux_2];
    Vetor_Resposta[aux+1] = v2[aux_2];
    aux_2++;
  }
  Mostrar_Vetor (Vetor_Resposta, 2*n);
}

int main () {
  int n;
  scanf("%d", &n);
  int v_1[n-1],v_2[n-1];
  Identificar_Vetor (v_1,n);
  Identificar_Vetor (v_2,n);
  Juntar_2_Vetores_Mesmo_Comprimento_Intercalando (v_1, v_2, n);
  return 0;
}
