#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 100
#define LER_ESPACO setbuf(stdin, NULL)

void Ler_NU (FILE *arq, int *nu)
/*
Ler o número de usuários registrados no arquivo "usuarios.txt".
*/
{

  char c = 0;
  *nu = 0;
  arq = fopen("usuarios.txt","r");

  fscanf(arq, "%*3c%d",nu);

  if ( arq != NULL )
    while ( fscanf ( arq, "%c", &c ) != EOF )
      if (c == ';')
        fscanf(arq, "%*4c%d",nu);

  fclose(arq);
}

int Verificar_Data (int d,int m,int a)
/*
Verifica se a data inserida é possível.
*/
{
  if (a<2020&&a>0)
  {
    if (m==1||m==3||m==5||m==7||m==8||m==10||m==12)
      if (d<=31&&d>0)
        return 0;
      else
      {
        printf("Data invalida, por favor insira outra data no formato 'dd mm aa'.\n - ");
        return 1;
      }
    if (m==4||m==6||m==9||m==11)
      if (d<=30&&d>0)
        return 0;
      else
      {
        printf("Data invalida, por favor insira outra data no formato 'dd mm aa'.\n - ");
        return 1;
      }
    if (m==02&&d>0&&d>=28)
      return 0;
    else
    {
      printf("Data invalida, por favor insira outra data no formato 'dd mm aa'.\n - ");
      return 1;
    }
  }
  else
  {
    printf("Data invalida, por favor insira outra data no formato 'dd mm aa'.\n - ");
    return 1;
  }
}

int Verificar_Nome (char nome[])
/*
Verifica o nome, se ele tem o número mínimo de caracteres (2), se ele não é vazio.
*/
{
  int i, j, p;
  for ( i = j = p = 0 ; nome[i] ; i++, j++ )
    if ( nome[i]==' ')
      p++;
  if (j<2 || p == i)
    return 0;
  return 1;
}

int Reg_Usuario (FILE *arq, int *id)
/*
  Registra um usuário no arquivo "usuarios.txt".
*/
{

  char nome[MAX];
  int i, d,m,a;
  *id = *id +1;

  printf("Para registrar um novo usuario, digite o nome completo dele.\n(minino de 2 caracteres, nao pode ser vazio)\n - ");
  LER_ESPACO;
  scanf("%[^\n]s", &nome);
  i = Verificar_Nome (nome);
  while (i == 0)
  {
    printf("Nome invalido, por favor digite novamente.\n - ");
    LER_ESPACO;
    scanf("%[^\n]s", &nome);
    i = Verificar_Nome (nome);
  }

  printf("Usuario '%s' , ID = [%d], favor colocar sua data de nascimento, no seguinte formato 'dd mm aaaa'\n - ", nome, *id);
  scanf("%d %d %d", &d,&m,&a);
  while ( Verificar_Data (d,m,a) )
    scanf("%d %d %d", &d,&m,&a);

  printf("Usuario registrado.\n");

  arq = fopen("usuarios.txt","a+");
  fprintf(arq, "ID:%d\nLogin:%s\nData Nascimento:%d/%d/%d\nNH:0\nHistorico:.\n;\n", *id, nome, d,m,a);
  fclose(arq);

  return *id;
}

int Procurar_Usuario (FILE *arq, int nu)
/*
  Procura um usuário registrado no arquivo "usuarios.txt".
*/
{

  int i, j, id, jp, fl;
  char c,k, nome[MAX];

  if (nu == 0)
  {
    printf("Nenhum usuario registrado, retornando ao Menu Inicial.\n");
    return 0;
  }

  printf("\nPor favor, insira seu ID.\n - ");
  scanf("%d", &id);

  arq = fopen("usuarios.txt","r");

  for ( i = 1 , fl = 0 ; i <= nu ; i++)
  {

    fscanf ( arq , "%3*c%d" , &jp );
    if ( jp == id )
    {

      while (c != ':')
        fscanf (arq,"%c", &c);

      LER_ESPACO;
      fscanf(arq,"%[^\n]s", &nome);
      printf("\nUsuario encontrado.\nSeja bem vindo, '%s'.\n", nome);
      fl = 0;
      break;

    }
    else;
    {

      fl++;
      fscanf(arq,"%c", &k);
      while (k != ';')
        fscanf(arq,"%c", &k);
      fscanf(arq,"%*c");

    }

  }

  fclose(arq);

  if ( fl != 0)
  {

    printf("ID nao encontrado\nDigite:\n1 - Procurar outro ID.\n2 - Retornar o menu principal.\n");
    scanf("%d", &jp);
    switch (jp)
    {

      case 1:
        id = Procurar_Usuario(arq, nu);
        return id;
      break;
      case 2:
        return 1000000;
      break;

    }

  }

  return id;

}

int Listar_Usuarios (FILE *arq)
/*
  Lista usuários registrados no arquivo "usuarios.txt".
*/
{

  int i, id, nu;

  Ler_NU (arq,&nu);

  char c, nome[MAX];
  printf("\n");

  if (nu == 0)
  {
    printf("Nenhum usuario registrado, retornando ao Menu Inicial.\n");
    return 0;
  }

  arq = fopen ("usuarios.txt","r");

  while ( fscanf ( arq, "%c", &c ) != EOF )
  {

    fscanf (arq, "%2*c%d", &id);
    LER_ESPACO;
    fscanf (arq, "%7*c%[^\n]s", &nome);
    printf("ID = [%d] Nome de Usuario = '%s'\n", id, nome);
    for ( i = 0 ; i < 5; )
    {

      fscanf (arq,"%c",&c);
      if ( c == '\n' )
        i++;

    }

  }

  fclose(arq);

}

int Remover_Usuario (FILE *arq, int id)
/*
  Remove um usuário registrado no arquivo "usuarios.txt".
*/
{

  int i, jp, k,nu;
  char c;
  Ler_NU(arq,&nu);
  FILE *arq2;

  if (nu == 0)
  {
    printf("Nenhum usuario registrado, retornando ao Menu Inicial.\n");
    return 0;
  }

  arq2 = fopen ("usuarios2.txt","w");
  arq = fopen ("usuarios.txt","r");
  fscanf(arq,"%3*c%d\n", &jp);

  for ( k = 1 ; jp != id ; fscanf(arq,"%3*c%d\n", &jp), k++ )
  {

    fprintf(arq2, "%ID:%d\n", jp);
    for ( i = 0 ; i < 5 ;  )
    {

      fscanf(arq,"%c",&c);
      fprintf(arq2, "%c", c);

      if ( c == '\n' )
        i++;

    }

  }

  for ( i = 0 ; i < 5 ;  )
  {

    fscanf(arq,"%c",&c);
    if ( c == '\n' )
      i++;

  }

  for ( ; k <= nu - 1 ; k++ )
  {

    for ( i = 0 ; i < 10 ;  )
    {

      fscanf(arq,"%c",&c);
      fprintf(arq2, "%c", c);
      if ( c == '\n' )
        i++;

    }

  }

  fclose(arq);
  fclose(arq2);

  remove("videos.txt");
  rename("videos2.txt","videos.txt");

  fclose(arq);
  fclose(arq2);
  remove("usuarios.txt");
  rename("usuarios2.txt","usuarios.txt");
  printf("Usuario removido com sucesso.\n");

}

