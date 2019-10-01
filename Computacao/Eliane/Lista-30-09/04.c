#include <stdio.h>

void Preencher_Matriz (int m[][70], int nl, int nc) {
  int i, j, k;
  for ( i=0, k=nc-1 ; i<nl ; i++, k-- ){
    for ( j=0 ; j<nc ; j++ ){
      m[i][j]= 3;
    }
    m[i][i] = 1;
    m[i][k] = 2;
  }
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
    Preencher_Matriz(m, n, n);
    Relatorio(m, n, n);
  }
  return 0;
}
