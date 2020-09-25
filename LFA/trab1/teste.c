#include <stdio.h>

int main() {
  char teste [40];
  int i;
  for (i = 0; scanf("%c", &teste[i]) ; i++)
  {

    printf(" %c \n i = %d \n ", teste[i], i);

  }
  printf("%s\n", teste);
  return 0;
}
