#include <stdio.h>

void Preencher_Matriz (float mat[][20],int l,int c) {
  int i, j;
  for ( i = 0 ; i < l ; i++ )
    for ( j = 0 ; j < c ; j++ )
      scanf("%f", &mat[i][j]);
}

float Matriz_Soma_Abaixo_Diagonal_Secundaria  (float m[][20], int l, int c) {
    int i,j;
    float soma;
    for ( i = l-1, soma = 0 ; i > 0 ; i-- )
      for ( j = c-i ; j < c ; j++ )
        soma += m[i][j];
    return soma;
}

float Matriz_Media_Abaixo_Diagonal_Secundaria (float m[][20], int l, int c) {
    int i,j;
    float media;
    for ( i = l-1, media = 0 ; i > 0 ; i-- )
      for ( j = c-i ; j < c ; j++ )
        media += m[i][j];
    return (media/66);
}

int main () {
    float m[20][20];
    char c;
    scanf("%c", &c);
    Preencher_Matriz (m,12,12);
    if (c == 'S')
        printf("%.1f\n", Matriz_Soma_Abaixo_Diagonal_Secundaria (m,12,12));
    if (c == 'M')
        printf("%.1f\n", Matriz_Media_Abaixo_Diagonal_Secundaria (m,12,12));
    return 0;
}
