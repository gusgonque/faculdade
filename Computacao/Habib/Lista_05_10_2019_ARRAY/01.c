#include <stdio.h>
#include <string.h>

void Numero_Letras (char *str1, char *str2) {
  int v[10000], i;
  for ( i = 0 ; *(str2+i) ; i++ ) {
    if ( strchr(*str1,*(str2+i)) != '\0' )
      v[i]++;
  }
  for ( i = 0 ; *(str1+i) ; i++)
    printf("#%c = #d\n", *(str1+i), v[i]);
}

int main () {
  char str1[10000], str2[10000];
  gets(str1);
  gets(str2);
  for (  ; strcmp(str2,"fim") ; gets(str2) )
    Numero_Letras (str1,str2);
  return 0;
}
