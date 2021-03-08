#include <stdio.h>
int main( int argc, char **argv)
{
    double a,b,c,d,x,y;
    printf("Entre com 4 numeros: ");
    scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
    for (int i = 0; i < 4; i++)
    {
      x = a;
      y = b;
      a = (x>y?x:y);
      b = (x<y?x:y);
      x = b;
      y = c;
      b = (x>y?x:y);
      c = (x<y?x:y);
      x = c;
      y = d;
      c = (x>y?x:y);
      d = (x<y?x:y);
    }
    printf("%.1lf\n", b);
    return(0);
}
