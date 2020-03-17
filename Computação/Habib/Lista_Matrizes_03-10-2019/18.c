#include <stdio.h>
#define MAXC 50

void Ler_Distancia_Cidades (int d[][MAXC], int *nc) {
  int i, j;
  printf("DIGITE O NUMERO DE CIDADES\n");
  scanf("%d", nc);
  printf("DIGITE AS DISTANCIAS ENTRE AS CIDADES\n");
  for ( i=0 ; i<*nc ; i++ )
    for ( j=0 ; j<*nc ; j++ )
      scanf("%d", &d[i][j]);
}

void Ler_Trajeto (int t[], int *ncp) {
  int i;
  printf("DIGITE O TRAJETO PERCORRIDO. TERMINE COM ENTER CTRL+Z ENTER\n");
  for ( i=0 ; scanf("%d", &t[i]) != EOF ; i++ ) {
  }
  *ncp = i;
}

void Leitura (int d[][MAXC], int t[], int *nc, int *ncp) {
  Ler_Distancia_Cidades (d,nc);
  Ler_Trajeto (t,ncp);
}

void Processo (int d[][MAXC], int nc, int t[], int ncp, int *dp) {
  int i,j;
  for ( *dp=0, i=0 ; i<ncp-1 ; i++ )
    if ( d[ t[i] ][ t[i+1] ] != -1 )
      (*dp) += d[ t[i] ][ t[i+1] ];
    else {
      (*dp) = -1;
      break;
    }
}

void Relatorio () {

}

int main () {

  int dist[MAXC][MAXC], traj[MAXC], dp, nc, ncp;

  Leitura (dist,traj,&nc,&ncp);
  Processo (dist,nc,traj,ncp,&dp);
  printf("DISTANCIA PERCORRIDA = %d\n", dp);

  return 0;
}
