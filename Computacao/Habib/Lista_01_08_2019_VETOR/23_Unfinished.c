#include <stdio.h>
#include <math.h>

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

int Vetor_Soma_Subindo (int v[], int n, int Indice) {
  int aux, soma;
  for ( aux = n, soma = 0 ; aux > n-Indice-1 ; aux-- ) {
    soma += v[aux];
  }
  return soma;
}

int Vetor_Soma_Descendo (int v[], int n, int Indice) {
  int aux, soma;
  for ( aux = soma = 0 ; aux < n-Indice-1 ; aux++ ) {
    soma += v[aux];
  }
  return soma;
}

int Indice_Menor_Elemento (int v[], int n) {
  int aux, Menor_Indice;
  for (aux = 1, Menor_Indice = 0; aux < n ; aux++) {
    if (v[aux] < v[Menor_Indice]){
      Menor_Indice = aux;
    }
  }
  return Menor_Indice;
}

void Vetor_Ponto_de_Equilibrio (int v[], int n) {
  int aux, v_aux[n-1];
  for ( aux = 0 ; aux < n-1 ; aux ++) {
    v_aux[aux] = abs(Vetor_Soma_Subindo (v,n,aux) - Vetor_Soma_Descendo (v,n,aux));
  }
  printf("%d\n", Indice_Menor_Elemento(v_aux,n-1));
}

int main () {
  int n;
  scanf("%d", &n);
  for (  ; n > 0 ; scanf("%d", &n) ) {
    int v[n-1];
    Identificar_Vetor (v,n);
    Vetor_Ponto_de_Equilibrio (v,n);
  }
  return 0;
}
