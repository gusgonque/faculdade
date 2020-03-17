#include <iostream>
using namespace std;

// n 0 1 2 3 4 5 6 ...
// r 0 1 1 2 3 5 8 ...

int fibonacci (int m,int n)
{
  if (n>1)
  {
    printf("Teste n = %d \n",n);
    return fibonacci ( m , n-1 ) + fibonacci ( m , n-2 );
  }
  else
    if (n==1)
      return 1;
    else
      return 0;


}

int main() {
  int n;
  cout << "Selecione um termo da sequencia de Fibonacci" << endl;
  scanf("%d", &n);
  cout << "Esse termo da sequencia de Fibonacci = " << fibonacci(0,n) << endl;
  return 0;
}
