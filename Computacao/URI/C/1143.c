#include <stdio.h>

int main (){
  int num_linhas, num;
  scanf ("%d", &num_linhas);
  for ( num = 1; num_linhas > 0 ; num_linhas --) {
    printf ("%d %d %d\n", num, (num * num), (num * num * num));
    num ++;
  }
  return 0;
}
