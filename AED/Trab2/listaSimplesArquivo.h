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

//Cria uma lista nova em arquivo
//Pré-condição: arquivo aberto para leitura/escrita
//Pós-condição: arquivo é inicializado com uma lista noEhVazio
void cria_lista_vazia(FILE* arq);

//Lê o cabeçalho da lista e retorna este
//Pré-condição: arquivo aberto para leitura/escrita
//Pós-condição: retorna o cabeçalho lido
cabecalhoLista* le_cabecalho_lista(FILE * arq);

//Escreve noArvoreB arquivo o cabeçalho contendo as informações da lista
//Pré-condição: arquivo deve estar aberto e ser um arquivo de lista
//Pós-condilção: cabeçalho escrito noArvoreB arquivo
void escreve_cabecalho_lista(FILE* arq, cabecalhoLista* cab);

//lê um nó em uma determinada posição do arquivo
//Pré-condição: arquivo deve estar aberto e ser um arquivo de lista
// pos deve ser uma posição válida da lista
//Pós-condição: ponteiro para nó lido é retornado
noLista* le_no_lista(FILE* arq, int posArq);

//Escreve um nó em uma determinada posição do arquivo
//Pré-condição: arquivo deve estar aberto e ser um arquivo de lista
// pos deve ser uma posição válida do arquivo
//Pós-condição: nó escrito noArvoreB arquivo
void escreve_no(FILE* arq, noLista* x, int pos);

//Insere um nó na cabeça do arquivo
//Pré-condição: arquivo deve estar aberto e ser um arquivo de lista
//Pós-condição: nó escrito noArvoreB arquivo
int insere_lista(FILE* arq, TipoItem info);

#endif //FACULDADE_LISTASIMPLESARQUIVO_H
