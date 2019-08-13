#include <stdio.h>

void Identificar_Vetor (int v[], int n) {
  int aux;
  printf("Digite os elementos desse vetor, um a um.\n");
  for (aux = 0; aux < n; aux ++) {
    scanf("%d", &v[aux]);
  }
}

void Mostrar_Vetor (int v[], int n) {
  int aux;
  for (aux = 0; aux < n; aux ++) {
    printf("vetor_resposta[%d] = %d\n", aux, v[aux]);
  }
}

int Qual_Maior (int x1, int x2) {
  printf("Maior entre %d e %d = %d\n", x1, x2, (x1 > x2) ? x1 : x2 );
  return (x1 > x2) ? x1 : x2;
}

int Qual_Menor (int x1, int x2) {
  printf("Menor entre %d e %d = %d\n", x1, x2, (x1 < x2) ? x1 : x2 );
  return (x1 < x2) ? x1 : x2;
}

void Vetor_Copiar (int v_ori[], int v_des[], int t) {
  int aux_contador;
  printf("O Vetor sera copiado em um vetor auxiliar\n");
  for ( aux_contador = 0 ; aux_contador < t ; aux_contador++ ) {
    v_des[aux_contador] = v_ori[aux_contador];
    printf("v_2[%d] = %d\n", aux_contador, v_des[aux_contador]);
  }
}

void Vetor_Reduzir_Maior_Menor (int v[], int t) {
  int aux_t, aux_alt, aux_v, t_final, aux_aux, v_aux[t-1];
  Vetor_Copiar (v,v_aux,t);
  for ( t_final = t, aux_aux = -1 ; t_final > 1 ;  ) {
    printf("Quantidade de elementos = %d\n", t_final);
    if ( t_final % 2 ) {
      aux_aux = v_aux[t_final-1];
      printf("Numero de elementos impar, ultimo elemento (%d) sera guardado\n", aux_aux);
      t_final--;
    }
    for ( aux_t = 0, aux_v = 0, aux_alt = 1 ; aux_t < t_final ; aux_t+=2 ) {
      v_aux[aux_v] = aux_alt == 1 ? Qual_Maior (v_aux[aux_t],v_aux[aux_t+1]) : Qual_Menor (v_aux[aux_t],v_aux[aux_t+1]);
      aux_v ++;
      aux_alt *= -1;
    }
    t_final/=2;
    if (aux_aux != -1) {
      t_final++;
      v_aux[t_final-1] = aux_aux;
      aux_aux = -1;
    }
  }
  Mostrar_Vetor (v_aux,t_final);
}

int main () {
  int n;
  scanf("%d", &n);
  int v[n-1];
  Identificar_Vetor (v,n);
  Vetor_Reduzir_Maior_Menor (v,n);
  return 0;
}
