#include <stdio.h>
#define MAXM 100

void Identificar_Matriz_Quadrada (int m[][MAXM], int *n)
{
  int i, j;
  printf("Digite a ordem da Matriz\n");
  scanf("%d", n);
  for ( i=0 ; i<*n ; i++ )
    for ( j=0 ; j<*n ; j++ )
      scanf("%d", &m[i][j]);
}

int Verificar_Matriz_Permutacao (int m[][MAXM], int n)
{
  int i,j,fl,aux;
  for ( i=0 ; i<n ; i++ )
  {
    for ( j=fl=0 ; j<n ; j++ )
      if (m[i][j] == 0)
        fl++;
      else
        aux = m[i][j];
    if ((fl != n-1)||(aux != 1))
      return 0;
  }
  for ( j=0 ; j<n ; j++ )
  {
    for ( i=fl=0 ; i<n ; i++ )
      if (m[i][j] == 0)
        fl++;
      else
        aux = m[i][j];
    if ((fl != n-1)||(aux != 1))
      return 0;
  }
  return 1;
}

void Relatorio (int i)
{
  if (i)
    printf("Eh uma matriz de permutacao\n");
  else
    printf("Nao eh uma matriz de permutacao\n");
}

int main ()
{
  int m[MAXM][MAXM], n;
  Identificar_Matriz_Quadrada (m,&n);
  Relatorio ( Verificar_Matriz_Permutacao (m,n) );
}
