#ifndef FACULDADE_TRAB2_H_INCLUDED
#define FACULDADE_TRAB2_H_INCLUDED

typedef struct{
    int cod;
    char nom[50];
    long long int cpf;
    char numReg[30];
    char end[100];
    long long int tel;
} profissional;

#define TAM 4

typedef struct{
    int cha[TAM];
    int ptDad[TAM];
    int fil[TAM+1];
} registro;

void interfacePrincipal();
int interfaceRegistro();

void inserirProfissionalManual();
void inserirProfissionalArquivo();
void inserirProfissional();

#endif //FACULDADE_TRAB2_H_INCLUDED
