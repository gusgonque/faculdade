#include <stdio.h>
#include "arvoreBTrab.h"

// procura o código no arquivo de indices
// retorna -1 se não está presente, qualquer outro retorno é a posição no arquivo de dados.
int buscaCodigo(int cod){
    registro regAux;
    int i, raiz, aux;
    FILE* arqInd = fopen("arqIndices.bin","rb");
    if (arqInd == NULL)
        return -1;

    fread(&raiz,sizeof(int),1,arqInd);
    fseek(arqInd,2*sizeof(int),SEEK_CUR);

    for (i = 0; i < raiz; ++i)
        fseek(arqInd,sizeof(registro),SEEK_CUR);

    fread(&regAux, sizeof(registro), 1, arqInd);
    fclose(arqInd);
    if (buscaPos(regAux, cod, &aux)){
        return regAux.ptDad[aux];
    } else {

    }

    return -1;
}

int buscaPos(registro reg, int info, int * pos) {
    for((*pos)=0; (*pos) < reg.numCha; (*pos)++)
        if(info == reg.cha[(*pos)])
            return 1; // chave já está na árvore
        else if(info < reg.cha[(*pos)])
            break; // info pode estar na subárvore filho[*pos]
    return 0; // chave não está neste nó
}

int vazia(registro reg) {
    return (reg.numCha == 0);
}

int eh_folha(registro reg) {
    return (reg.fil[0] == -1);
}

// Quebra o registro reg (com overflow) e retorna o registro criado e a chave chaPro que
// deve ser promovida
registro split(registro reg, int* chaPro) {
    registro regNov;
    int q = reg.numCha / 2;
    regNov.numCha = reg.numCha - q - 1;
    reg.numCha = q;
    *chaPro = reg.cha[q]; // chave mediana
    int i = 0;
    regNov.fil[0] = reg.fil[q + 1];
    for(i = 0; i < regNov.numCha; i++){
        regNov.cha[i] = reg.cha[q + i + 1];
        regNov.fil[i + 1] = reg.fil[q + i + 2];
    }
    return regNov;
}

// Adiciona a chave cha com o filho fil no registro reg.
void adicionaDireita(registro reg, int pos, int cha, int fil){
    int i;
    for(i=reg.numCha; i > pos; i--){
        reg.cha[i] = reg.cha[i - 1];
        reg.fil[i + 1] = reg.fil[i];
    }
    reg.cha[pos] = cha;
    reg.fil[pos + 1] = fil;
    reg.numCha++;
}

int overflow(registro reg) {
    return (reg.numCha==TAM);
}

registro procuraIndice(int ind){
    registro regAux;
    FILE* arqInd = fopen("arqIndices.bin","rb");
    fseek(arqInd,3,SEEK_CUR);
    fread(&regAux,sizeof (registro),ind,arqInd);
    fclose(arqInd);
    return regAux;
}

void insere_aux(registro reg, int info){
    int pos;
    if(!buscaPos(reg, info, &pos)){ // chave não está no registrador
        registro regFil = procuraIndice(reg.fil[pos]);
        if(eh_folha(reg)) {
            adicionaDireita(reg, pos, info, -1);
        }
        else {
            insere_aux(regFil, info);
            if(overflow(regFil))
            {
                int m; // valor da chave mediana
                registro regAux = split(regFil, &m);// TODO: fazer pra arquivo
                adicionaDireita(reg, pos, m, reg.fil[pos]);// TODO: fazer pra arquivo
            }
        }
    }
}


// Insere uma chave na ´arvore B e retorna raiz modificada
arvoreB* insere(arvoreB* r, int info){
    if(vazia(r)) {
        r = malloc(sizeof(arvoreB));
        r->chave[0] = info;
        for(int i = 0; i < ORDEM; i++)
            r->filho[i] = NULL;
        r->numChaves = 1;
    }
    else {
        insere_aux(r,info);
        if(overflow(r)){ // verifica se precisa split
            int m;
            arvoreB* x = split(r,&m);
            arvoreB* novaRaiz = malloc(sizeof(arvoreB));
            novaRaiz->chave[0] = m;
            novaRaiz->filho[0] = r;
            novaRaiz->filho[1] = x;
            for(int i = (((int)ORDEM/2)+1); i < ORDEM; i++)
                r->filho[i] = NULL;
            novaRaiz->numChaves = 1;
            return novaRaiz;
        }
    }
