#include <stdio.h>
#define MAXM 100

void Identificar_Matriz_Quadrada (int m[][MAXM], int *n)
{
  int i, j;
  printf("Digite a ordem da matriz.\n");
  scanf("%d", n);
  for ( i=0 ; i<*n ; i++ )
    for ( j=0 ; j<*n ; j++ )
      scanf("%d", &m[i][j]);
}

int Matriz_Soma_Diagonal_Principal (int m[][MAXM], int n)
{
  int i,soma;
  for ( i=soma=0 ; i<n ; i++ )
    soma += m[i][i];
}

int Matriz_Soma_Diagonal_Secundaria (int m[][MAXM], int n)
{
  int i,soma;
  for ( i=soma=0 ; i<n ; i++ )
    soma += m[i][n-i];
}

int Verificar_Matriz_Magica (int m[][MAXM], int n)
{
  int i,j,somas_linhas[n],somas_colunas[n],fl;

  for ( i=somas_linhas[0]=0 ; i<n ; i++,somas_linhas[i]=0 )
  {
    for ( j=0 ; j<n ; j++ )
      somas_linhas[i] += m[i][j];
    printf("%s\n", );
  }
  for ( j=somas_colunas[0]=0 ; j<n ; j++,somas_colunas[j]=0 )
  {
    for ( i=0 ; i<n ; i++ )
      somas_colunas[j] += m[i][j];
  }

  for ( i=fl=0 ; i<n ; i++ )
  {
    if ((somas_linhas[i]==Matriz_Soma_Diagonal_Principal(m,n)&&somas_linhas[i]==Matriz_Soma_Diagonal_Secundaria(m,n))&&somas_linhas==somas_colunas)
      fl++;
  }
  return (fl == n);
}

void Relatorio (int x)
{
  printf("%d\n", x);
}

int main ()
{
  int m[MAXM][MAXM], n;
  Identificar_Matriz_Quadrada (m,&n);
  Relatorio ( Verificar_Matriz_Magica(m,n) );
}
