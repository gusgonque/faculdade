#include <stdio.h>

void Identificar_Vetor (int v[], int n) {
  int aux;
  for (aux = 0; aux < n; aux ++) {
    scanf("%d", &v[aux]);
  }
}

void Mostrar_Vetor (int v[], int n) {
  int aux;
  for (aux = 0; aux < n; aux ++) {
    printf("%d\n", v[aux]);
  }
}

int Qual_Maior (int x1, int x2) {
  return (x1 > x2) ? x1 : x2;
}

int Qual_Menor (int x1, int x2) {
  return (x1 < x2) ? x1 : x2;
}

void Vetor_Reduzir_Maior_Menor (int v[], int t) {
  int aux_t, aux_alt, aux_v, t_final, aux_aux;
  for ( t_final = t, aux_aux = -1 ; t_final > 1 ;  ) {
    printf("Rodada %d\n", t-t_final+1);
    if ( t_final % 2 ) {
      aux_aux = v[t_final];
      t_final--;
    }
    for ( aux_t = 0, aux_v = 0, aux_alt = 1 ; aux_t < t_final ; aux_t+=2 ) {
      v[aux_v] = aux_alt == 1 ? Qual_Maior (v[aux_t],v[aux_t+1]) : Qual_Menor (v[aux_t],v[aux_t+1]);
      printf("Entre os numeros %d e %d do vetor, %d vence nessa rodada.\n", v[aux_t], v[aux_t+1], v[aux_v]);
      aux_v ++;
      aux_alt *= -1;
      t_final--;
    }
    if (aux_aux != -1) {
      t_final++;
      v[t_final] = aux_aux;
      aux_aux = -1;
    }
  }
  Mostrar_Vetor (v,t_final);
}

int main () {
  int n;
  scanf("%d", &n);
  int v[n-1];
  Identificar_Vetor (v,n);
  Vetor_Reduzir_Maior_Menor (v,n);
  return 0;
}
