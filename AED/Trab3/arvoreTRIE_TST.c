//
// Created by Gustavo on 07/06/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include "arvoreTRIE_TST.h"

// Verifica se o nó é vazio.
int ehVazio(TST_TRIE no){
    return (no == NULL);
}

// Verifica se o próximo caracter da string é \0.
int acabouString(char *str){
    return *(str + 1) == '\0';
}

//Insere no nó a string.
// Pré condição: valor tem que ser maior do que 0.
void inserirTST(TST_TRIE * no, char * str, int valor) {
    if(ehVazio(*no)){ // nó vazio
        if((*str) != '\0') { // fim da string
            (*no) = (noTST_TRIE*) malloc(sizeof (noTST_TRIE));
            (*no)->ch = (*str);
            (*no)->valor = (acabouString(str) ? (valor) : -1 ); // Se for a última letra adiciona o valor.
            (*no)->maior = NULL;
            (*no)->menor = NULL;
            (*no)->igual = NULL;
            inserirTST(&(*no)->igual, str + 1, valor);
        } else
            (*no) = NULL;
    } else if((*str) == (*no)->ch){ // caracter igual lexicograficamente
        if(acabouString(str))
            (*no)->valor = valor;
        else
            inserirTST(&(*no)->igual, str+1, valor);
    } else if((*str) > (*no)->ch){ // caracter maior lexicograficamente
        inserirTST(&(*no)->maior, str, valor);
    } else { // caracter menor lexicograficamente
        inserirTST(&(*no)->menor, str, valor);
    }
}

// Busca a string no nó e retorna 0 se não é possível continuar a busca, ou o valor do nó que termina a string.
int buscaTST(TST_TRIE *no, char *str){
    if(ehVazio(*no))
        return 0;
    if((*str) == (*no)->ch)
        return (acabouString(str) ? (*no)->valor : buscaTST(&(*no)->igual, str+1));
    if((*str) > (*no)->ch)
        return buscaTST(&(*no)->maior, str);
    return buscaTST(&(*no)->menor, str);
}

// Verifica se todas as ramificações do nó são vazias.
int ehFolha(TST_TRIE no){
    return (ehVazio(no->menor) && ehVazio(no->maior) && ehVazio(no->igual));
}

// Função auxiliar do removerTST que remove o nó pai do nó removido se aquele for folha e não tiver valor definido.
// Pré condição: Nó não nulo.
void removerTSTaux(TST_TRIE *no) {
    if (ehFolha(*no) && ((*no)->valor == -1)) {
        free(*no);
        (*no) = NULL;
    }
}

// Percorre o nó e retorna o nó sucessor do nó parâmetro.
// Pré-Condição: Nó parâmetro não vazio.
// Pós-Condição: Retorna o nó sucessor.
TST_TRIE encontraSucessor(TST_TRIE const *no){
    TST_TRIE noAux = *no;
    if(!ehVazio(noAux->menor)){
        noAux = noAux->menor;
        while (!ehVazio(noAux->maior))
            noAux = noAux->maior;
    } else {
        noAux = noAux->maior;
        while (!ehVazio(noAux->menor))
            noAux = noAux->menor;
    }
    return noAux;
}

// Faz a rotação do nó, se necessário, duplicando o sucessor no nó parâmetro e removendo o nó duplicado.
// Pré-Condição: Nó parâmetro não vazio.
void rotacaoTST(TST_TRIE * no){//TODO: testar.
    if(!ehFolha(*no) && ehVazio((*no)->igual)){ // Testa se é necessário realizar a rotação
        TST_TRIE noAux = encontraSucessor(no);
        TST_TRIE noAuxMaior = (*no)->maior;
        TST_TRIE noAuxMenor = (*no)->menor;
        (*no) = noAux;
        (*no)->maior = noAuxMaior;
        (*no)->menor = noAuxMenor;

        noAux = *no;
        if(!ehVazio((*no)->menor)){ // Encontra o pai do sucessor e remove o nó duplicado
            (*no) = (*no)->menor;
            if(!ehVazio((*no)->maior))
                while (!ehVazio((*no)->maior->maior))
                    (*no) = (*no)->maior;
            free((*no)->maior);
            (*no)->maior = NULL;
        } else {
            (*no) = (*no)->maior;
            if(!ehVazio((*no)->menor))
                while (!ehVazio((*no)->menor->menor))
                    (*no) = (*no)->menor;
            free((*no)->menor);
            (*no)->menor = NULL;
        }

        (*no) = noAux;
    }
}

// Remove da árvore a string str, se tiver.
void removerTST(TST_TRIE * no, char *str) {
    if (buscaTST(no, str) > 0) { // só vai remover se a palavra estiver no nó
        if (acabouString(str)) {
            if (ehFolha(*no)) {
                free(*no);
                (*no) = NULL;
            } else // Mao eh folha
                (*no)->valor = -1;
        } else if ((*str) == (*no)->ch) { // se a palavra for mais embaixo
            removerTST(&(*no)->igual, str + 1);
        } else if ((*str) > (*no)->ch) {
            removerTST(&(*no)->maior, str);
        } else
            removerTST(&(*no)->menor, str);
        removerTSTaux(no);
        rotacaoTST(no);
    }
}