void Editar_Dados (FILE *arq, int id)
/*
Edita os dados de um usuário registrado no arquivo "usuarios.txt".
*/
{

  int i, d,m,a;
  char novo[MAX], c;
  FILE *arq2;

  printf("\nDigite o novo nome de usuario\n(minino de 2 caracteres, nao pode ser vazio).\n - ");
  LER_ESPACO;
  scanf("%[^\n]s", &novo);

  i = Verificar_Nome (novo);

  while (i == 0)
  {

    printf("Nome invalido, por favor digite novamente.\n - ");
    LER_ESPACO;
    scanf("%[^\n]s", &novo);
    i = Verificar_Nome (novo);

  }

  printf("\nDigite a nova data de nascimento, no formato 'dd mm aaaa'.\n - ");
  scanf("%d %d %d", &d, &m, &a);

  while ( Verificar_Data (d,m,a) )
  scanf("%d %d %d", &d,&m,&a);

  arq2 = fopen ("usuarios2.txt","w");
  arq = fopen ("usuarios.txt","r");

  for ( i = 1 ; i < id ;  )
  {

    fscanf(arq,"%c", &c);
    if ( c == ';' )
    i++;

  }

  fprintf(arq2, "ID:%d\nLogin:%s\nData Nascimento:%d/%d/%d\n", id, novo, d,m,a);

  for ( i = 0 ; i < 3; )
  {

    fscanf (arq,"%c",&c);
    if ( c == '\n' )
    i++;

  }
  while ( fscanf ( arq, "%c", &c ) != EOF )
  fprintf(arq2, "%c", c);

  fclose(arq);
  fclose(arq2);

  remove("usuarios.txt");
  rename("usuarios2.txt","usuarios.txt");

  printf("Usuario editado com sucesso.\n\n");

}

void Limpar_H (FILE *arq, int id)
/*
Limpa os dados de histórico de filmes de um usuário registrado no arquivo "usuarios.txt".
*/
{

  int i, jp;
  char novo[MAX], c;
  FILE *arq2;

  arq2 = fopen ("usuarios2.txt","w");
  arq = fopen ("usuarios.txt","r");

  fscanf(arq,"%3*c%d", &jp);
  fprintf(arq2, "ID:%d", jp);
  for ( i = 1 ; i < id ;  )
  {

    fscanf(arq, "%c", &c);
    fprintf(arq2,"%c", c);
    if ( c == ';' )
    i++;

  }

  if (id==jp)
  for ( i = 0 ; i < 3; )
  {

    fscanf (arq,"%c", &c);
    fprintf(arq2,"%c", c);
    if ( c == '\n' )
    i++;

  }
  else
  for ( i = 0 ; i < 4; )
  {

    fscanf (arq,"%c", &c);
    fprintf(arq2,"%c", c);
    if ( c == '\n' )
    i++;

  }

  fprintf(arq2, "NH:0\nHistorico:.\n;\n");

  for ( i = 0 ; i < 3; )
  {

    fscanf (arq,"%c", &c);
    if ( c == '\n' )
    i++;

  }

  while ( fscanf ( arq, "%c", &c ) != EOF )
  fprintf(arq2, "%c", c);

  fclose(arq);
  fclose(arq2);

  remove("usuarios.txt");
  rename("usuarios2.txt","usuarios.txt");

  printf("Historico limpado com sucesso.\n");

}

int Ver_Usuario ( FILE *arq, int id )
/*
Vê as informações um usuário registrado no arquivo "usuarios.txt" e printa no prompt de comando.
*/
{

  int i, l, d,m,a, nh, nu, id2;
  char login[MAX], c, h[MAX];

  Ler_NU (arq,&nu);
  arq = fopen("usuarios.txt","r");

  for ( i = 1 ; i < nu ;  )
  {

    fscanf(arq,"%*3c%d", &id2);
    if (id2==id)
      break;
    while (c!=';')
      fscanf(arq,"%c", &c);
    fscanf(arq,"%c", &c);
    i++;

  }

  fscanf (arq,"\n");

  while (c != '\n')
  fscanf(arq,"%c", &c);

  LER_ESPACO;
  fscanf (arq,"%6*c%[^\n]s",&login);

  fscanf (arq,"%17*c%d/%d/%d%4*c%d%11*c",&d,&m,&a,&nh);

  for ( i = 0 ; i < nh ; i++ )
  fscanf(arq,"%d%*c",&h[i]);

  fclose(arq);

  printf("\nUsuario '%s', ID: %d\nData de nascimento: %d / %d / %d\nHistorico de filmes visitados:", login, id, d,m,a);

  for ( i = 0 ; i < nh ; i++ )
  {

    printf(" %d", h[i]);
    if ( i < nh-1 )
    printf(",");

  }

  printf(".\n\nDeseja editar algum de seus dados?\n1 - Editar informacoes.\n2 - Limpar historio de filmes.\n3 - Remover usuario. (volta para o menu inicial)\n4 - Voltar para o menu.\n - ");
  scanf("%d", &i);

  switch (i)
  {

    case 1:
    Editar_Dados (arq, id);
    return 0;
    break;
    case 2:
    Limpar_H (arq, id);
    return 0;
    break;
    case 3:
    Remover_Usuario (arq, id);
    return 0;
    break;
    case 4:
    return 0;
    break;

  }

  return 1;

}

int Menu_Inicial ( int *nu )
/*
MENU INICIAL
1 - Registrar novo usuario
2 - log in
3 - Listar usuarios registrados
4 - Remover usuario
5 - finalizar programa
*/
{

  int i, id;
  FILE *arq;

  printf("\nDigite:\n1 - Log in de usuario existente.\n2 - Registrar um novo usuario.\n3 - Listar usuarios registrados. (ou editar usuario registrado)\n4 - Finalizar o programa.\n - ");
  scanf("%d", &i);
  Ler_NU (arq, nu);

  switch (i)
  {
    case 1:

      Listar_Usuarios(arq);
      id = Procurar_Usuario(arq, *nu);
      if ( id == 1000000)
        return Menu_Inicial (nu);
      if (id == 0)
      {
        return Menu_Inicial (nu);
      }

    break;
    case 2:
      id = Reg_Usuario(arq, nu);
    break;
    case 3:
      Listar_Usuarios(arq);
      printf("Deseja editar os dados de algum usuario?\nDigite 0 para nao editar, voltando ao menu inicial, ou o id que deseja alterar.\n - ");
      scanf("%d", &id);
      if (id != 0)
        Ver_Usuario(arq, id);
      return Menu_Inicial(nu);
    break;
    case 4:
      return 0;
    break;

  }

  return id;

}

void Ler_NV ( FILE *arq, int *nv )
/*
  Lê o número de vídeos registrados no arquivo "videos.txt".
*/
{

  char i;
  char c;
  arq = fopen("videos.txt","r");

  *nv = 0;

  fscanf(arq, "%*3c%d",nv);

  if ( arq != NULL )
    while ( fscanf ( arq, "%c", &c ) != EOF )
      if (c == ';')
        fscanf(arq, "%*4c%d",nv);

  fclose(arq);

}

