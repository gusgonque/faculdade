#include <stdio.h>
#include <string.h>

int Processo (char s[]) {
  int i, cont;
  char aux[100];
  strcpy (aux,s);
  if (aux[0] == ')')
    return 0;
  for ( i=0, cont=0; aux[i] ; i++ ){
    cont += (aux[i] == '(' ? 1 : -1);
  }
  return (cont==0);
}

void Relatorio (int i) {
  if (i)
    printf("Sim.\n");
  else
    printf("Nao.\n");
}

int main () {
  char s[100];
  gets(s);
  for (  ; strcmp ( s , "fim" ) ; gets (s) ) {
  Relatorio(Processo(s));
  }
  return 0;
}
