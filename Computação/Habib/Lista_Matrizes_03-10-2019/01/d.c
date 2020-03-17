#include <stdio.h>
#define MAXM 100

void Preencher_Matriz_Triangulo_Inferior ( int m[][MAXM], int nl, int x) {
  int i, j;
  for ( i=0 ; i<nl ; i++ )
   for ( j=0 ; j<i ; j++ )
    m[i][j] = x;
}

void Preencher_Matriz_Triangulo_Superior ( int m[][MAXM], int nl, int nc, int x) {
  int i, j;
  for ( i=0 ; i<nl ; i++ )
   for ( j=i ; j<nc ; j++ )
    m[i][j] = x;
}

void Processo (int m[][MAXM], int n) {
  Preencher_Matriz_Triangulo_Inferior (m,n,0);
  Preencher_Matriz_Triangulo_Superior (m,n,n,1);
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
  Processo (m,n);
  Mostrar_Matriz (m,n,n);
  return 0;
}
