#include <stdio.h>

int ano_bissexto (int a) {
  return ((((a%4)==0)&&(((a % 400) == 0)||((a % 100) != 0)))?1:0);
}

int dias_no_mes (int m, int a) {
  if ((m == 1) || (m == 3) || (m == 5) || (m == 7) || (m == 8) || (m == 10) || (m == 12)) {
    return 31;
  }
  else {
  if (m == 2) {
    return (28 + ano_bissexto (a));
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

void soma_data_dia (int d, int m, int a, int x, int *dia_final, int *mes_final, int *ano_final) {
  int aux_dia = d, aux_mes = m, aux_ano = a, contador_fim = x;
  if (contador_fim >= 0) {
    for (aux_dia, aux_mes, aux_ano, contador_fim; contador_fim > 0; contador_fim--) {
      aux_dia ++;
      if (aux_dia > dias_no_mes(aux_mes, aux_ano)){
        aux_dia -= dias_no_mes(aux_mes, aux_ano);
        aux_mes ++;
        if (aux_mes > 12) {
          aux_mes -= 12;
          aux_ano ++;
        }
        else {
        }
      }
      else {
      }
    }
    *dia_final = aux_dia;
    *mes_final = aux_mes;
    *ano_final = aux_ano;
  }
  else {
    for (aux_dia, aux_mes, aux_ano, contador_fim; contador_fim < 0; contador_fim++) {
      aux_dia --;
      for (aux_dia, aux_mes, aux_ano; aux_dia <= 0; aux_dia += dias_no_mes(aux_mes, aux_ano)) {
        aux_mes --;
        aux_ano -= (aux_mes == 0);
        aux_mes += ((aux_mes == 0) * 12);
      }
    }
    *dia_final = aux_dia;
    *mes_final = aux_mes;
    *ano_final = aux_ano;
  }
}

int main () {
  int dia, mes, ano, numero_dias_a_somar, dia_final, mes_final, ano_final;
  scanf ("%d %d %d %d", &dia, &mes, &ano, &numero_dias_a_somar);
  for (dia, mes, ano, numero_dias_a_somar, dia_final, mes_final, ano_final; data_valida(dia, mes, ano) == 1; scanf ("%d %d %d %d", &dia, &mes, &ano, &numero_dias_a_somar)){
    soma_data_dia (dia, mes, ano, numero_dias_a_somar, &dia_final, &mes_final, &ano_final);
    printf("%d %d %d\n", dia_final, mes_final, ano_final);
  }
  return 0;
}
