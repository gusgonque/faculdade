/*****************************
* Nome do acadêmico: Gustavo Gonçalves Queiroz
* Nome do arquivo: 9_lista1.c
* Data de elaboração: 31/01
* Resumo: Dado um inteiro positivo n, verificar se n é primo.
// o resumo é uma breve descrição do objetivo do exercício
******************************/

#include <stdio.h>

int main()
{
  int n, i;

  printf("Digite n para determinar se n eh primo.\n");
  scanf("%d", &n);

  if (n == 1)
  {
    printf("%d nao eh primo\n", n);
    return 0;
  }

  for ( i = 2 ; i < n/2 ; i++ )
  {
    if ( n%i == 0 )
    {
      printf("%d nao eh primo\n", n);
      return 0;
    }
  }
  
  printf("%d eh primo\n", n);
  return 0;
}
