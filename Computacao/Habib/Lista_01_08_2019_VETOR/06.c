#include <stdio.h>

void Identificar_Vetor (int v[], int n) {
  int aux;
  for (aux = 0; aux < n; aux ++) {
    scanf("%d", &v[aux]);
    printf("v[%d]=%d\n", aux, v[aux] );
  }
}

void Maior_Indice (int v[], int n) {
  int aux, Maior_Indice, v_aux_num[n-1], v_aux_ind[n], aux_cont_participantes;
  for (aux = 0; aux < n; aux ++) {
    v_aux_num[aux] = v[aux];
    printf("v_aux_num[ %d ]= %d\n", aux, v_aux_num[aux]);
  }
  if (!(n%2)) {
    for (aux_cont_participantes = n; aux_cont_participantes != 0; aux_cont_participantes/2) {
      for (aux = 0; aux < aux_cont_participantes; aux += 2) {
        if (v_aux_num[aux]<v_aux_num[aux+1]) {
          v_aux_num[aux] = v_aux_num[aux+1];
          v_aux_ind[aux] = aux+1;
        }
        else
          v_aux_ind[aux] = aux;
      }
    }
    printf("%d\n", v_aux_ind[0]);
  }
  else{
    for (aux_cont_participantes = n; aux_cont_participantes != 0; aux_cont_participantes/2) {
      for (aux = 1; aux < aux_cont_participantes; aux += 2) {
        if (v_aux_num[aux]<v_aux_num[aux+1]) {
          v_aux_num[aux] = v_aux_num[aux+1];
          v_aux_ind[aux] = aux+1;
        }
        else
          v_aux_ind[aux] = aux;
      }
    }
    if (v_aux_num[0]>v_aux_num[1])
      printf("%d\n", v_aux_ind[0]);
      printf("%d\n", v_aux_ind[1]);
  }
}


int main () {
  int n;
  scanf("%d", &n);
  int v[n-1];
  Identificar_Vetor(v,n);
  Maior_Indice (v, n);
}
