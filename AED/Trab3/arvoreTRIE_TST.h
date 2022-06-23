//
// Created by Gustavo on 07/06/2022.
//

#ifndef FACULDADE_ARVORETRIE_TST_H
#define FACULDADE_ARVORETRIE_TST_H

typedef struct noTST {
    char ch; //caracter da TRIE
    int valor; // valor associado à chave
    struct noTST * menor; // antes de ch na ordem lexicográfica
    struct noTST * igual;
    struct noTST * maior; // depois de ch na ordem lexicográfica
} noTST_TRIE;

typedef noTST_TRIE * TST_TRIE;

int ehVazio(TST_TRIE no);

void inserirTST(TST_TRIE * no, char * str, int valor);

int buscaTST(TST_TRIE *no, char *str);

int ehFolha(TST_TRIE no);

void removerTSTaux(TST_TRIE *no);

TST_TRIE encontraSucessor(TST_TRIE const *no);

void rotacaoTST(TST_TRIE * no);

void removerTST(TST_TRIE *no, char *str);

#endif //FACULDADE_ARVORETRIE_TST_H
