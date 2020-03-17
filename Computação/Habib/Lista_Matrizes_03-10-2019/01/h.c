#include <stdio.h>
#define MAXM 100

void Preencher_Matriz_Alternando (int m[][MAXM], int nl)
{
  int i,j,fl;
  for ( i=0, fl=1 ; i<nl ; i++ )
    for ( j=0 ; j<nl ; j++, fl*=-1 )
      m[i][j] = (fl==1);
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
  Preencher_Matriz_Alternando (m,n);
  Mostrar_Matriz (m,n,n);
  return 0;
}
