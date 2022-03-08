// Projete uma fun¸c˜ao recursiva para calcular o n-´esimo n´umero catal˜ao, dado pela f´ormula:
#include <stdio.h>

int C (int n){
    if (n==0)
        return 1;
    else
        return ((2*((2*n)-1))/(n+1))*C(n-1);
}

int main () {
    printf ("Catalao de 1 = %d\n", C(1));
    printf ("Catalao de 2 = %d\n", C(2));
    printf ("Catalao de 3 = %d\n", C(3));

    return 0;
}