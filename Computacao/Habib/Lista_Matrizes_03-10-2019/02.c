#include <stdio.h>
#define MAXM 100

int Somadiag (int m[][MAXM], int n)
{
  int i,soma;
  for ( i=soma=0 ; i<n ; i++ )
    soma += m[i][i];
  return soma;
}

void Scanear_Matriz_Quadrada (int m[][MAXM], int *n)
{
  int i,j;
  printf("Digite a ordem da matriz\n");
  scanf("%d", n);
  for ( i=0 ; i<*n ; i++ )
    for ( j=0 ; j<*n ; j++ )
      scanf("%d", &m[i][j]);
}

int main ()
{
  int m[MAXM][MAXM], n;
  Scanear_Matriz_Quadrada(m,&n);
  printf("Soma da diagonal = %d\n", Somadiag(m,n));
}
