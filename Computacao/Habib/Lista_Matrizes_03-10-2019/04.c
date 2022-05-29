#include <stdio.h>
#define MAXM 100

void Identificar_Matriz (int m[][MAXM], int *nl, int *nc)
{
  int i, j;
  printf("Digite o nl e o nc da Matriz, respectivamente.\n");
  scanf("%d %d", nl, nc);
  for ( i=0 ; i<*nl ; i++ )
    for ( j=0 ; j<*nc ; j++ )
      scanf("%d", &m[i][j]);
}

int Verificar_Matriz_Zero_Linhas (int m[][MAXM], int nl, int nc)
{
  int i,j,fl,fl_2;
  for ( i=fl_2=0 ; i<nl ; i++ )
  {
    for ( j=fl=0 ; j<nc ; j++ )
      if (m[i][j] == 0)
        fl++;
    if (fl==nc)
      fl_2++;
  }
  return fl_2;
}

int Verificar_Matriz_Zero_Coluna (int m[][MAXM], int nl, int nc)
{
  int i,j,fl,fl_2;
  for ( j=fl_2=0 ; j<nl ; j++ )
  {
    for ( i=fl=0 ; i<nc ; i++ )
      if (m[i][j] == 0)
        fl++;
    if (fl==nc)
      fl_2++;
  }
  return fl_2;
}

void Relatorio (int x1, int x2)
{
  printf("Tem %d linhas nulas e %d colunas nulas\n", x1,x2);
}

int main ()
{
  int m[MAXM][MAXM], nl, nc;
  Identificar_Matriz (m,&nl,&nc);
  Relatorio ( Verificar_Matriz_Zero_Linhas (m,nl,nc), Verificar_Matriz_Zero_Coluna (m,nl,nc) );
}
