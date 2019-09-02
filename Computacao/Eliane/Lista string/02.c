#include <stdio.h>
#include "String.h"

int main () {
    int num_casos, tam, i;
    char str[100], ch;
    scanf("%d ", &num_casos);
    for ( i = 0 ; i < num_casos ; i++ ) {
        gets(str);
        Alternar_Letra_Maiuscula_Minuscula (str);
        puts (str);
    }
    return 0;
}
