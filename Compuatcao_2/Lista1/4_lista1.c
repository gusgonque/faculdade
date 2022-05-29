/*****************************
* Nome do acadêmico: Gustavo Gonçalves Queiroz
* Nome do arquivo: 4_lista1.c
* Data de elaboração: 31/01
* Resumo:  Dados um inteiro x e um inteiro não-negativo n, calcular x^n.
// o resumo é uma breve descrição do objetivo do exercício
******************************/

#include <stdio.h>

int main()
{
  int x, n, i, r;
  printf("Digite um inteiro x e um inteiro nao-negativo n para calcular x^n\n");
  scanf("%d %d", &x, &n);

  for ( i = 1, r = x ; i < n ; i++ )
    r = r * x;

  printf("%d\n", r);

  return 0;
}
