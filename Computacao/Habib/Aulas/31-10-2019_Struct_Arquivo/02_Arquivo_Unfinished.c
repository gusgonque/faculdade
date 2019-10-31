#include <stdio.h>
#define MAX 100

void Leitura (FILE *arq, int *n, float elem[])
{
  int i;
  for ( i=0 ; fscanf (arq,"%f",&elem[i]) ; i++ );
  *n = i;
}

void Processo (float elem[], int n, float *soma)
{
  int i;
  for ( i=*soma=0 ; i<n ; i++ )
    *soma += elem[i];
}

void Relatorio (float elem [], int n, float soma)
{
  int i;
  for ( i=0 ; i<n ; i++ )
    printf("#%d = %f\n", i, elem[i]);
  printf("SOMA = %f\n", soma);
}

int main ()
{
  FILE *arq;
  int n;
  float soma, elem[MAX];
  arq = fopen ("DADOS.txt", "r");
  Leitura (arq, &n, elem);
  fclose(arq);
  Processo (elem,n,&soma);
  Relatorio (elem,n,soma);
  return 0;
}
