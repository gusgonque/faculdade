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

int dias_desde_01_01_1600 (int d, int m, int a) {
  int dia_final = 0, aux_ano = a;
  for (aux_ano, dia_final; aux_ano > 1600; dia_final += dias_no_ano(aux_ano)) {
    aux_ano--;
  }
  dia_final += (d + ((ceil ((m - 1) / 2.0) *  31) + (m > 2) * ((floor ((m - 1) / 2.0) - 1) * 30) + (m > 2) * dias_no_mes (2, a)));
  return dia_final;
}

int maior_de_2 (int x, int y) {
  return (x > y)? x : y;
}

int menor_de_2 (int x, int y) {
  return (x < y)? x : y;
}

int diferenca_datas (int d_1, int m_1, int a_1, int d_2, int m_2, int a_2) {
  int aux_dias_1, aux_dias_2;
  aux_dias_1 = dias_desde_01_01_1600 (d_1, m_1, a_1);
  aux_dias_2 = dias_desde_01_01_1600 (d_2, m_2, a_2);
  return (maior_de_2(aux_dias_1, aux_dias_2) - menor_de_2 (aux_dias_1, aux_dias_2));

}

int main () {
  int dia_1, mes_1, ano_1, dia_2, mes_2, ano_2;
  scanf ("%d %d %d %d %d %d", &dia_1, &mes_1, &ano_1, &dia_2, &mes_2, &ano_2);
  for (dia_1, mes_1, ano_1, dia_2, mes_2, ano_2; ((data_valida(dia_1, mes_1, ano_1) == 1) && (data_valida(dia_2, mes_2, ano_2) == 1)); scanf ("%d %d %d %d %d %d", &dia_1, &mes_1, &ano_1, &dia_2, &mes_2, &ano_2)) {
    printf ("%d\n", diferenca_datas (dia_1, mes_1, ano_1, dia_2, mes_2, ano_2));
  }
  return 0;
}
