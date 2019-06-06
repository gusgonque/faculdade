#include <stdio.h>

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

int data_valida (int d, int m, int a) {
  if ((m <= 12) && (m > 0)) {
    if ((d > 0) && (d <= dias_no_mes (m, a))) {
      return 1;
    }
    else
      return 0;
  }
  else
  return 0;
}

int main() {
  int ano, mes, dia, contador;
  scanf ("%d", &contador);
  for (contador, dia, mes, ano; contador > 0; contador --) {
    scanf ("%d %d %d", &dia, &mes, &ano);
    printf((data_valida (dia, mes, ano) == 1)? "valida\n" : "nao valida\n");
  }
  return 0;
}
