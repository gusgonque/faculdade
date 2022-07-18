#include <stdio.h>
#include "trab3AED.h"
#include "arvoreTRIE_TST.h"

int main() {
    TST_TRIE dicionario = NULL;
    printf("Program feito por Gustavo Queiroz e Yuri Bueno\n\n");
    carregarDicionario(&dicionario);
    interfacePrincipal(&dicionario);
    return 0;
}
