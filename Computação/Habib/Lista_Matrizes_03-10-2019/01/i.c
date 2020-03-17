#include <stdio.h>
#define MAXM 100

void Preencher_Matriz_Fibonacci_Crescente (int m[][MAXM], int n)
{
  int i,j;
  for ( i=0 ; i<n ; i++ )
  {
    m[i][0] = m[i][1] = i+1;
    for ( j=2 ; j<n ; j++ )
      m[i][j] = m[i][j-1] + m[i][j-2];
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
  int m[MAXM][MAXM],n;
  scanf("%d", &n);
  Preencher_Matriz_Fibonacci_Crescente (m,n);
  Mostrar_Matriz (m,n);
}
