#include <stdio.h>
#include <stdlib.h>

#include "arvoreBArq.h"

//Busca a chave info nas chaves e retora 1 se ela está no nó, ou 0 se não está no nó
//o ponteiro posCha contém a posição do nó no vetor de chaves.
int buscaChave(noArvoreB* no, int info, int * posCha) {
    for((*posCha)=0; (*posCha) < no->numChaves; (*posCha)++)
        if(info == no->chave[(*posCha)])
            return 1; // chave já está na árvore
        else if(info < no->chave[(*posCha)])
            break; // info pode estar na subárvore filho[*posCha]
    return 0; // chave não está neste nó
}

//Verifica se o nó é vazio.
int vazia(noArvoreB* no) {
    return (no->numChaves == 0);
}

//Verifica se o nó é uma folha na árvore.
int eh_folha(noArvoreB* no) {
    return (no->filho[0] == -1);
}

//Altera o no na posição posArq para o novo no
//Pré-condição: arquivo deve estar aberto e ser um arquivo de arvore B
//Pós-condilção: nó re-escrito no arquivo
void alteraNoArquivo(FILE* arq, noArvoreB* no, int posArq){
    fseek(arq, sizeof(cabecalhoArvoreB) + posArq * sizeof(noArvoreB), SEEK_SET);
    fwrite(&no, sizeof(noArvoreB), 1, arq);
}

//Insere o novo nó no topo do arquivo
//Pré-condição: arquivo deve estar aberto e ser um arquivo de arvore B
//Pós-condilção: nó escrito no arquivo
void inserirTopoArvoreB(FILE* arq, noArvoreB* no){
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
    noArvoreB* x = malloc(sizeof(noArvoreB));
    fseek(arq, sizeof(cabecalhoArvoreB) + posArq * sizeof(noArvoreB), SEEK_SET);
    fread(x,sizeof(noArvoreB),1,arq);
    return x;
}

// Quebra o no (com overflow) e retorna o no criado e a chave cha que
// deve ser promovida
//Ter que liberar a memória após usar o nonov
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
//Pós-condilção:
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
int overflow(noArvoreB* no) {
    return (no->numChaves == ORDEM);
}

//Insere uma chave à Árvore B não vazia
//Pré-condição: arquivo deve estar aberto e ser um arquivo de arvore B
//Pós-condilção:
void insere_aux(FILE* arq, noArvoreB* noPai, int posArq, int cha, int ptDado){
    int posCha;
    if(!buscaChave(noPai, cha, &posCha)){ // chave não está nesse nó
        if(eh_folha(noPai)) {
            adicionaDireita(noPai, posCha, cha, ptDado, -1);
        }
        else {
            noArvoreB* noFil = leNoArvoreB(arq, noPai->filho[posCha]);
            insere_aux(arq, noFil, noPai->filho[posCha], cha, ptDado);
            if(overflow(noFil))
            {
                cabecalhoArvoreB* cab = leCabecalhoArvoreB(arq);
                int chaAux, ptDadoAux; // valor da chave mediana
                noArvoreB* noAux = split(noFil, &chaAux, &ptDadoAux);
                adicionaDireita(noPai, posCha, chaAux, ptDadoAux , cab->pos_topo);
                inserirTopoArvoreB(arq, noAux);
                alteraNoArquivo(arq, noFil, noPai->filho[posCha]);
                alteraNoArquivo(arq, noPai, posArq);
                free(cab);
            }
        }
    }
}

