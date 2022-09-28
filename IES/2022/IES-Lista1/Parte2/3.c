#include<stdio.h>

double InflcaionaPreco(double preco){
    while(preco<100){
       return preco * 1.1;
    }
    while(preco>=100){
        return preco * 1.2;
    }
}

int main(){
    double preco;
    printf("Digite o preco.\n - ");
    scanf("%lf", &preco);
    preco = InflcaionaPreco(preco);
    printf("Preco inflacionado = %f", preco);
    return 0;
}


