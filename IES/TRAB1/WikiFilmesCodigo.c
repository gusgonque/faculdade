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

int registro (FILE *arq, int id)
{

  char nome[MAX];
  int d,m,a;

  arq = fopen("usuarios.txt","a+");

  printf("Para registrar um novo usuario, digite o nome completo dele.\n - ");
  LER_ESPACO;
  scanf("%[^\n]s", &nome);

  printf("Usuario %s , ID = [%d], favor colocar sua data de nascimento, no seguinte formato 'dd mm aaaa'\n - ", nome, id);
  scanf("%d %d %d", &d,&m,&a);

  fprintf(arq, "ID:%d\nLogin:%s\nData Nascimento:%d/%d/%d\nNH:0\nHistorico:.\n;\n", id, nome, d,m,a);

  printf("Usuario registrado.\n");
  fclose(arq);
  return id;
}

int procurar_usuario (FILE *arq, int nu)
{

  int i, j, id, jp, fl;
  char c,k, nome[MAX];
  arq = fopen("usuarios.txt","r");
  printf("Por favor, insira seu ID.\n - ");
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
      printf("Usuario encontrado, '%s'.\n", nome);
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

int login ( int *nu )
{

  int i, id;
  FILE *arq;

  printf("Digite:\n1 - Registrar um novo usuario.\n2 - Log in de usuario existente.\n3 - Finalizar o programa.\n - ");
  scanf("%d", &i);
  ler_nu (arq, nu);

  switch (i)
  {
    case 1:

      *nu = *nu + 1;
      id = registro(arq, *nu);
      //printf("id = %d\n", id);

    break;
    case 2:

      id = procurar_usuario(arq, *nu);
      //printf("id = %d\n", id);
      if ( id == 1000000)
      {
        login (nu);
      }

    break;
    case 3:

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

void Editar_NU (FILE *arq, int id)
{
  int i;
  char novo[MAX], c;
  FILE *arq2;
  printf("Digite o novo nome de usuario.\n - ");
  LER_ESPACO;
  scanf("%s", &novo);

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

  for ( i = 0 ; i < id ;  )
  {
    fscanf(arq,"%c", &c);
    if ( c == ';' )
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
  printf("Renomeado com sucesso.\n");

}

void Editar_DDN ()
{

}

void Limpar_H ()
{

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
  LER_ESPACO;
  fscanf (arq,"%11*c%[^\n]s",&login);

  fscanf (arq,"%17*c%d/%d/%d%4*c%d%11*c",&d,&m,&a,&nh);

  ///printf("U = [%s] ID = [%d]\nData de nascimento: [%d] / [%d] / [%d]\n", login, id, d,m,a);
  for ( i = 0 ; i < nh ; i++ )
  {
    fscanf(arq,"%d%*c",&h[i]);
  }
  fclose(arq);
  //printf("NH = [%d]\n", nh);
  printf("Usuario '%s', ID: %d\nData de nascimento: %d / %d / %d\nHistorico de filmes visitados:", login, id, d,m,a);

  for ( i = 0 ; i < nh ; i++ )
  {
    printf(" %d", h[i]);
    if ( i < nh-1 )
      printf(",");
  }
  printf(".\nDeseja editar algum de seus dados?\n1 - Editar nome de usuario.\n2 - Editar data de nascimento.\n3 - Limpar historio de filmes\n4 - Voltar para o menu inicial.\n - ");
  scanf("%d", &i);
  switch (i)
  {
    case 1:
      Editar_NU (arq, id);
    break;
    case 2:
      Editar_DDN ();
    break;
    case 3:
      Limpar_H ();
    break;
    case 4:
      return 0;
    break;
  }
  return 1;
}

void procurar_video (/* arguments */)
{
  /* code */
}

void add_video (/* arguments */)
{
  /* code */
}

int menu_principal( int nu, int *nv, int id )
{
  /*
  1 - Ver informacoes (editar)
  2 - procurar video (editar)
  3 - adicionar video
  4 - sair do programa
  */
  int i, fl;
  FILE *arq;
  ler_nv (arq, nv);
  printf("Bem vindo ao menu principal. Digite:\n1 - Ver informacoes.\n2 - Procurar video.\n3 - Adicionar video\n4 - Sair do programa.\n - ");
  scanf("%d", &i);

  switch (i)
  {
    case 1:

      fl = ver_informacoes(arq, id);
      if (fl == 0) {
        menu_principal(nu,nv,id);
      }

    break;
    case 2:

      procurar_video();

    break;
    case 3:

      add_video();

    break;
    case 4:

      return 0;

    break;
  }

}

int main ()
{

  int nu, nv, id;

  printf("\nSeja bem vindo ao WikiFilmes.\n\n");
  id = login(&nu);
  if (id == 0)
  {
    return 0;
  }
  menu_principal(nu,&nv,id);

  return 0;
}
