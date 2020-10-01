#include <stdio.h>
#include <string.h>

typedef struct
{

  char estado_inicial[3], estados_finais[41], EF[20][20], estado_atual[3];
  int nf;

}
DADOS;

typedef struct
{

  char estado_in[20], estado_out[20], entrada[20], saida[20];
  int tamanho;

}
TRANSICOES;

void Leitura ( DADOS *x , TRANSICOES y[] )
{

  FILE *arq;
  char r;
  int i, j, p, k;
  char fn[50]; // fn = file name

  printf("Insira o nome do arquivo de dados abaixo. (Ex:Dados.txt)\n");

  gets (fn);

  printf("\nLendo arquivo [%s]...\n\n", fn);

  arq = fopen (fn,"r");

  fscanf ( arq, "%*s\n%*s\n%*s\n");

  fscanf ( arq, "%8*c%[^\n]s", x->estado_inicial);
  //printf("Estado inicial = [%s]\n", x->estado_inicial);

  fscanf ( arq, "%9*c%[^\n]s\n", x->estados_finais);
  //printf("Estados finais = [%s]\n", x->estados_finais);

  for ( i = j = k = 0; x->estados_finais[j] ; j++)
  {
    //printf("%s\n", x->estados_finais);
    if ( (x->estados_finais[j] == ',') || (x->estados_finais[j] == '}') )
    {

      //printf("t1\n");
      x->EF[i][j-k] = '\0';
      //printf("t2\n");
      for ( p = 0 ; p < j-k ; p++)
      {
        x->EF[i][p] = x->estados_finais[k+p];
      }

      //printf("Estado final [%d] = [%s]\n", i , x->EF[i]);

      k = j+1;
      //printf("T, x->EF[%d] = [%s]\n", i, x->EF[i]);
      i++;

    }
  }

  fscanf ( arq, "%c" );
  printf("\nLendo transicoes...\n\n");

  x->nf = i;

  for ( i=0 ; fscanf ( arq, "%c" ) != EOF ; i++ )
  {
    y[i-1].saida[0] = r;
    //printf("Transicao [%d]:\n", i);

    fscanf ( arq, "%[^,]s", y[i].estado_in );
    //printf ( "Estado IN = [%s]\n", y[i].estado_in );

    fscanf ( arq, "%1*c%[^)]s", y[i].entrada );
    //printf ( "Entrada = [%s]\n", y[i].entrada );

    fscanf ( arq, "%5*c%[^,]s", y[i].estado_out );
    //printf ( "Estado OUT = [%s]\n", y[i].estado_out );

    fscanf ( arq, "%1*c%[^)]s", y[i].saida );
    //printf ( "Saida = [%s]\n", y[i].saida );
    r=y[i].saida[0];
    fscanf ( arq, "%2*c");
    //printf ("---\n");

  }
  y->tamanho = i;
  fclose(arq);
}

void Processo_Relatorio ( DADOS *x , TRANSICOES y[] )
{
  int i, j, k, l, fl;
  char caminho[21], palavra_saida[50]= "\0";

  strcpy ( x->estado_atual , x->estado_inicial );

  printf("\nColoque o caminho desejado, para o automato seguir.\n");

  printf("[%s]", x->estado_atual);
  scanf("%s", &caminho);
  for ( i =  l = fl = 0 ; caminho[i] ; i++)
  {
    for ( j = 0; j < y->tamanho ; j++)
    {
      //printf("T2, y[j]->estado_in = [%s] x->estado_atual = [%s] \n", y[j].estado_in, x->estado_atual);

      if ( strcmp( y[j].estado_in , x->estado_atual ) == 0 )
      {

        //printf("T1, os dois sao iguais\n");
        fl=0;

        if ( caminho[i] == y[j].entrada[0] )
        {
          l++;
          //printf("T3, caminho (%s) [i] (%c) = entrada (%c)\n", caminho, caminho[i], y[j].entrada[0]);
          //printf("y[%d].saida = [%s], palavra_saida = [%s]\n", j ,y[j].saida, palavra_saida);

          strcat( palavra_saida , y[j].saida );

          strcpy ( x->estado_atual , y[j].estado_out );
          printf("[%s]%s saida:[%s]\n", x->estado_atual, caminho+i+1, y[j].saida);
        }
        else
        {
          fl++;
        }

      }
      else
      {
        fl++;
      }

    }

  }

  if ( fl != 0 )
  {
    printf("REJEITADA\n");
  }
  else
  {
    for ( i = 0; i < x->nf; i++ )
    {
      if ( strcmp( x->estado_atual , x->EF[i] ) == 0 )
      {
        printf("ACEITA\n");
        printf("Palavra de saida: [%s]\n", palavra_saida);
      }
    }
    printf("REJEITADA\n");
  }

}

int main ()
{
  DADOS x;

  TRANSICOES y[50];

  Leitura ( &x , y );

  Processo_Relatorio ( &x , y );

  return 0;
}
