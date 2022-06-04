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
  char ida [4];
  char sex [2];
  char rg [10];
  char cpf [12];
  char tel [12];
  char end [MAX];
  char pro [MAX];
  int pri;
  char vacDat [2][9]; // "01022020"
  int vac;
}
paciente;

typedef struct
{
  int numPacVac [MAX][2];
  int numPacNaoVac;
  int numPacReg;
}
prioridade;

typedef struct
{
  char nomTip [MAX];
  int numDos;
}
vacina;

paciente pac[MAX];
int nPac = 0;

prioridade pri[5];
int gruLib = 0;

vacina vac[MAX];
int nVac = 0;

int Zerar ()
/*

Pré-condições:
  Nenhuma.

Pós-condições:
  Número de pacientes não vacinados zerados;
  Número de pecientes registrados zerados.

*/
{
  int i;
  for ( i = 0; i < 5; i++ )
  {
    pri[i].numPacNaoVac = 0;
    pri[i].numPacReg = 0;
  }

}

int Verificar_Resposta (char str[])
/*

Pré-condições:
  String str de entrada.

Pós-condições:
  Se a string for vazia, ou preenchida apenas por espaços, retorna o número 1. Do contrário, retorna 0.

*/
{
  int fl, i;

  if (str[0] == '\0')
    return 1;

  for ( i = fl = 0 ; str[i] ; i++)
    if (str[i] != ' ')
      fl++;

  if (fl == 0)
    return 1;
  else
    return 0;

}

int Verificar_Numero(char str[])
/*

Pré-condições:
  String str de entrada.

Pós-condições:
  Se a string for formada por algum caracter que não seja número, ou apenas números 0, retorna o número 1. Do contrário, retorna 0.

*/
{
  int fl, i;

  if (Verificar_Resposta(str))
    return 1;

  for ( i = fl = 0 ; str[i] ; i++)
    if (str[i] == '0')
      fl++;
  if (fl == i)
    return 1;

  for ( i = fl = 0 ; str[i] ; i++)
    if ((str[i] < '0') || (str[i] >  '9'))
      fl++;

  if (fl != 0)
    return 1;
  else
    return 0;
}

int CadHab()
/*

Pré-condições:
  Nenhuma.

Pós-condições:
  É cadastrado um novo elemento na struct Paciente.

*/
{
  int i;
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
    while (Verificar_Resposta(pac[nPac].nom))
    {
      printf(" Nome invalido. Por favor, digite novamente. O programa nao aceita nomes em branco.\n - ");
      setbuf(stdin, NULL);
      gets(pac[nPac].nom);
    }
    printf(" Nome registrado: [%s]\n", pac[nPac].nom);

    printf(" Digite a idade do habitante.\n - ");
    setbuf(stdin, NULL);
    gets(pac[nPac].ida);
    while (Verificar_Numero(pac[nPac].ida))
    {
      printf(" Idade invalida. Por favor, digite novamente.\n - ");
      setbuf(stdin, NULL);
      gets(pac[nPac].ida);
    }
    printf(" Idade registrada: [%s]\n", pac[nPac].ida);

    printf(" Digite o sexo do habitante. (F/M)\n - ");
    scanf("%s", pac[nPac].sex);
    while ((pac[nPac].sex[0] != 'F') && (pac[nPac].sex[0] != 'M'))
    {
      printf(" Sexo invalido. Por favor, digite novamente.\n - ");
      scanf("%s", pac[nPac].sex);
    }
    printf(" Sexo registrado: [%s]\n", pac[nPac].sex);

    printf(" Digite o RG do habitante.\n - ");
    setbuf(stdin, NULL);
    gets(pac[nPac].rg);
    while (Verificar_Numero(pac[nPac].rg))
    {
      printf(" RG invalido. Por favor, digite novamente.\n - ");
      setbuf(stdin, NULL);
      gets(pac[nPac].rg);
    }
    printf(" RG registrado: [%s]\n", pac[nPac].rg);

    printf(" Digite o CPF do habitante.\n - ");
    setbuf(stdin, NULL);
    gets(pac[nPac].cpf);
    for ( i = 0 ; i < nPac ; i++ )
    {
      if (strcmp( pac[nPac].cpf, pac[i].cpf ) == 0)
      {
        printf(" CPF ja registrado. Voltando ao menu inicial\n\n");
        return 1;
      }
    }
    while (Verificar_Numero(pac[nPac].cpf))
    {
      printf(" CPF invalido. Por favor, digite novamente.\n - ");
      setbuf(stdin, NULL);
      gets(pac[nPac].cpf);
    }


    printf(" CPF registrado: [%s]\n", pac[nPac].cpf);

    printf(" Digite o telefone do habitante.\n - ");
    setbuf(stdin, NULL);
    gets(pac[nPac].tel);
    printf(" Telefone registrado: [%s]\n", pac[nPac].tel);

    printf(" Digite o endereco do habitante.\n - ");
    setbuf(stdin, NULL);
    gets(pac[nPac].end);
    printf(" Endereco registrado: [%s]\n", pac[nPac].end);

    printf(" Digite a profissao do habitante.\n - ");
    setbuf(stdin, NULL);
    gets(pac[nPac].pro);
    printf(" Profissao registrada: [%s]\n", pac[nPac].pro);

    printf(" Digite a prioridade do habitante.\n - ");
    scanf("%d", &pac[nPac].pri);
    while (pac[nPac].pri < 1 || pac[nPac].pri > 5)
    {
      printf(" Prioridade invalida. Digite novamente, um valor noArvoreB intervalo de 1 a 5\n - ");
      scanf("%d", pac[nPac].pri);
    }
    pri[pac[nPac].pri-1].numPacNaoVac++;
    pri[pac[nPac].pri-1].numPacReg++;

    strcpy(pac[nPac].vacDat[0] , "00000000");
    strcpy(pac[nPac].vacDat[1] , "00000000");
    pac[nPac].vac = -1;

    nPac ++;

  }
  return 1;
}

