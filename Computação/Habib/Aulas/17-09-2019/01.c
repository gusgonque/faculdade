#include <stdio.h>
#include <string.h>

#define maxl 100
#define maxc 200
#define maxb 10
#define skip printf("\n")

void Ler (char m_c[][maxl], float m_n[][maxb], int *nl, int *nc) {
  int i, j;
  char s[maxc];
  scanf("%d%*c", nc);
  scanf("%[^;]%*c", s);
  for ( i=0 ; strcmp ( s , "fim" ) ; i++ ) {
    strcpy (m_c[i],s);
    for ( j=0 ; j<*nc ; j++ )
      scanf("%f", &m_n[i][j]);
    scanf("%*c");
    scanf("%[^;]%*c", s);
  }
  *nl = i;
}

void Show (char m_c[][maxl], float m_n[][maxb], int nl, int nc) {
  int i, j;
  for ( i = 0 ; i < nl ; i++ ) {
    printf("%-20s", m_c[i]);
    for ( j = 0 ; j < nc ; j++ )
      printf("%.2f ", m_n[i][j]);
    skip;
  }
}

void Calc_Medias (float notas[][maxb],float *v_med[],int nl,int nc) {
  int i;
  float soma;
  for ( i=0 ; i<nl ; i++ ) {
    for ( j=0 ; j<nc ; j++ )
      soma += notas [i];
    *v_med = soma/nc;
  }
}

int main () {
  int nl, nc;
  float m_not[maxl][maxb],v_med[maxb];
  char m_nom[maxl][maxc];
  Ler (m_nom,m_not,&nl,&nc);
  Calc_Medias (m_not,v_med,nl,nc);
  Calc_Media_Bim (m_not,v_med_bim,nl,nc);
  Show (m_nom,m_not,nl,nc);
  return 0;
}
