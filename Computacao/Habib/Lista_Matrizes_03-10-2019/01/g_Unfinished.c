#include <stdio.h>
#define MAXM 100

void Preencher_Matriz_Diagonal_Selecionada_Ordem_Crescente ( int m[][MAXM], int nl,int fl, int *k) {
  int i;
  for ( i=fl ; i<nl ; i++, (*k)++ )
    m[i][i] = *k;
}

void Preencher_Matriz_Triangulo_Superior ( int m[][MAXM], int nl, int x) {
  int i, j;
  for ( i=0 ; i<nl ; i++ )
   for ( j=i ; j<nl ; j++ )
    m[i][j] = x;
}

void Processo (int m[][MAXM], int n) {
  int i, k;
  Preencher_Matriz_Triangulo_Superior (m,n,0);
  for ( i=0, k=0 ; i<n ; i++ )
    Preencher_Matriz_Diagonal_Selecionada_Ordem_Crescente (m,n,i,&k);
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
