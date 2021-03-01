/*
string nom [?]
int ida [3]
c sex [1]
int rg [9]
int cpf [11]
int tel [11]
string end [?]
string pro [?]
int pri [1]
int vacDat [8][2] "01022020"
int vac [?]
struct pac [?]


int numPacVac [2][?]
int numPacNaoVac [1]
int numPacReg [1]
struct pri [5]


string nomTip [?]
int numDos [2]
struct vac [?]


int priLib [1]


1 2 3 4 5
0 19 50 300 200

1
1 2 3 4 5
5 18 0 0 0
1 1 0 0 0

 1 - Cadastrar habitante.
 2 - Registrar vacinacao.
 3 - Retirar habitante.
 4 - Liberar grupo prioritario para vacinacao.
 5 - Efetuar controle das vacinas.
 6 - Gerar relatorio.
 7 - Backup.

*/

#include <stdio.h>
#include <string.h>

#define MAX 250

int priLib = 0;

typedef struct
{
  char nom [MAX];
  int ida [3];
  char sex;
  int rg [9];
  int cpf [11];
  int tel [11];
  char end [MAX];
  char pro [MAX];
  int pri;
  int vacDat [8][2]; // "01022020"
  int vac [MAX];
}
paciente;

typedef struct
{
  int numPacVac [2][MAX];
  int numPacNaoVac [1];
  int numPacReg [1];
}
prioridade;

typedef struct
{
  char nomTip [MAX];
  int numDos [2];
}
vacina;

paciente pac[MAX];
int nPac = 0;

prioridade pri[5];

vacina vac[MAX];
int nVac = 0;

int VerNom ()
{
  int fl;


}

int CadHab() // Não finalizado
{
  if (nPac >= MAX)
  {
    printf(" Nao e possivel cadastrar novo habitante, armazenamento completo.\n Retornando ao menu inicial.");
    return 1;
  }
  else
  {
    printf(" Digite o nome completo do habitante.\n - ");
    setbuf(stdin, NULL);
    gets(pac[nPac].nom);
    printf("%s\n", pac[nPac].nom);
    if (VerNom)
    nPac ++;
  }
  return 1;
}

int RegVac() // Não finalizado
{

}

int RetPac() // Não finalizado
{
  if (nPac <= 0)
  {
    printf(" Nao e possivel retirar nenhum habitante, armazenamento vazio.\n Retornando ao menu inicial.");
    return 1;
  }
  else
  {

  }
}

int LibPri() // Não finalizado
{

}

int ConVac() // Não finalizado
{

}

int Backup() // Não finalizado
{

}

int GerRel() // Não finalizado
{

}

int Interface () // Finalizado
{
  int n;
  printf(" Digite:\n 1 - Cadastrar habitante.\n 2 - Registrar vacinacao.\n 3 - Retirar habitante.\n 4 - Liberar grupo prioritario para vacinacao.\n 5 - Efetuar controle das vacinas.\n 6 - Gerar relatorio.\n 7 - Backup dos dados.\n 8 - Sair do programa.\n\n - ");
  scanf("%d", &n);
  printf("\n");

  while ((n<1)||(n>8))
  {
    printf(" Comando nao existente, por favor, digite outro comando\n\n - ");
    scanf("%d", &n);
    printf("\n");
  }
  switch (n)
  {
    case (1):
    {
      printf(" Acessando interface de cadastro de habitante.\n\n");
      if (CadHab())
      {
        Interface ();
        return 1;
      }
    }
    case (2):
    {
      printf(" Acessando interface de registro de vacinacao.\n\n");
      if (RegVac())
      {
        Interface ();
        return 1;
      }
    }
    case (3):
    {
      printf(" Acessando interface de retirada de habitante.\n\n");
      if (RetPac())
      {
        Interface ();
        return 1;
      }
    }
    case (4):
    {
      printf(" Acessando interface de liberacao de grupo prioritario.\n\n");
      if (LibPri())
      {
        Interface ();
        return 1;
      }
    }
    case (5):
    {
      printf(" Acessando interface de controle de vacinas.\n\n");
      if (ConVac())
      {
        Interface ();
        return 1;
      }
    }
    case (6):
    {
      printf(" Acessando interface de geracao de relatorios.\n\n");
      if (GerRel())
      {
        Interface ();
        return 1;
      }
    }
    case (7):
    {
      printf(" Acessando interface de Backup dos dados.\n\n");
      if (Backup())
      {
        Interface ();
        return 1;
      }
    }
    case (8):
      return 1;
  }
  return 1;
}

int main()
{

  printf(" Sistema de gerenciamento de vacinacao contra a COVID-19\n");
  if (Interface())
    return 0;

}
