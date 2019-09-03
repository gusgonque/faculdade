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

void Escolhendo_Duplas (int desejo[], int realidade[]) {
    int i, v_aux [1000];
    Copiar_Vetor ()
}

int main () {
    int num_alunos, desejo[1000], realidade[1000];
    scanf("%d", &num_alunos);
    for (  ; num_alunos != 0 ; scanf("%d", &num_alunos) ) {
        if (!(num_alunos%2)) {
            printf("IMPOSSIBLE\n");
            return 0;
        }
        Identificar_Vetor(desejo, num_alunos);
        Escolhendo_Duplas(desejo,&realidade);
    }
    Mostrar_Vetor(realidade);
    return 0;
}
