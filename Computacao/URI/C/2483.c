#include <stdio.h>

void Preencher_String (char *s, int t, char c) {
  int i;
  for ( i = 0 ; i < t ; i++) {
    *(s+i) = c;
  }
  *(s+i) = '\0';
}

void Feliz_Nataaaal (int x) {
  char s[10000];
  Preencher_String(s,x,'a');
  printf("Feliz nat");
  printf("%s", s);
  printf("l!\n");
}

int main() {
  int x;
  scanf("%d", &x);
  Feliz_Nataaaal(x);
  return 0;
}
