#include <stdio.h>

int main () {
  int final = 0, n;
  scanf("%d", &n);
  while (n >= 0) {
    final = (final*10) + n; // 1234
    scanf("%d", &n);
  }
  printf("%d\n", final);
  return 0;
}
