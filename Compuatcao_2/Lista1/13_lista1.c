/*****************************
* Nome do acadêmico: Gustavo Gonçalves Queiroz
* Nome do arquivo: 13_lista1.c
* Data de elaboração: 31/01
* Resumo: Dado um número natural na base binária, transformá-lo para a base decimal.
Exemplo: Dado 10010 a saída será 18, pois 1*2^4 + 0*2^3 + 0*2^2 + 1*2^1 + 0*2^0 = 18.
// o resumo é uma breve descrição do objetivo do exercício
******************************/

#include <stdio.h>
#include <math.h>

int main()
{
  int x,i,d;

  printf("Digite um numero natural na base binaria, para transforma-lo para a base decimal.\n");
  scanf("%d", &x);

  //Resto*2^Posicao

  for ( i = d = 0 ; x>0 ; i++ )
  {
    d += (x % 10) * ( pow ( 2 , i ) );
    x /= 10;
  }

  printf("Decimal = %d\n", d);

  return 0;
}
