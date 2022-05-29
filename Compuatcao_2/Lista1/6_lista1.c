/*****************************
* Nome do acadêmico: Gustavo Gonçalves Queiroz
* Nome do arquivo: 6_lista1.c
* Data de elaboração: 31/01
* Resumo: Dado um inteiro não-negativo n, determinar n!
// o resumo é uma breve descrição do objetivo do exercício
******************************/

#include <stdio.h>

int main()
{
  int n, i, r;

  printf("Digite o n para determinar n!\n");
  scanf("%d", &n);

  for ( i = 1, r = n ; i < n ; i++ )
    r = r * i;

  printf("%d\n", r);

  return 0;
}
