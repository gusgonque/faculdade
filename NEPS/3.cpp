#include <stdio.h>

int Gincana (int m)
{
  int x,i;
  for ( x=2 ; x<m ;x++  )
  {
    for ( i=x/2 ; i>1 ; i-- )
      if ( x%i==0 )
        break;
  }




  printf("%d\n", x);
}

int main ()
{
  int n,m;
  scanf("%d %d", &n, &m);
  Gincana (m);
  return 0;
}
