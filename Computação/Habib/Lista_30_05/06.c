#include <stdio.h>

int main () {
  int n, i;
  for ( i = 0, n = 26 ; n > 0 ; n--, i++) {
    if ((97+i==97)||(97+i==101)||(97+i==105)||(97+i==111)||(97+i==117)) {
    }
    else
      printf("%c\n", 97 + i);
  }
  return 0;
}
