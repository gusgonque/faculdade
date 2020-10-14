#include <stdio.h>
#include <string.h>
#define MAX 100
#define LER_ESPACO setbuf(stdin, NULL)

void ler_nu (FILE *arq, int *nu)
{
  char c = 0;
  *nu = 0;
  arq = fopen("usuarios.txt","r");
  if (arq!=NULL)
  {
    while ( fscanf ( arq, "%c", &c ) != EOF )
    {
      //printf("i = [%c]\n", i);
      if ( c == ';' )
      {
        *nu += 1 ;
        //printf("nu = [%d]\n", *nu);
      }
    }
  }
  //printf("nu = [%d]\n", *nu);
  fclose(arq);
}

int Verificar_Data (int d,int m,int a)
{
  if (a<2020&&a>0)
  {
    if (m==1||m==3||m==5||m==7||m==8||m==10||m==12)
    {
      if (d<=31&&d>0)
      {
        return 0;
      }
      else
      {
        printf("Data invalida, por favor insira outra data no formato 'dd mm aa'.\n - ");
        return 1;
      }
    }
    if (m==4||m==6||m==9||m==11)
    {
      if (d<=30&&d>0)
      {
        return 0;
      }
      else
      {
        printf("Data invalida, por favor insira outra data no formato 'dd mm aa'.\n - ");
        return 1;
      }
    }
    if (m==02&&d>0&&d>=28)
    {
      return 0;
    }
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
{
  int i, j, p;
  for ( i = j = p = 0; nome[i] ; i++, j++)
  {
    if ( nome[i]==' ')
    {
      p++;
    }
  }
  if (j<2 || p == i)
  {
    return 0;
  }
  return 1;
}

int registro (FILE *arq, int *id)
{

  char nome[MAX];
  int i, d,m,a;


  *id = *id +1;

  printf("Para registrar um novo usuario, digite o nome completo dele (minino de 2 caracteres).\n - ");
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

  printf("Usuario %s , ID = [%d], favor colocar sua data de nascimento, no seguinte formato 'dd mm aaaa'\n - ", nome, *id);
  scanf("%2d %2d %4d", &d,&m,&a);

  while ( Verificar_Data (d,m,a) )
  {
    scanf("%d %d %d", &d,&m,&a);
  }

  arq = fopen("usuarios.txt","a+");

  fprintf(arq, "ID:%d\nLogin:%s\nData Nascimento:%d/%d/%d\nNH:0\nHistorico:.\n;\n", *id, nome, d,m,a);

  printf("Usuario registrado.\n");
  fclose(arq);
  return *id;
}

int procurar_usuario (FILE *arq, int nu)
{

  int i, j, id, jp, fl;
  char c,k, nome[MAX];
  arq = fopen("usuarios.txt","r");
  printf("\nPor favor, insira seu ID.\n - ");
  scanf("%d", &id);

  for ( i = 1 , fl = 0 ; i <= nu ; i++)
  {

    fscanf ( arq , "%3*c%d" , &jp );
    //printf("JP = [%d]\n", jp);
    if ( jp == id )
    {
      while (c != ':')
      {
        fscanf (arq,"%c", &c);
        //printf("..\n");
      }
      LER_ESPACO;
      fscanf(arq,"%[^\n]s", &nome);
      //printf(".\n");
      printf("\nUsuario encontrado.\nSeja bem vindo, '%s'.\n", nome);
      fl = 0;
      break;
    }
    else;
    {
      //printf(".\n");
      fl++;
      fscanf(arq,"%c", &k);
      while (k != ';')
      {
        fscanf(arq,"%c", &k);
      }

      fscanf(arq,"%*c");

    }

  }

  fclose(arq);

  if ( fl != 0)
  {
    printf("ID nao encontrado\nDigite:\n1 - Procurar outro ID.\n2 - Retornar a tela inicial.\n");
    scanf("%d", &jp);
    switch (jp)
    {
      case 1:
      {
        id = procurar_usuario(arq, nu);
        return id;
      }
      case 2:
      {
        return 1000000;
      }

    }
  }

  return id;

}

void listar_usuarios (FILE *arq, int nu)
{
  int i, id;
  char c, nome[MAX];
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
      {
        i++;
      }
    }
  }
  fclose(arq);
}

