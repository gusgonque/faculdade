#include <stdio.h>



int main(){
  FILE *arq;
  char s[100];

  arq = fopen("dados", "wb");

  fprintf(arq, "hello world\n");

  fclose (arq);

  arq = fopen("dados", "rb");

  fscanf(arq, "%[^\n]",&s);
  printf("%s\n", s);
  fclose (arq);


  return 0;
}
