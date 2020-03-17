#include <iostream>
using namespace std;


int fatorial2 (int n)
{
  if (n>0)
    return n*fatorial2(n-1);
  else
    return 1;
}

int main() {
  cout << "Fatorial de 5 = " << fatorial2(5) << endl;
  return 0;
}
