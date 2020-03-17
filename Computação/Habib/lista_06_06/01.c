#include <stdio.h>

int ano_bissexto (int a) {
  return ((((a%4)==0)&&(((a % 400) == 0)||((a % 100) != 0)))?1:0);
}

int dias_no_ano (int a) {
  int bissexto;
  bissexto = ano_bissexto (a);
  return (365 + bissexto);
}


int main() {
  int a;
  scanf ("%d", &a);
  for (a; a>=1600; scanf ("%d", &a)) {
    printf("%d\n", dias_no_ano (a));
  }
  return 0;
}
