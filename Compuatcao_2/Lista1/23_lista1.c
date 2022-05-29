/*****************************
* Nome do acadêmico: Gustavo Gonçalves Queiroz
* Nome do arquivo: 23_lista1.c
* Data de elaboração: 31/01
* Resumo: Dadas duas matrizes reais Amxn e Bnxp, calcular o produto de A por B
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

void Produto_Matriz_Matriz(int m, int n, int p, double A[][100], double B[][100], double C[][100] )
{
  int i, j, k, l;

  // Amxn e Bnxp

  for ( i = 0 ; i < m ; i++ )
    for ( j = 0 ; j < p ; j++ )
    {
      C[i][j] = 0;
      for ( k = 0 ; k < n ; k++ )
        C[i][j] += A[i][k] * B[k][j];
    }

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
  int m,n,p;
  double A[100][100], B[100][100], C[100][100];

  printf("Para realizar o produto das matrizes reais A e B, informe o seguinte:\n");

  printf("Digite o numero m de linhas e n de colunas da matriz A.\n");
  scanf("%d %d", &m, &n);

  printf("Digite o numero p de colunas da matriz B.\n");
  scanf("%d", &p);

  printf("Digite os elementos da matriz A\n");
  Receber_Matriz(m,n,A);

  printf("Digite os elementos da matriz B\n");
  Receber_Matriz(n,p,B);

  Produto_Matriz_Matriz (m,n,p,A,B,C);

  printf("Matriz Solucao do produto:\n");
  Imprimir_Matriz(m,p,C);

  return 0;
}
