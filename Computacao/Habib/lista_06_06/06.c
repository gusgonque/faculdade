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

void data_a_partir (int d, int a, int *dia_final, int *mes_final) {
  int aux_dia = d, aux_mes = 1, mes_2 = dias_no_mes(2, a);
  if ((aux_dia > (31 + mes_2))) {
    aux_dia -= 29;
    aux_mes = 2;
    while (aux_dia>61) {
      aux_dia -= 61;
      aux_mes += 2;
    }
    if (aux_dia>30){
      aux_dia -= 30;
      aux_mes += 1;
    }
    else {
    }
  }
  else {
    if (aux_dia > 31) {
      aux_dia -= 31;
      aux_mes += 1;
    }
    else {
    }
  }
  *dia_final = aux_dia;
  *mes_final = aux_mes;
}

int main () {
  int dia, ano, dia_final, mes_final;
  scanf("%d %d", &dia, &ano);
  for (dia, ano; dia <= dias_no_ano(ano); scanf("%d %d", &dia, &ano)) {
    data_a_partir(dia, ano, &dia_final, &mes_final);
    printf("%d %d %d\n", dia_final, mes_final, ano);
  }
}
