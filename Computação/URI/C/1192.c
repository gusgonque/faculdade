#include <stdio.h>
#include <ctype.h>


int Jogo_Paula (int x,int y,char c) {
  if (x==y) {
    printf("%d\n", x*y);
    return 0;
  }
  if (isupper(c))
    printf("%d\n", y-x);
  else
    printf("%d\n", x+y);
}

int main () {
  int x,y,n,i;
  char c;
  scanf("%d", &n);
  for ( i=0 ; i<n ; i++ ) {
    scanf("%d%c%d", &x,&c,&y );
    Jogo_Paula(x,y,c);
  }
  return 0;
}
