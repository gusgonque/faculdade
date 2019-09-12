void Preencher_Matriz (int mat[][100],int *l,int *c) {
  int i, j;
  scanf("%d %d", l, c);
  for ( i = 0 ; i < *l ; i++ )
    for ( j = 0 ; j < *c ; j++ )
      scanf("%d", &mat[i][j]);
}

void Preencher_Matriz_Random (int mat[][100],int *l,int *c) {
  int i, j;
  *l = 3 + rand()%10;
  *c = 2 + rand()%5;
  for ( i = 0 ; i < *l ; i++ )
    for ( j = 0 ; j < *c ; j++ )
      mat[i][j] = 10+ rand()%41;
}

void Mostrar_Matriz (int mat[][100],int l,int c) {
  int i, j;
  for ( i = 0 ; i < l ; i++ ) {
    for ( j = 0 ; j < c ; j++ )
      printf("%d ", mat[i][j]);
    printf("\n");
  }
}
