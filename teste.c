#include <stdio.h>
#include <string.h>

int main () {
  int i;
  char s[100], aux;
  gets(s);
  for (i=0;i<strlen(s)/2;i++)
  {
    aux = s[i];
    s[i] = s[strlen(s)-i-1];
    s[strlen(s)-i-1] = aux;
  }
  puts(s);
  return 0;
}
//oi
