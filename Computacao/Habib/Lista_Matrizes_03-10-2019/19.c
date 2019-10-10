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
  for ( i=0 ; i<np ; i++ )
    for ( j=0 ; j<nmp ; j++ )
      of[i][j]= Soma_Elemento_x_Elemento (p[i],f[j],nmp);
}

float Soma_Coluna (float m[][MAXC], int nl, int c) {
  int i;
  float soma;
  for ( i=0, soma=0 ; i<nl ; i++ )
    soma += m[i][c];
  return soma;
}

void Orcamento_Total (float of[][MAXC], int np, int nmp, float ot[]) {
  int i;
  for ( i=0 ; i<np ; i++ )
    ot[i] = Soma_Coluna (of,np,i);
}

void Melhor_Fornecedor (float ot[], int nf, int *mf) {
  int i;
  for ( i=0 ; i<nf-1 ; i++ )
    *mf = ot[i]<ot[i+1]?i:i+1;
}

void Processo (float p[][MAXC], int np, int nmp, float f[][MAXC], int nf, float of[][MAXC],float ot[], int *mf) {
  Orcamento_Fornecedores (p,np,nmp,f,nf,of);
  Orcamento_Total (of,np,nmp,ot);
  Melhor_Fornecedor (ot,nf,mf);
}

void Mostrar_Vetor (float v[], int nc,int w,int p) {
  int i;
  for ( i=0 ; i<nc ; i++ )
    printf("%*.*f",w,p, v[i]);
}

void Mostrar_Matriz (float m[][MAXC], int nl, int nc, int w, int p) {
  int i, j;
  for ( i=0 ; i<nl ; i++ ) {
    Mostrar_Vetor(m[i],nc,w,p);
    printf("\n");
  }
  printf("\n");
}

void Relatorio (float p[][MAXC], int np, int nmp, float f[][MAXC], int nf, float of[][MAXC], float ot[], int mf) {
  int i, j;
  printf("  ");
  for ( i=0 ; i<nmp ; i++ )
    printf("%8c%d",'M', i);
  for ( i=0 ; i<nf ; i++ )
    printf("%6c%-3d",'F', i);
  printf("\n");
  for ( i=0 ; i<np ; i++ ) {
    printf("P%d", i);
    Mostrar_Vetor (p[i],nmp,9,1);
    Mostrar_Vetor (of[i],nf,9,2);
    printf("\n");
  }
  printf("\n%-38s","TOTAL");
  Mostrar_Vetor (ot,nf,9,2);
  printf("\n\n%s%d\n", "MELHOR FORNECEDOR = F", mf);
}

int main () {

  int np, nmp, nf, mf;
  float produtos[MAXC][MAXC], fornecedores[MAXC][MAXC], orc_for[MAXC][MAXC], orc_tot[MAXC];

  Leitura (produtos,&np,&nmp,fornecedores,&nf);
  Processo (produtos, np,nmp, fornecedores, nf, orc_for, orc_tot,&mf);
  Relatorio (produtos,np,nmp,fornecedores,nf,orc_for,orc_tot,mf);

  return 0;
}
