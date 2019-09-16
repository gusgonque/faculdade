#include <stdio.h>

void Preencher_Matriz (float mat[][20],int l,int c) {
  int i, j;
  for ( i = 0 ; i < l ; i++ )
    for ( j = 0 ; j < c ; j++ )
      scanf("%f", &mat[i][j]);
}

float Matriz_Soma_Coluna (float m[][20], int l, int c) {
    int i;
    float soma;
    for ( i=0, soma=0 ; i<l ; i++ )
        soma += m[i][c];
    return soma;
}

float Matriz_Media_Coluna (float m[][20], int l, int c) {
    int i;
    float media;
    for ( i=0, media=0 ; i<l ; i++ )
        media += m[i][c];
    return (media/l);
}

int main () {
    float m[20][20];
    int x;
    char c;
    scanf("%d ", &x);
    scanf("%c", &c);
    Preencher_Matriz (m,12,12);
    if (c == 'S')
        printf("%.1f\n", Matriz_Soma_Coluna (m,12,x));
    if (c == 'M')
        printf("%.1f\n", Matriz_Media_Coluna (m,12,x));
    return 0;
}
