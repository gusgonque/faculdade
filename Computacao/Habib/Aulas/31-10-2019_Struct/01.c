#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAXC 50
#define MAXM 100

typedef struct
{
  double v[MAXM];
  int nn;
}notas;

typedef struct
{
  double media;
  char nome[MAXC];
  notas notas;
}aluno;

void Leitura (aluno alu[], int *na)
{
  int i,j,nn;
  scanf("%d%*c", &nn);
  for ( i=0 ; gets (alu[i].nome) ; i++ )
  {
    for ( j=0 ; j<nn ; j++ )
      scanf("%lf", &alu[i].notas.v[j]);
    alu[i].notas.nn = nn;
    scanf("%*c");
  }
  *na = i;
}

void Processo (aluno alu[], int na)
{
  int i,j;
  double soma;
  for ( i=0 ; i<na ; i++ )
  {
    for ( j=soma=0 ; j<alu[i].notas.nn ; j++ )
      soma += alu[i].notas.v[j];
    alu[i].media = soma/alu[i].notas.nn;
  }
}

void Relatorio (aluno alu[], int na)
{
  int i,j;
  printf("%-15s", "NOME");
  for ( i=0 ; i<alu[0].notas.nn ; i++ )
    printf("%5c%d", 'N', i+1);
  printf("%7s\n", "MEDIA");
  for ( i=0 ; i<na ; i++ )
  {
    printf("%-15s", alu[i].nome);
    for ( j=0 ; j<alu[i].notas.nn ; j++ )
      printf("  %4.2lf", alu[i].notas.v[j]);
    printf("  %5.2lf\n", alu[i].media);
  }
}

int main ()
{
  aluno alunos[MAXM];
  int na;
  Leitura (alunos,&na);
  Processo (alunos,na);
  Relatorio (alunos,na);
  return 0;
}
