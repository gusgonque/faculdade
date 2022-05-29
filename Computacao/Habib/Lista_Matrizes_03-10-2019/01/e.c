#include <stdio.h>
#define MAXM 100

int Menor_Distancia (int i, int j, int nl, int nc) {
  if ( nl-i-1 < i )
    if ( nl-i-1 < j )
      if ( nl-i-1 < nc-j-1 )
        return nl-i-1;
      else
        return nc-j-1;
    else
      if ( j < nc-j-1 )
        return j;
      else
        return nc-j-1;
  else
    if ( i < j )
      if ( i < nc-j )
        return i;
      else
        return nc-j-1;
    else
      if ( j < nc-j-1 )
        return j;
      else
        return nc-j-1;
}

void Preencher_Matriz_Menor_Distancia ( int m[][MAXM], int nl, int nc) {
  int i,j, aux;
  for ( i=0, aux = 1 ; i<nl ; i++, aux++ )
    for ( j=0 ; j<nc ; j++ )
      m[i][j] = Menor_Distancia(i,j,nl,nc)+1;
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
  Preencher_Matriz_Menor_Distancia (m,n,n);
  Mostrar_Matriz (m,n,n);
  return 0;
}