void Listar_Vacinas()
/*

Pré-condições:
  Nenhuma.

Pós-condições:
  É printado noArvoreB cmd, a lista de todas as vacinas registradas.

*/
{
  int i;
  for ( i = 0 ; i < nVac ; i++ )
    printf(" %d - %s\n", i, vac[i].nomTip);
}

int RegVac()
/*

Pré-condições:
  Pelo menos um paciente registrado.

Pós-condições:
  É cadastrado a vacinação de um paciente registrado.

*/
{
  char n[MAX];
  int i, d;
  if (nPac <= 0)
  {
    printf(" Nao e possivel realizar a acao, sistema vazio.\n Retornando ao menu inicial.\n\n");
    return 1;
  }
  else
  {

    printf(" Digite o CPF do individuo a ser vacinado.\n - ");
    setbuf(stdin, NULL);
    gets(n);
    for ( i = 0 ; i < nPac ; i++ )
    {
      //printf("strcmp( %s, pac[%d].cpf = '%s' ) = %d\n", n, i,pac[i].cpf, strcmp( n, pac[i].cpf ));
      if (strcmp( n, pac[i].cpf ) == 0)
        break;
    }

    if (i == nPac)
    {
      printf(" Individuo nao encontrado. Retornando ao menu anterior.\n\n");
      return 1;
    }

    if (pac[i].pri > gruLib)
    {
      printf(" Grupo prioritario nao liberado ainda. Voltando ao menu anterior.\n\n");
      return 1;
    }

    if (nVac == 0)
    {
      printf(" Nenhuma vacina registrada noArvoreB sistema. Voltando ao menu anterior\n\n");
    }

    printf(" Digite o numero da vacina que quer registrar a vacinacao.\n");
    Listar_Vacinas();
    printf(" - ");
    scanf("%d", &d);
    while ((d<0)||(d>nVac))
    {
      printf(" Comando invalido. Digite novamente.\n - ");
      scanf("%d", &d);
    }

    if (vac[d].numDos == 0)
    {
      printf(" Estoque de doses dessa vacina esgotado. Retornando ao menu anterior.\n\n");
      return 1;
    }

    //printf("strcmp('00000000', %s ) = %d\n", pac[i].vacDat[0], strcmp("00000000", pac[i].vacDat[0] ));
    //printf("strcmp('00000000', %s ) = %d \n", pac[i].vacDat[1], strcmp("00000000", pac[i].vacDat[1] ));
    if (strcmp("00000000", pac[i].vacDat[0] ) == 0)
    {
      printf(" Registrando a primeira dose da vacina. Informe a data da vacinacao.(DDMMAAAA)\n - ");
      setbuf(stdin, NULL);
      gets(pac[i].vacDat[0]);
      while (Verificar_Numero(pac[i].vacDat[0]))
      {
        printf("Data invalida. Digite novamente.\n - ");
        setbuf(stdin, NULL);
        gets(pac[i].vacDat[0]);
      }
      pac[i].vac = d;
      vac[d].numDos--;
      pri[pac[i].pri-1].numPacNaoVac--;
      pri[pac[i].pri-1].numPacVac[d][0]++;
      printf(" Individuo vacinado, na data %s\n", pac[i].vacDat[0]);
    }
    else
    if (strcmp("00000000", pac[i].vacDat[1] ) == 0)
    {

      if (pac[i].vac != d)
      {
        printf("Individuo vacinado com primeira dose de outra vacina. Retornando ao menu anterior.\n\n");
        return 1;
      }

      printf(" Registrando a segunda dose da vacina. Informe a data da vacinacao.(DDMMAAAA)\n - ");
      setbuf(stdin, NULL);
      gets(pac[i].vacDat[1]);
      while (Verificar_Numero(pac[i].vacDat[1]))
      {
        printf("Data invalida. Digite novamente.\n - ");
        setbuf(stdin, NULL);
        gets(pac[i].vacDat[1]);
      }
      vac[d].numDos--;
      pri[pac[i].pri-1].numPacNaoVac--;
      pri[pac[i].pri-1].numPacVac[d][1]++;
      printf(" Individuo vacinado, na data %s\n", pac[i].vacDat[1]);
    }
    else
    {
      printf(" Habitante ja vacinado. Retornando ao menu anterior.\n\n");
      return 1;
    }


  }
  return 1;
}

