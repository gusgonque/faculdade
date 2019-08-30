#include <stdio.h>

int main () {
  long int raio_1, raio_2, num_casos;
  scanf("%d", &num_casos);
  for (  ; num_casos > 0 ; num_casos-- ) {
    scanf("%d %d", &raio_1, &raio_2);
    printf("%d\n", raio_1+raio_2);
  }
  return 0;
}
