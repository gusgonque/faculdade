#include <stdio.h>

void Preencher_Matriz (float mat[][20],int l,int c) {
  int i, j;
  for ( i = 0 ; i < l ; i++ )
    for ( j = 0 ; j < c ; j++ )
      scanf("%f", &mat[i][j]);
}

float Matriz_Soma_Linha (float m[][20], int l, int c) {
    int i;
    float soma;
    for ( i=0, soma=0 ; i<c ; i++ )
        soma += m[l][i];
    return soma;
}

float Matriz_Media_Linha (float m[][20], int l, int c) {
    int i;
    float media;
    for ( i=0, media=0 ; i<c ; i++ )
        media += m[l][i];
    return (media/c);
}

int main () {
    float m[20][20];
    int x;
    char c;
    scanf("%d ", &x);
    scanf("%c", &c);
    Preencher_Matriz (m,12,12);
    if (c == 'S')
        printf("%.1f\n", Matriz_Soma_Linha (m,x,12));
    if (c == 'M')
        printf("%.1f\n", Matriz_Media_Linha (m,x,12));
    return 0;
}
