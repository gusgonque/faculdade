#include <stdio.h>

int Inverno (int x[])
{
  int dif12 = x[1] - x[0] , dif23 = x[2] - x[1];
  if ( (dif12 < 0) && (dif23 >= 0) )
    return 1;
  if ( (dif12 > 0) && (dif23 <= 0) )
    return 0;
  if ( (dif12 > 0) && (dif23 > 0) && (dif23 < dif12) )
    return 0;
  if ( (dif12 > 0) && (dif23 > 0) && (dif23 >= dif12) )
    return 1;
  if ( (dif12 < 0) && (dif23 < 0) && (dif23 < dif12) )
    return 1;
  if ( (dif12 < 0) && (dif23 < 0) && (dif23 >= dif12) )
    return 0;
  if ( dif12==0 )
    if (dif23 > 0)
      return 1;
    else
      return 0;


}

int main()
{
  int x[3];
  scanf("%d %d %d", &x[0], &x[1], &x[2]);
  printf("%s\n", Inverno (x) ? ":)" : ":(");
  return 0;
}
