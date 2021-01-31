/*****************************
* Nome do acadêmico: Gustavo Gonçalves Queiroz
* Nome do arquivo: 15_lista1.c
* Data de elaboração: 31/01
* Resumo: Dados três números, imprimi-los em ordem crescente.
// o resumo é uma breve descrição do objetivo do exercício
******************************/

#include <stdio.h>

int main()
{
  int x[3],f,i;

  printf("Digite tres numeros para determina-los em ordem crescente.\n");
  scanf("%d %d %d", &x[0], &x[1], &x[2]);

  for ( i = f = 0 ; f != 0 ; i++ )
  {
    if (x[i]>x[i+1])
    {
      f++;

      x[i] = x[i+1] + x[i];
      x[i+1] = x[i] - x[i+1];
      x[i] = x[i] - x[i+1];
    }
    if (i=1)
      i = 0;
  }

  printf("%d %d %d", x[0], x[1], x[2]);

  return 0;
}
