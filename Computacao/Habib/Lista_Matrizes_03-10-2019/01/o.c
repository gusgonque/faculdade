#include <stdio.h>
#define MAXM 100

void Processo (int m[][MAXM], int n)
{
  int i,j,k;
  for ( i=0,k=-1 ; i<n ; i++ )
    for ( j=0 ; j<n ; j++,k=(k<1?k+1:k-2) )
    {
      m[i][j] = k;
    }
}

void Mostrar_Matriz (int m[][MAXM], int n)
{
  int i,j;
  for ( i=0 ; i<n ; i++ )
  {
    for ( j=0 ; j<n ; j++ )
      printf("%4d", m[i][j]);
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
