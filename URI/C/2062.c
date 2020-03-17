#include <stdio.h>
#include <string.h>

int Obi_Uri (char s[])
{
  int i;
  if ((strlen(s) == 3)&&(((s[0] == 'O') && (s[1] == 'B')) || ((s[0] == 'U') && (s[1] == 'R'))))
    s[2] = 'I';
}

int main ()
{
  int n,i,fl;
  char s[100];
  scanf("%d%*c", &n);
  for ( i=0 ; i<n ; i++ )
  {
    scanf("%s", &s);
    Obi_Uri(s);
    if (i!=0)
      printf(" ");
    printf("%s", s);
  }
  printf("\n");
  return 0;
}
