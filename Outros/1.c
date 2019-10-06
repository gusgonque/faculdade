#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

int *filtro(char *s1)
{
    static char s2[MAX];
    int i, t;

    t = strlen(s1);

    for(i=0;i<(t-1);++i){
        s2[i]=s1[i];

        if ((s1[i] >= 'a' && s1[i] <= 'z') || (s1[i] >= 'A' && s1[i] <= 'Z') || (s1[i] >= '0' && s1[i] <= '9')){
        s2[i] = s1[i];
    }
        else {
        s2[i] = '_';
    }

    }
    return s2;
}



int main()
{
    char s1[MAX];
    char *sf;

    printf("Escreva uma frase(string):\n");
    fgets(s1, MAX, stdin);

    sf = filtro(s1);

    printf("A frase apos o filtro e:\n");
    printf("%s", sf);

    return 0;
}
