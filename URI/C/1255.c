#include <stdio.h>
#include <string.h>
#include <ctype.h>

void Frequencia (char str[])
{
  int i, alf[26], top;

  for ( i = 0 ; i < 26 ; i++ )
    alf[i] = 0;

  for ( i = top = 0 ; i < strlen(str) ; i++ )
    if (isalpha(str[i]))
    {
      alf[tolower(str[i])-'a'] ++;
      if (top<alf[tolower(str[i])-'a'])
        top = alf[tolower(str[i])-'a'];
    }

  for ( i = 0 ; i < 26 ; i++ )
    if ( alf[i] == top )
      printf("%c", 'a'+i);

  printf("\n");
}

int main()
{
  int n, i;
  char str[250];

  scanf("%d%*c", &n);

  for ( i = 0 ; i < n ; i++ )
  {
    gets(str);
    Frequencia(str);
  }

  return 0;
}
