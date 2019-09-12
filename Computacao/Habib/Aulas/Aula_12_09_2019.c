#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matriz.h"

int main () {
  int mat[100][100],l,c,maior_l,maior_c,maior_elem;
  srand(time(NULL));
  Preencher_Matriz_Random_Quadrada (mat,&l,&c);
  Mostrar_Matriz (mat,l,c);
  printf("Soma = %d\n", Soma_Matriz(mat,l,c));
  Maior_Elemento_Matriz(mat,l,c);
  if (l == c) {
  Preencher_Matriz_Identidade (mat,l,c);
  Mostrar_Matriz (mat,l,c);
  Preencher_Matriz_Identidade_Inversa (mat,l,c);
  Mostrar_Matriz (mat,l,c);
  Preencher_Matriz_Sequencia (mat,l,c);
  Mostrar_Matriz (mat,l,c);
  Preencher_Matriz_Triangulo_Superior (mat,l,c);
  Mostrar_Matriz (mat,l,c);
  Preencher_Matriz_Triangulo_Inferior (mat,l,c);
  Mostrar_Matriz (mat,l,c);
  }
  else
    printf("Matriz nao quadrada\n");
  return 0;
}
