#include <stdio.h>
#define MAXM 100

void Preencher_Matriz_Numero_Linha ( int m[][MAXM], int nl, int nc) {
  int i,j;
  for ( i=0 ; i<nl ; i++ )
    for ( j=0 ; j<nc ; j++ )
      m[i][j] = i;
}

void Mostrar_Matriz (int m[][MAXM], int nl, int nc) {
  int i,j;
  for ( i=0 ; i<nl ; i++ ) {
    for ( j=0 ; j<nc ; j++ )
      printf("%2d", m[i][j]);
    printf("\n");
  }
}

int main () {
  int n, m[MAXM][MAXM];
  scanf("%d", &n);
  Preencher_Matriz_Numero_Linha (m,n,n);
  Mostrar_Matriz (m,n,n);
  return 0;
}
