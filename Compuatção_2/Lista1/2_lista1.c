/*****************************
* Nome do acadêmico: Gustavo Gonçalves Queiroz
* Nome do arquivo: 2_lista1.c
* Data de elaboração: 31/01
* Resumo:  Dado um número inteiro positivo n,
calcular a soma dos n primeiros números inteiros positivos.
// o resumo é uma breve descrição do objetivo do exercício
******************************/

#include <stdio.h>

int main()
{
  int n, i, r;
  scanf("%d", &n);
  for ( i = r = 0 ; i <= n ; i++ )
    r += i;
  printf("%d\n", r);
  return 0;
}