void Deletar_Video ( FILE *arq, int id, int *nv )
/*
  Deleta todas as informações um vídeo registrado no arquivo "videos.txt".
*/
{

  int jp,i,k;
  FILE *arq2;
  char c;

  arq = fopen ("videos.txt","r");
  arq2 = fopen ("videos2.txt","w");
  fscanf(arq,"%3*c%d\n", &jp);

  for ( k = 1 ; jp != id ; fscanf(arq,"%3*c%d\n", &jp), k++ )
  {

    fprintf(arq2, "%ID:%d\n", jp);

    for ( i = 0 ; i < 9 ;  )
    {

      fscanf(arq,"%c",&c);
      fprintf(arq2, "%c", c);

      if ( c == '\n' )
        i++;

    }

  }

  for ( i = 0 ; i < 9 ;  )
  {

    fscanf(arq,"%c",&c);
    if ( c == '\n' )
      i++;

  }

  for ( ; k <= *nv - 1 ; k++ )
  {

    for ( i = 0 ; i < 10 ;  )
    {

      fscanf(arq,"%c",&c);
      fprintf(arq2, "%c", c);
      if ( c == '\n' )
        i++;

    }

  }

  fclose(arq);
  fclose(arq2);

  remove("videos.txt");
  rename("videos2.txt","videos.txt");

}

int Verificar_Tempo (int h, int m)
/*
Verifica se o tempo inserido é possível, no intervalo Hora: [0,24],Minuto: [0,59].
*/
{

  if (h<0||h>24)
    return 0;
  if (m<0||m>59)
    return 0;
  if (m == h && m == 0)
    return 0;
  return 1;

}

int Verificar_Video ( int t, int h, int m, int ano, int nt, char nome[])
/*
Verifica se is informações inseridas são possiveis, em relação do vídeo registrado.
*/
{

  if ( (Verificar_Nome (nome)) == 0 )
    return 1;
  if (ano<0)
    return 2;
  if (t == 1)
  {
    if (Verificar_Tempo(h,m) == 0)
      return 3;
  }
  else
    if (t == 2)
    {
      if (nt<=0)
        return 2;
    }
    else
      return 1;

  return 0;

}

int Listar_Videos (FILE *arq)
/*
  Lista vídeos registrados no arquivo "videos.txt".
*/
{

  int i, j, id, nv;

  Ler_NV(arq,&nv);

  char c, nome[MAX];

  if (nv == 0)
  {
    printf("Nenhum video registrado, retornando ao Menu Principal.\n");
    return 0;
  }

  arq = fopen ("videos.txt","r");

  for ( i = 0 ; i < nv ; i++ )
  {

    fscanf (arq, "%3*c%d", &id);
    LER_ESPACO;
    fscanf (arq, "%6*c%[^\n]s", &nome);
    printf("ID = [%d] Nome do video = '%s'\n", id, nome);
    if (id != nv)
      for ( j = 0 ; j < 10; )
      {

        fscanf (arq,"%c",&c);
        if ( c == '\n' )
          j++;

      }
  }

  fclose(arq);
  return 0;

}

void Fazer_Log ( int *idv, int e)
/*
De acordo com a verificação do arquivo,
essa função escreve no aruivo "log.txt" o motivo
que tal vídeo não pode ser regitrado, e também seu ID.
*/
{

  FILE *arqLog;

  arqLog = fopen("log.txt","a+");

  if ( e == 1 )
    fprintf(arqLog, "ERRO 1: Video com ID = [%d], algum campo vazio ou incorreto.\n", *idv);
  if ( e == 2 )
    fprintf(arqLog,"ERRO 2: Video com ID = [%d], numero solicitado foi colocado de forma incorreta, por exemplo numeros negativos.\n", *idv);
  if ( e == 3 )
    fprintf(arqLog,"ERRO 3: Video com ID = [%d], numero da duracao solicitado foi colocado de forma incorreta, fora do intervalo formalizado (Hora: [0,24],Minuto: [0,59]).\n", *idv);

  fclose(arqLog);
}

void Adicionar_Historico (FILE *arq, int idu, int idv)
/*
  Adiciona o vídeo que o usuário acessar nos dados dele.
*/
{

  int i, nh, jp;
  char c,h[MAX];
  FILE *arq2;

  arq = fopen ("usuarios.txt","r");
  arq2 = fopen ("usuarios2.txt","w");

  fscanf(arq,"%3*c%d", &jp);
  fprintf(arq2, "ID:%d", jp);

  for ( i = 1 ; i < idu ;  )
  {

    fscanf(arq, "%c", &c);
    fprintf(arq2,"%c", c);

    if ( c == ';' )
      i++;

  }

  if (idu==jp)
    for ( i = 0 ; i < 3; )
    {

      fscanf (arq,"%c", &c);
      fprintf(arq2,"%c", c);
      if ( c == '\n' )
        i++;

    }
  else
    for ( i = 0 ; i < 4; )
    {

      fscanf (arq,"%c", &c);
      fprintf(arq2,"%c", c);
      if ( c == '\n' )
        i++;

    }

  fscanf(arq, "%3*c%d", &nh);
  fscanf (arq,"%11*c%[^.]s", &h);

  if ( h[2*nh-2]-'0' != idv )
  {

    nh++;

    if (nh == 1)
      fprintf(arq2, "NH:%d\nHistorico:%d.",nh,idv );
    else
      fprintf(arq2, "NH:%d\nHistorico:%s,%d.",nh,h,idv );

  }
  else
    fprintf(arq2, "NH:%d\nHistorico:%s.",nh,h);


  fscanf(arq, "%*c");

  while ( fscanf ( arq, "%c", &c ) != EOF )
    fprintf(arq2, "%c", c);

  fclose(arq);
  fclose(arq2);

  remove("usuarios.txt");
  rename("usuarios2.txt","usuarios.txt");

}

void Add_Tipo_Dados(int t)
{
  int i, d;
  char c;
  FILE *arq, *arq2;

  arq = fopen ("dados.txt","r");
  arq2 = fopen ("dados2.txt","w");

  for ( i = 0 ; i < 5 ; i++ )
  {

    fscanf(arq,"%c",&c);
    fprintf(arq2, "%c", c);

  }

  for ( i=0 ; i<t-1 ;  )
  {
    fscanf(arq,"%c",&c);
    if (c=='\n')
    {
      i++;
    }
  }

  for ( i = 0 ; i < 3 ; i++ )
  {
    fscanf(arq,"%c",&c);
    fprintf(arq2, "%c", c);
  }
  fscanf(arq,"%d",&d);
  fprintf(arq2, "%d", d+1);

  for ( i=0 ; i<3 ;  )
  {
    fscanf(arq,"%c",&c);
    fprintf(arq2, "%c", c);
    if (c==(';'))
    {
      i++;
    }
  }
  fclose(arq);
  fclose(arq2);
  remove("dados.txt");
  rename("dados2.txt","dados.txt");

}

void Add_Novo_Genero (FILE *arq)
{

  char c,s[MAX],s2[MAX];
  int i, numGen;
  FILE *arq2;

  arq = fopen ("dados.txt","r");
  arq2 = fopen ("dados2.txt","w");

  printf("Digite o novo genero.\n - ");
  LER_ESPACO;
  scanf("%s", &s);
  if (Verificar_Nome(s)==0)
  {
    printf("Genero invalido, favor digitar um novo.\n");
    LER_ESPACO;
    scanf("%s", &s);
  }

  for ( i = 0 ; i < 1 ;  )
  {
    fscanf(arq,"%c", &c);
    fprintf(arq2, "%c", c);
    if ( c == ';' )
      i++;
  }
  for ( i = 0 ; i < 1 ;  )
  {
    fscanf(arq,"%c", &c);
    fprintf(arq2, "%c", c);
    if ( c == ':' )
      i++;
  }

  fscanf (arq,"%d",&numGen);
  fprintf(arq2, "%d", numGen+1);

  for ( i = 0 ; i < numGen+1 ;  )
  {
    fscanf(arq,"%c", &c);
    fprintf(arq2, "%c", c);
    if ( c == '\n' )
      i++;
  }

  fprintf(arq2, "%s-0\n", s);

  for ( i = 0 ; i < 2 ; i++ )
  {
    fscanf(arq,"%c", &c);
    fprintf(arq2, "%c", c);
    while ( c!=';' )
    {
      fscanf(arq,"%c", &c);
      fprintf(arq2, "%c", c);
    }
  }

  printf("Novo Genero [%s] adicionado com sucesso na lista.\n",s);

  fclose(arq);
  fclose(arq2);
  remove("dados.txt");
  rename("dados2.txt","dados.txt");
}

