/*****************************
* Nome do acadêmico: Gustavo Gonçalves Queiroz
* Nome do arquivo: 16_lista1.c
* Data de elaboração: 31/01
* Resumo: Escreva um programa que imprime todos os milhares (4 algarismos) cuja raiz
quadrada seja a soma das dezenas formadas pela divisão acima.
// o resumo é uma breve descrição do objetivo do exercício
******************************/

#include <stdio.h>
#include <math.h>

int main()
{

  int i, d1, d2;
  for ( i = 1000 ; i < 9999 ; i++ )
  {
    d1 = i / 100;
    d2 = i % 100;
    d1 += d2;
    if (d1 == sqrt(i))
      printf("%d\n", i);
  }

  return 0;
}
