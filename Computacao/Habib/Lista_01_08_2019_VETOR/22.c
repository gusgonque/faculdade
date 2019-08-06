#include <stdio.h>

void Mostrar_Vetor (int v[], int n) {
  int aux;
  for (aux = 0; aux < n; aux ++) {
    printf("%d\n", v[aux]);
  }
}

int Numero_Primo (int x) {
  int aux;
  for ( aux = 2 ; aux <= (x/2)+(x==2)+(x==1) ; aux++){
    if ((!(x%aux))-(x==2))
      return 0;
  }
  return 1;
}

void Vetor_Primos ( int n) {
  int aux, v_primos[n-1], x;
  for ( aux = -1, x = 1 ; aux < n ;  ) {
    if (Numero_Primo(x)) {
      aux++;
      v_primos[aux] = x;
      x++;
    }
    else
      x++;
  }
  Mostrar_Vetor (v_primos, aux);
  printf("==\n");
}

int main () {
  int n;
  scanf("%d", &n);
  for (  ; n > 0 ; scanf("%d", &n) ) {
    Vetor_Primos (n);
  }
  return 0;
}
