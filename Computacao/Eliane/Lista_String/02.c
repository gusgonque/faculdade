#include <stdio.h>

void Alternar_Letra_Maiuscula_Minuscula (char s[]) {
    int i, flag;
    for ( i = 0, flag = 1 ; s[i] ; i++ ) {
        if (isalpha(s[i])) {
            if (flag == 1)
                s[i] = toupper(s[i]);
            else
                s[i] = tolower(s[i]);
            flag *= -1;
        }
    }
}

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
