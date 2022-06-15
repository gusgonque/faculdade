#ifndef FACULDADE_TRAB3AED_H
#define FACULDADE_TRAB3AED_H

#include "arvoreTRIE_TST.h"

#define MAXCHAR 150

void interfacePrincipal(TST_TRIE *dicionario);

int ehPalavraValida(char* str);

void carregarDicionario(TST_TRIE *dicionario);

TST_TRIE consultarPalavraAux(TST_TRIE no, char* pref);

void consultarPalavraAux2(TST_TRIE no, char *pref, int* i, int MAX);

void consultarPalavra(TST_TRIE dicionario);

void imprimirDicionario(TST_TRIE dicionario);

void carregarStopWords(TST_TRIE *dicionario);

#endif //FACULDADE_TRAB3AED_H
