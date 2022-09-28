#include<stdio.h>

void funcao(int x, int y){
    int i;
    if(x<y){
        for( i=x ; i<=y ; i++ )
            printf("%d\n", i);
    } else if (x>y){
        for( i=x ; i>=y ; i-- )
            printf("%d\n", i);
    } else {
        printf("Valores iguais\n");
    }
}

int main(){
    int x,y;
    printf("Digite os valores.\n - ");
    scanf("%d %d", &x, &y);
    funcao(x,y);
    return 0;
}
