#include <stdio.h>

void soma_digitos_int (int x){
  int soma = 0, i = 0, resto;
  while (x > 0) {
    i = x % 10;
    x /= 10;
    soma += i;
  }
  printf ("%d\n", soma);
}

int main () {
  int n;
  scanf ("%d", &n);
  while (n >= 0) {
  soma_digitos_int(n);
  scanf("%d", &n);
 }
  return 0;
}
