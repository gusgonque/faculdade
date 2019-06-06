#include <stdio.h>

void piramide_inversa (int x, char c) {
  int contador_character, contador_linha, aux, aux2, aux3;
  float contador_espacos;
  for (contador_character = ((x > 3)? x + 4: x + 2), contador_linha = x, contador_espacos = 1, aux = 1, aux2 = ((x > 3)? x + 4: x + 2); contador_linha > 0; contador_linha--) {
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
    aux ++;
    aux2 -= 2;
    contador_character = aux2;
    contador_espacos = aux;
  }
}

int main () {
  int n;
  char ch;
  scanf("%d %c", &n, &ch);
  for ( n, ch; n >= 0; scanf("%d %c", &n, &ch) ){
    piramide_inversa ( n, ch);
  }
  return 0;
}
