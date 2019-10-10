#include <stdio.h>
#define MAXM 100

void Preencher_Matriz_Ordem_Crescente ( int m[][MAXM], int nl, int nc) {
  int i, j, k;
  for ( i=0, k=0 ; i<nl ; i++ )
   for ( j=0 ; j<nc ; j++, k++ )
    m[i][j] = k;
}

void Mostrar_Matriz (int m[][MAXM], int nl, int nc) {
  int i,j;
  for ( i=0 ; i<nl ; i++ ) {
    for ( j=0 ; j<nc ; j++ )
      printf("%4d", m[i][j]);
    printf("\n");
  }
}

int main () {
  int n, m[MAXM][MAXM];
  scanf("%d", &n);
  Preencher_Matriz_Ordem_Crescente (m,n,n);
  Mostrar_Matriz (m,n,n);
  return 0;
}
