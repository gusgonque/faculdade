#include <stdio.h>

int main () {
  int n, i;
  scanf("%d", &n);
  for ( i = 0 ; n > 0 ; n--, i++) {
    if ((97+i==97)||(97+i==101)||(97+i==105)||(97+i==111)||(97+i==117)) {
      n++;
    }
    else
      printf("%c\n", 97 + i);
  }
  return 0;
}
