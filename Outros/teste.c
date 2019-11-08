#include <stdio.h>

int main()
{
  char str[100] = "data-01.txt";
  int i;
  for ( i=0 ; i<70 ; i++ )
  {
    if (str[6] < '9')
      str[6] ++;
    else
    {
      str[6] = '0';
      str[5] ++;
    }
    fopen(str,"r");
  }
  return 0;
}
