/*****************************
* Nome do acadêmico: Gustavo Gonçalves Queiroz
* Nome do arquivo: 12_lista1.c
* Data de elaboração: 31/01
* Resumo: Faça um programa que, dado n, calcula Fn.
// o resumo é uma breve descrição do objetivo do exercício
******************************/

#include <stdio.h>
#include <math.h>

int main()
{
  int n;

  printf("Digite n para determinar Fn.\n");
  scanf("%d", &n);

  printf("%1.0f\n", ( ( pow( 1.618034, n ) - pow( 1 - 1.618034, n )) / sqrt ( 5 ) ) );

  return 0;
}
