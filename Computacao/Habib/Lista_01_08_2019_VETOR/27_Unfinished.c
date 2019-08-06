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

int Qual_Maior (int x1, int x2) {
  return (x1 > x2) ? x1 : x2;
}

int Qual_Menor (int x1, int x2) {
  return (x1 < x2) ? x1 : x2;
}

void Vetor_Reduzir_Maior_Menor (int v[], int n) {
  int aux, aux_2, aux_3, n_final;
  for ( n_final = n, aux = aux_3 = 0 ; n_final > 1 ; (n_final/=2)+(n_final%2)-((n_final/2)==1) ) {
    for ( aux_2 = 1 ; aux < n_final ; aux+=2 ) {
      v[aux_3] = (aux_2 == 1) ? Qual_Maior (v[aux],v[aux+1]) : Qual_Menor (v[aux],v[aux+1]);
      aux_3++;
      aux_2*=(-1);
    }
  }
  Mostrar_Vetor (v,n_final);
}

int main () {
  int n;
  scanf("%d", &n);
  int v[n-1];
  Identificar_Vetor (v,n);
  Vetor_Reduzir_Maior_Menor (v,n);
  return 0;
}
