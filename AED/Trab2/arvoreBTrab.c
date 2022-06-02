#include <stdio.h>
#include "arvoreBTrab.h"

int buscaCodigo(int x){
    registro regAux;
    int i, raiz, aux;
    FILE* arqInd = fopen("arqIndices.bin","rb");
    if (arqInd == NULL)
        return -1;

    fread(&raiz,sizeof(int),1,arqInd);
    for (i = 0; i < raiz; ++i)
        fseek(arqInd,sizeof(registro),SEEK_CUR);

    fread(&regAux, sizeof(registro), 1, arqInd);
    while (regAux.cha[0] != x) {
        for (i = 1; i < TAM; ++i) {
            fread(&regAux, sizeof(registro), 1, arqInd);
            if(regAux.cha[0] == x) {
                break;
            }
        }
    }


    fclose(arqInd);
    return -1;
}