void remover_usuario (FILE *arq, int *nu)
{
  int id, i, jp, k;
  char c;
  printf("Digite o ID do usuario que deseja remover\n - ");
  scanf("%d", &id);
  FILE *arq2;
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
      //printf("c = %c\n",c);
      if ( c == '\n' )
      {
        //printf(".\n");
        i++;
      }
    }
  }

  for ( i = 0 ; i < 5 ;  )
  {
    fscanf(arq,"%c",&c);
    if ( c == '\n' )
    {
      i++;
    }
  }

  for ( ; k <= *nu-1 ; k++ )
  {
    for ( i = 0 ; i < 6 ;  )
    {
      fscanf(arq,"%c",&c);
      fprintf(arq2, "%c", c);
      if ( c == '\n' )
      {
        i++;
      }
    }
  }

  fclose(arq);
  fclose(arq2);
  remove("usuarios.txt");
  rename("usuarios2.txt","usuarios.txt");
  printf("Usuario removido com sucesso.\n");
  *nu = *nu + 1;
}

int login ( int *nu )
{

  /*
  1 - Registrar novo usuario
  2 - log in
  3 - Listar usuarios registrados
  4 - Remover usuario
  5 - finalizar programa
  */

  int i, id;
  FILE *arq;

  printf("\nDigite:\n1 - Log in de usuario existente.\n2 - Registrar um novo usuario.\n3 - Listar usuarios registrados.\n4 - Remover um usuario.\n5 - Finalizar o programa.\n - ");
  scanf("%d", &i);
  ler_nu (arq, nu);

  switch (i)
  {
    case 1:

      //printf("id = %d\n", id);
      id = procurar_usuario(arq, *nu);
      if ( id == 1000000)
      {
        return login (nu);
      }

    break;
    case 2:


    id = registro(arq, nu);
    //printf("id = %d\n", id);

    break;
    case 3:

      listar_usuarios(arq, *nu);
      return login(nu);

    break;
    case 4:

      listar_usuarios(arq,*nu);
      remover_usuario(arq,nu);
      return login(nu);

    break;
    case 5:

      return 0;

    break;

  }

  return id;

}

void ler_nv ( FILE *arq, int *nv )
{
  char i;
  *nv = 0;
  arq = fopen("videos.txt","r");
  if (arq!=NULL)
  {
    for ( i = 0 ;  fscanf ( arq, "%c", &i ) != EOF ; i++)
    {
      //printf("i = [%c]\n", i);
      if ( i == ';' )
      {
        *nv += 1 ;
        //printf("nv = [%d]\n", *nv);
      }
    }
  }
  //printf("nv = [%d]\n", *nv);
  fclose(arq);
}

void Editar_Dados (FILE *arq, int id)
{
  int i, d,m,a;
  char novo[MAX], c;
  FILE *arq2;

  printf("\nDigite o novo nome de usuario (minimo de 2 caracteres).\n - ");
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
  {
    scanf("%d %d %d", &d,&m,&a);
  }

  arq2 = fopen ("usuarios2.txt","w");
  arq = fopen ("usuarios.txt","r");

  for ( i = 1 ; i < id ;  )
  {
    fscanf(arq,"%c", &c);
    if ( c == ';' )
    {
      i++;
    }
  }

  fprintf(arq2, "ID:%d\nLogin:%s\nData Nascimento:%d/%d/%d\n", id, novo, d,m,a);

  for ( i = 0 ; i < 3; )
  {
    fscanf (arq,"%c",&c);
    if ( c == '\n' )
    {
      i++;
    }
  }
  while ( fscanf ( arq, "%c", &c ) != EOF )
  {
    fprintf(arq2, "%c", c);
  }
  fclose(arq);
  fclose(arq2);
  remove("usuarios.txt");
  rename("usuarios2.txt","usuarios.txt");
  printf("Usuario editado com sucesso.\n\n");

}

void Limpar_H (FILE *arq, int id)
{
  int i;
  char novo[MAX], c;
  FILE *arq2;
  arq2 = fopen ("usuarios2.txt","w");
  arq = fopen ("usuarios.txt","r");

  for ( i = 1 ; i < id ;  )
  {
    fscanf(arq,"%c", &c);
    if ( c == ';' )
    {
      i++;
    }
  }

  for ( i = 0 ; i < 3; )
  {
    fscanf (arq,"%c",&c);
    fprintf(arq2, "%c", c);
    if ( c == '\n' )
    {
      i++;
    }
  }

  fprintf(arq2, "NH:0\nHistorico:.\n;\n");

  for ( i = 0 ; i < 3; )
  {
    fscanf (arq,"%c",&c);
    if ( c == '\n' )
    {
      i++;
    }
  }

  while ( fscanf ( arq, "%c", &c ) != EOF )
  {
    fprintf(arq2, "%c", c);
  }
  fclose(arq);
  fclose(arq2);
  remove("usuarios.txt");
  rename("usuarios2.txt","usuarios.txt");
  printf("Historico limpado com sucesso.\n\n");

}

