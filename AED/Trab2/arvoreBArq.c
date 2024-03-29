#include <stdio.h>
#include <stdlib.h>

#include "arvoreBArq.h"

//Busca a chave info nas chaves e retora 1 se ela está no nó, ou 0 se não está no nó
//o ponteiro posCha contém a posição do nó no vetor de chaves.
//Pré-condição: no criado
//Pós-condilção: retora 1 se a info está no nó, ou 0 se não está no nó
int buscaChave(noArvoreB* no, int info, int * posCha) {
    for((*posCha)=0; (*posCha) < no->numChaves; (*posCha)++)
        if(info == no->chave[(*posCha)])
            return 1; // chave já está na árvore
        else if(info < no->chave[(*posCha)])
            break; // info pode estar na subárvore filho[*posCha]
    return 0; // chave não está neste nó
}

//Verifica se o nó é vazio.
//Pré-condição: no criado
//Pós-condilção: retora 1 se o nó é vazio, ou 0 se não
int noEhVazio(noArvoreB* no) {
    return (no->numChaves == 0);
}

//Verifica se o nó é uma folha na árvore.
//Pré-condição: no criado
//Pós-condilção: retora 1 se o nó é uma folha, ou 0 se não
int eh_folha(noArvoreB* no) {
    return (no->filho[0] == -1);
}

//Altera o no na posição posArq para o novo no
//Pré-condição: arquivo deve estar aberto e ser um arquivo de arvore B
//Pós-condilção: nó re-escrito no arquivo
void alteraNoArquivo(FILE* arq, noArvoreB* no, int posArq){
    fseek(arq, sizeof(cabecalhoArvoreB) + (posArq * sizeof(noArvoreB)), SEEK_SET);
    fwrite(no, sizeof(noArvoreB), 1, arq);
}

//Insere o novo nó no topo do arquivo
//Pré-condição: arquivo deve estar aberto e ser um arquivo de arvore B
//Pós-condilção: nó escrito no arquivo
void escreveTopoArvoreB(FILE* arq, noArvoreB* no){
    cabecalhoArvoreB* cab = leCabecalhoArvoreB(arq);
    alteraNoArquivo(arq,no,cab->pos_topo);
    cab->pos_topo++;
    escreveCabecalhoArvore(arq,cab);
    free(cab);
}

//lê um nó em uma determinada posição do arquivo
//Pré-condição: arquivo deve estar aberto e ser um arquivo de Arvore B
// posArq deve ser uma posição válida da Arvore B
//Pós-condição: ponteiro para nó lido é retornado
//Ter que liberar a memória após usar o x
noArvoreB* leNoArvoreB(FILE* arq, int posArq) {
    cabecalhoArvoreB* cab = leCabecalhoArvoreB(arq);
    noArvoreB* noVaz = malloc(sizeof (noArvoreB));
    if(posArq<0||posArq>cab->pos_topo) {
        noVaz->numChaves = 0;
        return noVaz;
    }
    free(noVaz);
    noArvoreB* noAux = malloc(sizeof(noArvoreB));
    fseek(arq, sizeof(cabecalhoArvoreB) + (posArq * sizeof(noArvoreB)), SEEK_SET);
    fread(noAux, sizeof(noArvoreB), 1, arq);
    return noAux;
}

// Quebra o no (com ehOverflow) e retorna o no criado e a chave cha que deve ser promovida
// Ter que liberar a memória após usar o nonov
// Pré-condição: no valido.
// Pós-condição: retorna o no criado e a chave cha que deve ser promovida
noArvoreB* split(noArvoreB* no, int* cha, int* ptDado) {
    noArvoreB *noNov = (noArvoreB*) malloc(sizeof(noArvoreB));
    int q = no->numChaves / 2;
    noNov->numChaves = no->numChaves - q - 1;
    no->numChaves = q;
    *cha = no->chave[q]; // chave mediana
    *ptDado = no->ptDado[q]; // ptDado mediano
    noNov->filho[0] = no->filho[q + 1];
    int i;
    for(i = 0; i < noNov->numChaves; i++){
        noNov->chave[i] = no->chave[q + i + 1];
        noNov->ptDado[i] = no->ptDado[q + i + 1];
        noNov->filho[i + 1] = no->filho[q + i + 2];
    }
    return noNov;
}

