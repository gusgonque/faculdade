#include <stdio.h>

void pares ( int x ) {
  if ( x % 2 != 0) {
    printf("IMPOSSIBLE\n");
  } else {
    int alunos_sem_par[x], alunos_com_par[x], aux;
    for ( aux = 0 ; aux < x ; aux++) {
      scanf("%d", &alunos_sem_par[aux]);
      alunos_com_par[aux] = 0;
    }
    for ( aux = 1 ; aux <= x ; aux++ ) {
      if (alunos_com_par[aux] == 0) {
        if (alunos_com_par[alunos_sem_par[aux]]==0) {
          alunos_com_par[aux] = alunos_sem_par[aux];
          alunos_com_par[alunos_sem_par[aux]] = aux;
        }
        else {}
      }
      else {}
    }
    for ( aux = 1 ; aux <= x ; aux++) {
      printf("%d ", alunos_com_par[aux]);
    }
    printf("\n");
  }
}

int main () {
  int num_alunos_em_sala;
  scanf("%d", &num_alunos_em_sala);
  for (  ;  ; scanf("%d", &num_alunos_em_sala) ) {
    pares (num_alunos_em_sala);
  }
  return 0;
}