int RetPac()
/*

Pré-condições:
  Pelo menos um paciente registrado.

Pós-condições:
  É retirado um elemento da struct Paciente.

*/
{
  char n[MAX];
  int i;

  if (nPac <= 0)
  {
    printf(" Nao e possivel realizar a acao, sistema vazio.\n Retornando ao menu inicial.\n\n");
    return 1;
  }
  else
  {
    printf(" Digite o CPF do individuo a ser retirado do sistema.\n - ");
    setbuf(stdin, NULL);
    gets(n);

    for ( i = 0 ; i < nPac ; i++ )
      if (strcmp( n, pac[i].cpf ) == 0)
        break;
    if (i == nPac)
    {
      printf(" Individuo nao encontrado. Retornando ao menu anterior.\n\n");
      return 1;
    }

    for (  ; i < nPac-1 ; i++ )
    {

      strcpy( pac[i].nom , pac[i+1].nom );
      strcpy( pac[i].ida , pac[i+1].ida );
      strcpy( pac[i].sex , pac[i+1].sex );
      strcpy( pac[i].rg , pac[i+1].rg );
      strcpy( pac[i].cpf , pac[i+1].cpf );
      strcpy( pac[i].tel , pac[i+1].tel );
      strcpy( pac[i].end , pac[i+1].end );
      strcpy( pac[i].pro , pac[i+1].pro );
      strcpy( pac[i].vacDat[0] , pac[i+1].vacDat[0] );
      strcpy( pac[i].vacDat[1] , pac[i+1].vacDat[1] );
      pac[i].pri = pac[i+1].pri;
      pac[i].vac = pac[i+1].vac;

    }

    nPac--;

  }

  return 1;

}

int LibPri()
/*

Pré-condições:
  O grupo de prioridade 5 não estar liberado.

Pós-condições:
  Libera o próximo grupo de prioridade.

*/
{
  char n;

  if (gruLib==5)
  {
    printf(" Grupo de prioridade 5 ja liberado. Retornando ao menu inicial.\n\n");
    return 1;
  }

  printf(" Esse comando liberara o grupo prioritario %d para vacinacao, deseja continuar? (S/N)\n - ", gruLib+1);
  setbuf(stdin, NULL);
  scanf("%c", &n);
  while ( n != 'S' && n != 'N' )
  {
    printf(" Comando invalido, tente novamente.\n - ");
    setbuf(stdin, NULL);
    scanf("%c", &n);
  }

  if (n == 'S')
  {
    gruLib++;
    printf(" Grupo %d liberado para vacinacao. Retornando ao menu inicial.\n\n", gruLib);
  }
  else
  {
    printf(" Retornando ao menu inicial\n\n");
  }
  return 1;

}