// Adiciona a chave cha com o filho fil.
// Pré-condição: no valido.
//Pós-condilção: adiciona a chave cha no nó
// o nó deve ser alterado no arquivo após adicionar a chave
void adicionaDireita(noArvoreB* no, int posCha, int cha, int ptDado, int fil){
    int i;
    for(i=no->numChaves; i > posCha; i--){
        no->chave[i] = no->chave[i - 1];
        no->ptDado[i] = no->ptDado[i - 1];
        no->filho[i + 1] = no->filho[i];
    }
    no->chave[posCha] = cha;
    no->ptDado[posCha] = ptDado;
    no->filho[posCha + 1] = fil;
    no->numChaves++;
}

// Verifica se o nó tem o número máximo de chaves.
//Pré-condição: no valido
//Pós-condilção: retora 1 se o nó tem exesso de chaves, ou 0 se não
int ehOverflow(noArvoreB* no) {
    return (no->numChaves == ORDEM);
}

//Insere uma chave à Árvore B não vazia
//Pré-condição: arquivo deve estar aberto e ser um arquivo de arvore B
//Pós-condilção: insere o chave no nó
void insere_aux(FILE* arq, noArvoreB* noPai, int posArq, int cha, int ptDado){
    int posCha;
    if(!buscaChave(noPai, cha, &posCha)){ // chave não está nesse nó
        if(eh_folha(noPai)) {
            adicionaDireita(noPai, posCha, cha, ptDado, -1);
        }
        else {
            noArvoreB* noFil = leNoArvoreB(arq, noPai->filho[posCha]);
            insere_aux(arq, noFil, noPai->filho[posCha], cha, ptDado);
            if(ehOverflow(noFil)){
                cabecalhoArvoreB* cab = leCabecalhoArvoreB(arq);
                int chaAux, ptDadoAux; // valor da chave mediana
                noArvoreB* noAux = split(noFil, &chaAux, &ptDadoAux);
                adicionaDireita(noPai, posCha, chaAux, ptDadoAux , cab->pos_topo);
                cab->pos_topo++;
                escreveTopoArvoreB(arq, noAux);
                alteraNoArquivo(arq, noFil, noPai->filho[posCha]);
                escreveCabecalhoArvore(arq,cab);free(cab);
            }
        }
        alteraNoArquivo(arq, noPai, posArq);
    }
}

// Insere uma chave raiz nó na raíz da árvore B
//Pré-condição: arquivo deve estar aberto e ser um arquivo de arvore B
//Pós-condilção: insere o chave no nó
void insereNo(FILE* arq, noArvoreB* raiz, int posArq, int cha, int ptDado){
    cabecalhoArvoreB* cab = leCabecalhoArvoreB(arq);
    int i;
    if(noEhVazio(raiz)) {
        raiz = malloc(sizeof(noArvoreB));
        raiz->numChaves = 1;
        raiz->chave[0] = cha;
        for ( i = 1; i < ORDEM; ++i)
            raiz->chave[i] = -1;
        raiz->ptDado[0] = ptDado;
        for ( i = 1; i < ORDEM; ++i)
            raiz->ptDado[i] = -1;
        for ( i = 0; i <= ORDEM; ++i)
            raiz->filho[i] = -1;
        alteraNoArquivo(arq, raiz, posArq);
        free(raiz);
        cab->pos_topo++;
        escreveCabecalhoArvore(arq,cab);
    }
    else {
        insere_aux(arq, raiz, posArq, cha, ptDado);
        if(ehOverflow(raiz)){ // verifica se precisa split (CASO 3)
            int chaAux, ptDadoAux;
            noArvoreB* novoFilho = split(raiz, &chaAux, &ptDadoAux);
            noArvoreB* novaRaiz = malloc(sizeof(noArvoreB));
            escreveTopoArvoreB(arq, novoFilho);
            novaRaiz->numChaves = 1;
            novaRaiz->chave[0] = chaAux;
            for ( i = 1; i < ORDEM; ++i)
                novaRaiz->chave[i] = -1;
            novaRaiz->ptDado[0] = ptDadoAux;
            for ( i = 1; i < ORDEM; ++i)
                novaRaiz->ptDado[i] = -1;
            novaRaiz->filho[0] = posArq;//posição do nó original
            novaRaiz->filho[1] = cab->pos_topo;//posição do filho da raiz nova
            for ( i = 2; i <= ORDEM; ++i)
                novaRaiz->filho[i] = -1;
            free(cab);
            cab = leCabecalhoArvoreB(arq);
            raiz->filho[0] = -1;
            alteraNoArquivo(arq, raiz, posArq);
            escreveTopoArvoreB(arq, novaRaiz);
            cab->pos_raiz = cab->pos_topo;
            cab->pos_topo++;
            escreveCabecalhoArvore(arq,cab);
        } else
            alteraNoArquivo(arq,raiz,posArq);
    }
    free(cab);
}

