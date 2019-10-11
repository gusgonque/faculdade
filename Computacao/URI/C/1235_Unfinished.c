#include <stdio.h>
#include <string.h>

void Descriptografia_Dentro_Tras (char s[]) {
  int i,t,j;
  char aux;
  for ( t=0 ; t<strlen(s) ; t++ ){
  }
  for ( i=(t/2) ; i>=0 ; i-- ){
    aux = s[i];
    s[i] = s [(t/2)-i];
    s [(t/2)-i] = aux;
  }
  for ( i=(t/2)+1, j=0 ; i<t ; i++, j++ ){
    aux = s[i];
    s[i] = s [t-j];
    s [t-j] = aux;
  }
}

int main () {
  char s[100];
  int n, i;
  scanf("%d%*c", &n);
  for ( i=0 ; i<n ; i++ ) {
    gets (s);
    Descriptografia_Dentro_Tras (s);
    puts (s);
  }
  return 0;
}
