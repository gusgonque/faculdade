#include <stdio.h>

int fatorialLaco(int x){
    int i, res;
    for( i=0, res=1 ; i<x ; i++ ){
        res*=i+1;
    }
    return res;
}

int fatorialRecursivo(int x){
    if(x>1)
        return x*fatorialRecursivo(x-1);
    else
        return x;
}

int main() {
    printf("fatorial de 5 laco = %d\n", fatorialLaco(5));
    printf("fatorial de 5 recursivo = %d\n", fatorialRecursivo(5));
    return 0;
}

