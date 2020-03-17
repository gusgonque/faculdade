int Eh_Identidade (int mat[][100],int l,int c) {
  int i,j;
  if (l!=c)
    return 0;
  for ( i = 0 ; i < l ; i++ )
    for ( j = 0 ; j < c ; j++ )
      if ( i == j )
        if ( mat[i][j] != 1 ) {
          return 0;
        }
        else
          if ( mat[i][j] )
            return 0;
  return 1;
}

int Soma_Matriz (int mat[][100],int l,int c) {
  int i, j,soma;
  for ( i = 0 ; i < l ; i++ )
    for ( j = 0 ; j < c ; j++ )
      soma += mat[i][j];
  return soma;
}

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

void Preencher_Matriz_Random_Quadrada (int mat[][100],int *l,int *c) {
  int i, j;
  *l = 1 + rand()%10;
  *c = *l;
  for ( i = 0 ; i < *l ; i++ )
    for ( j = 0 ; j < *c ; j++ )
      mat[i][j] = 1 + rand()%50;
}

void Mostrar_Matriz (int mat[][100],int l,int c) {
  int i, j;
  for ( i = 0 ; i < l ; i++ ) {
    for ( j = 0 ; j < c ; j++ )
      printf("%d ", mat[i][j]);
    printf("\n");
  }
  printf("\n");
}

void Preencher_Matriz_Identidade (int mat[][100],int l,int c) {
  int i,j;
  for ( i = 0 ; i < l ; i++ ) {
    for ( j = 0 ; j < c ; j++ )
        mat[i][j] = 0;
    mat[i][i] = 1;
    }
}

void Preencher_Matriz_Identidade_Inversa (int mat[][100],int l,int c) {
  int i, j;
  for ( i = 0 ; i < l ; i++ ) {
    for ( j = 0 ; j < c ; j++ )
      mat[i][j] = 0;
    mat[i][c-i-1] = 1;
  }
}

void Preencher_Matriz_Sequencia (int mat[][100],int l,int c) {
  int i, j, k;
  for ( i = k = 0 ; i < l ; i++ )
    for ( j = 0 ; j < c ; j++, k++ )
      mat[i][j] = k;
}

void Preencher_Matriz_Triangulo_Superior (int mat[][100],int l,int c) {
  int i, j;
  Preencher_Matriz_Identidade (mat,l,c);
  for ( i = 0 ; i < l ; i++)
    for ( j = i+1 ; j < c ; j++ )
      mat[i][j] = 1;
}

void Preencher_Matriz_Triangulo_Inferior (int mat[][100],int l,int c) {
  int i, j;
  Preencher_Matriz_Identidade (mat,l,c);
  for ( i = 0 ; i < l ; i++)
    for ( j = 0 ; j < i ; j++ )
      mat[i][j] = 1;
}

void Maior_Elemento_Matriz (int mat[][100], int l, int c) {
  int i, j, maior_elem, maior_i, maior_j;
  maior_elem = mat[0][0];
  maior_i = 0;
  maior_j = 0;
  for ( i=0 ; i<l ; i++ )
    for ( j=0 ; j<c ; j++ )
      if (mat[i][j]>maior_elem) {
        maior_i = i+1;
        maior_j = j+1;
        maior_elem = mat[i][j];
      }
  printf("Maior elemento [%d] [%d] = %d\n", maior_i, maior_j, maior_elem);
}
