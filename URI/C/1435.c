#include <stdio.h>

void Preencher_Matriz (int m[][100], int nl, int nc, int x) {
  int i, j;
  for ( i=0 ; i<nl ; i++ )
    for ( j=0 ; j<nc ; j++ )
      m[i][j]=x;
}

void Matriz_Cebola (int *x,int l,int c,int k,int o) {
  if ( ( l > k && l < o ) && ( c > k && c < o )) {
    (*x) ++;
    k++;
    o--;
    Matriz_Cebola (x, l, c, k, o);
  }
}

void Relatorio (int m[][100],int nl,int nc) {
  int i,j;
  for ( i=0 ; i<nl ; i++ ) {
    for ( j=0 ; j<nc ; j++ ) {
      if (j!=0)
        printf(" ");
      printf("%3d", m[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void Processo (int m[][100], int nl, int nc) {
  int i, j, k, o;
  Preencher_Matriz (m,nl,nc,1);
  for ( i = k = 0, o = nc-1 ; i<nl ; i++ )
    for ( j=0 ; j<nc ; j++ )
      Matriz_Cebola (&m[i][j], i, j, k, o);
}

int main () {
  int n, m[100][100];
  scanf("%d", &n);
  for (  ; n > 0 ; scanf("%d", &n) ) {
    Processo(m,n,n);
    Relatorio(m,n,n);
  }
  return 0;
}
