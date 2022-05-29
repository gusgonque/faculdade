#include <stdio.h>

void Identificar_Vetor (int v[], int n) {
  int aux;
  for (aux = 0; aux < n; aux ++) {
    scanf("%d", &v[aux]);
  }
}

int Vetor_Forma_Palindromo ( int v[], int n) {
  int aux;
  for ( aux = 0 ; aux < n ; aux++ ) {
    if (!(v[aux]==v[n-1-aux])) {
      printf("Nao forma palindromo\n");
      return 0;
    }
  }
  printf("Forma palindromo\n");
  return 0;
}

int main () {
  int n;
  scanf("%d", &n);
  for (  ; n > 0 ; scanf("%d", &n) ) {
    int v[n-1];
    Identificar_Vetor (v,n);
    Vetor_Forma_Palindromo (v,n);
  }
  return 0;
}
