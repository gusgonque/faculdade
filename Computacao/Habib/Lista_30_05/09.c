#include <stdio.h>

int main () {
  int num_linha, num_letra, i;
  scanf("%d", &num_linha);
  for ( num_letra=1, i=1 ; i <= num_linha ; i++) {
    while (num_letra <= i) {
      printf("%c", (96+num_letra));
      num_letra++;
    }
    printf("\n");
    num_letra = 1;
  }
  return 0;
}
