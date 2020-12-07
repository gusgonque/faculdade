#include <stdio.h>
#include <string.h>
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

int Verificar_Video ( int t, int h, int m, int ano, int nt, char nome[], char diretor[])
/*
Verifica se is informações inseridas são possiveis, em relação do vídeo registrado.
*/
{

  if ( (Verificar_Nome (nome)&&Verificar_Nome(diretor)) == 0 )
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
      for ( j = 0 ; j < 9; )
      {

        fscanf (arq,"%c",&c);
        if ( c == '\n' )
          j++;

      }
  }

  fclose(arq);
  return 0;

}

void Fazer_Log (FILE *arq, int *idv, int e)
/*
De acordo com a verificação do arquivo,
essa função escreve no aruivo "log.txt" o motivo
que tal vídeo não pode ser regitrado, e também seu ID.
*/
{

  FILE *arq2;

  arq2 = fopen("log.txt","a+");

  if ( e == 1 )
    fprintf(arq2, "ERRO 1: Video com ID = [%d], algum campo vazio ou incorreto.\n", *idv);
  if ( e == 2 )
    fprintf(arq2,"ERRO 2: Video com ID = [%d], numero solicitado foi colocado de forma incorreta, por exemplo numeros negativos.\n", *idv);
  if ( e == 3 )
    fprintf(arq2,"ERRO 3: Video com ID = [%d], numero da duracao solicitado foi colocado de forma incorreta, fora do intervalo formalizado (Hora: [0,24],Minuto: [0,59]).\n", *idv);

}