int ver_informacoes ( FILE *arq, int id )
{

  int i, l, d,m,a, nh;
  char login[MAX], c, h[MAX];
  arq = fopen("usuarios.txt","r");
  //printf("ID = [%d]\n", id);
  for ( i = 1 ; i < id ;  )
  {
    fscanf(arq,"%c", &c);
    if ( c == ';' )
    {
      i++;
    }
  }
  fscanf (arq,"\n");
  while (c != '\n')
  {
    fscanf(arq,"%c", &c);
  }
  LER_ESPACO;
  fscanf (arq,"%6*c%[^\n]s",&login);

  fscanf (arq,"%17*c%d/%d/%d%4*c%d%11*c",&d,&m,&a,&nh);

  ///printf("U = [%s] ID = [%d]\nData de nascimento: [%d] / [%d] / [%d]\n", login, id, d,m,a);
  for ( i = 0 ; i < nh ; i++ )
  {
    fscanf(arq,"%d%*c",&h[i]);
  }
  fclose(arq);
  //printf("NH = [%d]\n", nh);
  printf("\nUsuario '%s', ID: %d\nData de nascimento: %d / %d / %d\nHistorico de filmes visitados:", login, id, d,m,a);

  for ( i = 0 ; i < nh ; i++ )
  {
    printf(" %d", h[i]);
    if ( i < nh-1 )
      printf(",");
  }
  printf(".\n\nDeseja editar algum de seus dados?\n1 - Editar informacoes.\n2 - Limpar historio de filmes.\n3 - Voltar para o menu inicial.\n - ");
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
      return 0;
    break;
  }
  return 1;
}

void Deletar_Video ( FILE *arq, int id, int *nv )
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
      //printf("c = %c\n",c);
      if ( c == '\n' )
      {
        //printf(".\n");
        i++;
      }
    }
  }

  for ( i = 0 ; i < 9 ;  )
  {
    fscanf(arq,"%c",&c);
    if ( c == '\n' )
    {
      i++;
    }
  }

  for ( ; k <= *nv ; k++ )
  {
    for ( i = 0 ; i < 10 ;  )
    {
      fscanf(arq,"%c",&c);
      fprintf(arq2, "%c", c);
      if ( c == '\n' )
      {
        i++;
      }
    }
  }

  fclose(arq);
  fclose(arq2);
  remove("videos.txt");
  rename("videos2.txt","videos.txt");
}

int Verificar_Tempo (int h, int m)
{
  if (h<0||h>24)
    return 0;
  if (m<0||m>60)
    return 0;
  if (m == h && m == 0)
    return 0;
  return 1;
}

int Verificar_Video ( int t, int h, int m, int ano, int nt, char nome[], char diretor[], char generos[])
{
  if ( (Verificar_Nome (nome)&&Verificar_Nome(diretor)&&Verificar_Nome(generos)) == 0 )
    return 1;
  if (ano<0)
    return 2;
  if (t == 2)
  {
    if (Verificar_Tempo(h,m) == 0)
      return 3;
  }
  else
    if (t == 1)
    {
      if (nt<=0)
      {
        return 2;
      }
    }
    else
      return 1;
  return 0;
}

void Listar_Videos (FILE *arq, int nv)
{
  int i, id;
  char c, nome[MAX];
  arq = fopen ("videos.txt","r");
  while ( fscanf ( arq, "%c", &c ) != EOF )
  {
    fscanf (arq, "%2*c%d", &id);
    LER_ESPACO;
    fscanf (arq, "%6*c%[^\n]s", &nome);
    printf("ID = [%d] Nome do video = '%s'\n", id, nome);
    for ( i = 0 ; i < 9; )
    {
      fscanf (arq,"%c",&c);
      if ( c == '\n' )
      {
        i++;
      }
    }
  }
  fclose(arq);
}

