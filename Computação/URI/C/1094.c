#include <stdio.h>

int main () {
  int num_casos, num, num_r, num_c, num_s, tot_animais;
  char CHAR;
  float por_r, por_c, por_s;
  scanf("%d", &num_casos);
  for ( num_r = 0, num_c = 0, num_s = 0 ; num_casos > 0 ; num_casos-- ) {
    scanf("%d %c", &num, &CHAR);
    if (CHAR == 'R') {
      num_r += num;
    }
    else
    if (CHAR == 'C') {
      num_c += num;
    }
    else
      num_s += num;
  }
  tot_animais = num_r + num_c + num_s;
  por_r = (num_r * 100.0) / tot_animais;
  por_c = (num_c * 100.0) / tot_animais;
  por_s = (num_s * 100.0) / tot_animais;
  printf ("Total: %d cobaias\n", tot_animais);
  printf ("Total de coelhos: %d\n", num_c);
  printf ("Total de ratos: %d\n", num_r);
  printf ("Total de sapos: %d\n", num_s);
  printf ("Percentual de coelhos: %.2f %\n", por_c);
  printf ("Percentual de ratos: %.2f %\n", por_r);
  printf ("Percentual de sapos: %.2f %\n", por_s);
  return 0;
}