int AumDos()
/*

Pré-condições:
  Alguma vacina registrada noArvoreB sistema.

Pós-condições:
  É aumentado o número de doses da vacina que o usuário escolher.

*/
{
  int i, n, d;

  if (nVac == 0)
  {
    printf(" Nenhuma vacina registrada. Voltando ao menu anterior.\n");
    return 1;
  }

  printf(" Digite o numero da vacina que quer aumentar o numero de doses.\n");
  Listar_Vacinas();
  printf(" - ");
  scanf("%d", &n);
  while ((n<0)||(n>nVac))
  {
    printf(" Comando invalido. Digite novamente.\n - ");
    scanf("%d", &n);
  }

  printf("Digite o numero de doses a ser aumentado para essa vacina.\n - ");
  scanf("%d", &d);
  while (d<0)
  {
    printf(" Numero invalido. Digite novamente.\n - ");
    scanf("%d", &d);
  }

  vac[n].numDos += d;
  printf(" %d doses foram adicionadas a vacina %s.\n\n", d, vac[n].nomTip);

  return 1;

}

int RegNovVac()
/*

Pré-condições:
  Nenhuma.

Pós-condições:
  É cadastrado um novo elemento na struct Vacina.

*/
{
  int i;

  printf(" Digite o nome do tipo da vacina.\n - ");
  setbuf(stdin, NULL);
  gets(vac[nVac].nomTip);
  while (Verificar_Resposta(vac[nVac].nomTip))
  {
    printf(" Nome invalido. Por favor, digite novamente. O programa nao aceita nomes em branco.\n - ");
    setbuf(stdin, NULL);
    gets(vac[nVac].nomTip);
  }
  printf(" Nome registrado: [%s]\n\n", vac[nVac].nomTip);

  printf(" Digite a quantidade inicial de doses dessa vacina.\n - ");
  scanf("%d", &vac[nVac].numDos);
  while ( vac[nVac].numDos < 0 )
  {
    printf(" Valor invalido. Digite novamente.\n - ");
    scanf("%d", &vac[nVac].numDos);
  }

  for ( i = 0 ; i < 5 ; i++ )
  {
    pri[i].numPacVac[nVac][0] = 0;
    pri[i].numPacVac[nVac][1] = 0;
  }

  nVac++;

  return 1;

}

int ConVac()
/*

Pré-condições:
  Nenhuma.

Pós-condições:
  Abre um menu com opções para o controle de vacinas. Opções:
  1 - Aumento noArvoreB numero de doses de uma vacina ja criada.
  2 - Registro de uma nova vacina noArvoreB sistema.
  3 - Voltar ao menu inicial.

*/
{
  int n;
  printf(" Menu de controle de vacinas. Digite:\n 1 - Aumento noArvoreB numero de doses de uma vacina ja criada.\n 2 - Registro de uma nova vacina noArvoreB sistema.\n 3 - Voltar ao menu inicial.\n\n - ");
  scanf("%d", &n);
  printf("\n");

  while ((n<1)||(n>3))
  {
    printf(" Comando nao existente, por favor, digite outro comando.\n - ");
    scanf("%d", &n);
    printf("\n");
  }

  switch (n)
  {
    case (1):
    {
      AumDos();
      ConVac();
      return 1;
    }
    case (2):
    {
      RegNovVac();
      ConVac();
      return 1;
    }
    case (3):
    {
      return 1;
    }
  }

  return 1;

}

void Gerar_Relatorio_1()
/*

Pré-condições:
  Nenhuma.

Pós-condições:
  Printa noArvoreB cmd um relatório com as vacinas registradas e seus respectivos múmero de doses.

*/
{
  int i;
  if (nVac == 0)
    printf(" Nenhuma vacina registrada noArvoreB sistema. Retornando ao menu anterior.\n");
  for ( i = 0 ; i < nVac ; i++ )
    printf(" %s: %d doses disponiveis.\n", vac[i].nomTip, vac[i].numDos);
  printf("\n");
}

