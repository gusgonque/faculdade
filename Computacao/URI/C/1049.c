#include <stdio.h>

int Str_Iguais (char s1[], char s2[]) {
    int i;
    printf("Sao iguais?\n");
    for ( i = 0 ; s1[i] ; i++ )
        if ( s1[i] != s2[i])
            return 1;
        else
            return 0;
}

void Animal ( char s1, char s2, char s3 ) {
    if (Str_Iguais (s1,"vertebrado"))
        if (Str_Iguais (s2,"ave"))
            if (Str_Iguais (s3,"carnivoro"))
                printf("aguia\n");
            else
                printf("pomba\n");
        else
            if (Str_Iguais (s3,"onivoro"))
                printf("homem\n");
            else
                printf("vaca\n");
    else
        if (Str_Iguais (s2,"inseto"))
            if (Str_Iguais (s3,"hematofago"))
                printf("pulga\n");
            else
                printf("lagarta\n");
        else
            if (Str_Iguais (s3,"hematofago"))
                printf("sanguessuga\n");
            else
                printf("minhoca\n");

}

int main () {
    char s1[100], s2[100], s3[100];
    gets(s1);
    gets(s2);
    gets(s3);
    Animal ( s1, s2, s3 );
    return 0;
}
