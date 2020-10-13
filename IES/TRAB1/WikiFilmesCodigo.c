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

int registro (FILE *arq, int *id)
{

  char nome[MAX];
  int d,m,a;

  arq = fopen("usuarios.txt","a+");
  *id = *id +1;

  printf("Para registrar um novo usuario, digite o nome completo dele.\n - ");
  LER_ESPACO;
  scanf("%[^\n]s", &nome);

  printf("Usuario %s , ID = [%d], favor colocar sua data de nascimento, no seguinte formato 'dd mm aaaa'\n - ", nome, *id);
  scanf("%2d %2d %4d", &d,&m,&a);

  while ( Verificar_Data (d,m,a) )
  {
    scanf("%d %d %d", &d,&m,&a);
  }

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
      printf("\nUsuario encontrado, '%s'.\n\n", nome);
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
        printf(".\n");
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
  *nu = *nu - 1;

  for ( ; k <= *nu ; k++ )
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
  printf("Usuario removido com sucesso.\n\n");
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

  printf("\nDigite o novo nome de usuario.\n - ");
  LER_ESPACO;
  scanf("%[^\n]s", &novo);
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
    break;
    case 3:
      return 0;
    break;
  }
  return 1;
}

void procurar_video (/* arguments */)
{
  /* code */
}

void Editar_Video ( )
{

}

int Verificar_Duracao ()
{

}

int add_video (FILE *arq, int *id)
{
  char nome[MAX], diretor[MAX], genero[MAX], t;
  int h = 0,m = 0,ano,ng,nt;
  *id = *id + 1 ;
  arq = fopen("videos.txt","a+");
  fprintf(arq, "%ID:%d\n", *id);

  printf("Para registrar um novo video, digite o nome completo dele.\n - ");
  LER_ESPACO;
  scanf("%[^\n]s", &nome);
  fprintf(arq, "Nome:%s\n", nome);

  printf("Digite:\n'f' - Se o video for um filme.\n's' - Se o video for uma serie\n - ");
  scanf("%c", &t);
  fprintf(arq,"Tipo:%c\n", t);

  printf("Digite o nome do diretor de seu video.\n - ");
  LER_ESPACO;
  scanf("%[^\n]s", &diretor);
  fprintf(arq, "Diretor:%s\n", diretor);

  if (t == 'f')
  {
    printf("Digite a duracao no formato 'hh mm'\n - ");
    scanf("%d %d", &h,&m);
    fprintf(arq, "Duracao:%d,%d\nTemporadas:0",h,m );
  }
  if (t == 's')
  {
    printf("Digite a quantidade de temporadas.\n - ");
    scanf("%s\n", &nt);
    fprintf(arq, "Duracao:0,0\nTemporadas:%d",nt );
  }



  fprintf(arq, "ID:%d\n...\n", *id);

  printf("Video registrado.\n");
  fclose(arq);
  return *id;
}

int menu_principal( int *nu, int *nv, int id )
{
  /*
  1 - Ver informacoes (editar)
  2 - procurar video (editar)
  3 - adicionar video
  4 - logout
  5 - sair do programa
  */
  int i, fl;
  FILE *arq;
  ler_nv (arq, nv);
  printf("Bem vindo ao menu principal. Digite:\n1 - Ver informacoes.\n2 - Procurar video.\n3 - Adicionar video\n4 - Fazer Log Out\n5 - Sair do programa.\n - ");
  scanf("%d", &i);

  switch (i)
  {
    case 1:

      fl = ver_informacoes(arq, id);
      if (fl == 0)
      {
        menu_principal(nu,nv,id);
      }

    break;
    case 2:

      procurar_video();

    break;
    case 3:

      add_video(arq,*nv);

    break;
    case 4:

      return 2;

    break;
    case 5:

      return 0;

    break;
  }

}

int main ()
{

  int nu, nv, id, jp;

  printf("\nSeja bem vindo ao WikiFilmes.\n");
  id = login(&nu);
  if (id == 0)
  {
    return 0;
  }
  jp = menu_principal(&nu,&nv,id);
  if ( jp == 2)
  {
    main();
  }

  return 0;
}