int Editar_Video (FILE *arq, int *idv, int nv)
/*
  Edita os dados de um vídeo registrado no arquivo "usuarios.txt".
*/
{

  int i,t,h,m,ano,nt,ng;
  char nome[MAX], diretor[MAX]/*, generos[MAX]*/, c;
  FILE *arq2;

  //Escaneando
  printf("Digite o nome completo do video.\n - ");
  LER_ESPACO;
  scanf("%[^\n]s", &nome);

  printf("Digite:\n 1 - Se o video for um filme.\n 2 - Se o video for uma serie\n - ");
  LER_ESPACO;
  scanf("%d", &t);

  printf("Digite o nome do diretor do video.\n - ");
  LER_ESPACO;
  scanf("%[^\n]s", &diretor);

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

  //printf("Digite os generos do video, separando cada um por virgula, por exemplo 'acao,aventura'.\n - ");
  //LER_ESPACO;
  //scanf("%[^\n]s", &generos);

  //printando no arquivo
  i = Verificar_Video ( t, h, m, ano, nt, nome, diretor );

  if ( i == 0 )
  {

    printf("Video Editado com sucesso. Seguem as informacoes do video\n");
    printf("ID: [%d]\nNome: '%s'\nDiretor: '%s'\n", *idv, nome, diretor);

    arq = fopen ("videos.txt","r");
    arq2 = fopen ("videos2.txt","w");

    for ( i = 1 ; i < *idv ;  )
    {

      fscanf(arq,"%c",&c);
      fprintf(arq2, "%c", c);
      if ( c == ';' )
        i++;

    }

    fprintf(arq2, "\nID:%d\nNome:%s\nTipo:%d\nDiretor:%s\n", *idv, nome, t, diretor);

    for ( i = 0 ; i < 4 ;  )
    {

      fscanf(arq,"%c",&c);
      if ( c == '\n' )
        i++;

    }

    if (t == 1)
    {

      printf("Duracao: %d horas e %d minutos.\n", h, m);
      fprintf(arq2, "Duracao:%d,%d\nTemporadas:0\n", h, m);

    }

    if (t == 2)
    {

      printf("Temporadas:%d\n", nt);
      fprintf(arq2, "Duracao:0,0\nTemporadas:%d\n", nt );

    }

    for ( i = 0 ; i < 2 ;  )
    {

      fscanf(arq,"%c",&c);
      if ( c == '\n' )
        i++;

    }

    printf("Ano de lancamento: %d\n", ano);
    fprintf(arq2, "ano.lanc:%d\n", ano);
    for ( i = 0 ; i < 1 ;  )
    {

      fscanf(arq,"%c",&c);
      if ( c == '\n' )
        i++;

    }
    /*
    for ( i = 0, ng = 1 ; generos[i] ; i++ )

      if ( generos[i] == ',')
         ng++;

    if ( generos [i-1] == '.')
    {

      printf("Generos: %s\n", generos);
      fprintf(arq2, "ng:%d\nGeneros:%s\n", ng, generos);

    }
    else
    {

      printf("Generos:%s.\n", generos);
      fprintf(arq2, "ng:%d\nGeneros:%s.\n", ng, generos);

    }
    */
    for ( i = 0 ; i < 3 ;  )
    {

      fscanf(arq,"%c",&c);
      if ( c == '\n' )
        i++;

    }

    for ( i = *idv ; i < nv ;  )
    {

      fscanf(arq,"%c",&c);
      if ( c == ';' )
        i++;

      fprintf(arq2, "%c", c);

    }

    fclose(arq);
    fclose(arq2);

    remove("videos.txt");
    rename("videos2.txt","videos.txt");

    return 0;

  }
  else
  {

    printf("Erro ao editar video, favor acessar o arquivo 'log.txt'\n");

    Fazer_Log(arq,idv,i);

  }

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

void Mostrar_Video (FILE *arq, int idv, int nv)
/*
  Vê as informações um vídeo registrado no arquivo "usuarios.txt" e printa no prompt de comando.
*/
{

  int t, h, m, nt, ng, ano;
  char nome[MAX], diretor[MAX], generos[MAX];
  int i, fl, jp;
  char c = '0', k;


  arq = fopen ("videos.txt","r");

  for ( i = 1 ; i < idv ;  )
  {

    fscanf(arq,"%c", &c);
    if ( c == ';' )
      i++;

  }

  fscanf(arq,"%*c");

  while ( c != '\n'  )
    fscanf(arq,"%c", &c);

  LER_ESPACO;
  fscanf(arq,"%5*c%[^\n]s", &nome);

  while ( c != ':' )
    fscanf(arq,"%c", &c);

  fscanf(arq,"%d", &t);

  LER_ESPACO;
  fscanf(arq,"%9*c%[^\n]s", &diretor);

  if ( t == 1 )
  {

    fscanf(arq,"%9*c%d",&h);
    fscanf(arq,"%*c%d", &m);
    for ( i = 0 ; i < 2 ;  )
    {

      fscanf(arq,"%c",&c);
      if ( c == '\n' )
        i++;

    }

  }
  if ( t == 2 )
    fscanf(arq,"%24*c%d", &nt);

  fscanf(arq,"%9*c%d", &ano);
  fscanf(arq,"%3*c%d", &ng);
  fscanf(arq,"%11*c");

  LER_ESPACO;
  fscanf(arq,"%[^.]s", &generos);

  fclose (arq);

  printf("ID: [%d]\nNome: '%s'\nDiretor: '%s'\n", idv, nome, diretor);

  if ( t == 1 )
    printf("Duracao: %d horas e %d minutos.\n", h, m);

  if ( t == 2 )
    printf("Temporadas: %d\n", nt);

  printf("Ano de lancamento: %d\n", ano);

  if ( generos [i-1] == '.' )
    printf("Generos: %s\n", generos);

  else
    printf("Generos:%s.\n", generos);

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

  for ( i=0 ; i<4 ;  )
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

  char c,s[MAX];
  int i,ng;
  FILE *arq2;

  arq = fopen ("dados.txt","r");
  arq2 = fopen ("dados2.txt","w");

  printf("Digite o novo genero.\n - ");
  gets(s);
  if (Verificar_Nome(s)==0)
  {
    printf("Genero invalido, favor digitar um novo.\n");
    gets(s);
  }

  c='0';
  while ( c!=';' )
  {
    fscanf(arq,"%c", &c);
    fprintf(arq2, "%c", c);
  }
  while ( c!=':' )
  {
    fscanf(arq,"%c", &c);
    fprintf(arq2, "%c", c);
  }
  fscanf(arq,"%d", &ng);
  fprintf(arq2, "%d\n", ng);
  for ( i = 0 ; i < ng ; i++ )
  {
    while ( c!='\n' )
    {
      fscanf(arq,"%c", &c);
      fprintf(arq2, "%c", c);
    }
  }
  fprintf(arq2, "%s-1\n", s);
  for ( i = 0 ; i < 3 ; i++ )
  {
    while ( c!=';' )
    {
      fscanf(arq,"%c", &c);
      fprintf(arq2, "%c", c);
    }
  }
  fclose(arq);
  fclose(arq2);
  remove("dados.txt");
  rename("dados2.txt","dados.txt");
}

void Add_Genero_Dados (int gv[], int *ngv)
{
  int fl, fl2 ,i,j, d, ng, gd[MAX];
  char c, s[MAX];
  FILE *arq;

  for (fl = 1, i = *ngv = 0 ; fl != 0 ;  )
  {
    arq = fopen ("dados.txt","r");

    for ( j=0 ; j<1 ;  )
    {
      fscanf(arq,"%c",&c);
      if (c==(';'))
      {
        j++;
      }
    }

    fscanf(arq,"%*9c%d",&ng);

    printf("Digite:\n-1 - Se ja tiver adicionado todos os generos desejados, para sair desse menu.\n0 - Adicionar um genero nao listado abaixo.\nOu para adicionar um dos seguintes generos:\n");

    for ( j = 0 ; j<ng ; j++ )
    {

      fscanf(arq,"%*c%[^-]s",&s);
      fscanf(arq,"%*c%d",&d);
      printf("%d - %s\n", j+1, s);

    }

    printf(" - ");
    scanf("%d", &d);

    if (d>0)
    {

      for ( j = fl2 = 0 ; j < ng ; j++ )
      {
        if (gv[j]==d-1)
        {
          fl2++;
        }
      }
      if (fl2==0)
      {
        gd[d-1]++;
        gv[i] = d-1;
        i++;
        *ngv++;
        printf("Genero [%d] adiconado.\n", d);
      }
      else
        printf("Genero ja adicionado a este video. Por favor, escolha outra opcao.\n" );

      fl = 1;

    }
    if (d==0)
    {

      fclose(arq);
      Add_Novo_Genero (arq);
      *ngv++;
      arq = fopen ("dados.txt","r");

    }
    if (d==-1)
    {
      fl=0;
    }

    fclose(arq);
  }

}

int Reg_Video (FILE *arq, int *nv, int *idv, int idu)
/*
  Registra um vídeo no arquivo "videos.txt".
*/
{

  int i, t, h, m, ng, ano, nt, generos[MAX];
  char nome[MAX], diretor[MAX];

  h = m = 0;
  *nv = *nv + 1;
  *idv = *nv;
  arq = fopen("videos.txt","a+");

  printf("Para registrar um novo video, digite o nome completo dele.\n - ");
  LER_ESPACO;
  scanf("%[^\n]s", &nome);

  printf("Digite:\n 1 - Se o video for um filme.\n 2 - Se o video for uma serie\n - ");
  LER_ESPACO;
  scanf("%d", &t);

  printf("Digite o nome do diretor de seu video.\n - ");
  LER_ESPACO;
  scanf("%[^\n]s", &diretor);

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

  Add_Genero_Dados (generos,&ng);

  i = Verificar_Video ( t, h, m, ano, nt, nome, diretor);

  if ( i == 0 )
  {

    printf("Video registrado. Seguem as informacoes do video\nID: [%d]\nNome: '%s'\nDiretor: '%s'\n", *idv, nome, diretor);
    fprintf(arq, "ID:%d\nNome:%s\nTipo:%d\nDiretor:%s\n", *idv, nome, t, diretor);
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

    printf("Ano de lancamento: %d\n", ano);
    fprintf(arq, "ano.lanc:%d\n", ano);

    fprintf(arq, "ng:%d\nGeneros:", ng);
    while (ng>0)
    {
      fprintf(arq,"%d", generos[ng]);
      ng--;
      if (ng>0)
        fprintf(arq,",");

    }
    fprintf(arq,".\n;\n");

    fclose(arq);

    return 0;

  }
  else
  {

    fclose(arq);
    printf("Erro ao cadastrar video, favor acessar o arquivo 'log.txt'\n");
    Fazer_Log(arq,idv,i);

  }

  return 0;

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

  printf("\nBem vindo ao menu principal. Digite:\n1 - Ver informacoes de usuario.\n2 - Procurar video.\n3 - Adicionar video.\n4 - Listar videos.\n5 - Fazer Log Out.\n6 - Finalizar do programa.\n - ");
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
  if ( jp == 2)
    main();

  return 0;

}
