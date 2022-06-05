#ifndef FACULDADE_LISTASIMPLESARQUIVO_H
#define FACULDADE_LISTASIMPLESARQUIVO_H

#include "trab2AED.h"

typedef profissional TipoItem; // tipo dos elementos na lista

// cabecalhoLista do arquivo
typedef struct {
    int pos_topo; // 1a posição não usada noLista fim do arquivo
    int pos_livre; // posição do início da lista de nós livres
} cabecalhoLista;

// estrutura de noLista para lista encadeada
typedef struct {
    TipoItem info;
} noLista;

void cria_lista_vazia(FILE* arq);

cabecalhoLista* le_cabecalho_lista(FILE * arq);

void escreve_cabecalho_lista(FILE* arq, cabecalhoLista* cab);

noLista* le_no_lista(FILE* arq, int posArq);

void escreve_no(FILE* arq, noLista* x, int pos);

int insere_lista(FILE* arq, TipoItem info);

//void retira(FILE* arq, TipoItem x);

#endif //FACULDADE_LISTASIMPLESARQUIVO_H
