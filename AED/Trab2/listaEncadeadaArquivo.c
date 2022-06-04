#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeadaArquivo.h"

//Cria uma lista nova em arquivo
//Pré-condição: arquivo aberto para leitura/escrita
//Pós-condição: arquivo é inicializado com uma lista vazia
void cria_lista_vazia(FILE* arq){
    cabecalhoListaEncadeada * cab = (cabecalhoListaEncadeada*) malloc(sizeof(cabecalhoListaEncadeada));
    cab->pos_cabeca = -1;
    cab->pos_topo = 0;
    cab->pos_livre = -1;
    escreve_cabecalho(arq,cab);
    free(cab);
}

//Lê o cabeçalho da lista e retorna este
//Pré-condição: arquivo aberto para leitura/escrita
//Pós-condição: retorna o cabeçalho lido
cabecalhoListaEncadeada* le_cabecalho(FILE * arq) {
    cabecalhoListaEncadeada * cab = (cabecalhoListaEncadeada*) malloc(sizeof(cabecalhoListaEncadeada));
    fseek(arq,0,SEEK_SET); // posiciona noArvoreB início do arquivo
    fread(cab, sizeof(cabecalhoListaEncadeada), 1, arq);
    return cab;
}

//Escreve noArvoreB arquivo o cabeçalho contendo as informações da lista
//Pré-condição: arquivo deve estar aberto e ser um arquivo de lista
//Pós-condilção: cabeçalho escrito noArvoreB arquivo
void escreve_cabecalho(FILE* arq, cabecalhoListaEncadeada* cab){
    fseek(arq,0,SEEK_SET); //posiciona noArvoreB início do arquivo
    fwrite(cab, sizeof(cabecalhoListaEncadeada), 1, arq);
}

//lê um nó em uma determinada posição do arquivo
//Pré-condição: arquivo deve estar aberto e ser um arquivo de lista
// pos deve ser uma posição válida da lista
//Pós-condição: ponteiro para nó lido é retornado
noListaEncadeada* le_no(FILE* arq, int pos) {
    noListaEncadeada* x = malloc(sizeof(noListaEncadeada));
    fseek(arq, sizeof(cabecalhoListaEncadeada) + pos * sizeof(noListaEncadeada), SEEK_SET);
    fread(x, sizeof(noListaEncadeada), 1, arq);
    return x;
}

//Escreve um nó em uma determinada posição do arquivo
//Pré-condição: arquivo deve estar aberto e ser um arquivo de lista
// pos deve ser uma posição válida do arquivo
//Pós-condição: nó escrito noArvoreB arquivo
void escreve_no(FILE* arq, noListaEncadeada* x, int pos){
    fseek(arq, sizeof(cabecalhoListaEncadeada) + pos * sizeof(noListaEncadeada), SEEK_SET);
    fwrite(x, sizeof(noListaEncadeada), 1, arq);
}

//Insere um nó na cabeça do arquivo
//Pré-condição: arquivo deve estar aberto e ser um arquivo de lista
//Pós-condição: nó escrito noArvoreB arquivo
void insere_lista(FILE* arq, TipoItem info){
    cabecalhoListaEncadeada* cab = le_cabecalho(arq);
    noListaEncadeada x;
    x.info = info;
    x.prox = cab->pos_cabeca;
    if(cab->pos_livre == -1) { // não há nós livres, então usar o topo
        escreve_no(arq,&x,cab->pos_topo);
        cab->pos_cabeca = cab->pos_topo;
        cab->pos_topo++;
    }
    else { // usar nó da lista de livres
        noListaEncadeada* aux = le_no(arq, cab->pos_livre);
        escreve_no(arq,&x,cab->pos_livre);
        cab->pos_cabeca = cab->pos_livre;
        cab->pos_livre = aux->prox;
        free(aux);
    }
    escreve_cabecalho(arq,cab); free(cab);
}

//Retira um nó da lista
//Pré-condição: arquivo deve estar aberto e ser um arquivo de lista
//Pós-condição: nó retirado da lista caso pertença a ela
void retira(FILE* arq, TipoItem x){
    cabecalhoListaEncadeada* cab = le_cabecalho(arq);
    int pos_aux = cab->pos_cabeca;
    int pos_ant = cab->pos_cabeca;
    noListaEncadeada* aux = NULL;
    while(pos_aux != -1 && // procura o elemento a ser retirado
          ((aux = le_no(arq,pos_aux))!= NULL) &&
          aux->info != x){ //TODO: Fazer a comparação!
        pos_ant = pos_aux;
        pos_aux = aux->prox;
        free(aux);
        aux = NULL;
    }
    if(pos_aux != -1) { //encontrou o elemento
        if(pos_ant == pos_aux){ // remoção na cabeça
            cab->pos_cabeca = aux->prox;
        }
        else { // remoção noArvoreB meio
            noListaEncadeada * ant = le_no(arq, pos_ant);
            ant->prox = aux->prox;
            escreve_no(arq,ant,pos_ant);
            free(ant);
        }
        aux->prox = cab->pos_livre; // torna o nó removido um nó livre
        cab->pos_livre = pos_aux;
        escreve_no(arq,aux,pos_aux);
        escreve_cabecalho(arq,cab);
        free(aux);
    }
    free(cab);
}

