#include <stdio.h>
#include <math.h>

int main()
{
  int basOri, basDes, numInt, desNaoInt;
  double numNaoInt, numDes;
  printf(" Digite a base origem do seu numero.\n - ");
  scanf("%d", &basOri);
  printf(" Digite a base destino do seu numero.\n - ");
  scanf("%d", &basDes);

  printf(" Digite a parte inteira de seu numero.\n - ");
  scanf("%d", &numInt);
  printf(" Digite a parte nao inteira de seu numero. (comece com 0.)\n - ");
  scanf("%lf", &numNaoInt);

  int i;
  for ( i = numDes = 0 ; ((numInt/basDes) > 0) && (i<20) ; i++ )
  {
    numDes += ((numInt%basDes)*(pow(10,i)));
    numInt = (numInt/basDes);
    printf("%lf\n", numDes);
  }
  for ( i = desNaoInt =0 ; ((numNaoInt*basDes)-1 != 0) && (i<20) ; i++ )
  {
    desNaoInt += ((numNaoInt*basDes)*(pow(10,-i)));
    numNaoInt = (numNaoInt*basDes);
    if (numNaoInt >= 1)
      numNaoInt--;
    printf("%d\n", desNaoInt);
  }


}
