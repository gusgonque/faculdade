/*****************************
* Nome do acadêmico: Gustavo Gonçalves Queiroz
* Nome do arquivo: 18_lista1.c
* Data de elaboração: 31/01
* Resumo: Dada uma sequência de n números, imprimi-la na ordem inversa à da leitura.
// o resumo é uma breve descrição do objetivo do exercício
******************************/

#include <stdio.h>
#include <string.h>

int main()
{
  char s[100];
  int i,t;

  printf("Digite uma sequencia de numeros, para imprimi-la na ordem inversa a da leitura.\n");

  gets(s);

  t=strlen(s);

  for(i=t; i>=0; i--)
  {

  printf("%c", s[i]);

  }

  return 0;
}
