#include <stdio.h>

int main () {
  int n, contador_1 = 1, contador_2 = 1;
  char c;
  scanf("%d %c", &n, &c);
  while (n >= 0) {
    while (contador_1 <= n) {
      while (contador_2 <= contador_1) {
        printf("%c", c);
        contador_2++;
      }
      printf("\n");
      contador_1++;
      contador_2 = 1;
    }
    scanf("%d %c", &n, &c);
    contador_1 = 1;
  }
  return 0;
}
