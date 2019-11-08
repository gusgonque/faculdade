#include <stdio.h>

#define MAXC 50
#define MAXM 100

typedef struct
{
  int nm;
  double area, custo;
  char nome[MAXC], na[MAXC];
}
apartamento;

typedef struct
{
  apartamento ap[MAXM];
  int ntm, nap;
  double ata, cta, vc;
}
condominio;

void Leitura (char *fn, condominio c)
{
  int i;
  FILE *arq;
  arq = fopen (fn,"r");
  fscanf (arq,"%lf%*c",&c.vc);
  for ( i=0 ; fgets (c.ap[i].na,MAXC,arq) ; i++ )
  {
    fgets (c.ap[i].nome,MAXC,arq);
    fscanf (arq,"%d %lf%*c",&c.ap[i].nm,&c.ap[i].area);
  }
  c.nap = i;
  fclose(arq);
}

void Processo (condominio c)
{
  int i;
  double aux = c.vc / 2;
  for ( i = c.ntm = c.ata = c.cta = 0 ; i<c.nap ; i++ )
  {
    c.ap[i].custo = (aux/c.ap[i].nm) + (aux/c.ap[i].area);
    c.cta += c.ap[i].custo;
    c.ntm += c.ap[i].nm;
    c.ata += c.ap[i].area;
  }
}

void Relatorio (char *fn, condominio c)
{
  FILE *arq;
  arq = fopen (fn,"w");
  int i;
  if (arq == NULL)
    printf("ERRO\n");
  fprintf (arq,"%5s%15s%5s%7s%10s%10s","NUM","NOME","APT","MOR","AREA","CUSTO");
  fclose (arq);
}

int main ()
{
  condominio c;
  Leitura ("Entrada_01.txt",c);
  Processo (c);
  Relatorio ("Saida_01.txt",c);
  return 0;
}
