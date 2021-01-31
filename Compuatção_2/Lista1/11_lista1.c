/*****************************
* Nome do acadêmico: Gustavo Gonçalves Queiroz
* Nome do arquivo: 11_lista1.c
* Data de elaboração: 31/01
* Resumo: Dizemos que um inteiro positivo n é perfeito se for igual à soma de seus
divisores positivos diferentes de n.
Exemplo: 6 é perfeito, pois 1+2+3 = 6.
Dado um inteiro positivo n, verificar se n é perfeito.
// o resumo é uma breve descrição do objetivo do exercício
******************************/

#include <stdio.h>

int main()
{
  int n,i,r;

  printf("Digite n inteiro positivo para determinar se n eh perfeito.\n");
  scanf("%d", &n);

  for ( i = 1, r = 0 ; i <= n/2 ; i++ )
    if ( n % i == 0 )
      r += i;
      
  if ( r == n )
    printf("%d eh perfeito\n", n);
  else
    printf("%d nao eh perfeito\n", n);

  return 0;
}
