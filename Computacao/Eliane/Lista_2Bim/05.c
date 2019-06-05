#include <stdio.h>

int main () {
  int n, contador_1 = 1;
  char c;
  scanf("%d %c", &n, &c);
  int contador_2 = n, aux = n;
  while (n >= 0) {
    while (contador_1 <= n) { // contador_1 tem q chegar ao n (<=)
      while (contador_2 > 0){ // contador_2 tem q chegar a zero
        printf("%c", c);
        contador_2 --;
      }
      printf("\n");
      contador_1 ++;
      aux --;
      contador_2 = aux;
    }
    scanf("%d %c", &n, &c);
    contador_1 = 1;
  }
  return 0;
}
