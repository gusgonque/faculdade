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
  int x,y,z;

  printf("Digite tres numeros para determina-los em ordem crescente.\n");
  scanf("%d %d %d", &x, &y, &z);

  if(x>y && x>z && y>z)
      printf("%d %d %d", z, y, x);

  if(x>y && x>z && z>y)
      printf("%d %d %d", y, z, x);

  if(y>x && y>z && x>z)
      printf("%d %d %d", z, x, y);

  if(y>x && y>z && z>x)
      printf("%d %d %d", x, z, y);

  if(z>x && z>y && x>y)
      printf("%d %d %d", y, x, z);

  if(z>x && z>y && y>x)
      printf("%d %d %d", x, y, z);

  return 0;
}
