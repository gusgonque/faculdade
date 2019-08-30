#include <stdio.h>

void Identificar_Vetor (int v[], int n) {
  int aux;
  for (aux = 0; aux < n; aux ++) {
    scanf("%d", &v[aux]);
  }
}

void Mostrar_Vetor_Sem_Pular (int v[], int n) {
  int aux;
  for (aux = 0; aux < n; aux ++) {
    printf("%d ", v[aux]);
  }
  printf("\n");
}

void Preencher_Vetor (int v[], int t, int x) {
  int i;
  for ( i = 0 ; i < t ; i++) {
    v[i] = x;
  }
}

void Fazendo_Duplas (int des[], int real[], int c, int f) {
  int i;
  for ( i = c ; i < f ; i++ ) {
    if ((!(real[des[i] - 1]))&&(!real[i])) {
      real[des[i] - 1] = i+1;
      real[i] = des[i];
    }
  }
}

void Escolhendo_Duplas (int des[], int real[], int num_alunos) {
  Preencher_Vetor(real,num_alunos,0);
  int i, j, k, l;
  for ( i = k = 0 , j = 1, l = j; j < num_alunos ; i++, k++) {
    if (real[i] == 0){
      Preencher_Vetor(real,num_alunos,0);
      Fazendo_Duplas (des, real, 0, j);
      Fazendo_Duplas (des, real, l, num_alunos);
      j++;
      l = j;
      i = -1;
    }
  }
  for ( i = 0 ; i < num_alunos ; i++ ) {
    if (real[i] == 0){
      printf("IMPOSSIBLE\n");
      return 0;
    }
  }
  Mostrar_Vetor_Sem_Pular (real,num_alunos);
}

int main () {
  int num_alunos, desejo[100000], realidade[100000];
  scanf("%d", &num_alunos);
  for (  ; num_alunos >= 2 ; scanf("%d", &num_alunos) ) {
      if (num_alunos%2) {
        printf("IMPOSSIBLE\n");
      }
      else {
        Identificar_Vetor(desejo,num_alunos);
        Escolhendo_Duplas(desejo,realidade,num_alunos);
      }
  }
  return 0;
}
