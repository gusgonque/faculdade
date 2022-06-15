#include <stdio.h>
#include "trab3AED.h"
#include "arvoreTRIE_TST.h"

int main() {
    TST_TRIE dicionario = NULL;
    carregarDicionario(&dicionario);
    interfacePrincipal(&dicionario);
    return 0;
}
