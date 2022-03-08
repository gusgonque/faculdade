// 7. Projete um algoritmo recursivo que dada uma cadeia de caracteres str, decida se str ´e pal´ındrome ou n˜ao.
#include <stdio.h>
#include <string.h>

int palindromo (char *i, char *f){
    if (i==f)
        return 1;
    if (*i == *f){
        return 1 && palindromo (i+1,f-1);
    }
    else
        return 0;
}

int main (){
    char str [5] = "arara";
    if (palindromo(str,str+strlen(str)-1))
        printf("Eh palindromo.\n");
    else
        printf("Nao eh palindromo.\n");
    return 0;
}
