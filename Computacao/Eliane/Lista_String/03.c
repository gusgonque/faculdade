#include <stdio.h>
#include "String.h"

int main () {
    int num_casos, tam, i;
    char str[1000], ch;
    scanf("%d", &num_casos);
    for ( i = 0 ; i < num_casos ; i++ ) {
        scanf("%d %c", &tam, &ch);
        Preencher_String_Char_3 (tam,ch,str);
        puts (str);
    }
    return 0;
}
