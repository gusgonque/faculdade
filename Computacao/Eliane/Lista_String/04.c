#include <stdio.h>
#include "String.h"

int main () {
    int num_casos, tam, i;
    char str[1000], ch;
    scanf("%d ", &num_casos);
    for ( i = 0 ; i < num_casos ; i++ ) {
        gets(str);
        Inverter_String (str);
    }
    return 0;
}