// Insere uma chave raiz nó na raíz da árvore B
void insereNo(FILE* arq, noArvoreB* raiz, int posArq, int cha, int ptDado){
    cabecalhoArvoreB* cab = leCabecalhoArvoreB(arq);
    if(vazia(raiz)) {
        raiz = malloc(sizeof(noArvoreB));
        raiz->numChaves = 1;
        raiz->chave[0] = cha;
        raiz->ptDado[0] = ptDado;
        raiz->filho[0] = -1;
        alteraNoArquivo(arq, raiz, posArq);
        free(raiz);
        cab->pos_topo++;
    }
    else {
        insere_aux(arq, raiz, posArq, cha, ptDado);
        if(overflow(raiz)){ // verifica se precisa split (CASO 3)
            int chaAux, ptDadoAux;
            noArvoreB* novoFilho = split(raiz, &chaAux, &ptDadoAux);
            noArvoreB* novaRaiz = malloc(sizeof(noArvoreB));
            inserirTopoArvoreB(arq, novoFilho);
            novaRaiz->chave[0] = chaAux;
            novaRaiz->ptDado[0] = ptDadoAux;
            novaRaiz->filho[0] = posArq;//posição do nó original
            novaRaiz->filho[1] = cab->pos_topo;//posição do filho da raiz nova
            free(cab);
            cab = leCabecalhoArvoreB(arq);
            raiz->filho[0] = -1;
            alteraNoArquivo(arq, raiz, posArq);
            novaRaiz->numChaves = 1;
            inserirTopoArvoreB(arq, novaRaiz);
            cab->pos_raiz = cab->pos_topo;
            cab->pos_topo++;
        }
    }
    escreveCabecalhoArvore(arq,cab);
    free(cab);
}

//Cria uma Arvore B nova em arquivo
//Pré-condição: arquivo aberto para leitura/escrita
//Pós-condição: arquivo é inicializado com uma Arvore B vazia
void criaArvoreVazia(FILE* arq){
    cabecalhoArvoreB * cab = (cabecalhoArvoreB*) malloc(sizeof(cabecalhoArvoreB));
    cab->pos_raiz = 0;
    cab->pos_topo = 0;
    cab->pos_livre = -1;
    escreveCabecalhoArvore(arq,cab);
    free(cab);
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

noArvoreB* busca(FILE* arq, noArvoreB* raiz, int info, int* posCha, int* posArq){
    if(vazia(raiz))
        return NULL;
    int i = 0;
    while(i < raiz->numChaves && raiz->chave[i] < info) i++;
    if((i+1) > raiz->numChaves || raiz->chave[i] > info){
        noArvoreB* noAux = leNoArvoreB(arq,raiz->filho[i]);

        //TODO: TERMINAR

        return busca(raiz->filho[i], info, posCha);
    }
    *posCha = i;
    return raiz;
}

//Retira um nó da lista
//Pré-condição: arquivo deve estar aberto e ser um arquivo de lista
//Pós-condição: nó retirado da lista caso pertença a ela
//void retira(FILE* arq, TipoItem x){
//    cabecalhoArvoreB* cab = le_cabecalho(arq);
//    int pos_aux = cab->pos_cabeca;
//    int pos_ant = cab->pos_cabeca;
//    noArvoreB* aux = NULL;
//    while(pos_aux != -1 && // procura o elemento a ser retirado
//          ((aux = le_no(arq,pos_aux))!= NULL) &&
//          aux->info != x){ //TODO: Fazer a comparação!
//        pos_ant = pos_aux;
//        pos_aux = aux->prox;
//        free(aux);
//        aux = NULL;
//    }
//    if(pos_aux != -1) { //encontrou o elemento
//        if(pos_ant == pos_aux){ // remoção na cabeça
//            cab->pos_cabeca = aux->prox;
//        }
//        else { // remoção noArvoreB meio
//            noArvoreB * ant = le_no(arq, pos_ant);
//            ant->prox = aux->prox;
//            escreve_no(arq,ant,pos_ant);
//            free(ant);
//        }
//        aux->prox = cab->pos_livre; // torna o nó removido um nó livre
//        cab->pos_livre = pos_aux;
//        escreve_no(arq,aux,pos_aux);
//        escreve_cabecalho(arq,cab);
//        free(aux);
//    }
//    free(cab);
//}
