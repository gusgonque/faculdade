#include <stdio.h>
#include <string.h>

#define maxl 100
#define maxc 50
#define maxb 10
#define skip printf("\n")

void Preencher_Matriz (float mat[][maxb],int *l,int *c) {
  int i, j;
  scanf("%d %d", l, c);
  for ( i = 0 ; i < *l ; i++ )
    for ( j = 0 ; j < *c ; j++ )
      scanf("%f%*c", &mat[i][j]);
}

void Ler_Nomes_Notas (char m_c[][maxc], float m_n[][maxb], int *nl, int nc) {
  int i, j;
  char s[maxc];
  scanf("%[^;]%*c", s);
  for ( i=0 ; strcmp ( s , "fim" ) ; i++ ) {
    strcpy (m_c[i],s);
    for ( j=0 ; j<nc ; j++ )
      scanf("%f", &m_n[i][j]);
    scanf("%*c");
    scanf("%[^;]%*c", s);
  }
  *nl = i;
}

float Somaprod (float notas[],float pesos[],int cp) {
  int i,soma;
  for ( i=0, soma=0 ; i<cp ; i++ )
    soma += (notas[i]*pesos[i]);
  return soma;
}

void Media_Pesos (float pesos[][maxb],int lp,int cp,float notas[][maxb],int ln, float medias[][maxb]) {
  int i, j;
  for ( i=0 ; i<ln ; i++ )
    for ( j=0 ; j<cp ; j++)
      medias[i][j] = Somaprod (notas[i],pesos[i],cp);
}

void Calc_Media_Bim (float notas[][maxb],int ln,int cp,float med_bim[]) {
  int i,j;
  float soma;
  for ( j=0 ; j<cp ; j++ ) {
    for ( i=0, soma=0 ; i<ln ; i++)
      soma += notas[i][j];
    med_bim[j] = soma/ln;
  }
}

void Leitura (float m_pes[][maxb],int *lp,int *cp,char m_nom[][maxc],float m_not[][maxb],int *ln,int *cn) {
  Preencher_Matriz (m_pes,lp,cp);
  Ler_Nomes_Notas (m_nom,m_not,ln,*cn);
}

void Calculo (float m_pes[][maxb],int lp,int cp,char m_nom[][maxc],float m_not[][maxb],int ln, float m_med[][maxb],float v_medbim[]) {
  Media_Pesos (m_pes,lp,cp,m_not,ln,m_med);
  Calc_Media_Bim (m_not,ln,cp,v_medbim);
}

void Relatorio (char nomes[][maxc],int ln,float notas[][maxb],int cn,float medias[][maxb],int cm,float med_bim[]) {
  int i,j;
  printf("%-20s","   NOME");
  for ( i=1 ; i<=cn ; i++)
    printf("N%-4d", i);
  for ( i=1 ; i<=cn ; i++)
    printf("M%-4d", i);
  skip;
  for ( i = 0 ; i < ln ; i++ ) {
    printf("%-20s", nomes[i]);
    for ( j = 0 ; j < cn ; j++ )
      printf("%-5.2f ", notas[i][j]);
    for ( j = 0 ; j < cm ; j++ )
      printf("%.2f ", medias[i][j]);
    skip;
  }
  skip;
  printf("%-20s","  MEDIAS BIMESTRAIS");

}

int main () {

  int lp,cp,ln,cn;
  float m_pes[maxl][maxb],m_not[maxl][maxb],m_med[maxl][maxb],v_medbim[maxb];
  char m_nom[maxl][maxc];

  Leitura (m_pes,&lp,&cp,m_nom,m_not,&ln,&cn);

  Calculo (m_pes,lp,cn,m_nom,m_not,ln,m_med,v_medbim);

  Relatorio (m_nom,ln,m_not,cn,m_med,lp,v_medbim);

  return 0;
}