int Add_Genero_Listado (int posGen, int numGen)
/*
pgen = Posicao GENEROS
ngen = n de generos
*/
{
  int i, numTotGen;
  char c;
  FILE *arq, *arq2;
  arq = fopen ("dados.txt","r");
  arq2 = fopen ("dados2.txt","w");


  for ( i = 0 ; i < 1 ;  )
  {
    fscanf(arq,"%c", &c);
    fprintf(arq2, "%c", c);
    if ( c == ';' )
      i++;
  }
  for ( i = 0 ; i < 1 ;  )
  {
    fscanf(arq,"%c", &c);
    fprintf(arq2, "%c", c);
    if ( c == ':' )
      i++;
  }
  fscanf(arq,"%d", &numTotGen);
  fprintf(arq2, "%d", numTotGen);

  for ( i = 0 ; i < posGen ;  )
  {
    fscanf(arq,"%c", &c);
    fprintf(arq2, "%c", c);
    if ( c == '-' )
      i++;
  }
  fscanf(arq,"%*c");
  fprintf(arq2, "%d", numGen);
  for ( i = 0 ; i < 2 ;  )
  {
    fscanf(arq,"%c", &c);
    fprintf(arq2, "%c", c);
    if ( c == ';' )
      i++;
  }

  fclose(arq);
  fclose(arq2);
  remove("dados.txt");
  rename("dados2.txt","dados.txt");

}

int Add_Genero_Dados (int *idVid)
{
  int fl, fl2 ,i,j,d, numGenDad, numGenVid, numInsGen[MAX], vetTemp[MAX];
  char c, s[MAX];
  FILE *arq, *arq2;

  for (fl = 1, i = numGenVid = 0 ; fl != 0 ;  )
  {
    arq = fopen ("dados.txt","r");

    for ( i = 0 ; i < 1 ;  )
    {
      fscanf(arq,"%c", &c);
      if ( c == ';' )
        i++;
    }
    for ( i = 0 ; i < 1 ;  )
    {
      fscanf(arq,"%c", &c);
      if ( c == ':' )
        i++;
    }
    fscanf(arq,"%d", &numGenDad);
    printf("Digite:\n-1 - Se ja tiver adicionado todos os generos desejados, para sair desse menu.\n0 - Adicionar um genero nao listado abaixo na lista. (Ainda tem que colocar no filme posteriormente)\n");

    for ( j = 0 ; j<numGenDad ; j++ )
    {

      fscanf(arq,"%*c%[^-]s",&s);
      fscanf(arq,"%*c%d",&numInsGen[j]);
      printf("%d - Adicionar o genero [%s]\n", j+1, s);

    }

    printf(" - ");
    scanf("%d", &d);

    if (d>0)
    {
      if (d<=numGenDad)
      {
        for ( j = fl2 = 0 ; j < i ; j++ )
          if ( vetTemp[j] == d-1 )
            fl2++;
        if (fl2==0)
        {
          fclose(arq);
          vetTemp[i] = Add_Genero_Listado(d,numInsGen[d-1]+1);
          arq = fopen ("dados.txt","r");
          i++;
          numGenVid++;
          printf("Genero [%d] adiconado.\n", d);
          arq2 = fopen ("Dados_Temporarios2.txt","a+");
          fprintf(arq2, "%d\n", d-1);
          fclose(arq2);
        }
        else
          printf("Genero ja adicionado a este video. Por favor, escolha outra opcao.\n" );
        fl = 1;
      }
      else
        printf("Comando indisponivel, tente novamente.\n");
    }
    if ( d==0 )
    {

      fclose(arq);
      Add_Novo_Genero (arq);
      numGenDad++;
      arq = fopen ("dados.txt","r");
      fl = 1;

    }
    if (d==-1)
    {
      printf("Generos adicionados.\n");
      fl=0;
    }

    fclose(arq);
  }
  if ( numGenVid == 0)
  {
    printf("Erro ao processar video, favor acessar o arquivo 'log.txt'\n");
    Fazer_Log(idVid,2);
    return -5;
  }
  return d;
}

void Add_Novo_Diretor (FILE *arq)
{

  char c,s[MAX],s2[MAX];
  int i, numDir;
  FILE *arq2;

  arq = fopen ("dados.txt","r");
  arq2 = fopen ("dados2.txt","w");

  printf("Digite o nome do novo diretor.\n - ");
  LER_ESPACO;
  scanf("%s", &s);
  if (Verificar_Nome(s)==0)
  {
    printf("Nome invalido, favor digitar um novo.\n");
    LER_ESPACO;
    scanf("%s", &s);
  }

  for ( i = 0 ; i < 2 ;  )
  {
    fscanf(arq,"%c", &c);
    fprintf(arq2, "%c", c);
    if ( c == ';' )
      i++;
  }
  for ( i = 0 ; i < 1 ;  )
  {
    fscanf(arq,"%c", &c);
    fprintf(arq2, "%c", c);
    if ( c == ':' )
      i++;
  }

  fscanf (arq,"%d\n",&numDir);
  fprintf(arq2, "%d\n", numDir+1);

  for ( i = 0 ; i < numDir ; i++ )
  {
    fscanf(arq,"%c", &c);

    fprintf(arq2, "%c", c);
    while ( c!='\n' )
    {
      fscanf(arq,"%c", &c);
      fprintf(arq2, "%c", c);
    }
  }

  fprintf(arq2, "%s-0\n", s);

  for ( i = 0 ; i < 1 ;  )
  {
    fscanf(arq,"%c", &c);
    fprintf(arq2, "%c", c);
    if ( c == ';' )
      i++;
  }

  printf("Novo diretor [%s] adicionado com sucesso na lista.\n",s);

  fclose(arq);
  fclose(arq2);
  remove("dados.txt");
  rename("dados2.txt","dados.txt");
}

int Add_Diretor_Listado (int posDir, int numDir)
{
  int i, numTotDir;
  char c;
  FILE *arq, *arq2;
  arq = fopen ("dados.txt","r");
  arq2 = fopen ("dados2.txt","w");

  for ( i = 0 ; i < 2 ;  )
  {
    fscanf(arq,"%c", &c);
    fprintf(arq2, "%c", c);
    if ( c == ';' )
      i++;
  }
  for ( i = 0 ; i < 1 ;  )
  {
    fscanf(arq,"%c", &c);
    fprintf(arq2, "%c", c);
    if ( c == ':' )
      i++;
  }
  fscanf(arq,"%d", &numTotDir);
  fprintf(arq2, "%d", numTotDir);

  for ( i = 0 ; i < posDir ;  )
  {
    fscanf(arq,"%c", &c);
    fprintf(arq2, "%c", c);
    if ( c == '-' )
      i++;
  }
  fscanf(arq,"%*c");
  fprintf(arq2, "%d", numDir);
  for ( i = 0 ; i < 1 ;  )
  {
    fscanf(arq,"%c", &c);
    fprintf(arq2, "%c", c);
    if ( c == ';' )
      i++;
  }

  fclose(arq);
  fclose(arq2);
  remove("dados.txt");
  rename("dados2.txt","dados.txt");

}

