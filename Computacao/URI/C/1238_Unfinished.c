#include <stdio.h>
#include <string.h>

void Combinador (char s1[],char s2[],char s[]) {
  int i,j;
  for ( i=j=0 ; i < strlen(s1)+strlen(s2)-1 ; i++,j++ ) {
    if ( i<strlen(s1) )
      s[j] = s1[i];
    if ( i < (strlen(s1)>strlen(s2)?strlen(s1):strlen(s2)))
      j++;
    if ( i<strlen(s2) )
      s[j] = s2[i];
  }
}

int main () {
  char s1[100],s2[100],s[100];
  int n, i;
  scanf("%d%*c", &n);
  for ( i=0 ; i<n ; i++ ) {
    scanf("%s%*c %s",&s1,&s2);
    Combinador (s1,s2,s);
    puts (s);
  }
  return 0;
}
