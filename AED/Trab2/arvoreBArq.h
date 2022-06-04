#ifndef FACULDADE_ARVOREBARQ_H
#define FACULDADE_ARVOREBARQ_H

#include "trab2AED.h"

// cabecalhoListaEncadeada do arquivo
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
int vazia(noArvoreB* no);
int eh_folha(noArvoreB* reg);
void alteraNoArquivo(FILE* arq, noArvoreB* no, int posArq);
void inserirTopo(FILE* arq, noArvoreB* no);
noArvoreB* le_no(FILE* arq, int posArq);
noArvoreB* split(noArvoreB* no, int* cha, int* ptDado);
void adicionaDireita(noArvoreB* no, int posCha, int cha, int ptDado, int fil);
int overflow(noArvoreB* no);
noArvoreB* insereNo(FILE* arq, noArvoreB* no, int posArq, int cha, int ptDado);
void criaArvoreVazia(FILE* arq);
cabecalhoArvoreB* le_cabecalho(FILE * arq);
void escreve_cabecalho(FILE* arq, cabecalhoArvoreB* cab);
noArvoreB* le_no(FILE* arq, int posArq);

//void retira(FILE* arq, TipoItem x);

#endif //FACULDADE_ARVOREBARQ_H
