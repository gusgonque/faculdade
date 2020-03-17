#include <stdio.h>

void Preencher_Matriz (double mat[][20],int l,int c) {
  int i, j;
  for ( i = 0 ; i < l ; i++ )
    for ( j = 0 ; j < c ; j++ )
      scanf("%lf", &mat[i][j]);
}

double Matriz_Soma_Area_Inferior  (double m[][20], int l, int c) {
    int i,j,k;
    double soma;
    for ( i = l-1, soma = k = 0 ; i > 6 ; i--, k++ )
      for ( j = c-i ; j < 11-k ; j++ )
        soma += m[i][j];
    return soma;
}

double Matriz_Media_Area_Inferior (double m[][20], int l, int c) {
    int i,j,k;
    double media;
    for ( i = l-1, media = k = 0 ; i > 6 ; i--, k++ )
      for ( j = c-i ; j < 11-k ; j++ )
        media += m[i][j];
    return (media/30);
}

int main () {
    double m[20][20];
    char c;
    scanf("%c", &c);
    Preencher_Matriz (m,12,12);
    if (c == 'S')
        printf("%.1lf\n", Matriz_Soma_Area_Inferior (m,12,12));
    if (c == 'M')
        printf("%.1lf\n", Matriz_Media_Area_Inferior (m,12,12));
    return 0;
}
