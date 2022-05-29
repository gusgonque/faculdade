#include <stdio.h>



void sequencia_characteres (char c1, char c2) {
  int contador_character = c1 - c2;
  printf("[%c][%c]\n", c1, c2);
  if ((c1 - c2) >= 0) {
    for (contador_character, c1, c2; contador_character >= 0; contador_character --) {
      printf("%c", c1);
      c1 --;
    }
  }
  else{
    for (contador_character, c1, c2; contador_character <= 0; contador_character ++) {
      printf("%c", c1);
      c1 ++;
    }
  }
}

int main () {
  char ch1, ch2;
  scanf("%c %c", &ch1, &ch2);
  for (ch1, ch2; (ch1 != ch2) || (ch2 == ch1); scanf("\n%c %c", &ch1, &ch2)) {
    sequencia_characteres(ch1, ch2);
    printf("\n");
  }
  return 0;
}
