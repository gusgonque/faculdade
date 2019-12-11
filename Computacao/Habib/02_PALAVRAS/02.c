#include <stdio.h>
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


int main ()
{

  int n_pal [MAX], t;
  char m_pal [MAX] [MAXC];

  Leitura ( m_pal , &t , "dados-2.txt" );

  Processo ();

  Relatorio ();

  return 0;
}