//Cria uma Arvore B nova em arquivo
//Pré-condição: arquivo aberto para leitura/escrita
//Pós-condição: arquivo é inicializado com uma Arvore B noEhVazio
void criaArvoreVazia(FILE* arq){
    cabecalhoArvoreB * cab = (cabecalhoArvoreB*) malloc(sizeof(cabecalhoArvoreB));
    cab->pos_raiz = 0;
    cab->pos_topo = 0;
    cab->pos_livre = -1;
    escreveCabecalhoArvore(arq,cab);
    noArvoreB* noRai = malloc(sizeof (noArvoreB));
    noRai->numChaves = 0;
    alteraNoArquivo(arq,noRai,0);
    free(cab);
    free(noRai);
}

//Lê o cabeçalho da Arvore B e retorna este
//Pré-condição: arquivo aberto para leitura/escrita
//Pós-condição: retorna o cabeçalho lido
//Ter que liberar a memória após usar o cab
cabecalhoArvoreB* leCabecalhoArvoreB(FILE * arq) {
    cabecalhoArvoreB * cab = (cabecalhoArvoreB*) malloc(sizeof(cabecalhoArvoreB));
    fseek(arq,0,SEEK_SET); // posiciona noArvoreB início do arquivo
    fread(cab, sizeof(cabecalhoArvoreB), 1, arq);
    return cab;
}

//Escreve noArvoreB arquivo o cabeçalho contendo as informações da Arvore B
//Pré-condição: arquivo deve estar aberto e ser um arquivo de Arvore B
//Pós-condilção: cabeçalho escrito noArvoreB arquivo
void escreveCabecalhoArvore(FILE* arq, cabecalhoArvoreB* cab){
    fseek(arq,0,SEEK_SET); //posiciona noArvoreB início do arquivo
    fwrite(cab, sizeof(cabecalhoArvoreB), 1, arq);
}

//Busca o nó no arquivo de Árvore B, retornando umna chave vazia se não encontrá-lo
//Se encontrar, utilizar as posições para continuar
//Lembrar de liberar memória do nó retornado após utilização.
//Pré-condição: arquivo deve estar aberto e ser um arquivo de Arvore B
//Pós-condilção: retorna o nó que estiver o info
noArvoreB* buscaArvoreB(FILE* arq, noArvoreB* raiz, int info, int* posCha, int* posArqDad){
    noArvoreB* noAux = malloc(sizeof (noArvoreB));
    if(noEhVazio(raiz)) {
        noAux->numChaves = 0;
        return noAux;
    }
    int i = 0;
    while(i < raiz->numChaves && raiz->chave[i] < info) i++;
    if((i+1) > raiz->numChaves || raiz->chave[i] > info){
        free(noAux);
        noAux = leNoArvoreB(arq,raiz->filho[i]);
        *posArqDad = raiz->ptDado[i];
        return buscaArvoreB(arq, noAux, info, posCha, posArqDad);
    }
    *posCha = i;
    return raiz;
}
