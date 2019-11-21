#include <stdio.h>
#define maxc 50
#define maxcol 100
#define maxlin 200

typedef struct
{
  double xmed,ymed,xdp,ydp,coefA,coefB,coefR;
}
Estatistica

typedef struct
{
  char nome[maxc];
  int nxy;
  double elemx[maxcol], elemy[maxcol];
  Estatistica estatisticas;
}
Medidas;

void Leitura (Medidas *med, char *fn)
{
  int i;
  FILE *arq;
}

int main() {
  Medidas medida[maxlin];
  Leitura (&medida,"Ajuste.txt");
  Processo ();
  Relatorio ();
  return 0;
}
