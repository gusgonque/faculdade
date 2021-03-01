/*****************************
* Nome do acadêmico: Gustavo Gonçalves Queiroz
* Nome do arquivo: 17_lista1.c
* Data de elaboração: 31/01
* Resumo: Dado um número natural n > 10 , verificar se n é palíndrome
// o resumo é uma breve descrição do objetivo do exercício
******************************/

#include <stdio.h>
#include <math.h>

int main()
{

  int n,f,a;

  printf("Digite um numero n >= 10 para verificar se n eh palindrome.\n");

  scanf("%d", &n);

  // 112211

  a = n;

  for ( f = 0 ; a > 0 ;  )
  {
    f = f * 10 + a % 10;
    a = a/10;
  }
  if (f == n)
    printf("%d eh palindrome.\n", n);
  else
    printf("%d nao eh palindrome.\n", n);

  return 0;
}
