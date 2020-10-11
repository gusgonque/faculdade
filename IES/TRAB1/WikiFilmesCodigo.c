#include <stdio.h>
#include <string.h>
#define MAX 50

void ler_nu (FILE *arq, int *nu)
{
  char i;
  *nu = 0;
  arq = fopen("usuarios.txt","r");
  if (arq!=NULL)
  {
    for ( i = 0 ;  fscanf ( arq, "%c", &i ) != EOF ; i++)
    {
      //printf("i = [%c]\n", i);
      if ( i == ';' )
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

  printf("Para registrar um novo usuario, digite o nome completo dele.\n");
  setbuf(stdin, NULL);
  scanf("%[^\n]s", &nome);

  printf("Usuario %s , ID = [%d], favor colocar sua data de nascimento, no seguinte formato 'dd mm aaaa'\n", nome, id);
  scanf("%d %d %d", &d,&m,&a);

  fprintf(arq, "ID:%d\nLogin:%s\nData Nascimento:%d/%d/%d\nNH:0\nHistorico:.\n;\n", id, nome, d,m,a);

  printf("Usuario registrado.\n");
  fclose(arq);
  return id;
}

int procurar_usuario (FILE *arq, int nu)
{

  int i, j, id, jp, fl;
  char k;
  arq = fopen("usuarios.txt","r");
  printf("Por favor, insira seu ID.\n");
  scanf("%d", &id);

  for ( i = 1 , fl = 0 ; i <= nu ; i++)
  {

    fscanf ( arq , "%3*c%d" , &jp );
    //printf("JP = [%d]\n", jp);
    if ( jp == id )
    {
      printf("Usuario encontrado.\n");
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

void menu_principal(/* arguments */)
{
  /* code */
}

int login ( int *nu )
{

  int i, id;
  FILE *arq;

  printf("Digite:\n1 - Registrar um novo usuario.\n2 - Log in de usuario existente.\n3 - Finalizar o programa.\n");
  scanf("%d", &i);
  ler_nu (arq, nu);

  switch (i)
  {
    case 1:
    {

      *nu = *nu + 1;
      id = registro(arq, *nu);
      //printf("id = %d\n", id);

    }
    case 2:
    {

      id = procurar_usuario(arq, *nu);
      //printf("id = %d\n", id);
      if ( id == 1000000)
      {
        login (nu);
      }

    }
    case 3:
    {
      return 0;
    }

  }



}

int main ()
{

  int nu, nv;

  printf("\nSeja bem vindo ao WikiFilmes.\n\n");
  if (login(&nu))
  {
    return 0;
  }
  menu_principal();

  return 0;
}
