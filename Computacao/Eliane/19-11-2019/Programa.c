#include <stdio.h>
#define maxc 50
#define maxm 100

typedef struct
{
  char item[maxc];
  int qtd;
  double vlr;
}
Lista;

typedef struct
{
  char nome[maxc], ent[maxc], sai[maxc];
  int n_mesa;
  Lista list[maxc];

}
Mesa;

typedef struct
{
  Mesa mesas[maxm];
  char itens[maxm][maxc];

}
Restaurante;

int main ()
{
  Leitura (&mesas);
  Processo ();
  Relatorio ();
  return 0;
}
