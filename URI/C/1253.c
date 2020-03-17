#include <stdio.h>
#include <string.h>
#include <ctype.h>

void Cifra_Cesar(char s[], int x)
{
  int i;
  for ( i=0 ; s[i] ; i++ )
    if (!(isalpha(s[i] - x)))
    {
      if (isupper(s[i]))
      {
        s[i] = 'Z'-'A' + s[i] - x + 1;
      }
      else
      {
        s[i] = 'Z'-'A' + s[i] - x + 1;
      }

    }
    else
      s[i] -= x;
}

int main () {
  int n,x,i;
  char s[100];
  scanf("%d%*c", &n);
  for ( i=0 ; i<n ; i++ ) {
    scanf("%s\n%d", &s,&x);
    Cifra_Cesar(s,x);
    puts(s);
  }
  return 0;
}
