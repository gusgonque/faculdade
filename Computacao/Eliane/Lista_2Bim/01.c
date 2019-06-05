#include <stdio.h>

int main () {
  int final = 0, n, i = 1;
  scanf("%d", &n);
  while (n >= 0) {
    final = final + (n * i);
    i = i * 10;
    scanf("%d", &n);
  }
  printf("%d\n", final);
  return 0;
}