int Add_Diretor_Dados (int *idVid)
{
  int fl, fl2 ,i,j,d, numDirDad, numDirVid, numInsDir[MAX], vetTemp[MAX];
  char c, s[MAX];
  FILE *arq, *arq2;

  for (fl = 1, i = numDirVid = 0 ; fl != 0 ;  )
  {
    arq = fopen ("dados.txt","r");

    for ( i = 0 ; i < 2 ;  )
    {
      fscanf(arq,"%c", &c);
      if ( c == ';' )
        i++;
    }
    for ( i = 0 ; i < 1 ;  )
    {
      fscanf(arq,"%c", &c);
      if ( c == ':' )
        i++;
    }
    fscanf(arq,"%d", &numDirDad);
    printf("Digite:\n-1 - Se ja tiver adicionado todos os diretores desejados, para sair desse menu.\n0 - Adicionar um diretor nao listado abaixo na lista. (Ainda tem que colocar no filme posteriormente)\n");

    for ( j = 0 ; j<numDirDad ; j++ )
    {

      fscanf(arq,"%*c%[^-]s",&s);
      fscanf(arq,"%*c%d",&numInsDir[j]);
      printf("%d - Adicionar o diretor [%s]\n", j+1, s);

    }

    printf(" - ");
    scanf("%d", &d);

    if (d>0)
    {
      if (d<=numDirDad)
      {
        for ( j = fl2 = 0 ; j < i ; j++ )
          if ( vetTemp[j] == d-1 )
            fl2++;
        if (fl2==0)
        {
          fclose(arq);
          vetTemp[i] = Add_Diretor_Listado(d,numInsDir[d-1]+1);
          arq = fopen ("dados.txt","r");
          i++;
          numDirVid++;
          printf("Diretor [%d] adiconado.\n", d);
          arq2 = fopen ("Dados_Temporarios.txt","a+");
          fprintf(arq2, "%d\n", d-1);
          fclose(arq2);
        }
        else
          printf("Diretor ja adicionado a este video. Por favor, escolha outra opcao.\n" );
        fl = 1;
      }
      else
        printf("Comando indisponivel. Por favor, escolha outra opcao..\n");
    }
    if ( d==0 )
    {

      fclose(arq);
      Add_Novo_Diretor (arq);
      numDirDad++;
      arq = fopen ("dados.txt","r");
      fl = 1;

    }
    if (d==-1)
    {
      printf("Diretores adicionados\n");
      fl=0;
    }

    fclose(arq);
  }

  if (numDirVid == 0)
  {
    printf("Erro ao processar video, favor acessar o arquivo 'log.txt'\n");
    Fazer_Log(idVid,2);
    return -5;
  }
  return d;
}

void Mostrar_Video (FILE *arq, int idv, int nv)
/*
  Vê as informações um vídeo registrado no arquivo "usuarios.txt" e printa no prompt de comando.
*/
{

  int t, h, m, nt, ng, ano, numDir, numGen;
  char nome[MAX], gen[MAX], dir[MAX];
  int i, fl, j;
  char c;


  arq = fopen ("videos.txt","r");

  for ( i = 0 ; i < idv-1 ;  )
  {

    fscanf(arq,"%c", &c);
    if ( c == ';' )
      i++;

  }

  for ( i = 0 ; i < 2 ;  )
  {

    fscanf(arq,"%c", &c);
    if ( c == ':' )
      i++;

  }

  fscanf(arq,"%[^\n]s", &nome);

  for ( i = 0 ; i < 1 ;  )
  {

    fscanf(arq,"%c", &c);
    if ( c == ':' )
      i++;

  }

  fscanf(arq,"%d", &t);

  if ( t == 1 )
  {
    for ( i = 0 ; i < 1 ;  )
    {

      fscanf(arq,"%c", &c);
      if ( c == ':' )
        i++;

    }
    fscanf(arq,"%d",&h);
    fscanf(arq,"%*c%d", &m);
    for ( i = 0 ; i < 2 ;  )
    {

      fscanf(arq,"%c", &c);
      if ( c == ':' )
        i++;

    }

  }
  if ( t == 2 )
  {
    for ( i = 0 ; i < 2 ;  )
    {

      fscanf(arq,"%c", &c);
      if ( c == ':' )
        i++;

    }
    fscanf(arq,"%d", &nt);
    for ( i = 0 ; i < 1 ;  )
    {

      fscanf(arq,"%c", &c);
      if ( c == ':' )
        i++;

    }
  }

  fscanf(arq,"%d", &ano);
  for ( i = 0 ; i < 1 ;  )
  {

    fscanf(arq,"%c", &c);
    if ( c == ':' )
      i++;

  }
  fscanf(arq,"%d%*c", &numDir);
  for ( i = 0 ; i < 1 ;  )
  {

    fscanf(arq,"%c", &c);
    if ( c == ':' )
      i++;

  }
  fscanf(arq,"%[^\n]s%*c", &dir);
  for ( i = 0 ; i < 1 ;  )
  {

    fscanf(arq,"%c", &c);
    if ( c == ':' )
      i++;

  }
  fscanf(arq,"%d%*c", &numGen);
  for ( i = 0 ; i < 1 ;  )
  {

    fscanf(arq,"%c", &c);
    if ( c == ':' )
      i++;

  }
  fscanf(arq,"%[^\n]s%*c", &gen);
  fclose (arq);

  printf("ID: [%d]\nNome: '%s'\n", idv, nome);

  if ( t == 1 )
    printf("Duracao: %d horas e %d minutos.\n", h, m);

  if ( t == 2 )
    printf("Temporadas: %d\n", nt);

  printf("Ano de lancamento: %d\n", ano);

  printf("Diretor(es): %s\n", dir);
  printf("Genero(s): %s\n", gen);

}

