//
// Created by Gustavo on 07/06/2022.
//

#ifndef FACULDADE_TRAB3AED_H
#define FACULDADE_TRAB3AED_H

#include "arvoreTRIE_TST.h"

#define MAXCHAR 150

void interfacePrincipal();

int ehPalavraValida(char* str);

TST_TRIE carregarDicionario();

TST_TRIE consultarPalavraAux(TST_TRIE no, char* str);

void consultarPalavra(TST_TRIE dicionario);

#endif //FACULDADE_TRAB3AED_H
