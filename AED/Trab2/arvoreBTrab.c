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
        for (i = 1; i < regAux.numCha; ++i) {
            fread(&regAux, sizeof(registro), 1, arqInd);
            if(regAux.cha[i] == x) {
                return regAux.ptDad[i];
            }
        }
    }


    fclose(arqInd);
    return -1;
}

////Quebra o n´o x (com overflow) e retorna o n´o criado e chave m que
//// deve ser promovida
//arvoreB* split(arvoreB* x, int * m) {
//    arvoreB* y = (arvoreB*) malloc(sizeof(arvoreB));
//    int q = x->numChaves/2;
//    y->numChaves = x->numChaves - q - 1;
//    x->numChaves = q;
//    *m = x->chave[q]; // chave mediana
//    int i = 0;
//    y->filho[0] = x->filho[q+1];
//    for(i = 0; i < y->numChaves; i++){
//        y->chave[i] = x->chave[q+i+1];
//        y->filho[i+1] = x->filho[q+i+2];
//    }
//    return y;
//}
//
//int eh_folha(arvoreB* r) {
//    return (r->filho[0] == NULL);
//}
//
//void adicionaDireita(arvoreB* r, int pos, int k, arvoreB* p){
//    int i;
//    for(i=r->numChaves; i>pos; i--){
//        r->chave[i] = r->chave[i-1];
//        r->filho[i+1] = r->filho[i];
//    }
//    r->chave[pos] = k;
//    r->filho[pos+1] = p;
//    r->numChaves++;
//}
//
//void insere_aux(arvoreB* r, int info){
//    int pos;
//    if(!buscaPos(r,info, &pos)){ // chave n~ao est´a no n´o r
//        if(eh_folha(r)) {
//            adicionaDireita(r,pos,info,NULL);
//        }
//        else {
//            insere_aux(r->filho[pos],info);
//            if(overflow(r->filho[pos])){
//                int m; // valor da chave mediana
//                arvoreB* aux = split(r->filho[pos],&m);
//                adicionaDireita(r,pos,m,aux);
//            }
//        }
//    }
//}
//
//// Insere uma chave na ´arvore B e retorna raiz modificada
//arvoreB* insere(arvoreB* r, int info){
//    if(vazia(r)) {
//        r = malloc(sizeof(arvoreB));
//        r->chave[0] = info;
//        for(int i = 0; i < ORDEM; i++)
//            r->filho[i] = NULL;
//        r->numChaves = 1;
//    }
//    else {
//        insere_aux(r,info);
//        if(overflow(r)){ // verifica se precisa split
//            int m;
//            arvoreB* x = split(r,&m);
//            arvoreB* novaRaiz = malloc(sizeof(arvoreB));
//            novaRaiz->chave[0] = m;
//            novaRaiz->filho[0] = r;
//            novaRaiz->filho[1] = x;
//            for(int i = (((int)ORDEM/2)+1); i < ORDEM; i++)
//                r->filho[i] = NULL;
//            novaRaiz->numChaves = 1;
//            return novaRaiz;
//        }
//    }