int Editar_Video (FILE *arqVid, int *idv, int nv)
/*
  Edita os dados de um vídeo registrado no arquivo "usuarios.txt".
*/
{

  int i,t,h,m,ano,nt,ng, numDir, numDir2, numGen2, dir, gen;
  char nome[MAX], c;
  FILE *arqVid2, *arqDad, *arqTem;

  printf("Digite o nome completo do video.\n - ");
  LER_ESPACO;
  scanf("%[^\n]s", &nome);

  printf("Digite:\n 1 - Se o video for um filme.\n 2 - Se o video for uma serie\n - ");
  LER_ESPACO;
  scanf("%d", &t);

  if ( t == 1 )
  {

    printf("Digite a duracao no formato 'hh mm', no intervalo :\nHora: [0,24]\nMinuto: [0,59]\n - ");
    LER_ESPACO;
    scanf("%d %d", &h, &m);

  }

  if ( t == 2 )
  {

    printf("Digite a quantidade de temporadas.\n - ");
    scanf("%d", &nt);

  }

  printf("Digite o ano de lancamento.\n - ");
  scanf("%d", &ano);

  i = Verificar_Video ( t, h, m, ano, nt, nome );

  if ( i == 0 )
  {

    arqVid = fopen ("videos.txt","r");
    arqVid2 = fopen ("videos2.txt","w");

    for ( i = 0 ; i < *idv ;  )
    {

      fscanf(arqVid,"%c",&c);
      fprintf(arqVid2, "%c", c);
      if ( c == ';' )
        i++;

    }

    fprintf(arqVid2, "\nID:%d\nNome:%s\nTipo:%d\n", *idv, nome, t);

    for ( i = 0 ; i < 4 ;  )
    {

      fscanf(arqVid,"%c",&c);
      if ( c == '\n' )
        i++;

    }

    if (t == 1)
    {

      printf("Duracao: %d horas e %d minutos.\n", h, m);
      fprintf(arqVid2, "Duracao:%d,%d\nTemporadas:0\n", h, m);

    }

    if (t == 2)
    {

      printf("Temporadas:%d\n", nt);
      fprintf(arqVid2, "Duracao:0,0\nTemporadas:%d\n", nt );

    }

    for ( i = 0 ; i < 2 ;  )
    {

      fscanf(arqVid,"%c",&c);
      if ( c == '\n' )
        i++;

    }

    printf("Ano de lancamento: %d\n", ano);
    fprintf(arqVid2, "ano.lanc:%d\n", ano);


    numDir = Add_Diretor_Dados(idv);
    if (numDir == -5)
      return 0;
    ng = Add_Genero_Dados (idv);
    if (ng == -5)
      return 0;
    printf("Video registrado. Seguem as informacoes do video\nID: [%d]\nNome: '%s'\n", *idv, nome);
    fprintf(arqVid2, "ID:%d\nNome:%s\nTipo:%d\n", *idv, nome, t);
    Add_Tipo_Dados(t);

    if (t == 1)
    {

      printf("Duracao: %d horas e %d minutos.\n", h, m);
      fprintf(arqVid2, "Duracao:%d,%d\nTemporadas:0\n", h, m);

    }

    if (t == 2)
    {

      printf("Temporadas:%d\n", nt);
      fprintf(arqVid2, "Duracao:0,0\nTemporadas:%d\n", nt );

    }


    fprintf(arqVid2, "nd:%d\nDiretor:", numDir);
    printf("Diretor:");
    arqTem = fopen ("Dados_Temporarios.txt","r");
    while (numDir>0)
    {
      fscanf(arqTem,"%d", &dir);
      fprintf(arqVid2,"%d", dir);
      printf("%d", dir+1);
      numDir--;
      if (numDir>0)
      {
        fprintf(arqVid2,",");
        printf(",");
      }
    }
    fprintf(arqVid2,".\n");
    printf(".\n");
    fclose(arqTem);
    remove("Dados_Temporarios.txt");

    printf("Ano de lancamento: %d\n", ano);
    fprintf(arqVid2, "ano.lanc:%d\n", ano);

    fprintf(arqVid2, "ng:%d\nGeneros:", ng);
    printf("Generos:");
    arqTem = fopen ("Dados_Temporarios2.txt","r");
    while (ng>0)
    {
      fscanf(arqTem,"%d", &gen);
      fprintf(arqVid2,"%d", gen);
      printf("%d", gen+1);
      ng--;
      if (ng>0)
      {
        fprintf(arqVid2,",");
        printf(",");
      }
    }
    fprintf(arqVid2,".\n;\n");
    printf(".\n");
    fclose(arqTem);
    remove("Dados_Temporarios2.txt");

    printf("Video Editado com sucesso. Seguem as informacoes do video\n");
    printf("ID: [%d]\nNome: '%s'\n", *idv, nome);

    fclose(arqVid);
    fclose(arqVid2);

    remove("videos.txt");
    rename("videos2.txt","videos.txt");

    return 0;

  }
  else
  {

    printf("Erro ao editar video, favor acessar o arquivo 'log.txt'\n");

    Fazer_Log(idv,i);

  }

}

int Procurar_Video (FILE *arq,int *nv,int *idv, int idu)
/*
  Lista os video registrados no arquivo "videos.txt",
  pergunta ao usuário qual vídeo ele deseja acessar,
  adiciona esse vídeo no histórico do usuário, e
  após acessar as informações desse vídeo,
  pergunta ao usuário se ele deseja editar ou excluir aquele video.
*/
{

  int i, fl;

  if (*nv == 0)
  {
    printf("Nenhum video registrado, retornando ao Menu Principal.\n");
    return 0;
  }

  Listar_Videos (arq);
  printf("Digite o ID do video para consulta.\n - ");
  scanf("%d", idv);

  Adicionar_Historico(arq,idu,*idv);

  Mostrar_Video(arq,*idv, *nv);

  printf("Digite:\n 1 - Editar informacoes do video selecionado.\n 2 - Deletar o video selecionado.\n 3 - Voltar para o menu principal.\n - ");
  scanf("%d", &i);

  switch (i)
  {

    case 1:
      Editar_Video (arq, idv, *nv);
      return 0;
    break;
    case 2:
      Deletar_Video ( arq, *idv, nv );
      return 0;
    break;
    case 3:
      return 0; //menu principal
    break;

  }

}

int Reg_Video (FILE *arq, int *nv, int *idv, int idu)
/*
  Registra um vídeo no arquivo "videos.txt".
*/
{

  int i, t, h, m, ng, ano, nt, genero, numDir, diretor;
  char nome[MAX];
  FILE *arq2;

  h = m = ng = 0;
  *nv = *nv + 1;
  *idv = *nv;
  arq = fopen("videos.txt","a+");

  printf("Para registrar um novo video, digite o nome completo dele.\n - ");
  LER_ESPACO;
  scanf("%[^\n]s", &nome);

  printf("Digite:\n 1 - Se o video for um filme.\n 2 - Se o video for uma serie\n - ");
  LER_ESPACO;
  scanf("%d", &t);
  if ( t == 1 )
  {

    printf("Digite a duracao no formato 'hh mm', no intervalo :\nHora: [0,24]\nMinuto: [0,59]\n - ");
    LER_ESPACO;
    scanf("%d %d", &h, &m);

  }
  if ( t == 2 )
  {

    printf("Digite a quantidade de temporadas.\n - ");
    scanf("%d", &nt);

  }

  printf("Digite o ano de lancamento.\n - ");
  scanf("%d", &ano);


  i = Verificar_Video (t, h, m, ano, nt, nome);
  if ( i != 0 )
  {

    fclose(arq);
    printf("Erro ao cadastrar video, favor acessar o arquivo 'log.txt'\n");
    Fazer_Log(idv,i);
    return 0;

  }

  numDir = Add_Diretor_Dados(idv);

  ng = Add_Genero_Dados (idv);

  printf("Video registrado. Seguem as informacoes do video\nID: [%d]\nNome: '%s'\n", *idv, nome);
  fprintf(arq, "ID:%d\nNome:%s\nTipo:%d\n", *idv, nome, t);
  Add_Tipo_Dados(t);

  if (t == 1)
  {

    printf("Duracao: %d horas e %d minutos.\n", h, m);
    fprintf(arq, "Duracao:%d,%d\nTemporadas:0\n", h, m);

  }

  if (t == 2)
  {

    printf("Temporadas:%d\n", nt);
    fprintf(arq, "Duracao:0,0\nTemporadas:%d\n", nt );

  }


  fprintf(arq, "nd:%d\nDiretor:", numDir);
  printf("Diretor:");
  arq2 = fopen ("Dados_Temporarios.txt","r");
  while (numDir>0)
  {
    fscanf(arq2,"%d", &diretor);
    fprintf(arq,"%d", diretor);
    printf("%d", diretor+1);
    numDir--;
    if (numDir>0)
    {
      fprintf(arq,",");
      printf(",");
    }
  }
  fprintf(arq,".\n");
  printf(".\n");
  fclose(arq2);
  remove("Dados_Temporarios.txt");

  printf("Ano de lancamento: %d\n", ano);
  fprintf(arq, "ano.lanc:%d\n", ano);

  fprintf(arq, "ng:%d\nGeneros:", ng);
  printf("Generos:");
  arq2 = fopen ("Dados_Temporarios2.txt","r");
  while (ng>0)
  {
    fscanf(arq2,"%d", &genero);
    fprintf(arq,"%d", genero);
    printf("%d", genero+1);
    ng--;
    if (ng>0)
    {
      fprintf(arq,",");
      printf(",");
    }
  }
  fprintf(arq,".\n;\n");
  printf(".\n");
  fclose(arq2);
  remove("Dados_Temporarios2.txt");
  fclose(arq);
  return 0;

}

