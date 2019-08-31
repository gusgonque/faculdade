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

void Fazendo_Duplas_Crescente (int des[], int real[], int c, int f) {
  int i;
  for ( i = c ; i < f ; i++ ) {
    if ((!(real[des[i] - 1]))&&(!real[i])) {
      real[des[i] - 1] = i+1;
      real[i] = des[i];
    }
  }
}

void Fazendo_Duplas_Decrescente (int des[], int real[], int c, int f) {
  int i;
  for ( i = c ; i > f ; i-- ) {
    if ((!(real[des[i] - 1]))&&(!real[i])) {
      real[des[i] - 1] = i+1;
      real[i] = des[i];
    }
  }
}

int Fatorial(int n){
   if (n>0)
      return n*Fatorial(n-1);
   else
      return 1;
}

int Permutacao(int n){
  return Fatorial(n);
}

int Arranjo(int n, int p){
  if (p>1)
      return n*Arranjo(n-1,p-1);
   else
      return n;
}

int Combinacao(int n, int p){
   return Arranjo(n,p)/Fatorial(p);
}

void Escolhendo_Duplas (int des[], int real[], int num_alunos) {
  Preencher_Vetor(real,num_alunos,0);
  int i, j, k;
  for ( i = j = 0; j < num_alunos ; j++) {
    if (real[i] == 0){
      Preencher_Vetor (real,num_alunos,0);
      Fazendo_Duplas_Crescente (des, real, j, num_alunos);
      Fazendo_Duplas_Crescente (des, real, 0, j);
      Mostrar_Vetor_Sem_Pular (real,num_alunos);
      i = -1;
    }
    i++;
  }
  for ( i = 0; j > 0 ; j--) {
    if (real[i] == 0){
      Preencher_Vetor (real,num_alunos,0);
      Fazendo_Duplas_Decrescente (des, real, num_alunos, j);
      Fazendo_Duplas_Decrescente (des, real, j, 0);
      Mostrar_Vetor_Sem_Pular (real,num_alunos);
      i = -1;
    }
    i++;
  }
  for ( i = 0 ; i < num_alunos ; i++ ) {
    if (real[i] == 0){
      printf("IMPOSSIBLE\n");
      printf("-----\n");
      return 0;
    }
  }
  Mostrar_Vetor_Sem_Pular (real,num_alunos);
  printf("-----\n");
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
