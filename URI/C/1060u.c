#include <stdio.h>

void Qnts_Pos( float n[] ) {
  int i, c;
  for ( i=c=0 ; n[i] ; i++ )
    c += ( n[i] > 0 ) ? 1 : 0 ;
  printf("%d valores positivos\n", c);
}

int main ()
{
  int i;
  float n[8];
  for ( i=0 ; n[i] ; i++)
    scanf("%f", &n[i]);
  Qnts_Pos (n);
}
