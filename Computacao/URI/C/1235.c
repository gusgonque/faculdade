#include <stdio.h>
#include <string.h>
#include <math.h>

void Inverter_String_Primeira_Metade (char s[],int c,int f) {
  int i, j;
  char aux;
  for ( i=c, j=1 ; i<ceil(f/2) ; i++, j++) {
    aux = s[i];
    s[i] = s[f-j];
    s[f-j] = aux;
  }
}

void Inverter_String_Segunda_Metade (char s[],int c,int f) {
  int i, j;
  char aux;
  for ( i=c, j=1 ; i<ceil(f*0.75) ; i++, j++) {
    aux = s[i];
    s[i] = s[f-j];
    s[f-j] = aux;
  }
}

void Descriptografia_Dentro_Tras (char s[]) {
  int i,j;
  Inverter_String_Primeira_Metade (s,0,strlen(s)/2);
  Inverter_String_Segunda_Metade ( s , (strlen(s)/2) , strlen(s) );
}

int main () {
  char s[10000];
  int n, i;
  scanf("%d%*c", &n);
  for ( i=0 ; i<n ; i++ ) {
    gets (s);
    Descriptografia_Dentro_Tras (s);
    puts (s);
  }
  return 0;
}
