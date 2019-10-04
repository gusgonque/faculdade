#include <stdio.h>
#define MAXC 50

void Ler_Prod_Mat_Primas (float p[][MAXC],int *np,int *nmp) {
  int i, j;
  printf("ENTRE COM A RELACAO DE PRODUTOS COM AS RESPECTIVAS QUANTIDADES DE MATERIAS-PRIMAS\n");
  scanf("%d %d", np, nmp );
  for ( i=0 ; i<*np ; i++ )
    for ( j=0 ; j<*nmp ; j++ )
      scanf("%f", &p[i][j]);
}

void Ler_Fornecedores (float f[][MAXC], int *nf, int nmp) {
  int i, j;
  printf("ENTRE COM A RELACAO DE FORNECEDORES COM OS RESPECTIVOS CUSTOS DAS MATERIAS-PRIMAS\n");
  scanf("%d", nf);
  for ( i=0 ; i<*nf ; i++ )
    for ( j=0 ; j<nmp ; j++ )
      scanf("%f", &f[i][j]);
}

void Leitura (float p[][MAXC], int *np, int *nmp,float f[][MAXC], int *nf) {
  Ler_Prod_Mat_Primas (p,np,nmp);
  Ler_Fornecedores (f,nf,*nmp);
}

float Soma_Elemento_x_Elemento (float v1[],float v2[],int nc) {
  float soma, aux;
  int i;
  for ( i=0, soma=0 ; i<nc ; i++ ){
    aux = v2[i];
    soma += ((v1[i]) * aux);
  }
  return soma;
}

void Orcamento_Fornecedores (float p[][MAXC],int np,int nmp,float f[][MAXC],int nf,float of[][MAXC]) {
  int i, j;
  float soma;
  for ( i=0 ; i<nf ; i++ )
    for ( j=0 ; j<nmp ; j++ )
      of[i][j]= Soma_Elemento_x_Elemento (p[i],f[i],nmp);
}

float Soma_Coluna (float m[][MAXC], int nl, int c) {
  int soma, i;
  for ( i=0, soma=0 ; i<nl ; i++ )
    soma += m[i][c];
  return soma;
}

void Orcamento_Total (float of[][MAXC], int nf, int nmp, float ot[]) {
  int i;
  for ( i=0 ; i<nf ; i++ )
    ot[i] = Soma_Coluna (of,nf,i);
}

void Processo (float p[][MAXC], int np, int nmp, float f[][MAXC], int nf, float of[][MAXC],float ot[]) {
  Orcamento_Fornecedores (p,np,nmp,f,nf,of);
  Orcamento_Total (of,nf,nmp,ot);
}

void Mostrar_Matriz (float m[][MAXC], int nl, int nc) {
  int i, j;
  for ( i=0 ; i<nl ; i++ ) {
    for ( j=0 ; j<nc ; j++ )
      printf("%.2f ", m[i][j]);
    printf("\n");
  }
  printf("\n");
}

void Mostrar_Vetor (float v[], int nc) {
  int i;
  for ( i=0 ; i<nc ; i++ )
    printf("%.1f ", v[i]);
  printf("\n");
}

void Relatorio (float p[][MAXC], int np, int nmp, float f[][MAXC], int nf, float of[][MAXC], float ot[]) {
  printf("RELACAO PROTUDO MATERIAL\n");
  Mostrar_Matriz (p,np,nmp);
  printf("ORCAMENTO FORNECEDORES\n");
  Mostrar_Matriz (of,np,nf);
  printf("ORCAMENTO TOTAL\n");
  Mostrar_Vetor (ot,nf);
}

int main () {

  int np, nmp, nf;
  float produtos[MAXC][MAXC], fornecedores[MAXC][MAXC], orc_for[MAXC][MAXC], orc_tot[MAXC];
  char mf;

  Leitura (produtos,&np,&nmp,fornecedores,&nf);
  Processo (produtos, np,nmp, fornecedores, nf, orc_for, orc_tot);
  Relatorio (produtos,np,nmp,fornecedores,nf,orc_for,orc_tot);

  return 0;
}
