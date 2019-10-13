#include <stdio.h>
#include <string.h>

void Combinador (char s1[],char s2[],char s[]) {
  int i,j;
  for ( i=j=0 ; (i<strlen(s1))||(i<strlen(s2)) ; i++ ) {
    s[j] = s1[i];
    j++;
    s[j] = s2[i];
    j++;
  }
}

int main () {
  char s1[1000],s2[1000],s[1000];
  int n, i;
  scanf("%d%*c", &n);
  for ( i=0 ; i<n ; i++ ) {
    scanf("%s %s",&s1,&s2);
    Combinador (s1,s2,s);
    puts (s);
  }
  return 0;
}
