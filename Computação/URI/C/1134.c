#include <stdio.h>

int main (){
  int num, num_alcool, num_gasolina, num_diesel;
  for ( num = 0, num_alcool = 0, num_gasolina = 0, num_diesel = 0 ; num != 4 ; scanf ("%d", &num) ) {
    if (num == 1)
      num_alcool ++;
    else
      if (num == 2)
        num_gasolina ++;
      else
        if (num == 3)
          num_diesel ++;
        else
          if (num == 4)
            break;
  }
  printf ("MUITO OBRIGADO\n");
  printf ("Alcool: %d\n", num_alcool);
  printf ("Gasolina: %d\n", num_gasolina);
  printf ("Diesel: %d\n", num_diesel);
  return 0;
}
