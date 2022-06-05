#ifndef FACULDADE_TRAB2_H_INCLUDED
#define FACULDADE_TRAB2_H_INCLUDED

#define CHARMAX 100

typedef struct{
    int cod;
    char nom[50];
    char cpf[11];
    char numReg[30];
    char end[100];
    char tel[11];
} profissional;

void interfacePrincipal();

int interfaceRegistro();

int buscaCodigo(int cod);

void inserirProfissionalManual();

void inserirProfissional(profissional proNov);

void alterarProfissional(profissional pro, int booEnd, int booTel);

void removerProfissional(profissional pro);

void carregarArquivo();


#endif //FACULDADE_TRAB2_H_INCLUDED
