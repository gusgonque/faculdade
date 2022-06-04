#ifndef FACULDADE_LISTAENCADEADAARQUIVO_H
#define FACULDADE_LISTAENCADEADAARQUIVO_H

#include "trab2AED.h"

typedef profissional TipoItem; // tipo dos elementos na lista

// cabecalhoListaEncadeada do arquivo
typedef struct {
    int pos_cabeca; //posição do início da lista
    int pos_topo; // 1a posição não usada noListaEncadeada fim do arquivo
    int pos_livre; // posição do início da lista de nós livres
} cabecalhoListaEncadeada;

// estrutura de noListaEncadeada para lista encadeada
typedef struct {
    TipoItem info;
    int prox;
} noListaEncadeada;

void cria_lista_vazia(FILE* arq);

cabecalhoListaEncadeada* le_cabecalho(FILE * arq);

void escreve_cabecalho(FILE* arq, cabecalhoListaEncadeada* cab);

noListaEncadeada* le_no(FILE* arq, int posArq);

void escreve_no(FILE* arq, noListaEncadeada* x, int pos);

void insere_lista(FILE* arq, TipoItem info);

void retira(FILE* arq, TipoItem x);

#endif //FACULDADE_LISTAENCADEADAARQUIVO_H
