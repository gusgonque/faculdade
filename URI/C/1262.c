#include <stdio.h>
#include <string.h>

int main() {
  int i, p, f, c;
  char str[100];

  c = 0;

  while (scanf("%s", &str) != EOF)
  {
    scanf("%d%*c", &p);
    for ( i = c = 0 ; i < strlen(str) ; i++ )
    {
      while (str[i] == 'R')
      {
        for ( f=0 ; str[i]=='R' && f<p && strlen(str) ; i++, f++ );
        c++;
      }
      if (str[i] == 'W')
        c++;
    }
    printf("%d\n", c);
  }

  return 0;
}