void Gerar_Relatorio_Simples(int numUsu, int numVid)
{

  srand(time(NULL));
  int i, numHis, ran;
  char c, nomRel[MAX];
  FILE *arqUsu, *arqVid, *arqRel, *arqTem;

  ran = rand();

  arqTem = fopen("arqTem.txt","w");
  fprintf(arqTem,"relatorio_simples_%4d.txt", ran);
  fclose (arqTem);
  arqTem = fopen("arqTem.txt","r");
  fscanf(arqTem,"%s", &nomRel);
  fclose (arqTem);
  remove("arqTem.txt");

  arqUsu = fopen ("usuarios.txt","r");
  arqVid = fopen ("videos.txt","r");
  arqRel = fopen (nomRel,"w");

  fprintf(arqRel, "Informacoes a respeitos dos usuarios:\n");
  for ( i = 0; i < numUsu-1 ;  )
  {
    fscanf(arqUsu,"%c",&c);
    fprintf(arqRel,"%c", c);
    if ( c == ';' )
      i++;
  }
  fprintf(arqRel, "\n\nInformacoes a respeitos dos videos:\n");
  for ( i = 0; i < numVid ;  )
  {
    fscanf(arqVid,"%c",&c);
    fprintf(arqRel,"%c", c);
    if ( c == ';' )
      i++;
  }

  printf("Arquivo criado com o nome '%s'\n", nomRel);

  fclose(arqUsu);
  fclose(arqVid);
  fclose(arqRel);
}

void Gerar_Relatorio_Estatisticas(int numUsu)
{

  srand(time(NULL));
  int i,j, numHis, ran, numVid;
  char c, nomRel[MAX];
  FILE *arqUsu, *arqDad, *arqRel, *arqTem;

  ran = rand();

  arqTem = fopen("arqTem.txt","w");
  fprintf(arqTem,"relatorio_estatisticas_%4d.txt", ran);
  fclose (arqTem);
  arqTem = fopen("arqTem.txt","r");
  fscanf(arqTem,"%s", &nomRel);
  fclose (arqTem);
  remove("arqTem.txt");

  arqUsu = fopen ("usuarios.txt","r");
  arqDad = fopen ("dados.txt","r");
  arqRel = fopen (nomRel,"w");

  fprintf(arqRel, "Quantidade de videos dos tipos:\nFilme:");
  for ( i = 0 ; i < 1 ;  )
  {
    fscanf(arqDad,"%c",&c);
    if ( c == '-' )
      i++;
  }
  fscanf(arqDad,"%d",&i);
  fprintf(arqRel,"%d",i);

  fprintf(arqRel, "\nSerie:");
  for ( i = 0 ; i < 1 ;  )
  {
    fscanf(arqDad,"%c",&c);
    if ( c == '-' )
      i++;
  }
  fscanf(arqDad,"%d",&i);
  fprintf(arqRel,"%d",i);

  fprintf(arqRel, "\nQuantidade de videos para cada genero:\n");
  for ( i = 0 ; i < 1 ;  )
  {
    fscanf(arqDad,"%c",&c);
    if ( c == ':' )
      i++;
  }
  fscanf(arqDad,"%d%*c",&ran);
  for ( i = 0 ; i < ran ;  )
  {
    fscanf(arqDad,"%c",&c);
    fprintf(arqRel,"%c",c);
    if ( c == '\n' )
      i++;
  }

  fprintf(arqRel, "Quantidade de vídeos assistidos por cada cliente:\n");

  for ( i = 0 ; i < numUsu-1 ; i++ )
  {
    fscanf(arqUsu,"%*3c%d%*c",&numVid);
    fprintf(arqRel, "ID %d:", numVid);
    for ( j = 0 ; j < 2 ;  )
    {
      fscanf(arqUsu,"%c",&c);
      if ( c == '\n' )
        j++;
    }
    fscanf(arqUsu,"%*3c%d%*c",&numVid);
    fprintf(arqRel, "%d video(s).\n", numVid);
    for ( j = 0 ; j < 2 ;  )
    {
      fscanf(arqUsu,"%c",&c);
      if ( c == '\n' )
        j++;
    }
  }

  printf("Arquivo criado com o nome '%s'\n", nomRel);

  fclose(arqUsu);
  fclose(arqDad);
  fclose(arqRel);

}

