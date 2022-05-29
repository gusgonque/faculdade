#include <stdio.h>
#include <math.h>
#define MAXM 100

void Processo (int m[][MAXM], int n)
{
  int i,j;
  for ( i=0 ; i<n ; i++ )
    for ( j=0 ; j<n ; j++ )
      m[i][j] = pow(i+1,j);
}

void Mostrar_Matriz (int m[][MAXM], int n)
{
  int i,j;
  for ( i=0 ; i<n ; i++ )
  {
    for ( j=0 ; j<n ; j++ )
      printf("%5d", m[i][j]);
    printf("\n");
  }
}

int main ()
{
  int m[MAXM][MAXM], n;
  scanf("%d",&n);
  Processo(m,n);
  Mostrar_Matriz(m,n);
}
