#include <stdio.h>

void Preencher_Vetor (int v[], int t, int x) {
  int i;
  for ( i = 0 ; i < t ; i++) {
    v[i] = x;
  }
}

void Multiplos_2_3_4_5 (int v[], int t) {
  int mul [4], i;
  Preencher_Vetor(mul,4,0);
  for ( i = 0; i < t ; i++) {
    if (!(v[i]%5)) {
      mul[3]++;
    }
    if (!(v[i]%4)) {
      mul[2]++;
    }
    if (!(v[i]%3)) {
      mul[1]++;
    }
    if (!(v[i]%2)) {
      mul[0]++;
    }
  }
  for ( i = 0; i < 4 ; i++) {
    printf("%d Multiplo(s) de %d\n", mul[i], i+2);
  }
}

int main() {
  int num_casos, v[1000], i;
  scanf("%d", &num_casos);
  for ( i = 0; i < num_casos; i++) {
    scanf("%d", &v[i]);
  }
  Multiplos_2_3_4_5 (v, num_casos);
  return 0;
}
