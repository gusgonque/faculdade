#include <stdio.h>

void circulo_caracteres (int x, char c) {
  int contador_character, contador_linha, contador_espacos;
  for (contador_character = x; contador_character > 0; contador_character --) {
    printf("%c", c);
  }
  printf("\n");
  for (contador_espacos = x - 2; contador_espacos > 0; contador_espacos --){
    printf("%c", c);
    int aux = x - 2;
    for (aux; aux > 0; aux --){
      printf(" ");
    }
    printf("%c\n", c);
  }
  for (contador_character = x; contador_character > 0; contador_character --) {
    printf("%c", c);
  }

  printf("\n");
}

int main () {
  int n;
  char ch;
  scanf("%d %c", &n, &ch);
  for ( n, ch; n >= 0; scanf("%d %c", &n, &ch) ){
    circulo_caracteres ( n, ch);
  }
  return 0;
}