void Editar_Video ( )
{
  /*
  int i, d,m,a;
  char novo[MAX], c;
  FILE *arq2;

  printf("\nDigite o novo nome de usuario (minimo de 2 caracteres).\n - ");
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
  {
    scanf("%d %d %d", &d,&m,&a);
  }

  arq2 = fopen ("usuarios2.txt","w");
  arq = fopen ("usuarios.txt","r");

  for ( i = 1 ; i < id ;  )
  {
    fscanf(arq,"%c", &c);
    if ( c == ';' )
    {
      i++;
    }
  }

  fprintf(arq2, "ID:%d\nLogin:%s\nData Nascimento:%d/%d/%d\n", id, novo, d,m,a);

  for ( i = 0 ; i < 3; )
  {
    fscanf (arq,"%c",&c);
    if ( c == '\n' )
    {
      i++;
    }
  }
  while ( fscanf ( arq, "%c", &c ) != EOF )
  {
    fprintf(arq2, "%c", c);
  }
  fclose(arq);
  fclose(arq2);
  remove("usuarios.txt");
  rename("usuarios2.txt","usuarios.txt");
  printf("Usuario editado com sucesso.\n\n");
 */
}

void Adicionar_Historico (FILE *arq, int idu, int idv)
{
  int i, nh;
  char c;
  FILE *arq2;

  arq2 = fopen ("usuarios2.txt","w");
  arq = fopen ("usuarios.txt","r");

  for ( i = 0 ; i < idu ;  )
  //pular u/v
  {
    fscanf(arq,"%c", &c);
    //printf("[%c]", c);
    fprintf(arq2,"%c", c);
    if ( c == ';' )
    {
      i++;
    }
  }

  for ( i = 0 ; i < 3 ; i++)
  {
    printf(".\n");
    while ( c != '\n'  )
    //pular linha
    {
      printf("..\n");
      fscanf(arq,"%c", &c);
      fprintf(arq2,"%c", c);
    }
  }

  for ( i = 0 ; i < 3 ; i++ )
  {
    fscanf(arq,"%c", &c);
    fprintf(arq2,"%c", c);
  }

  fscanf(arq,"%d", &nh);
  nh++;
  fprintf(arq2,"%d\n", nh);
  for ( i = 0 ; i < 10 ; i++ )
  {
    fscanf(arq,"%c", &c);
    fprintf(arq2,"%c", c);
  }
  for ( i = 0 ; i < nh ; i++ )
  {
    fscanf(arq,"%c", &c);
    if ( c != ',' )
      fprintf(arq2,"%c", c);
    else
      if ( c == ',' )
        fprintf(arq2,",");
      else
        fprintf(arq2,",");
  }

  while ( fscanf(arq,"%c", &c) != EOF )
  //pular linha
  {
    fprintf(arq2,"%c", c);
  }

  fclose(arq);
  fclose(arq2);
  remove("usuarios.txt");
  rename("usuarios2.txt","usuarios.txt");
}

void Mostrar_Video (FILE *arq, int idv, int nv)
{
  int t, h, m, nt, ng, ano;
  char nome[MAX], diretor[MAX], generos[MAX];
  int i, fl, jp;
  char c = '0', k;

  arq = fopen ("videos.txt","r");
  //printf("..\n");

  for ( i = 1 ; i < idv ;  )
  {
    fscanf(arq,"%c", &c);
    if ( c == ';' )
    {
      i++;
    }
  }
  fscanf(arq,"%*c");

  while ( c != '\n'  )
  {
    fscanf(arq,"%c", &c);
    //printf("%c\n", c);
  }

  LER_ESPACO;
  fscanf(arq,"%5*c%[^\n]s", &nome);
  //printf("nome = [%s]\n", nome);

  while ( c != ':' )
  {
    fscanf(arq,"%c", &c);
    //printf("c = %c\n", c);
  }
  fscanf(arq,"%d", &t);
  //printf("t = %d\n", t);

  LER_ESPACO;
  fscanf(arq,"%9*c%[^\n]s", &diretor);

  //printf(".4\n");

  if ( t == 1 )
  {
    fscanf(arq,"%8*c%2d%*c%2d", &h, &m);
    fscanf(arq,"%c", &k);
    while (k != '\n')
    {
      fscanf(arq,"%c", &k);
    }
  }
  if ( t == 2 )
  {
    fscanf(arq,"%24*c%d", &nt);
  }
  fscanf(arq,"%10*c%d", &ano);
  fscanf(arq,"%3*c%d", &ng);
  fscanf(arq,"%11*c");
  LER_ESPACO;
  fscanf(arq,"%[^.]s", &generos);
  //printf(".6\n");
  fclose (arq);

  printf("ID: [%d]\nNome: '%s'\nDiretor: '%s'\n", idv, nome, diretor);
  if ( t == 1 )
  {
    printf("Duracao: %d horas e %d minutos.\n", h, m);
  }
  if ( t == 2 )
  {
    printf("Temporadas: %d\n", nt);
  }
  printf("Ano de lancamento: %d\n", ano);
  if ( generos [i-1] == '.' )
  {
    printf("Generos: %s\n", generos);
  }
  else
  {
    printf("Generos:%s.\n", generos);
  }
}

