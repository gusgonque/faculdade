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

/* Preferimos usar 2 estruturas struct diferentes pois percebemos
que precisariam de muitos dados para as transições. */

void Leitura ( DADOS *x , TRANSICOES y[] )
//Lê os dados.
{

  FILE *arq;
  char r;
  int i, j, p, k;
  char fn[50]; // fn = file name.

  printf("Insira o nome do arquivo de dados abaixo. (Ex:Dados.txt)\n");

  gets (fn);

  printf("\nLendo arquivo [%s]...\n\n", fn);

  arq = fopen (fn,"r");

  fscanf ( arq, "%*s\n%*s\n%*s\n");
  fscanf ( arq, "%8*c%[^\n]s", x->estado_inicial);
  //printf("Estado inicial = [%s]\n", x->estado_inicial);
  //Função para mostrar qual é o estado inicial.

  fscanf ( arq, "%9*c%[^\n]s\n", x->estados_finais);
  for ( i = j = k = 0; x->estados_finais[j] ; j++)
  //Função para organizar os estados finais.
  {

    if ( (x->estados_finais[j] == ',') || (x->estados_finais[j] == '}') )
    {

      x->EF[i][j-k] = '\0';
      for ( p = 0 ; p < j-k ; p++)
      {
        x->EF[i][p] = x->estados_finais[k+p];
      }
      //printf("Estado final [%d] = [%s]\n", i , x->EF[i]);
      k = j+1;
      i++;

    }

  }

  fscanf ( arq, "%c" );
  printf("\nLendo transicoes...\n\n");
  x->nf = i;
  for ( i=0 ; fscanf ( arq, "%c" ) != EOF ; i++ )
  //Função para escanear cada dado de cada transição separada. Para ver qual é cada dado, remover os "//" dentro da função.
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

int Processo_Relatorio ( DADOS *x , TRANSICOES y[] )
//Processa os dados e envia o relatório.
{
  int i, j, fl;
  // fl = flag; Que marca quando a cadeia for rejeitada.
  char cadeia[21], palavra_saida[50] = "\0";

  strcpy ( x->estado_atual , x->estado_inicial );

  printf("\nColoque a cadeia desejada, para o automato seguir.\n");
  printf("[%s]", x->estado_atual);
  scanf("%s", &cadeia);

  for ( i = fl = 0 ; cadeia[i] ; i++)
  //Lê cada letra da cadeia.
  {
    for ( j = 0; j < y->tamanho ; j++)
    //Lê cada transição do autômato.
    {
      if ( strcmp( y[j].estado_in , x->estado_atual ) == 0 )
      //Se o estado atual for igual estado de entrada daquela transição.
      {
        fl=0;
        if ( cadeia[i] == y[j].entrada[0] )
        //Se a letra da cadeia for igual à letra da saída daquela transição.
        {
          if (y[j].saida[0]!='@')
          //Não coloca o @ (vazio) na palavra de saída.
          {
            strcat( palavra_saida , y[j].saida );
          }
          strcpy ( x->estado_atual , y[j].estado_out );
          printf("[%s]%s saida:[%s]\n", x->estado_atual, cadeia+i+1, y[j].saida);
          break;
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
    printf("Palavra de saida: [%s]\n", palavra_saida);
    return 0;
  }
  else
  {
    for ( i = 0; i < x->nf; i++ )
    //Confirma se o último estado atual é um estado final.
    {
      if ( strcmp( x->estado_atual , x->EF[i] ) == 0 )
      {
        printf("ACEITA\n");
        printf("Palavra de saida: [%s]\n", palavra_saida);
        return 0;
      }
    }
    printf("REJEITADA\n");
    printf("Palavra de saida: [%s]\n", palavra_saida);
    return 0;
  }
}

int main ()
//comanda as funções Leitura e Processo_Relatorio
{
  DADOS x;

  TRANSICOES y[21];

  char Continuar[5] = "sim";

  Leitura ( &x , y );

  while ( strcmp( Continuar , "sim" ) == 0 )
  //Para múltiplas cadeias de entrada.
  {

    Processo_Relatorio ( &x , y );

    printf("\nPara iserir outra cadeia, digite 'sim'. Qualquer outra palavra finaliza o programa.\n");
    scanf("%s", &Continuar );

  }

  return 0;
}
