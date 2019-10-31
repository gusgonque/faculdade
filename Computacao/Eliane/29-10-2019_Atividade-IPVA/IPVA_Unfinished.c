#include <stdio.h>
#include <string.h>
#define MAX 50

typedef struct{
    char modelo[MAX];
    int tipo;
    float preco;
}Veiculo;

void Leitura (Veiculo vei[], int *nv, float ali[][MAX])
{
  int i,j;
  char s[MAX];
  for ( i=0 ; gets(vei[i].modelo) ; i++ )
  {
    gets(s);
    if (!(strcmp(s,"CARRO")))
      vei[i].tipo = 1;
    else
      if (!(strcmp(s,"ONIBUS")))
        vei[i].tipo = 2;
      else
        if (!(strcmp(s,"MOTOCICLETA")))
          vei[i].tipo = 3;
        else
          vei[i].tipo = 4;
    scanf("%f%*c", vei[i].preco);
  }
  for ( i=0 ; i<4 ; i++ )
    for ( j=0 ; i<4 ; j++ )
      scanf("%f", ali[i][j]);
}

void Processo (Veiculo vei[], int nv, float ali[][MAX])
{
  int i,j;
  for ( i=0 ; i<nv ; i++ )
    if (!(strcmp(vei[i],"CARRO")))
      for ( j=0 ; )
}

int main ()
{
  Veiculo vei[MAX];
  int nv;
  float aliquotas[MAX][MAX];
  Leitura (vei,*nv,aliquotas);
  Processo (vei,nv,aliquotas);
  Relatorio (vei,nv,aliquotas);
  return 0;
}
