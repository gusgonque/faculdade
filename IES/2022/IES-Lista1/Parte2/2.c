#include<stdio.h>

void funcao(){
    int i;
    printf("Tabela ASCII em decimal:\n");
    for( i=0 ; i<127 ; i++)
        printf("%d\n", i);
    printf("Tabela ASCII em hexadecimal:\n");
    for( i=0 ; i<127 ; i++)
        printf("%x\n", i);
    printf("Tabela ASCII em caracter:\n");
    for( i=0 ; i<127 ; i++)
        printf("%c\n", i);
}

int main(){
    funcao();
    return 0;
}

