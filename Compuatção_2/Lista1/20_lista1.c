/*****************************
* Nome do acadêmico: Gustavo Gonçalves Queiroz
* Nome do arquivo: 20_lista1.c
* Data de elaboração: 31/01
* Resumo: Dados dois strings (um contendo uma frase e outro contendo uma palavra),

ANA E MARIANA GOSTAM DE BANANA

ANA

determine o número de vezes que a palavra ocorre na frase.
// o resumo é uma breve descrição do objetivo do exercício
******************************/

#include <stdio.h>
#include <string.h>

int main()
{
  int i, o, j , f, ta, tb;
  char sa[100], sb[100];

  printf("Digite duas strings (um contendo uma frase e outro contendo uma palavra) para determinar o numero de vezes que a palavra ocorre na frase.\n");

  gets (sa);
  gets (sb);

  ta = strlen (sa);
  tb = strlen (sb);

  for ( i = o = 0 ; i <= (ta>tb?ta:tb) ; i++ )
  {
    if ( ta>tb )
    {
      for ( j = f = 0 ; j < tb ; j++, i++ )
        if( sa[i] == sb[j] )
          f++;
      if(f == tb)
        o++;
      i-=j;
    }
    else
    {
      for ( j = f = 0 ; j < ta ; j++, i++ )
        if( sb[i] == sa[j] )
          f++;
      if(f == ta)
        o++;
      i-=j;
    }
  }
  printf("Numero de ocorrencias = %d\n", o);

  return 0;
}
