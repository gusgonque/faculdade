#include <stdio.h>

void ImprimeHexaOctal(int x){
    printf("Em hexadecimal: %x\n", x);
    printf("Em octadecimal: %o\n", x);
}

int main (){
    int x;
    printf("Digite o valor a ser apresentado em hexadecimal e octadecimal.\n - ");
    scanf("%d", &x);
    ImprimeHexaOctal(x);
    return 0;
}
