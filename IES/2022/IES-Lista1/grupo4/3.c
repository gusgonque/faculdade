#include <stdio.h>

int fatorialRecursivo(int x){
    if(x>1)
        return x*fatorialRecursivo(x-1);
    else
        return x;
}

int potencia(int x, int n){
    int i, res;
    if(n=0)
        return 1;
    for( i=0, res=x ; i<n-1 ; i++ ){
        res*=x;
    }
    return res;
}

double calculaEx(double x, int n){
    double y = (potencia(x,n)/fatorialRecursivo(n));
    if(x>516.73529967)
        return y+calculaEx(x,n+1);
    else
        return 0;
}

int main() {
    printf("Ex de 5 = %ld\n", calculaEx(5.0,0));
    return 0;
}


