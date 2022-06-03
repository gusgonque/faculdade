#ifndef FACULDADE_ARVOREBTRAB_H
#define FACULDADE_ARVOREBTRAB_H

#define TAM 5 // Ordem

typedef struct{
    int numCha;
    int cha[TAM];
    int ptDad[TAM];
    int fil[TAM+1];
} registro;

int buscaCodigo(int x);
int buscaPos(registro reg, int info, int * pos);
int vazia(registro reg);
int eh_folha(registro reg);
registro split(registro reg, int* chaPro);
void adicionaDireita(registro reg, int pos, int cha, int fil);
int overflow(registro reg);
//TODO: fazer a funcao inserirProfissionalArquivo.

#endif //FACULDADE_ARVOREBTRAB_H
