#include <stdio.h>
#include <string.h>
#include <ctype.h>

void Preencher_Vetor (int v[], int t, int x)
{
  int i;
  for ( i=0 ; i<t ; i++ )
    v[i] = x;
}

int Validador_Senha (char s[])
{
  int i, condicoes[4];
  Preencher_Vetor (condicoes,4,0);
  if ((strlen(s) > 6) && (strlen(s) < 32))
    for ( i=0 ; s[i] ; i++ )
    {
      if (isupper(s[i]))
        condicoes[0]++;
      if (islower(s[i]))
        condicoes[1]++;
      if (isdigit(s[i]))
        condicoes[2]++;
      if (!(isalpha(s[i])))
        condicoes[3]++;
    }
    for ( i=0 ; i<3 ; i++ )
    {
      if (condicoes[i] != 0)
      {
        printf("Senha invalida.\n");
        return 0;
      }
    }
    if (condicoes[3]!=0)
      printf("Senha invalida.\n");
    else
      printf("Senha valida.\n");
}

int main ()
{
  char s[35];
  for (  ; gets(s) ;  )
  {
    Validador_Senha (s);
  }
}
