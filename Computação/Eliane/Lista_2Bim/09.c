#include <stdio.h>

void n_characteres_a_frente(int x, char c) {
  int contador_character = x;
  for (contador_character, c; contador_character > 0; contador_character--) {
    printf("%c", c);
    c ++;
  }
  printf("\n");
}

int main () {
  int n;
  char ch;
  scanf("%d %c", &n, &ch);
  for (n, ch; n >= 0; scanf("%d %c", &n, &ch)) {
    n_characteres_a_frente(n, ch);
  }
  return 0;
}
