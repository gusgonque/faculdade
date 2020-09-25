#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct
{

  char estado_inicial[3], estados_finais[41], EF[20][20], estado_atual[3];

}
DADOS;

typedef struct
{

  char estado_in[20], estado_out[20], entrada[20], saida[20];

}
TRANSICOES;

int Leitura ( DADOS *x , TRANSICOES y[] )
{

  FILE *arq;

  int i, j, p, k;
  char fn[51]; // fn = file name

  gets (fn);

  arq = fopen (fn,"r");

  fscanf ( arq, "%78*c%[^\n]s", x->estado_inicial);
  printf("estado_inicial = [%s]\n", x->estado_inicial);

  fscanf ( arq, "%9*c%[^\n]s\n", x->estados_finais);
  printf("estados_finais = [%s]\n", x->estados_finais);

  for ( i = j = k = 0; x->estados_finais[j] ; j++)
  {
    printf("%s\n", x->estados_finais);
    if ( (x->estados_finais[j] == ',') || (x->estados_finais[j] == '}') )
    {

      //printf("t1\n");
      x->EF[i][j-k] = '\0';
      //printf("t2\n");
      for ( p = 0 ; p < j-k ; p++)
      {
        x->EF[i][p] = x->estados_finais[k+p];
        //printf("Teste, x->EF[%d][%d] = %c\n", i, p, x->estados_finais[k+p]);
      }
      printf("t3\n");
      k = j+1;
      printf("T, x->EF[%d] = [%s]\n", i, x->EF[i]);
      i++;

    }
    else
    {
    //printf("NF\n");
    }

  }

  for ( i=0 ; fscanf ( arq, "%c" ) != EOF ; i++ )
  {

    fscanf ( arq, "%[^,]s", y[i].estado_in );
    //printf ( "estado in = [%s]\n", y[i].estado_in );

    fscanf ( arq, "%1*c%[^)]s", y[i].entrada );
    //printf ( "entrada = [%s]\n", y[i].entrada );

    fscanf ( arq, "%5*c%[^,]s", y[i].estado_out );
    //printf ( "estado out = [%s]\n", y[i].estado_out );

    fscanf ( arq, "%1*c%[^)]s", y[i].saida );
    //printf ( "saida = [%s]\n", y[i].saida );

    fscanf ( arq, "%2*c");

    //printf ( "-- i = %d --\n", i);

  }

  fclose(arq);
}

void Mudar_Estado (char a[], char b[])
{
  int i;
  for ( i = 0 ; b[i] ; i++)
  {
    a[i] = b[i];
  }
}

int Comparar_String (char a[], char b[])
{

  int i;

  printf("T10, a[%d] = [%c], b[%d] = %c\n", i, a[i], i, b[i]);

  for ( i = 0 ; b[i] ; i++)
  {

    printf("T11, a[%d] = [%c], b[%d] = %c\n", i, a[i], i, b[i]);

    if ( a[i]!=b[i] )
    {
      printf("T12\n");

      return 0;



    }

  }

  printf("T12\n");

  return 1;
}

int Comparar_Char_String (char a, char b[])
{
  int i;
  for ( i = 0 ; b[i] ; i++)
  {
    if ( a!=b[i] )
    {
      return 0;
    }
  }
  return 1;
}

void Processo_Relatorio ( DADOS *x , TRANSICOES *y[] )
{
  int i, j, p, k, l, fl;
  char caminho[21], palavra_saida[50];

  Mudar_Estado ( x->estado_atual , x->estado_inicial );

  printf("[%s]", x->estado_atual);
  scanf("%s", &caminho);
  for ( i = l = fl = 0 ; caminho[i] ; i++)
  {

    printf("T1\n");

    for ( j = 0; y[j]->estado_in ; j++)
    {

      printf("T2\n");

      if ( Comparar_String ( &y[j]->estado_in , &x->estado_atual ) )
      {
        printf("T3\n");
        fl=0;

        for ( p = j; y[p]->entrada ; p++ )
        {

          printf("T4\n");

          if ( Comparar_Char_String ( caminho[i] , y[p]->entrada ) )
          {

            printf("T5\n");

            for ( k = 0 ; y[p]->saida[k] ; k++, l++)
            {

              printf("T6\n");

              palavra_saida[l] = y[p]->saida[k];

            }

            printf("T7\n");

            Mudar_Estado ( x->estado_atual , y[p]->estado_out );

          }

          else
          {

            fl++;

            printf("T8\n");

          }

          printf("palavra_saida = [%s]\n", palavra_saida);

        }
      }
      else
      {

        printf("T9\n");

        fl++;
      }

    }

    if ( fl != 0 )
    {
      //REJEITADO
    }
    else
    {
      //APROVADO
    }
  }

}

int main ()
{

 DADOS x;

 TRANSICOES y[20];

  Leitura ( &x , y );

  Processo_Relatorio ( &x , y );

  return 0;
}
