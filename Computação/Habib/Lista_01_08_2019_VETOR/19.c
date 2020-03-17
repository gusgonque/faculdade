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

int Soma_Digitos (int x) {
  int aux, sd;
  for ( aux = x, sd = 0 ; aux > 0 ; aux/=10 ) {
    sd += aux % 10;
  }
  return sd;
}

void Vetor_Separar_SD_Par_Impar (int v[], int n) {
  int aux, v_sd_par[n-1], v_sd_impar[n-1], n_par, n_impar;
  for ( aux = n_par = n_impar = 0 ; aux < n ; aux ++ ) {
    if (!(Soma_Digitos(v[aux])%2)) {
      v_sd_par[n_par] = v[aux];
      n_par++;
    }
    else {
      v_sd_impar[n_impar] = v[aux];
      n_impar++;
    }
  }
  printf("Primeiro vetor\n");
  Mostrar_Vetor (v_sd_par,n_par);
  printf("\nSegundo vetor\n");
  Mostrar_Vetor (v_sd_impar,n_impar);
}

int main () {
  int n;
  scanf("%d", &n);
  int v[n-1];
  Identificar_Vetor (v,n);
  Vetor_Separar_SD_Par_Impar (v,n);
  return 0;
}
