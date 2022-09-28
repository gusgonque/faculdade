#include <stdio.h>

void ImprimeValores(int x){
    printf("Em metros: %d\n", x);
    printf("Em decimetros: %d\n", x*10);
    printf("Em centimetros: %d\n", x*100);
    printf("Em milimetros: %d\n", x*1000);
}

int main(){
    int x;
    printf("digite o valor em metros.\n - ");
    scanf("%d",&x);
    ImprimeValores(x);
}
