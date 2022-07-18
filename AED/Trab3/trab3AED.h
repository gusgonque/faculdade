#ifndef FACULDADE_TRAB3AED_H
#define FACULDADE_TRAB3AED_H

#include "arvoreTRIE_TST.h"

#define MAXCHAR 50

// Interface Principal.
// Pré-Condição: dicionário tem que ser um nó TST válido.
// Pós-Condição: 'Interface' do menu aberto para o usuário escolher uma ação.
void interfacePrincipal(TST_TRIE *dicionario);

// Verifica se a palavra é valida.
// Pré-Condição: String str deve existir.
// Pós-Condição: Transforma todos os caracteres em letras minúsculas e retorna um teste de ter apenas letras minúsculas (1) ou não (0).
int ehPalavraValida(char* str);

// Carrega o arquivo do dicionário.
// Pré-Condição: Nó dicionário tem que ser um nó TST válido.
// Pós-Condição: Nó dicionário carregado com as palavras do arquivo.
void carregarDicionario(TST_TRIE *dicionario);

// Função auxiliar à consulta de palavra que percorre o nó.
// Pré-Condição: String pref tem que ser um prefixo em nó.
// Pós-Condição: Retorna o nó em que o prefixo termina.
TST_TRIE consultarPalavraAux(TST_TRIE no, char* pref);

// Função auxiliar à consulta de palavra que percorre o nó na ordem in-ordem.
// Pré-Condição: String pref tem que ser um prefixo em nó.
// Pós-Condição: Imprime até MAX palavras que encontrar, em ordem alfabética.
void consultarPalavraAux2(TST_TRIE no, char *pref, int* i, int MAX);

// Consulta as palavras que tiverem o prefisso.
// Pré-Condição: Nó dicionário tem que ser um nó TST válido.
// Pós-Condição: Imprime as palavras que encontrar no dicionário, em ordem alfabética.
void consultarPalavra(TST_TRIE dicionario);

// Imprime todas as palavras no dicionario.
// Pré-Condição: Nó dicionário tem que ser um nó TST válido.
// Pós-Condição: Imprime as palavras do dicionário, em ordem alfabética.
void imprimirDicionario(TST_TRIE dicionario);

// Carrega o arquivo de palavras a serem removidas do dicionario.
// Pré-Condição: Nó dicionário tem que ser um nó TST válido.
// Pós-Condição: Remove palavras do dicionário, de acordo com o arquivo.
void carregarStopWords(TST_TRIE *dicionario);

// Consulta as palavras semelhantes à digitada pelo usuário, pelo algoritmo de Levenshtein.
// Pré-Condição: Nó dicionário tem que ser um nó TST válido.
// Pós-Condição: Imprime as palavras semelhantes à escolhida.
void consultaSemelhante(TST_TRIE dicionario);

#endif //FACULDADE_TRAB3AED_H
