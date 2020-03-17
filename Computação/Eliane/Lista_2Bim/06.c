#include <stdio.h>

void piramide (int x, char c) {
  int contador_character, contador_linha, aux, aux2, aux3;
  float contador_espacos;
  for (contador_character = 1, contador_linha = x, contador_espacos = x, aux = x, aux2 = 1; contador_linha > 0; contador_linha--) {
    for (contador_espacos; contador_espacos > 0; contador_espacos --) {
      printf(" ");
    }
    for (contador_character;  contador_character > 0; contador_character --) {
      printf("%c", c);
    }
    contador_espacos = aux;
    for ( contador_espacos; contador_espacos > 0; contador_espacos --) {
      printf(" ");
    }
    printf("\n");
    aux --;
    aux2 += 2;
    contador_character = aux2;
    contador_espacos = aux;
  }
}

int main () {
  int n;
  char ch;
  scanf("%d %c", &n, &ch);
  for ( n, ch; n >= 0; scanf("%d %c", &n, &ch) ){
    piramide ( n, ch);
  }
  return 0;
}
