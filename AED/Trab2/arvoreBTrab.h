#ifndef FACULDADE_ARVOREBTRAB_H
#define FACULDADE_ARVOREBTRAB_H

#define TAM 4 // Ordem

typedef struct{
    int numCha;
    int cha[TAM];
    int ptDad[TAM];
    int fil[TAM+1];
} registro;

int buscaCodigo(int x);
//TODO: fazer a funcao inserirProfissionalArquivo.

#endif //FACULDADE_ARVOREBTRAB_H
