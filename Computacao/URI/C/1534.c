#include <stdio.h>

void Preencher_Matriz (int m[][70], int nl, int nc, int x) {
  int i, j;
  for ( i=0 ; i<nl ; i++ )
    for ( j=0 ; j<nc ; j++ )
      m[i][j] = x;
}

void Preencher_Diagonal_Principal (int m[][70], int nl, int x) {
  int i;
  for ( i=0 ; i<nl ; i++ )
    m[i][i] = x;
}

void Preencher_Diagonal_Secundaria (int m[][70], int nl, int nc, int x) {
  int i;
  for ( i=0 ; i<nl ; i++ )
    m[i][nc-i-1] = x;
}

void Matriz_123 (int n, int m[][70]) {
  Preencher_Matriz (m,n,n,3);
  Preencher_Diagonal_Principal (m,n,1);
  Preencher_Diagonal_Secundaria (m,n,n,2);
}

void Mostrar_Matriz (int m[][70], int nl, int nc) {
  int i, j;
  for ( i=0 ; i<nl ; i++ ) {
    for ( j=0 ; j<nc ; j++ )
      printf("%d", m[i][j]);
    printf("\n");
  }
}

int main () {
  int n, m[70][70];
  for (  ; scanf("%d", &n) != EOF ;  ) {
    Matriz_123 (n, m);
    Mostrar_Matriz (m,n,n);
  }
  return 0;
}
