#include <stdio.h>

int Eh_Divisivel_2_ou_5 (int x[], int d)
{
  return ((x[sizeof(x)-1]%d)==0);
}

int main()
{
  int x[1000];
  gets(x);
  printf("%c\n", Eh_Divisivel_2_ou_5 (x,2) ? 'S' : 'N' );
  printf("%c\n", Eh_Divisivel_2_ou_5 (x,5) ? 'S' : 'N' );
  printf("%c\n", Eh_Divisivel_3 (x) ? 'S' : 'N' );
  return 0;
}
