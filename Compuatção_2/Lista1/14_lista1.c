/*****************************
* Nome do acadêmico: Gustavo Gonçalves Queiroz
* Nome do arquivo: 14_lista1.c
* Data de elaboração: 31/01
* Resumo: Dado um número natural na base decimal, transformá-lo para a base binária.
Exemplo: Dado 18 a saída deverá ser 10010.
// o resumo é uma breve descrição do objetivo do exercício
******************************/

#include <stdio.h>
#include <math.h>

int main()
{
  int x,i;
  float d;

  printf("Digite um numero natural na base decimal, para transforma-lo para a base binaria.\n");
  scanf("%d", &x);

  for ( i = d = 0 ; x>0 ; i++ )
  {
    d += (x % 2) * ( pow ( 10 , i ) );
    x /= 2;
  }

  printf("Binario = %.0f\n", d);

  return 0;
}
