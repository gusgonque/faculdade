#include <stdio.h>
#include <math.h>
#define MAXM 101
void Preencher_Matriz (int m[][MAXM], int nl, int nc, int x) {
  int i, j;
  for ( i=0 ; i<nl ; i++ )
    for ( j=0 ; j<nc ; j++ )
      m[i][j] = x;
}

void Preencher_Diagonal_Principal (int m[][MAXM], int nl, int x) {
  int i;
  for ( i=0 ; i<nl ; i++ )
    m[i][i] = x;
}

void Preencher_Diagonal_Secundaria (int m[][MAXM], int nl, int nc, int x) {
  int i;
  for ( i=0 ; i<nl ; i++ )
    m[i][nc-i-1] = x;
}

void Preencher_Matriz_Interior (int m[][MAXM], int nl, int nc, int x) {
  int i, j, aux;
  aux = nl/3.0;
  for ( i=aux ; i<nl-aux ; i++ )
    for ( j=aux ; j<nc-aux ; j++ )
      m[i][j] = x;
}

void Matriz_Quadrada_IV (int n, int m[][MAXM]) {
  int x = floor((n-1)/2.0);
  Preencher_Matriz (m,n,n,0);
  Preencher_Diagonal_Principal (m,n,2);
  Preencher_Diagonal_Secundaria (m,n,n,3);
  Preencher_Matriz_Interior (m,n,n,1);
  m[x][x] = 4;
}

void Mostrar_Matriz (int m[][MAXM], int nl, int nc) {
  int i, j;
  for ( i=0 ; i<nl ; i++ ) {
    for ( j=0 ; j<nc ; j++ )
      printf("%d", m[i][j]);
    printf("\n");
  }
}

int main () {
  int n, m[MAXM][MAXM];
  for (  ; scanf("%d", &n) != EOF ;  ) {
    Matriz_Quadrada_IV (n, m);
    Mostrar_Matriz (m,n,n);
    printf("\n");
  }
  return 0;
}
