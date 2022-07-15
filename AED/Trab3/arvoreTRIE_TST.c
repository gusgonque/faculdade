//
// Created by Gustavo on 07/06/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
// Pré condição:
void removerTSTaux2(TST_TRIE *no) {
    if (!ehVazio(*no) && ehFolha(*no) && ((*no)->valor == -1)) {
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
// Pré-Condição:
void rotacaoTST(TST_TRIE * no){//TODO: testar.
    if(!ehVazio(*no) && !ehFolha(*no) && ehVazio((*no)->igual)){ // Testa se é necessário realizar a rotação
        TST_TRIE noAux = (*no);
        TST_TRIE noAuxSucessor = encontraSucessor(no);
        TST_TRIE noAuxMaior = (*no)->maior;
        TST_TRIE noAuxMenor = (*no)->menor;
        (*no) = noAuxSucessor;
        (*no)->maior = noAuxMaior;
        (*no)->menor = noAuxMenor;

        if(!ehVazio(noAux->menor)){ // Encontra o pai do sucessor e remove o nó duplicado
            noAux = noAux->menor;
            if(!ehVazio(noAux->maior))
                while (!ehVazio(noAux->maior->maior))
                    noAux = noAux->maior;
            free(noAux->maior);
            noAux->maior = NULL;
        } else {
            noAux = noAux->maior;
            if(!ehVazio(noAux->menor))
                while (!ehVazio(noAux->menor->menor))
                    noAux = noAux->menor;
            free(noAux->menor);
            noAux->menor = NULL;
        }
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
        removerTSTaux2(no);
        //rotacaoTST(no);
    }
}

int min(int a, int b, int c){
    if(a <= b && a <= c)
        return a;
    else if(b <= a && b <= c)
        return b;
    return c;
}

int distanciaLevenshtein (char * str1, char * str2){
    unsigned int  x, y, str1len, str2len;
    str1len = strlen(str1);
    str2len = strlen(str2);
    unsigned int matrix[str2len+1][str1len+1];
    matrix[0][0] = 0;
    for (x = 1; x <= str2len; x++)
        matrix[x][0] = matrix[x-1][0] + 1;
    for (y = 1; y <= str1len; y++)
        matrix[0][y] = matrix[0][y-1] + 1;
    for (x = 1; x <= str2len; x++)
        for (y = 1; y <= str1len; y++)
            matrix[x][y] = min(matrix[x-1][y] + 1, matrix[x][y-1] + 1, matrix[x-1][y-1] + (str1[y-1] == str2[x-1] ? 0 : 1));

    return(matrix[str2len][str1len]);
}

void consultarSemelhanteTST(TST_TRIE no, char *str, char *strW, int n) {
    if(!ehVazio(no)) {

        consultarSemelhanteTST((no->menor),str,strW,n);

        int aux = strlen(str);
        str = (char *) realloc(str, sizeof(str)+1);
        *(str + aux) = no->ch;
        *(str + aux + 1) = '\0';

        if((no->valor != -1) && (distanciaLevenshtein(str, strW) <= n))
            printf("%s\n", str);
        consultarSemelhanteTST((no->igual),str,strW,n);

        *(str + aux) = '\0';
        strW = (char *) realloc(strW, sizeof(strW));
        consultarSemelhanteTST((no->maior),str,strW,n);
    }
}