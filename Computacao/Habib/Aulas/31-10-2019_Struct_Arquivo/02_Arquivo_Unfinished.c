#include <stdio.h>
#define MAX 100

void Leitura (char *fn, int *n, float elem[])
{
  int i;
  FILE *arq;
  arq = fopen (fn,"r");
  for ( i=0 ; fscanf (arq,"%f",&elem[i]) ; i++ )
  {}
  *n = i;
  fclose(arq);
}

void Processo (float elem[], int n, float *soma)
{
  int i;
  for ( i=*soma=0 ; i<n ; i++ )
    *soma += elem[i];
}

void Relatorio (char *fn,float elem [], int n, float soma)
{
  int i;
  for ( i=0 ; i<n ; i++ )
    printf("#%d = %f\n", i, elem[i]);
  printf("SOMA = %f\n", soma);
}

int main ()
{
  int n;
  float soma, elem[MAX];
  Leitura ("Dados_02.txt",&n, elem);
  Processo (elem,n,&soma);
  Relatorio ("Saida_02.txt",elem,n,soma);
  return 0;
}
