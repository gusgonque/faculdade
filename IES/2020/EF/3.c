#include <stdio.h>

int main( )
{
  int x,y;
  printf("Digite o valor de x.\n");
  scanf("%d", &x);

  printf("Digite o valor de y.\n");
  scanf("%d", &y);

  if (x = y)
    printf("Os dois numeros sao iguais\n");
  if (x > y || y < x)
    printf("Os dois numeros nao sao iguais\n");

  return 0;
}
