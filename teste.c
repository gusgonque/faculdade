#include <stdio.h>
#include <math.h>

int ano_bissexto (int a) {
  return ((((a%4)==0)&&(((a % 400) == 0)||((a % 100) != 0)))?1:0);
}

int dias_no_ano (int a) {
  int bissexto;
  bissexto = ano_bissexto (a);
  return (365 + bissexto);
}

int dias_no_mes (int m, int a) {
  int bissexto;
  bissexto = ano_bissexto (a);
  if ((m == 1) || (m == 3) || (m == 5) || (m == 7) || (m == 8) || (m == 10) || (m == 12)) {
    return 31;
  }
  else {
  if (m == 2) {
    return (28 + bissexto);
  }
  else
  return 30;
  }
}

int dias_desde_01_01 (int d, int m, int a) {
  return (d + ((ceil ((m - 1) / 2.0) *  31) + ((floor ((m - 1) / 2.0) - 1) * 30) + dias_no_mes (2, a)));
}

int main () {
  int dia, mes, ano;
  scanf ("%d %d %d", &dia, &mes, &ano);
  printf("%d", dias_desde_01_01(dia, mes, ano));
  return 0;
}
