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

void Separar_2_Vetores_Maior_Menor (int v1[], int *n1, int v2[], int *n2) {
  if ( *n2 < *n1 ) {
    int aux, Indice_Aux;
    for ( aux = 0 ; aux < *n2 ; aux++) {
      v1[aux] += v2 [aux];
      v2[aux] = v1[aux] - v2[aux];
      v1[aux] -= v2[aux];
    }
    *n1 += *n2;
    *n2 = *n1 - *n2;
    *n1 -= *n2;
  }
}

void Juntar_2_Vetores_Intercalando (int v1[], int n1, int v2[], int n2) {
  int aux, Vetor_Resposta[n1+n2], aux_2;
  for ( aux = 0, aux_2 = 0 ; aux < n1*2 ; aux+=2 ) {
    Vetor_Resposta[aux] = v1[aux_2];
    Vetor_Resposta[aux+1] = v2[aux_2];
    aux_2++;
  }
  for ( aux = 0 ; aux < (n1+n2)-(n1*2) ; aux++ ) {
    Vetor_Resposta[(n1*2)+aux] = v2[(n1+n2)-(n1*2)+aux+1];
  }
  Mostrar_Vetor (Vetor_Resposta,n1+n2);
}

int main () {
  int n,n_2;
  scanf("%d", &n);
  int v[n-1];
  Identificar_Vetor (v,n);
  scanf("%d", &n_2);
  int v_2[n_2-1];
  Identificar_Vetor (v_2,n_2);
  Separar_2_Vetores_Maior_Menor (v,&n,v_2,&n_2);
  Juntar_2_Vetores_Intercalando (v, n, v_2, n_2);
  return 0;
}
