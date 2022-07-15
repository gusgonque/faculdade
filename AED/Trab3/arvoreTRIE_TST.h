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

int acabouString(char *str);

void inserirTST(TST_TRIE * no, char * str, int valor);

int buscaTST(TST_TRIE *no, char *str);

int ehFolha(TST_TRIE no);

void removerTSTaux2(TST_TRIE *no);

TST_TRIE encontraSucessor(TST_TRIE const *no);

void rotacaoTST(TST_TRIE * no);

void removerTST(TST_TRIE *no, char *str);

int min (int a, int b, int c);

int distanciaLevenshtein (char * str1, char * str2);

void consultarSemelhanteTST(TST_TRIE no, char *str, char *strW, int n);

#endif //FACULDADE_ARVORETRIE_TST_H
