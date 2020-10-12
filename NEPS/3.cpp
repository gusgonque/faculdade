#include <stdio.h>

int Eh_Primo (int x)
{
  int i;
  for (i=x/2;i>1;i--)
    if (x%i==0)
      return 0;
  return 1;
}

void Gincana (int m)
{
  int x,i;
  for ( x=m-1 ; x>1 ; x-- )
    if (Eh_Primo(x))
      break;
  printf("%d\n", x);
}

int main ()
{
  long int n, m;
  scanf("%d %d", &n, &m);
  Gincana (m);
  return 0;
}
