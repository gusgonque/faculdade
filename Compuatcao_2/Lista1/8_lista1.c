/*****************************
* Nome do acadêmico: Gustavo Gonçalves Queiroz
* Nome do arquivo: 8_lista1.c
* Data de elaboração: 31/01
* Resumo: Dado um inteiro não-negativo n, verificar se n é triangular.
Dizemos que um número natural é triangular se ele é produto de três números
naturais consecutivos.
Exemplo: 120 é triangular, pois 4.5.6 = 120.
// o resumo é uma breve descrição do objetivo do exercício
******************************/

#include <stdio.h>

int main()
{
  int n, i;

  printf("Digite n para determinar se n eh triangular.\n");
  scanf("%d", &n);

  for ( i = 0 ; i < n/3 ; i++ )
  {
    if ( i * (i+1) * (i+2) == n )
    {
      printf("%d eh triangular.\n %d * %d * %d = %d", n, i, i+1, i+2, n);
      return 0;
    }
  }
  printf("%d nao eh triangular.", n);

  return 0;
}
