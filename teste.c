#include <stdio.h>

int main () {
  long int raio_1, raio_2, num_casos;
  scanf("%li", num_casos);
  for (  ; num_casos >= 0 ; num_casos-- ) {
    scanf("%li %li", raio_1, raio_2);
    printf("%d\n", raio_1+raio_2);
  }
  return 0;
}
