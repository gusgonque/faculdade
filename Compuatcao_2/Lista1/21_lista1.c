/*****************************
* Nome do acadêmico: Gustavo Gonçalves Queiroz
* Nome do arquivo: 21_lista1.c
* Data de elaboração: 31/01
* Resumo: Implementar o procedimento void troca ( int *a, int *b ) sem usar variável auxiliar.
// o resumo é uma breve descrição do objetivo do exercício
******************************/

#include <stdio.h>

void troca ( int *a, int *b )
{
  *a += *b;
  *b = *a - *b;
  *a = *a - *b;

}

int main()
{
  int a,b;

  printf("Digite um numero a e outro b para ser printado b e a.\n");

  scanf("%d %d", &a, &b);

  troca ( &a, &b );
  
  printf("%d %d\n", a, b);


  return 0;
}