void Gerar_Relatorio_2()
/*

Pré-condições:
  Algum paciente estar registrado apenas com a primeira dose de alguma vacina.

Pós-condições:
  Printa noArvoreB cmd um relatório com o nome e CPF dos pacientes registrados apenas com a primeira dose de alguma vacina.

*/
{
  int i, f;
  if (nPac == 0)
    printf(" Nenhuma pessoa registrada noArvoreB sistema. Retornando ao menu anterior.\n");
  for ( i = f = 0 ; i < nPac ; i++ )
    if (strcmp("00000000", pac[i].vacDat[0] ) != 0)
      if (strcmp("00000000", pac[i].vacDat[1] ) == 0)
      {
        printf(" Nome:%s - CPF:%s\n",pac[i].nom, pac[i].cpf );
        f++;
      }
  if (f == 0)
    printf(" Nenhuma pessoa vacinada somente com a primeira dose de nenhuma vacina.\n");
  printf("\n");
}

void Gerar_Relatorio_3()
/*

Pré-condições:
  Algum paciente estar registrado com a segunda dose de alguma vacina.

Pós-condições:
  Printa noArvoreB cmd um relatório com o número de pacientes registrados com a segunda dose de alguma vacina.

*/
{
  int i, j, r;
  for ( i = r = 0 ; i < 5 ; i++ )
    for ( j = 0 ; j < nVac ; j++ )
      r += pri[i].numPacVac [j][1];
  printf(" %d pessoas foram vacinadas com a segunda dose de alguma vacina.\n\n", r);
}

void Gerar_Relatorio_4()
/*

Pré-condições:
  Algum paciente estar registrado noArvoreB sistema.

Pós-condições:
  Printa noArvoreB cmd um relatório com a lista de habitantes (nome, CPF) nao vacinados agrupados pelo grupo prioritario.

*/
{
  int i, j;

  if (nPac == 0)
    printf(" Nenhuma pessoa registrada noArvoreB sistema. Retornando ao menu anterior.\n");

  for (size_t j = 0; j < 5; j++)
  {
    printf(" Grupo %d\n", j+1);
    for ( i = 0 ; i < pri[j].numPacReg ; i++ )
      if (strcmp("00000000", pac[i].vacDat[0] ) == 0)
        printf(" Nome:%s - CPF:%s\n",pac[i].nom, pac[i].cpf );
  }
  printf("\n");
}

void Gerar_Relatorio_5()
/*

Pré-condições:
  Algum paciente estar registrado noArvoreB sistema.

Pós-condições:
  Printa noArvoreB cmd um relatório com o numero de habitantes por grupo prioritario.

*/
{
  int i;
  if (nPac == 0)
  printf(" Nenhuma pessoa registrada noArvoreB sistema. Retornando ao menu anterior.\n");

  for (size_t i = 0; i < 5; i++)
    printf(" Grupo %d: %d\n", i+1, pri[i].numPacReg);

  printf("\n");
}

int GerRel()
/*

Pré-condições:
  Nenhuma

Pós-condições:
  Abre um menu com opções para a geração de relatórios. Opções:
  1 - Numero de doses noArvoreB estoque por tipo de vacina.
  2 - Lista de habitantes (nome, CPF) vacinados somente com a 1a dose.
  3 - Numero de habitantes vacinados, ja com a 2a dose.
  4 - Lista de habitantes (nome, CPF) nao vacinados agrupados pelo grupo prioritario.
  5 - Numero de habitantes por grupo prioritario.
  6 - Retornar ao menu anterior.

*/
{
  int n;

  printf(" Digite para gerar o relatorio:\n 1 - Numero de doses noArvoreB estoque por tipo de vacina.\n 2 - Lista de habitantes (nome, CPF) vacinados somente com a 1a dose.\n 3 - Numero de habitantes vacinados, ja com a 2a dose.\n 4 - Lista de habitantes (nome, CPF) nao vacinados agrupados pelo grupo prioritario.\n 5 - Numero de habitantes por grupo prioritario.\n 6 - Retornar ao menu anterior.\n\n - ");
  scanf("%d", &n);
  printf("\n");

  while ((n<1)||(n>6))
  {
    printf(" Comando nao existente, por favor, digite outro comando\n\n - ");
    scanf("%d", &n);
    printf("\n");
  }

  switch (n)
  {
    case (1):
    {
      Gerar_Relatorio_1();
      return 1;
    }
    case (2):
    {
      Gerar_Relatorio_2();
      return 1;
    }
    case (3):
    {
      Gerar_Relatorio_3();
      return 1;
    }
    case (4):
    {
      Gerar_Relatorio_4();
      return 1;
    }
    case (5):
    {
      Gerar_Relatorio_5();
      return 1;
    }
    case (6):
    {
      return 1;
    }
  }

  return 1;
}

