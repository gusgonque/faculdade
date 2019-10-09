#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#define MAXC 1000

void Primeira_Passada (char s[]) {
  int i;
  for ( i=0 ; s[i] ; i++ )
    if (isalpha(s[i]))
      s[i] += 3;
}

void Inverter_String (char s[]) {
  int i, t;
  char aux;
  t = strlen(s);
  for ( i=0 ; i<t ; i++, t--) {
    aux = s[i];
    s[i] = s[t-1];
    s[t-1] = aux;
  }
}

void Terceira_Passada (char s[]) {
  int i;
  for ( i= ceil(strlen(s) / 2) ; s[i] ; i++ )
    s[i] -= 1;
}

void Processo (char s[]) {
  Primeira_Passada (s);
  Inverter_String (s);
  Terceira_Passada (s);
}

int main () {
  int n, i;
  char s[MAXC];
  scanf("%d%*c",&n);
  for ( i=0 ; i<n ; i++ ) {
    gets (s);
    Processo (s);
    puts (s);
  }
  return 0;
}
