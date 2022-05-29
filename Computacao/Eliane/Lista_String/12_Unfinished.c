#include <stdio.h>
#include <string.h>

void Eliminar_String_Dentro (char s1[], char s2[])
{
  int i, j, fl;
  char aux;
  for ( i=0 ; s1[i] ; i++ )
  {
    for ( j=i,fl=0 ; j<i+strlen(s2) ; j++)
    {
      if (s1[j]==s2[j])
      {
        fl++;
      }
    }
    if ( fl == (strlen(s2)-1) )
    {
      for ( j=i ; s1[j] ; j++ )
      {
        aux = s1[j];
        s1[j] = s1[j+strlen(s2)-1];
        s1[j+strlen(s2)-1] = aux;
      }
    }
  }
}

int main ()
{
  char s1[100], s2[100];
  gets(s1);
  for (  ; strcmp(gets(s2),"fim") ;  )
  {
    Eliminar_String_Dentro (s2,s1);
    puts(s2);
  }
}
