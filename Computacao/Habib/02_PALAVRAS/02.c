#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 1000
#define MAXC 50

void Leitura ( char m_pal[][MAXC], int *t , char *fn )
{

  int i;
  FILE *arq;

  arq = fopen (fn,"r");

  for ( i = 0 ; fscanf (arq, "%[^' ']%*c", m_pal[i]) ; i++ )
  { }
  *t = i;
  fclose (arq);

}
//lindo me salva pfvr

void Organizar_Ordem_Alfabetica ( char m_pal[][MAXC] , int t )
{
  int i, j, k;
  char aux[MAXC];

  for ( i=0 ; i<t ; i++ )

    for ( j=0 ; j < strlen ( m_pal[i] ) ; j++ )

      if ( isalpha ( m_pal[i][j] ) )
      {
        if (j != 0)
        {

          for ( k = 0 ; k < strlen ( m_pal[i] )-j ; k++ )
            aux [k] = m_pal [i][j+k];


        }

      }
}

void Processo ( )
{

}

int main ()
{

  int n_pal [MAX], t;
  char m_pal [MAX] [MAXC];

  Leitura ( m_pal , &t , "dados-2.txt" );

  Processo ();

  Relatorio ();

  return 0;
}
