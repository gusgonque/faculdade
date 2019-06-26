#include <stdio.h>

int main () {
  int num_linha, aux_linha,num_espacos, aux_espacos, num_letra, aux_letra;
  scanf("%d", &num_linha);
  for ( aux_linha=1, num_espacos=(num_linha-1), num_letra=1 ; aux_linha<=num_linha; aux_linha++, num_espacos--, num_letra++ ) {
    for ( aux_espacos=num_espacos; aux_espacos > 0 ; aux_espacos-- ) {
      printf(" ");
    }
    for ( aux_letra = 0; aux_letra < num_letra; aux_letra++) {
      printf("%c", ('a'+aux_letra) );
    }
    printf("\n");
  }
}
