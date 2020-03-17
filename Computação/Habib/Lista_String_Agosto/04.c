#include <stdio.h>
#include <string.h>
#define MAXC 100

int Quantas_Repete_Primeira (char s[])
{
  int i,j,k;
  char aux[MAXC],aux2[MAXC];
  for ( i=0 ; s[i] != ' ' ; i++ )
    aux[i] = s[i];
  for ( k=0, j=0 ; s[i] ; i++ )
  {
    if (s[i] != ' ')
    {
      aux2[j] = s[i];
      j++;
    }
    else
      j = 0;
    if (strcmp(aux,aux2) == 0)
    {
      k++;
      j = 0;
    }
  }
  return k;
}

int main ()
{
  char s[MAXC];
  for (  ; strcmp(gets(s),"fim") ;  )
  {
    printf("%d\n", Quantas_Repete_Primeira (s));
  }
}
