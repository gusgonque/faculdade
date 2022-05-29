#include <stdio.h>

void Leitura_Vetor (int v[], int t) {
  int i;
  for ( i=0 ; i<t ; i++) {
    scanf("%d", &v[i]);
  }
}

void Leitura (int *n, int v1[], int v2[]) {
  scanf("%d", n);
  Leitura_Vetor(v1,*n);
  Leitura_Vetor(v2,*n);
}

int Processo (int t, int v1[], int v2[]) {
  int i, j;
  for ( i=0 ; i<t ; i++ )
    for ( j=0 ; j<t ; j++ )
      if (v1[i] == v2[j])
        return 1;
  return 0;
}

void Relatorio (int i) {
  if (i)
    printf("Iguais.\n");
  else
    printf("Diferentes.\n");
}

int main () {
  int v1[100], v2[100], n;
  Leitura(&n,v1,v2);
  Relatorio(Processo(n,v1,v2));
  return 0;
}
