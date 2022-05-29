/*****************************
* Nome do acadêmico: Gustavo Gonçalves Queiroz
* Nome do arquivo: 24_lista1.c
* Data de elaboração: 31/01
* Resumo: Dada uma matriz Amxn, imprimir o número de linhas
e o número de colunas nulas da matriz.
// o resumo é uma breve descrição do objetivo do exercício
******************************/
#include <stdio.h>

void Receber_Matriz(int m,int n,double M[][100])
{
  int i, j;
  for ( i = 0; i < m ; i++ )
    for ( j = 0 ; j < n ; j++ )
      scanf("%lf", &M[i][j]);
}

void Linhas_Colunas_Nulas (int m,int n,double A[][100])
{
  int i,j,f,o;

  for ( i = o =0 ; i < m ; i++ )
  {
    for ( j = f = 0 ; j < n ; j++ )
      if (A[i][j]==0)
        f++;
    if (f == n)
      o++;
  }
  printf("Ocorreram %d linhas nulas na matriz.\n", o);
  for ( i = o = 0 ; i < n ; i++ )
  {
    for ( j = f = 0 ; j < m ; j++ )
      if (A[j][i]==0)
        f++;
    if (f == m)
      o++;
  }
  printf("Ocorreram %d colunas nulas na matriz.\n", o);
}

int main()
{
  int m,n;
  double A[100][100];

  printf("Para determinar o numero de linhas e colunas nulas em uma matriz real A, informe o seguinte:\n");

  printf("Digite o numero m de linhas e n de colunas da matriz A.\n");
  scanf("%d %d", &m, &n);

  printf("Digite os elementos da matriz A\n");
  Receber_Matriz(m,n,A);

  Linhas_Colunas_Nulas (m,n,A);

  return 0;
}
