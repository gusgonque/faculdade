/*****************************
* Nome do acadêmico: Gustavo Gonçalves Queiroz
* Nome do arquivo: 10_lista1.c
* Data de elaboração: 31/01
* Resumo: Dados dois números inteiros positivos, determinar o máximo divisor comum.
entre eles usando o algoritmo de Euclides
// o resumo é uma breve descrição do objetivo do exercício
******************************/

#include <stdio.h>

int main()
{
  int x, y;

  printf("Digite dois numeros inteiros positivos para determinar o maximo divisor comum entre eles usando o algoritmo de Euclides.\n");
  scanf("%d %d", &x, &y);

  for (  ; (x != 0) && (y != 0)  ;  )
  {
    x = x % y;

    x = x + y;
    y = x - y;
    x = x - y;
  }

  if (x == 0)
    printf("maximo divisor comum = %d\n", y);
  if (y == 0)
    printf("maximo divisor comum = %d\n", x);

  return 0;
}
