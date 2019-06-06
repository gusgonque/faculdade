#include <stdio.h>

int ano_bissexto (int a) {
  return ((((a%4)==0)&&(((a % 400) == 0)||((a % 100) != 0)))?1:0);
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

int main () {
  int mes, ano;
  scanf ("%d %d", &mes, &ano);
  for (mes, ano; ano >= 1600; scanf ("%d %d", &mes, &ano)) {
    printf ("%d\n", dias_no_mes(mes, ano));
  }
  return 0;
}
