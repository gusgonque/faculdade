/*****************************
* Nome do acadêmico: Gustavo Gonçalves Queiroz
* Nome do arquivo: 1_lista1.c
* Data de elaboração: 31/01
* Resumo:  Dada uma sequência de números inteiros não-nulos,
seguida por 0, imprimir seus quadrados.
// o resumo é uma breve descrição do objetivo do exercício
******************************/

#include <stdio.h>

int main()
{
  int x = 1;
  while (x != 0)
  {
    scanf("%d", &x);
    printf("%d\n", x*x);
  }
  return 0;
}
