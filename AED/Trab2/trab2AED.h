#ifndef FACULDADE_TRAB2_H_INCLUDED
#define FACULDADE_TRAB2_H_INCLUDED

#include "arvoreBArq.h"

#define CHARMAX 100
#define LER_ESPACO setbuf(stdin, NULL) // Mecessário para usar o gets


typedef struct{
    int cod;
    char nom[50];
    char cpf[12];
    char numReg[30];
    char end[CHARMAX];
    char tel[15];
} profissional;

void interfacePrincipal();

int interfaceRegistro();

int buscaCodigo(int cod);

void inserirProfissionalManual();

void inserirProfissional(profissional proNov);

void alterarProfissionalManual();

void alterarProfissional(profissional pro, int booEnd, int booTel);

void removerProfissionalManual();

void removerProfissional(profissional pro);

void carregarArquivo();

void consultarProfissional();

void listarProfissionais();

void imprimirArvoreB();

void imprimirPosicoesLivresDados(FILE* arqDad);

void imprimirPosicoesLivresIndices(FILE* arqInd);

#endif //FACULDADE_TRAB2_H_INCLUDED