int Realizar_Backup()
/*

Pré-condições:
  Nenhuma

Pós-condições:
  (Quase) Todos os dados são salvos em um arquivo.
  Deliberadamente escolhemos não salvar o grupo prioritario liberado para melhor interação do professor com o código.

*/
{
  int i, j;
  char n[MAX];
  FILE *arq;

  printf(" Digite o nome e o caminho do seu backup. (Nao esqueca do .txt)\n - ");
  setbuf(stdin, NULL);
  gets(n);

  arq = fopen(n,"w");
  fprintf(arq, "%d\n", nPac);
  for ( i = 0 ; i < nPac ; i++ )
  {
    fprintf(arq, "%s;%s;%s;%s;%s;%s;%s;%s;%d;%s;%s;%d\n", pac[i].nom, pac[i].ida, pac[i].sex, pac[i].rg, pac[i].cpf, pac[i].tel, pac[i].end, pac[i].pro, pac[i].pri,pac[i].vacDat[0],pac[i].vacDat[1],pac[i].vac);
  }
  fprintf(arq, "%d\n", nVac);
  for ( i = 0 ; i < nVac ; i++ )
  {
    fprintf(arq, "%s;%d\n", vac[i].nomTip, vac[i].numDos);
  }
  fprintf(arq, "\n");
  for ( i = 0 ; i < 5 ; i++ )
  {

    fprintf(arq,"%d;%d\n", pri[i].numPacNaoVac, pri[i].numPacReg);
    for ( j = 0 ; j < nVac ; j++)
    {
      fprintf(arq,"%d;%d\n", pri[i].numPacVac[j][0], pri[i].numPacVac[j][1]);
    }
  }

  fclose(arq);

  printf(" Backup realizado.\n\n");

}

int Chamar_Backup( char s[] )
/*

Pré-condições:
  Existir um arquivo de backup com o nome/caminho registrado na string s.

Pós-condições:
  Todos os dados salvos são resgatados de volta noArvoreB sistema.

*/
{
  int i, j;
  char c;
  FILE *arq;

  arq = fopen(s,"r");
  if (arq == NULL)
  {
    printf(" Backup nao encontrado.\n");
    return 0;
  }
  fscanf(arq, "%d\n", &nPac);
  for ( i = 0 ; i < nPac ; i++ )
  {
    fscanf(arq,"%c", &c);
    for (j = 0; c != ';'; j++)
    {
      pac[i].nom[j] = c;
      fscanf(arq,"%c", &c);
    }
    fscanf(arq,"%c", &c);
    for (j = 0; c != ';'; j++)
    {
      pac[i].ida[j] = c;
      fscanf(arq,"%c", &c);
    }
    fscanf(arq,"%c", &c);
    for (j = 0; c != ';'; j++)
    {
      pac[i].sex[j] = c;
      fscanf(arq,"%c", &c);
    }
    fscanf(arq,"%c", &c);
    for (j = 0; c != ';'; j++)
    {
      pac[i].rg[j] = c;
      fscanf(arq,"%c", &c);
    }
    fscanf(arq,"%c", &c);
    for (j = 0; c != ';'; j++)
    {
      pac[i].cpf[j] = c;
      fscanf(arq,"%c", &c);
    }
    fscanf(arq,"%c", &c);
    for (j = 0; c != ';'; j++)
    {
      pac[i].tel[j] = c;
      fscanf(arq,"%c", &c);
    }
    fscanf(arq,"%c", &c);
    for (j = 0; c != ';'; j++)
    {
      pac[i].end[j] = c;
      fscanf(arq,"%c", &c);
    }
    fscanf(arq,"%c", &c);
    for (j = 0; c != ';'; j++)
    {
      pac[i].pro[j] = c;
      fscanf(arq,"%c", &c);
    }
    fscanf (arq, "%d;", &pac[i].pri);
    fscanf(arq,"%c", &c);
    for (j = 0; c != ';'; j++)
    {
      pac[i].vacDat[0][j] = c;
      fscanf(arq,"%c", &c);
    }
    fscanf(arq,"%c", &c);
    for (j = 0; c != ';'; j++)
    {
      pac[i].vacDat[1][j] = c;
      fscanf(arq,"%c", &c);
    }
    fscanf (arq, "%d\n", &pac[i].vac);
  }
  fscanf(arq, "%d\n", &nVac);
  for ( i = 0 ; i < nVac ; i++ )
  {
    fscanf(arq, "%c", &c);
    for ( j = 0;  c != ';' ; j++ )
    {
      vac[i].nomTip[j] = c;
      fscanf(arq, "%c", &c);
    }
    fscanf(arq, "%d\n", &vac[i].numDos);
  }
  fscanf (arq, "\n");
  for ( i = 0 ; i < 5 ; i++ )
  {

    fscanf(arq,"%d;%d\n", &pri[i].numPacNaoVac, &pri[i].numPacReg);
    for ( j = 0 ; j < nVac ; j++)
    {
      fscanf(arq,"%d;%d\n", &pri[i].numPacVac[j][0], &pri[i].numPacVac[j][1]);
    }
  }

  fclose(arq);

  printf(" Backup Chamado com sucesso.\n\n");

  return 1;

}