int procurar_video (FILE *arq,int *nv,int *idv, int idu)
{
  int i;
  Listar_Videos (arq,*nv);
  printf("Digite o ID do video para consulta, edicao ou remocao.\n - ");
  scanf("%d", idv);
  Adicionar_Historico(arq,idu,*idv);
  Mostrar_Video(arq,*idv, *nv);
  printf("Digite:\n 1 - Editar informacoes do video selecionado.\n 2 - Deletar o video selecionado.\n 3 - Voltar para o menu principal.\n - ");
  scanf("%d", &i);

  switch (i)
  {
    case 1:
      Editar_Video ();
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

void Fazer_Log (FILE *arq, int *idv, int e)
{
  FILE *arq2;
  arq2 = fopen("log.txt","a+");
  if ( e == 1 )
  {
    fprintf(arq2, "ERRO 1: Video com ID = [%d], algum campo vazio ou incorreto.\n", *idv);
  }
  if ( e == 2 )
  {
    fprintf(arq2,"ERRO 2: Video com ID = [%d], numero solicitado foi colocado de forma incorreta, por exemplo numeros negativos.\n", *idv);
  }
  if ( e == 3 )
  {
    fprintf(arq2,"ERRO 3: Video com ID = [%d], numero da duracao solicitado foi colocado de forma incorreta, fora do intervalo formalizado (Hora: [0,24],Minuto: [0,59]).\n", *idv);
  }
}

int add_video (FILE *arq, int *nv, int *idv, int idu)
{

  int i, t, h, m, ng, ano, nt;
  char nome[MAX], diretor[MAX], generos[MAX];
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

  printf("Digite os generos do video, separando cada um por virgula, por exemplo 'acao,aventura'.\n - ");
  LER_ESPACO;
  scanf("%[^\n]s", &generos);

  i = Verificar_Video ( t, h, m, ano, nt, nome, diretor, generos );

  if ( i == 0 )
  {
    printf("Video registrado. Seguem as informacoes do video\n");

    printf("ID: [%d]\nNome: '%s'\nDiretor: '%s'\n", *idv, nome, diretor);
    fprintf(arq, "ID:%d\nNome:%s\nTipo:%c\nDiretor:%s\n", *idv, nome, t, diretor);
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
    for ( i = 0, ng = 1 ; generos[i] ; i++ )
      if ( generos[i] == ',')
         ng++;
    if ( generos [i-1] == '.')
    {
      printf("Generos: %s\n", generos);
      fprintf(arq, "ng:%d\nGeneros:%s\n;\n", ng, generos);
    }
    else
    {
      printf("Generos:%s.\n", generos);
      fprintf(arq, "ng:%d\nGeneros:%s.\n;\n", ng, generos);
    }

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

int menu_principal( int *nu, int *nv, int idu, int *idv)
{
  /*
  1 - Ver informacoes (editar)
  2 - procurar video (editar/excluir)
  3 - adicionar video
  4 - listar videos
  5 - logout
  6 - sair do programa
  */
  int i, fl;
  FILE *arq;
  ler_nv (arq, nv);
  printf("\nBem vindo ao menu principal. Digite:\n1 - Ver informacoes de usuario.\n2 - Procurar video.\n3 - Adicionar video.\n4 - Listar videos.\n5 - Fazer Log Out.\n6 - Sair do programa.\n - ");
  scanf("%d", &i);

  switch (i)
  {
    case 1:

      fl = ver_informacoes(arq, idu);
      if (fl == 0)
      {
        menu_principal(nu,nv,idu,idv);
      }

    break;
    case 2:
      fl = procurar_video(arq, nv, idv, idu);
      if (fl == 0)
      {
        menu_principal(nu,nv,idu,idv);
      }
    break;
    case 3:

      fl = add_video(arq,nv, idv, idu);
      if (fl == 0)
      {
        menu_principal(nu,nv,idu,idv);
      }
    break;
    case 4:

      Listar_Videos(arq,*nv);
      menu_principal(nu,nv,idu,idv);

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
{

  int nu, nv, idu, idv, jp;

  printf("\nSeja bem vindo ao WikiFilmes.\n");
  idu = login(&nu);
  if (idu == 0)
  {
    return 0;
  }
  jp = menu_principal(&nu,&nv,idu,&idv);
  if ( jp == 2)
  {
    main();
  }

  return 0;
}
