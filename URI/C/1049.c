#include <stdio.h>
#include <string.h>

void Animal ( char s1[], char s2[], char s3[] ) {
    if (!strcmp(s1,"vertebrado"))
        if (!strcmp(s2,"ave"))
            if (!strcmp(s3,"carnivoro"))
                printf("aguia\n");
            else
                printf("pomba\n");
        else
            if (!strcmp(s3,"onivoro"))
                printf("homem\n");
            else
                printf("vaca\n");
    else
        if (!strcmp(s2,"inseto"))
            if (!strcmp(s3,"hematofago"))
                printf("pulga\n");
            else
                printf("lagarta\n");
        else
            if (!strcmp(s3,"hematofago"))
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
