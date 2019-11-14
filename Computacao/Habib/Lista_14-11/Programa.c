#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAXM 100
#define MAXC 50

typedef struct
{
  int np;
  double peso[MAXM], media, dp, max, min;
}
Dados;

typedef struct
{
  Dados dados;
  char nome[MAXC];
}
Pessoa;

void Leitura ( Pessoa *p , int *np , char *fn )
{
  int i,j;
  FILE *arq;
  char aux;
  arq = fopen (fn,"r");
  for ( i=0 ; fgets (p->nome,MAXC,arq) ; p++, i++ )
  {
    aux = 'a';
    for ( j=0 ; aux != '\n' ; j++ )
      fscanf (arq,"%d%c",&p->dados.peso[i],&aux);
    p->dados.np = j;
    p->nome[strlen(p->nome)-1] = ' ';
  }
  *np = i;
  fclose(arq);
}

void Media_Pesos ( Pessoa *p, int np )
{
  double somatoria;
  int i,j;
  for ( i=0 ; i<np ; i++,p++ )
  {
    for ( j=somatoria=0 ; j<p->dados.np ; j++ )
      somatoria += p->dados.peso[j];
    p->dados.media = somatoria / j;
  }
}

void DP_Pesos ( Pessoa *p, int np )
{
  int i,j;
  double somatoria;
  for ( i=0 ; i<np ; i++,p++ )
  {
    for ( j=somatoria=0 ; j<p->dados.np ; j++ )
      somatoria += pow((p->dados.peso[j] - p->dados.media),2);
    p->dados.dp = somatoria / (j-1);
  }
}

void Maior_Peso ( Pessoa *p, int np )
{
  int i,j;
  for ( i=0 ; i<np ; i++,p++ )
  {
    for ( j=0 ; j<p->dados.np-1 ; j++)
      if (p->dados.peso[j] > p->dados.peso[j+1])
        p->dados.max = p->dados.peso[j];
      else
        p->dados.max = p->dados.peso[j+1];
  }
}

void Menor_Peso ( Pessoa *p, int np )
{
  int i,j;
  for ( i=0 ; i<np ; i++ )
  {
    for ( j=0 ; j<p->dados.np-1 ; j++)
      if (p->dados.peso[j] < p->dados.peso[j+1])
        p->dados.min = p->dados.peso[j];
      else
        p->dados.min = p->dados.peso[j+1];
  }
}

void Processo ( Pessoa *p, int np )
{
  Media_Pesos (p,np);
  DP_Pesos (p,np);
  Maior_Peso (p,np);
  Menor_Peso (p,np);
}

int Maior_Num_Pesos ( Pessoa *p , int np )
{
  int i,j,mnp;
  for ( i=0 ; i<np-1 ; i++,p++ )
  {
      if (p->dados.np > (p+1)->dados.np)
        mnp = i;
      else
        mnp = i+1;
  }
  return mnp;
}

void Relatorio ( Pessoa *p, int np, char *fn )
{
  int i,j, mnp;
  FILE *arq;
  arq = fopen (fn,"w");
  mnp = Maior_Num_Pesos ( p , np );
  fprintf (arq,"%-5s %-15s ","NUM","NOME");
  for ( i=0 ; i<mnp ; i++ )
    fprintf (arq,"#%-4d ",i+1);
  fprintf (arq,"%5s %5s %5s %5s\n","MED","DP","MAX","MIN");
  for ( i=0 ; i<np ; i++,p++)
  {
    fprintf(arq, "%5d %-15s ", i+1, p->nome);
    for ( j=0 ; j<mnp ; j++ )
      fprintf (arq, "%-5.1lf ", p->dados.peso[j]);
    fprintf(arq, "%5lf %5lf %5lf %5lf\n", p->dados.media, p->dados.dp, p->dados.max, p->dados.min);
  }
  fclose (arq);
}

int main ()
{
  int np;
  Pessoa pessoas [200];
  Leitura (pessoas,&np,"Entrada.txt");
  Processo (pessoas,np);
  Relatorio (pessoas,np,"Saida.txt");
  return 0;
}
