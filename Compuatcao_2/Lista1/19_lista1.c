/*****************************
* Nome do acadêmico: Gustavo Gonçalves Queiroz
* Nome do arquivo: 19_lista1.c
* Data de elaboração: 31/01
* Resumo: Tentando descobrir se um dado era viciado, um dono de cassino honesto o lançou n vezes.
Dados os n resultados dos lançamentos, determinar o número de ocorrências de cada face.
// o resumo é uma breve descrição do objetivo do exercício
******************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n,i,r;

  printf("Digite um numero n de lancamentos do dado.\n");

  scanf("%d", &n);

  int l[n];

  for ( i = 0 ; i < n ; i++ )
    l[i] = rand()%6+1;

  for ( i = r = 0 ; i < n ; i++ )
    if ( l[i] == 1 )
      r++;
  printf("A face de numero 1 foi ocorrida %d vezes.\n", r);

  for ( i = r = 0 ; i < n ; i++ )
    if ( l[i] == 2 )
      r++;
  printf("A face de numero 2 foi ocorrida %d vezes.\n", r);

  for ( i = r = 0 ; i < n ; i++ )
    if ( l[i] == 3 )
      r++;
  printf("A face de numero 3 foi ocorrida %d vezes.\n", r);

  for ( i = r = 0 ; i < n ; i++ )
    if ( l[i] == 4 )
      r++;
  printf("A face de numero 4 foi ocorrida %d vezes.\n", r);

  for ( i = r = 0 ; i < n ; i++ )
    if ( l[i] == 5 )
      r++;
  printf("A face de numero 5 foi ocorrida %d vezes.\n", r);

  for ( i = r = 0 ; i < n ; i++ )
    if ( l[i] == 6 )
      r++;
  printf("A face de numero 6 foi ocorrida %d vezes.\n", r);

  return 0;
}