void Gerar_Relatorio_Metadados(int numUsu)
{
  srand(time(NULL));
  int i,j,k, numHis, ran, numVid, tip[2], numDir, numFilAssUsu[numUsu], fila[MAX];
  char c, nomRel[MAX];
  FILE *arqUsu, *arqDad, *arqRel, *arqTem;

  ran = rand();

  arqTem = fopen("arqTem.txt","w");
  fprintf(arqTem,"relatorio_metadados_%4d.txt", ran);
  fclose (arqTem);
  arqTem = fopen("arqTem.txt","r");
  fscanf(arqTem,"%s", &nomRel);
  fclose (arqTem);
  remove("arqTem.txt");

  arqDad = fopen ("dados.txt","r");
  arqRel = fopen (nomRel,"w");

  fprintf(arqRel, "Tipo de vídeo mais comum no cadastro: ");
  for ( i = 0 ; i < 1 ;  )
  {
    fscanf(arqDad,"%c",&c);
    if ( c == '\n' )
      i++;
  }
  fscanf(arqDad,"%*2c");
  fscanf(arqDad,"%d%*c",&tip[0]);
  fscanf(arqDad,"%*2c");
  fscanf(arqDad,"%d%*c",&tip[1]);
  if (tip[0]>tip[1])
    fprintf(arqRel, "Filme\n");
  else
  if (tip[0]<tip[1])
    fprintf(arqRel, "Serie\n");
  else
    fprintf(arqRel, "Mesmo numero de filmes e series cadastrados.\n");

  for ( i = 0 ; i < 2 ;  )
  {
    fscanf(arqDad,"%c",&c);
    if ( c == ';' )
      i++;
  }
  fscanf(arqDad,"%*9c%d%*c",&numDir);
  int dir[numDir];
  for (i = 0; i < numDir ; i++ )
  {
    for ( j = 0 ; j < 1 ;  )
    {
      fscanf(arqDad,"%c",&c);
      if ( c == '-' )
        j++;
    }
    fscanf(arqDad,"%d%*c",&dir[i]);
    fila[i] = i;
  }

  int l, fl, aux;
  for ( fl = 1 ; fl > 0 ;  )
  {
    fl = 0;
    for ( l = 0 ; l < numDir-1 ; l++ )
    {
      if (dir[l]<dir[l+1])
      {
        aux = dir[l];
        dir[l] = dir[l+1];
        dir[l+1] = aux;
        aux = fila[l];
        fila[l] = fila[l+1];
        fila[l+1] = aux;
        fl=1;
      }
    }
  }
  for ( l = 0 ; dir[l]==dir[l+1] ; l++, fl++)
  {}

  i = fl;
  fprintf(arqRel,"Nome do diretor mais frequente no cadastro:\n");
  if ( i == 0 )
  {
    fclose(arqDad);
    arqDad = fopen ("dados.txt","r");
    for ( j = 0 ; j < 2 ;  )
    {
      fscanf(arqDad,"%c",&c);
      if ( c == ';' )
        j++;
    }
    for ( j = 0 ; j < fila[0]+2 ;  )
    {
      fscanf(arqDad,"%c",&c);
      if ( c == '\n' )
        j++;
    }
    for ( j = 0 ; j < 1 ;  )
    {
      fscanf(arqDad,"%c",&c);
      if ( c == '-' )
        break;
      fprintf(arqRel,"%c", c);
    }

  }
  else
  {
    fclose(arqDad);
    arqDad = fopen ("dados.txt","r");
    for ( j = 0 ; j < 2 ;  )
    {
      fscanf(arqDad,"%c",&c);
      if ( c == ';' )
        j++;
    }
    for ( j = 0 ; j < 2 ;  )
    {
      fscanf(arqDad,"%c",&c);
      if ( c == '\n' )
        j++;
    }
    for ( k = 0 ; k < i+1 ; k++ )
    {
      for ( j = 0 ; j < fila[k] ;  )
      {
        fscanf(arqDad,"%c",&c);
        if ( c == '\n' )
          j++;
      }
      for ( j = 0 ; j < 1 ;  )
      {
        fscanf(arqDad,"%c",&c);
        if ( c == '-' )
        {
          fprintf(arqRel, "\n");
          break;
        }
        fprintf(arqRel,"%c", c);
      }
    }
  }
  fprintf(arqRel, "\n");


  arqUsu = fopen ("usuarios.txt","r");
  for (i = 0; i < numUsu-1 ; i++ )
  {
    for ( j = 0 ; j < 3 ;  )
    {
      fscanf(arqUsu,"%c",&c);
      if ( c == '\n' )
        j++;
    }
    fscanf(arqUsu,"%*3c");
    fscanf(arqUsu,"%d",&numFilAssUsu[i]);

    for ( j = 0 ; j < 1 ;  )
    {
      fscanf(arqUsu,"%c",&c);
      if ( c == ';' )
        j++;
    }
    fscanf(arqUsu,"%*c");
    fila[i] = i;
  }


  for ( aux = 0, fl = 1 ; fl > 0 ;  )
  {
    fl = 0;
    for ( l = 0 ; l < numUsu-2 ; l++ )
    {
      if (numFilAssUsu[l]<numFilAssUsu[l+1])
      {
        aux = numFilAssUsu[l];
        numFilAssUsu[l] = numFilAssUsu[l+1];
        numFilAssUsu[l+1] = aux;

        aux = fila[l];
        fila[l] = fila[l+1];
        fila[l+1] = aux;

        fl=1;
      }
    }
  }
  for ( l = 0 ; numFilAssUsu[l]==numFilAssUsu[l+1] ; l++, fl++)
  {}

  i = fl;
  printf("i = %d\n", i);
  fprintf(arqRel, "ID, nome e idade do cliente que assistiu mais vídeos:\n");
  if ( i == 0 )
  {
    fclose(arqUsu);
    arqUsu = fopen ("usuarios.txt","r");
    for ( j = -1 ; j < fila[0]+2 ;  )
    {
      fscanf(arqUsu,"%c",&c);
      fprintf(arqRel,"%c", c);
      if ( c == '\n' )
        j++;
    }
  }
  else
  {
    for ( k = 0 ; k < i+1 ; k++ )
    {
      fclose(arqUsu);
      arqUsu = fopen ("usuarios.txt","r");
      for ( j = 0 ; j < fila[k] ;  )
      {
        fscanf(arqUsu,"%c",&c);
        if ( c == ';' )
          j++;
      }
      fscanf(arqUsu,"%*c");
      for ( j = 0 ; j < 3 ;  )
      {
        fscanf(arqUsu,"%c",&c);
        fprintf(arqRel,"%c", c);
        if ( c == '\n' )
          j++;
      }
    }
    fprintf(arqRel,"\n", c);
  }

  printf("Arquivo criado com o nome '%s'\n", nomRel);

  fclose(arqUsu);
  fclose(arqDad);
  fclose(arqRel);

}

void Gerar_Relatorio(int numUsu, int numVid)
{
  int i;
  printf("\nBem vindo ao menu de geracao de relatorios. Digite:\n1 - Gerar relatorio simples.\n2 - Gerar relatorio de estatisticas.\n3 - Gerar relatorio de metadados.\n4 - Retornar ao menu principal.\n - ");
  scanf("%d", &i);

  switch (i)
  {

    case 1:
      Gerar_Relatorio_Simples(numUsu,numVid);
      Gerar_Relatorio(numUsu,numVid);
    break;
    case 2:
      Gerar_Relatorio_Estatisticas(numUsu);
      Gerar_Relatorio(numUsu,numVid);
    break;
    case 3:
      Gerar_Relatorio_Metadados(numUsu);
      Gerar_Relatorio(numUsu,numVid);
    break;
    case 4:
    break;

  }
}

int Menu_Principal( int *nu, int *nv, int idu, int *idv)
/*
MENU PRINCIPAL
1 - Ver informacoes (editar)
2 - procurar video (editar/excluir)
3 - adicionar video
4 - listar videos
5 - logout
6 - Finalizar do programa
*/
{

  int i, fl;
  FILE *arq;

  printf("\nBem vindo ao menu principal. Digite:\n1 - Ver informacoes de usuario.\n2 - Procurar video.\n3 - Adicionar video.\n4 - Listar videos.\n5 - Fazer Log Out.\n6 - Gerar relatorio.\n7 - Finalizar do programa.\n - ");
  scanf("%d", &i);

  Ler_NV (arq, nv);

  switch (i)
  {

    case 1:
      fl = Ver_Usuario(arq, idu);
      if (fl == 0)
        Menu_Principal(nu,nv,idu,idv);
    break;
    case 2:
      fl = Procurar_Video(arq, nv, idv, idu);
      if (fl == 0)
        Menu_Principal(nu,nv,idu,idv);
    break;
    case 3:
      fl = Reg_Video(arq,nv, idv, idu);
      if (fl == 0)
        Menu_Principal(nu,nv,idu,idv);
    break;
    case 4:
      fl = Listar_Videos(arq);
      if (fl == 0)
        Menu_Principal(nu,nv,idu,idv);
    break;
    case 5:
      return 2;
    break;
    case 6:
      Gerar_Relatorio(*nu,*nv);
      Menu_Principal(nu,nv,idu,idv);
    break;
    case 7:
      return 0;
    break;

  }

}

int main ()
/*
  Função Main do código. Comanda o Menu Inicial e o Menu Principal.
*/
{

  int nu, nv, idu, idv, jp;

  printf("\nSeja bem vindo ao WikiFilmes.\n");

  idu = Menu_Inicial(&nu);
  if (idu == 0)
    return 0;

  jp = Menu_Principal(&nu,&nv,idu,&idv);
  if ( jp == 2 )
    main();

  return 0;

}
