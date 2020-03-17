#include <stdio.h>

void Preencher_Matriz (int m[][100], int nl, int nc, int x) {
  int i, j;
  for ( i=0 ; i<nl ; i++ )
    for ( j=0 ; j<nc ; j++ )
      m[i][j]=x;
}

void Matriz_Cebola2_Superior (int m[][100],int nl,int nc,int k,int o) {
  int i, j;
  for ( i=k ; i<nl ; i++ )
    for ( j=i+o+1 ; j<nc ; j++ )
      m[i][j]++;
  o++;
  if (o<nc)
    Matriz_Cebola2_Superior (m,nl,nc,k,o);
}

void Matriz_Cebola2_Inferior (int m[][100],int nl,int nc,int k,int o) {
  int i, j;
  for ( i=k+1 ; i<nl ; i++ )
    for ( j=o ; j<i-k ; j++ )
      m[i][j]++;
  k++;
  if (k<nl)
    Matriz_Cebola2_Inferior (m,nl,nc,k,o);
}

void Matriz_Cebola2 (int m[][100],int nl,int nc,int k,int o) {
  Matriz_Cebola2_Superior (m,nl,nc,k,o);
  Matriz_Cebola2_Inferior (m,nl,nc,k,o);
}

void Processo (int m[][100], int nl, int nc) {
  Preencher_Matriz (m,nl,nc,1);
  Matriz_Cebola2 (m,nl,nc,0,0);
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

int main () {
  int n, m[100][100];
  scanf("%d", &n);
  for (  ; n > 0 ; scanf("%d", &n) ) {
    Processo(m,n,n);
    Relatorio(m,n,n);
  }
  return 0;
}
