#include <stdio.h>

int potencia(int x, int n){
    int i, res;
    for( i=0, res=x ; i<n-1 ; i++ ){
        res*=x;
    }
    return res;
}

int main() {
    printf("2^5 = %d", potencia(2,5));
    return 0;
}
