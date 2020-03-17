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

int Numero_Primo (int x) {
  int aux;
  for ( aux = 2 ; aux <= x/2+(x==2) ; aux++){
    if ((!(x%aux))-(x==2))
      return 0;
  }
  return 1;
}

void Vetor_Separar_Primos (int v[], int n) {
  int aux, v_primos[n-1], v_nao_primos[n-1], n_primos, n_nao_primos;
  for ( aux = n_primos = n_nao_primos = 0 ; aux < n ; aux++) {
    if (Numero_Primo(v[aux])) {
      v_primos[n_primos] = v[aux];
      n_primos++;
    }
    else {
      v_nao_primos[n_nao_primos] = v[aux];
      n_nao_primos++;
    }
  }
  printf("Primos\n");
  Mostrar_Vetor (v_primos,n_primos);
  printf("\nNao primos\n");
  Mostrar_Vetor (v_nao_primos, n_nao_primos);
}

int main () {
  int n;
  scanf("%d", &n);
  int v[n-1];
  Identificar_Vetor (v,n);
  Vetor_Separar_Primos (v,n);
  return 0;
}
