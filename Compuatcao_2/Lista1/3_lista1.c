/*****************************
* Nome do acadêmico: Gustavo Gonçalves Queiroz
* Nome do arquivo: 3_lista1.c
* Data de elaboração: 31/01
* Resumo:  Dado um número inteiro positivo n,
imprimir os n primeiros naturais ímpares.
Exemplo: Para n=4 a saída deverá ser 1,3,5,7
// o resumo é uma breve descrição do objetivo do exercício
******************************/

#include <stdio.h>

int main()
{
  int n, i, j;
  scanf("%d", &n);

  for ( j = i = 0 ; j < n ; i++ )
    if ( i%2 == 1)
      {
        printf("%d ", i);
        j++;
      }

  return 0;
}
