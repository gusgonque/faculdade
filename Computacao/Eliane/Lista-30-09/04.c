#include <stdio.h>

void Preencher_Matriz (int m[][70], int nl, int nc, int x) {
  int i, j;
  for ( i=0 ; i<nl ; i++ )
    for ( j=0 ; j<nc ; j++ )
      m[i][j]=x;
}

void Preencher_Diagonal_Secundaria_Matriz(int m[][70], int nl, int nc, int x) {
  int i, j;
  for ( i=0, j=nc-1 ; i<nl ; i++,j-- )
      m[i][j]=x;
}

void Preencher_Diagonal_Principal_Matriz(int m[][70], int nl, int nc, int x) {
  int i;
  for ( i=0 ; i<nl ; i++ )
      m[i][i] = x;
}

void Processo (int m[][70], int n) {
  Preencher_Matriz(m, n, n, 3);
  Preencher_Diagonal_Principal_Matriz(m, n, n, 1);
  Preencher_Diagonal_Secundaria_Matriz(m, n, n, 2);
}

void Relatorio (int m[][70], int nl, int nc) {
  int i, j;
  for ( i=0 ; i<nl ; i++ ) {
    for ( j=0 ; j<nc ; j++ )
      printf("%d", m[i][j]);
    printf("\n");
  }
}

int main () {
  int m[70][70], n;
  scanf("%d", &n);
  for (  ; n >= 3 ; scanf("%d", &n) ) {
    Processo(m,n);
    Relatorio(m, n, n);
  }
  return 0;
}
