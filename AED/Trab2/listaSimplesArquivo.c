#include <stdio.h>
#include <stdlib.h>
#include "listaSimplesArquivo.h"

//Cria uma lista nova em arquivo
//Pré-condição: arquivo aberto para leitura/escrita
//Pós-condição: arquivo é inicializado com uma lista noEhVazio
void cria_lista_vazia(FILE* arq){
    cabecalhoLista * cab = (cabecalhoLista*) malloc(sizeof(cabecalhoLista));
    cab->pos_topo = 0;
    cab->pos_livre = -1;
    escreve_cabecalho_lista(arq,cab);
    free(cab);
}

//Lê o cabeçalho da lista e retorna este
//Pré-condição: arquivo aberto para leitura/escrita
//Pós-condição: retorna o cabeçalho lido
cabecalhoLista* le_cabecalho_lista(FILE * arq) {
    cabecalhoLista * cab = (cabecalhoLista*) malloc(sizeof(cabecalhoLista));
    fseek(arq,0,SEEK_SET); // posiciona noArvoreB início do arquivo
    fread(cab, sizeof(cabecalhoLista), 1, arq);
    return cab;
}

//Escreve noArvoreB arquivo o cabeçalho contendo as informações da lista
//Pré-condição: arquivo deve estar aberto e ser um arquivo de lista
//Pós-condilção: cabeçalho escrito noArvoreB arquivo
void escreve_cabecalho_lista(FILE* arq, cabecalhoLista* cab){
    fseek(arq,0,SEEK_SET); //posiciona noArvoreB início do arquivo
    fwrite(cab, sizeof(cabecalhoLista), 1, arq);
}

//lê um nó em uma determinada posição do arquivo
//Pré-condição: arquivo deve estar aberto e ser um arquivo de lista
// pos deve ser uma posição válida da lista
//Pós-condição: ponteiro para nó lido é retornado
noLista* le_no_lista(FILE* arq, int pos) {
    noLista* x = malloc(sizeof(noLista));
    fseek(arq, sizeof(cabecalhoLista) + pos * sizeof(noLista), SEEK_SET);
    fread(x, sizeof(noLista), 1, arq);
    return x;
}

//Escreve um nó em uma determinada posição do arquivo
//Pré-condição: arquivo deve estar aberto e ser um arquivo de lista
// pos deve ser uma posição válida do arquivo
//Pós-condição: nó escrito noArvoreB arquivo
void escreve_no(FILE* arq, noLista* x, int pos){
    fseek(arq, sizeof(cabecalhoLista) + pos * sizeof(noLista), SEEK_SET);
    fwrite(x, sizeof(noLista), 1, arq);
}

//Insere um nó na cabeça do arquivo
//Pré-condição: arquivo deve estar aberto e ser um arquivo de lista
//Pós-condição: nó escrito noArvoreB arquivo
int insere_lista(FILE* arq, TipoItem info){
    cabecalhoLista* cab = le_cabecalho_lista(arq);
    noLista no;
    int posArq;
    no.info = info;
    if(cab->pos_livre == -1) { // não há nós livres, então usar o topo
        escreve_no(arq, &no, cab->pos_topo);
        posArq = cab->pos_topo;
        cab->pos_topo++;
    }
    else { // usar nó da lista de livres
        noLista* noAux = le_no_lista(arq, cab->pos_livre);
        int posArqAux;
        while (noAux->info.cod != -1){ // Percorre até a posição livre
            posArqAux = posArq;
            posArq = noAux->info.cod;
            noAux = le_no_lista(arq, noAux->info.cod);
        }
        noLista* noAux2 = le_no_lista(arq, posArq);
        noAux2->info.cod = -1;
        escreve_no(arq,noAux2,posArqAux);
        escreve_no(arq, &no, posArq);
        posArq = cab->pos_livre;
        cab->pos_livre = posArqAux;
        free(noAux);
        free(noAux2);
    }
    escreve_cabecalho_lista(arq,cab); free(cab);
    return posArq;
}

//Retira um nó da lista
//Pré-condição: arquivo deve estar aberto e ser um arquivo de lista
//Pós-condição: nó retirado da lista caso pertença a ela
//void retira(FILE* arq, TipoItem x){
//    cabecalhoLista* cab = le_cabecalho(arq);
//    int pos_aux = cab->pos_cabeca;
//    int pos_ant = cab->pos_cabeca;
//    noLista* aux = NULL;
//    while(pos_aux != -1 && // procura o elemento a ser retirado
//          ((aux = le_no(arq,pos_aux))!= NULL) &&
//          aux->info != x){
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
//            noLista * ant = le_no(arq, pos_ant);
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
//
