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
  fclose(arq);
}

void registro (FILE *arq, int id)
{

  char nome[MAX];
  int d,m,a;

  arq = fopen("usuarios.txt","a+");
  printf("Para registrar um novo usuario, digite o nome completo dele.\n");
  setbuf(stdin, NULL);
  scanf("%[^\n]s", &nome);
  printf("Usuario %s , ID = [%d], favor colocar sua data de nascimento, no seguinte formato 'dd mm aaaa'\n", nome, id);
  scanf("%d %d %d", &d,&m,&a);
  fprintf(arq, "ID: %d\nLogin: %s\nData Nascimento: %d/%d/%d\nNH: 0\nHistorico:\n;\n", id, nome, d,m,a);

  fclose(arq);

}

void login ( int *nu )
{

  int i;
  FILE *arq;

  printf("Digite:\n1 - Registrar um novo usuario.\n2 - Log in de usuario existente.\n");
  scanf("%d", &i);
  ler_nu (arq, nu);

  switch (i)
  {
    case 1:
    {

      *nu = *nu + 1;
      registro(arq, *nu);
      //printf("%d\n", *nu);

    }
    case 2:
    {



    }

  }

}

void Leitura ( int *nu, int *nv )
{
  login(nu);
}

void Processo ( )
{

}

int main ()
{

  int nu, nv;

  Leitura(&nu,&nv);
  Processo( );

  return 0;
}
