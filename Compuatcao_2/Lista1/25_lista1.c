/*****************************
* Nome do acadêmico: Gustavo Gonçalves Queiroz
* Nome do arquivo: 25_lista1.c
* Data de elaboração: 31/01
* Resumo: Imprimir as n primeiras linhas do triângulo de Pascal
// o resumo é uma breve descrição do objetivo do exercício
******************************/
#include <stdio.h>


int fatorial (int x)
{
  int i, r;

  if (x == 0)
    return 1;

  for ( i = 1, r = x ; i < x ; i++ )
    r = r * i;

  return r;
}

int Binomio(int n,int p)
{

  int r;
  r = (fatorial(n) / (fatorial(p)*fatorial(n-p)));
  return r;

}

void Imprimir_Pascal (int n)
{
  int i, j, x;
  for ( i = 0; i <= n ; i++ )
  {
    for (j = 0 ; j <= i ; j++ )
    {
      x = Binomio(i,j);
      printf("%d ", x);
    }
    printf("\n");
  }
}

int main()
{
  int n, V[100];

  printf("Para imprimir as n primeiras linhas do triangulo de Pascal, informe o seguinte:\n");

  printf("Digite o numero n.\n");
  scanf("%d", &n);

  Imprimir_Pascal(n);

  return 0;
}
