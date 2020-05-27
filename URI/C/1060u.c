#include <stdio.h>

void Qnts_Pos( int n[] ) {
  int i, c;
  for ( i=c=0 ; n[i] ; i++ )
    c += ( n[i] > 0 ) ? 1 : 0 ;
}

int main ()
{
  int n[5], i;
  for ( i=0 ; n[i] ; i++)
    scanf("%d", n[i]);
  Qnts_Pos (n);
}
