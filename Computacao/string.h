#include <ctype.h>

void Preencher_String_Char ( int tam, char ch, char dest[]) {
    int i;
    for ( i = 0 ; i < tam ; i++)
        dest[i] = ch;
    dest[i] = '\0';
}

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

void Preencher_String_Char_3 ( int n, char ch, char dest[]) {
    int i,j,k;
    for ( i = j = 0 ; i < n ; i++, j++ ) {
        for ( k = 0 ; k <= i ; k++, j++ ) {
            dest[ j ] = ch;
        }
        dest [ j ] = ' ';
    }
    dest[ j ] = '\0';
}

int Tamanho_String ( char *s ) {
    int i;
    for ( i = 0 ; *s ; *(s++) )
        i++;
    return i;
}

void Inverter_String ( char *s ) {
    int i;
    char dest[1000];
    for ( i = 0 ; *(s+i) ; i++ )
        dest[Tamanho_String(s)-1-i] = *(s+i);
    dest [Tamanho_String(s)] = '\0';
    puts(dest);
}