int Backup()
/*

Pré-condições:
  Nenhuma

Pós-condições:
  Abre um menu com opções para a geração ou chamada de um backup dos dados. Opções:
  1 - Realizar Backup noArvoreB computador.
  2 - Chamar Backup do computador.
  3 - Voltar ao menu anterior.

*/
{
  int n;
  char s[MAX];
  printf(" Digite:\n 1 - Realizar Backup noArvoreB computador.\n 2 - Chamar Backup do computador.\n 3 - Voltar ao menu anterior.\n - ");
  scanf("%d", &n);
  while ((n<1)||(n>3))
  {
    printf(" Comando nao existente, por favor, digite outro comando\n\n - ");
    scanf("%d", &n);
    printf("\n");
  }
  switch (n)
  {
    case (1):
    {
      Realizar_Backup();
      return 1;
    }
    case (2):
    {
      printf(" Digite o nome e o caminho do seu backup.\n - ");
      setbuf(stdin, NULL);
      gets(s);
      Chamar_Backup(s);
      return 1;
    }
    case (3):
    {
      return 1;
    }
  }
  return 1;
}

int Interface ()
/*

Pré-condições:
  Nenhuma

Pós-condições:
  Abre o menu inicial, com opções para a chamada de outras funções. Opções:
  1 - Cadastrar habitante.
  2 - Registrar vacinacao.
  3 - Retirar habitante.
  4 - Liberar grupo prioritario para vacinacao.
  5 - Efetuar controle das vacinas.
  6 - Gerar relatorio.
  7 - Backup dos dados.
  8 - Sair do programa.

*/
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
      CadHab();
      Interface ();
      return 1;
    }
    case (2):
    {
      printf(" Acessando interface de noArvoreB de vacinacao.\n\n");
      RegVac();
      Interface ();
      return 1;
    }
    case (3):
    {
      printf(" Acessando interface de retirada de habitante.\n\n");
      RetPac();
      Interface ();
      return 1;
    }
    case (4):
    {
      printf(" Acessando interface de liberacao de grupo prioritario.\n\n");
      LibPri();
      Interface ();
      return 1;
    }
    case (5):
    {
      printf(" Acessando interface de controle de vacinas.\n\n");
      ConVac();
      Interface ();
      return 1;
    }
    case (6):
    {
      printf(" Acessando interface de geracao de relatorios.\n\n");
      GerRel();
      Interface ();
      return 1;
    }
    case (7):
    {
      printf(" Acessando interface de Backup dos dados.\n\n");
      Backup();
      Interface ();
      return 1;
    }
    case (8):
      return 1;
  }
  return 1;
}

int main()
/*

Pré-condições:
  Nenhuma

Pós-condições:
  Chama a função Zerar, tenta chamar um backup pelo nome "backup.txt", então chama a função Interface.

*/
{
  Zerar();

  if ( Chamar_Backup("Backup.txt") == 0 )
    printf(" Configurando primeira vez noArvoreB programa...\n\n");
  else
    printf(" Backup recuperado. Listas de dados atualizados.\n\n");

  printf(" Sistema de gerenciamento de vacinacao contra a COVID-19\n");
  Interface();

  return 0;

}
