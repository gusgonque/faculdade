/*****************************
* Nome do acadêmico: Gustavo Gonçalves Queiroz
* Nome do arquivo: 22_lista1.c
* Data de elaboração: 31/01
* Resumo: Dada uma matriz real A com m linhas e n colunas e um vetor
real V com n elementos, determinar o produto de A por V
// o resumo é uma breve descrição do objetivo do exercício
******************************/
#include <stdio.h>

void Receber_Matriz(int m,int n,double A[][100])
{
  int i, j;
  for ( i = 0; i < m ; i++ )
    for ( j = 0 ; j < n ; j++ )
      scanf("%lf", &A[i][j]);
}

void Receber_Vetor(double n,double V[])
{
  int i;
  for ( i = 0; i < n ; i++ )
      scanf("%lf", &V[i]);
}

void Produto_Matriz_Vetor(int m, int n, double A[][100], double V[], double B[][100] )
{
  int i, j;
  for ( i = 0; i < m ; i++ )
    for ( j = 0 ; j < n ; j++ )
      B[i][j] = A[i][j] * V[j];
}

void Imprimir_Matriz (int m, int n,double B[][100])
{
  int i,j;
  for ( i = 0; i < m ; i++ )
  {
    for ( j = 0 ; j < n ; j++ )
      printf("%.0lf ", B[i][j]);
    printf("\n");
  }
}

int main()
{
  int m,n;
  double A[100][100], B[100][100],V[100];

  printf("Digite o numero m de linhas e n de colunas da matriz e do vetor.\n");
  scanf("%d %d", &m, &n);

  printf("Digite os elementos da matriz A\n");
  Receber_Matriz(m,n,A);
  printf("Digite os elementos do vetor V\n");
  Receber_Vetor(n,V);
  Produto_Matriz_Vetor(m,n,A,V,B);
  printf("Matriz Solucao do produto:\n");
  Imprimir_Matriz(m,n,B);

  return 0;
}
