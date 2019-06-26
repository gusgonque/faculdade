#include <stdio.h>

int main () {
  int num_linha, num_letra, aux_linha ;
  scanf("%d", &num_linha);
  for ( aux_linha=1 ; num_linha>=3 ; aux_linha-=3, num_linha-=3 ) {
    for ( aux_linha=1 ; aux_linha <= 3 ; aux_linha++ ) {
      for ( num_letra=1 ; num_letra <= aux_linha ; num_letra++ ) {
        printf("%c", (96+num_letra));
      }
      printf("\n");
    }
  }
  for ( aux_linha=1 ; aux_linha <= num_linha ; aux_linha++ ) {
    for ( num_letra=1 ; num_letra <= aux_linha ; num_letra++ ) {
      printf("%c", (96+num_letra));
    }
    printf("\n");
  }
  return 0;
}
