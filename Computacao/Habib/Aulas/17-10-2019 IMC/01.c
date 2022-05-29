#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAXC 50
#define MAXM 100

typedef struct
{
  double peso, altura, imc;
  char nome[MAXC];
}PESSOA;

int Leitura (PESSOA x[], int *t, char *fn)
{
  int i;
  FILE *arq;
  arq = fopen (fn,"r");
  for ( i=0 ; fgets(x[i].nome,MAXC,arq) ; i++ )
  {
    fscanf(arq,"%lf %lf%*c", &x[i].peso,&x[i].altura);
    x[i].nome[]
  }
  *t = i;
  fclose(arq);
}

void Processo (PESSOA x[], int t)
{
  int i;
  for ( i=0 ; i<t ; i++ )
    x[i].imc = x[i].peso / pow(x[i].altura,2);
}

void Relatorio (PESSOA x[],int t, char *fn)
{
  int i;
  FILE *arq;
  arq = fopen (fn,"w");
  fprintf(arq,"%16s%10s%8s%9s\n\n", "Nome", "Peso", "Altura", "IMC");
  for ( i=0 ; i<t ; i++ )
    fprintf(arq,"%16s%10.2lf%8.2lf%9.2lf\n", x[i].nome, x[i].peso, x[i].altura, x[i].imc);
}

int main ()
{
  int t;
  PESSOA x[MAXM];
  Leitura(x,&t,"Dados.txt");
  Processo(x,t);
  Relatorio(x,t, "Relatorio.txt");
  return 0;
}
