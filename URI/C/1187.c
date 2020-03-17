#include <stdio.h>

void Preencher_Matriz (double mat[][20],int l,int c) {
  int i, j;
  for ( i = 0 ; i < l ; i++ )
    for ( j = 0 ; j < c ; j++ )
      scanf("%lf", &mat[i][j]);
}

double Matriz_Soma_Area_Superior  (double m[][20], int l, int c) {
    int i,j;
    double soma;
    for ( i = soma = 0 ; i < l ; i++ )
      for ( j = 1+i ; j < c-1-i ; j++ )
        soma += m[i][j];
    return soma;
}

double Matriz_Media_Area_Superior (double m[][20], int l, int c) {
    int i,j;
    double media;
    for ( i = media = 0 ; i < l ; i++ )
      for ( j = 1+i ; j < c-1-i ; j++ )
        media += m[i][j];
    return (media/30);
}

int main () {
    double m[20][20];
    char c;
    scanf("%c", &c);
    Preencher_Matriz (m,12,12);
    if (c == 'S')
        printf("%.1lf\n", Matriz_Soma_Area_Superior (m,12,12));
    if (c == 'M')
        printf("%.1lf\n", Matriz_Media_Area_Superior (m,12,12));
    return 0;
}
