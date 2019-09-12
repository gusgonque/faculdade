#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Preencher_Matriz (int mat[][100],int *l,int *c) {
  int i, j;
  //*l = 3 + rand()%10;
  //*c = 2 + rand()%5;
  scanf("%d %d", l, c);
  for ( i = 0 ; i < *l ; i++ )
    for ( j = 0 ; j < *c ; j++ )
      //mat[i][j] = 10+ rand()%41;
      scanf("%d", &mat[i][j]);
}

void Mostrar_Matriz (int mat[][100],int l,int c) {
  int i, j;
  for ( i = 0 ; i < l ; i++ ) {
    for ( j = 0 ; j < c ; j++ )
      printf("%d ", mat[i][j]);
    printf("\n");
  }
}

int Soma_Matriz (int mat[][100],int l,int c) {
  int soma, i, j;
  for ( i = 0, soma = 0 ; i < l ; i++ )
    for ( j = 0 ; j < c ; j++ )
      soma += mat[i][j];
  return soma;
}

int main () {
  int mat[100][100],l,c;
  //srand(time(NULL));
  Preencher_Matriz (mat,&l,&c);
  Mostrar_Matriz (mat,l,c);
  printf("Soma = %d\n", Soma_Matriz(mat,l,c));
  return 0;
}
