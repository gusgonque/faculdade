#include <stdio.h>

void Medalhas (int t1, int t2, int t3)
{
  if (t1<t2)
    if (t1<t3)
    {
      printf("1\n");
      if (t2<t3)
        printf("2\n3\n");
      else
        printf("3\n2\n");
    }
    else
      printf("3\n1\n2\n");
  else
    if (t2<t3)
    {
      printf("2\n");
      if (t1<t3)
        printf("1\n3\n");
      else
        printf("3\n1\n");
    }
    else
      printf("3\n2\n1\n");
}

int main()
{
  int t1, t2, t3;
  scanf("%d %d %d", &t1, &t2, &t3);
  Medalhas (t1,t2,t3);
  return 0;
}
