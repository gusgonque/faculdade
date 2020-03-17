#include <stdio.h>
#define MAXC 100

void Relatorio (int m[][MAXC], int n)
{
  int i,j;
  for ( i=0 ; i<n ; i++ )
  {
    for ( j=0 ; j<n ; j++ )
      printf("%3d", m[i][j]);
    printf("\n");
  }
}

void Scanear_Matriz_Quadrada (int m[][MAXC], int n)
{
  int i,j;
  for ( i=0 ; i<n ; i++ )
    for ( j=0 ; j<n ; j++ )
      scanf("%d", &m[i][j]);
}

void Leitura (int m[][MAXC], int *n)
{
  printf("Digite a ordem da mtriz quadrada.\n");
  scanf ("%d", n);
  printf ("Digite a matriz\n");
  Scanear_Matriz_Quadrada (m,*n);
}

void Copiar_Matriz_Quadrada (int md[][MAXC], int mo[][MAXC], int n)
{
  int i,j;
  for ( i=0 ; i<n ; i++ )
    for ( j=0 ; j<n ; j++ )
      md[i][j] = mo[i][j];
}

void Maior_Elemento_Vetor (int v[], int n, int *me, int *mc)
{
  int i;
  for ( i=1 ; i<n ; i++ )
    if (v[i]>v[i-1])
    {
      *me = v[i];
      *mc = i;
    }
    else
    {
      *me = v[i-1];
      *mc = i-1;
    }
}

void Maior_Elemento_Matriz (int m[][MAXC], int n, int *me, int *ml, int *mc)
{
  int i,j,aux_me[n],aux_mc[n],aux_ml[n];
  for ( i=0 ; i<n ; i++ )
    Maior_Elemento_Vetor (m[i],n,&aux_me[i],&aux_mc[i]);
  Maior_Elemento_Vetor (aux_me,n,me,mc);
  for ( i=0 ; i<n-1 ; i++ )
    if (aux_me[i]>aux_me[i+1])
    {
      *ml = i;
      *mc = aux_mc[i];
    }
    else
    {
      *ml = i+1;
      *mc = aux_mc[i+1];
    }
}

void Organizar_Matriz_Ordem_Decrescente (int m[][MAXC], int n)
{
  int aux[MAXC][MAXC],me,ml,mc,i,j;
  Copiar_Matriz_Quadrada (aux,m,n);
  for ( i=0 ; i<n ; i++ )
    for ( j=0 ; j<n ; j++ )
    {
      Maior_Elemento_Matriz (aux,n,&me,&ml,&mc);
      printf("AUX\n");
      Relatorio(aux,n);
      m[ml][mc] = m[i][j];
      m[i][j] = me;
      aux[ml][mc] = -1;
      printf("AUX\n");
      Relatorio(aux,n);
      printf("Maior elemento = %d\nLinha = %d\nColuna = %d\n", me,ml,mc);
      printf("M\n");
      Relatorio(m,n);
    }
}

int main ()
{
  int m[MAXC][MAXC],n;
  Leitura (m,&n);
  Organizar_Matriz_Ordem_Decrescente (m,n);
  Relatorio (m,n);
}
