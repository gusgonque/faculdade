#ifndef FACULDADE_ARVOREBARQ_H
#define FACULDADE_ARVOREBARQ_H

#include "trab2AED.h"

// cabecalhoLista do arquivo
typedef struct {
    int pos_raiz; //posição da raiz da arvore
    int pos_topo; // 1a posição não usada noArvoreB fim do arquivo
    int pos_livre; // posição do início da lista de nós livres
} cabecalhoArvoreB;

#define ORDEM 5 // Ordem

typedef struct no {
    int numChaves;
    int chave[ORDEM];
    int ptDado[ORDEM];
    int filho[ORDEM+1];
} noArvoreB;

int buscaChave(noArvoreB* no, int info, int * posCha);

int noEhVazio(noArvoreB* no);

int eh_folha(noArvoreB* reg);

void alteraNoArquivo(FILE* arq, noArvoreB* no, int posArq);

void inserirTopoArvoreB(FILE* arq, noArvoreB* no);

noArvoreB* leNoArvoreB(FILE* arq, int posArq);

noArvoreB* split(noArvoreB* no, int* cha, int* ptDado);

void adicionaDireita(noArvoreB* no, int posCha, int cha, int ptDado, int fil);

int ehOverflow(noArvoreB* no);

void insereNo(FILE* arq, noArvoreB* raiz, int posArq, int cha, int ptDado);

void criaArvoreVazia(FILE* arq);

cabecalhoArvoreB* leCabecalhoArvoreB(FILE * arq);

void escreveCabecalhoArvore(FILE* arq, cabecalhoArvoreB* cab);

noArvoreB* buscaArvoreB(FILE* arq, noArvoreB* raiz, int info, int* posCha, int* posArq);

//void retira(FILE* arq, TipoItem x);

#endif //FACULDADE_ARVOREBARQ_H
