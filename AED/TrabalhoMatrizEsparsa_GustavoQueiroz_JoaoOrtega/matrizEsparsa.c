#include "matrizEsparsa.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct celula* inicializarCabecaMatriz(){
    struct celula *aux = (struct celula *) malloc(sizeof(struct celula));
    aux->linha = -1;
    aux->coluna = -1;
    aux->direita = NULL;
    aux->abaixo = NULL;
    return aux;
}

Matriz* inicializarMatriz(){
    Matriz *aux = (Matriz *) malloc(sizeof(Matriz));
    aux->cabeca = inicializarCabecaMatriz();
    aux->totalLinha  = 0;
    aux->totalColuna = 0;
    return aux;
}

struct celula* inicializarCabecaColuna(){
    struct celula *aux = (struct celula *) malloc(sizeof(struct celula));
    aux->direita = NULL;
    aux->abaixo = NULL;
    aux->coluna = -1;
    return aux;
}

void criarCabecasColunas(Matriz *x){
    int i;
    struct celula *p;
    p = x->cabeca;
    for(i = 0; i < x->totalColuna; i++){
        p->direita = inicializarCabecaColuna();
        p = p->direita;
        p->abaixo = p;
    }
    p->direita = x->cabeca; // garantir circularidade horizontal da lista!!
}

struct celula* inicializarCabecaLinha(){
    struct celula *aux = (struct celula *) malloc(sizeof(struct celula));
    aux->direita = NULL;
    aux->abaixo = NULL;
    aux->linha = -1;
    return aux;
}

void criarCabecasLinhas(Matriz *x){
    int i;
    struct celula *p;
    p = x->cabeca;
    for(i = 0; i < x->totalLinha; i++){
        p->abaixo = inicializarCabecaLinha();
        p = p->abaixo;
        p->direita = p;
    }
    p->abaixo = x->cabeca; // garantir circularidade vertical da lista!!
}

void criarCabecasMatriz(Matriz *x){
    criarCabecasColunas(x);
    criarCabecasLinhas(x);
}

struct celula* criarCelula(int linha, int coluna, int valor){
    struct celula *aux = (struct celula *) malloc(sizeof(struct celula));
    aux->direita = NULL;
    aux->abaixo = NULL;
    aux->linha = linha;
    aux->coluna = coluna;
    aux->valor = valor;
    return aux;
}

void encadearLinha(struct celula *cabecaMatriz, struct celula *aux){
    int i;
    struct celula *p, *cabecaLinha;
    p = cabecaMatriz;
    for(i = 0; i < aux->linha; i++) // encontra cabecaLinha!!
        p = p->abaixo;
    cabecaLinha = p;
    while(p->direita->linha != -1) // encontra lugar onde deve ser encadeado!!
        p = p->direita;
    p->direita = aux;
    aux->direita = cabecaLinha; // garantir circularidade horizontal da lista!!
}

void encadearColuna(struct celula *cabecaMatriz, struct celula *aux){
    int i;
    struct celula *p, *cabecaColuna;
    p = cabecaMatriz;
    for(i = 0; i < aux->coluna; i++) // encontra cabecaColuna!!
        p = p->direita;
    cabecaColuna = p;
    while(p->abaixo->coluna != -1) // encontra lugar onde deve ser encadeado!!
        p = p->abaixo;
    p->abaixo = aux;
    aux->abaixo = cabecaColuna; // garantir circularidade vertical da lista!!
}

void montarMatriz(Matriz *x, int linha, int coluna, int valor){
    struct celula *aux = criarCelula(linha, coluna, valor);
    encadearLinha(x->cabeca, aux);
    encadearColuna(x->cabeca, aux);
}

void lerArquivoMatriz(Matriz *x, char *fnm){
    FILE *f;
    int linha, coluna, valor;
    char aux, str[10];
    f = fopen(fnm, "r");
    /*
        fazer tratamento de excecao f == NULL arquivo nao exista!!!
    */
    fscanf(f, "%dx%d%*c", &x->totalLinha, &x->totalColuna); // descartar o '\n'!!
    criarCabecasMatriz(x);
    while(fscanf(f, "%c", &aux) != EOF){
        if(aux != 'f'){
            fseek(f, -1, SEEK_CUR);
            fscanf(f, "%d,%d,%d%*c", &linha, &coluna, &valor); // descartar o '\n'!!!
            montarMatriz(x, linha, coluna, valor);

            /*

            tratar excecao caso a linha e coluna achada sejam maiores que o limite passado no arquivo!!

            */
        }
        else{
            fseek(f, -1, SEEK_CUR);
            fscanf(f, "%s", str);
            if(!strcmp("fim", str))
                fseek(f, 0, SEEK_END);
        }
    }
    fclose(f);
}

int valorCelula(Matriz *x, int linha, int coluna){
    int i;
    struct celula *p = x->cabeca;
    for(i = 0; i < linha; i++)
        p = p->abaixo;
    p = p->direita; // fazer este ponteiro apontar para uma celula que nao seja cabeca de linha!!
    while(p->linha != -1){
        if(p->linha == linha && p->coluna == coluna)
            return p->valor;
        p = p->direita;
    }
    return 0;
}

int existeCelula(Matriz *x, int linha, int coluna){
    int i;
    struct celula *p = x->cabeca;
    for(i = 0; i < linha; i++)
        p = p->abaixo;
    p = p->direita; // fazer este ponteiro apontar para uma celula que nao seja cabeca de linha!!
    while(p->linha != -1){
        if(p->linha == linha && p->coluna == coluna)
            return 1;
        p = p->direita;
    }
    return 0;
}

Matriz* somaMatriz(Matriz *x, Matriz *y){
    Matriz *resultado;
    int i, j, valorSoma = 0;
    if(x->totalLinha != y->totalLinha || x->totalColuna != y->totalColuna){
        printf("Matrizes nao sao de mesma ordem!!\n");
        return NULL;
    }
    resultado = inicializarMatriz();
    resultado->totalLinha = x->totalLinha;
    resultado->totalColuna = x->totalColuna;
    criarCabecasMatriz(resultado);
    for(i = 1; i <= resultado->totalLinha; i++){
        for(j = 1; j <= resultado->totalColuna; j++){
            if(existeCelula(x, i, j) && existeCelula(y, i, j)){
                valorSoma = valorCelula(x, i, j) + valorCelula(y, i, j);
                montarMatriz(resultado, i, j, valorSoma);
            }
            else
                if(existeCelula(x, i, j)){
                    valorSoma = valorCelula(x, i, j);
                    montarMatriz(resultado, i, j, valorSoma);
                }
            else
                if(existeCelula(y, i, j)){
                    valorSoma = valorCelula(y, i, j);
                    montarMatriz(resultado, i, j, valorSoma);
                }
        }
    }
    return resultado;
}

Matriz* subtraiMatriz(Matriz *x, Matriz *y){
    Matriz *resultado;
    int i, j, valorSubtracao = 0;
    if(x->totalLinha != y->totalLinha || x->totalColuna != y->totalColuna){
        printf("Matrizes nao sao de mesma ordem!!\n");
        return NULL;
    }
    resultado = inicializarMatriz();
    resultado->totalLinha = x->totalLinha;
    resultado->totalColuna = x->totalColuna;
    criarCabecasMatriz(resultado);
    for(i = 1; i <= resultado->totalLinha; i++){
        for(j = 1; j <= resultado->totalColuna; j++){
            if(existeCelula(x, i, j) && existeCelula(y, i, j)){
                valorSubtracao = valorCelula(x, i, j) - valorCelula(y, i, j);
                montarMatriz(resultado, i, j, valorSubtracao);
            }
            else
                if(existeCelula(x, i, j)){
                    valorSubtracao = valorCelula(x, i, j);
                    montarMatriz(resultado, i, j, valorSubtracao);
                }
            else
                if(existeCelula(y, i, j)){
                    valorSubtracao = -valorCelula(y, i, j);
                    montarMatriz(resultado, i, j, valorSubtracao);
                }
        }
    }
    return resultado;
}

Matriz* multiplicaMatriz(Matriz *x, Matriz *y){
    Matriz* resultado;
    int i, j, k, valorMultiplicacao;
    if(x->totalColuna != y->totalLinha){
        printf("Matrizes incompativeis para multiplicacao!!\n");
        return NULL;
    }
    resultado = inicializarMatriz();
    resultado->totalLinha = x->totalLinha;
    resultado->totalColuna = y->totalColuna;
    criarCabecasMatriz(resultado);
    for(i = 1; i <= x->totalLinha; i++)
        for(j = 1; j <= y->totalColuna; j++){
            valorMultiplicacao = 0;
            for(k = 1; k <= x->totalColuna; k++)
                if(existeCelula(x, i, k) && existeCelula(y, k, j)) // somente este caso eh relevante para a multiplicacao, caso uma celula nao exista nao ha a necessidade de somar 0!!
                    valorMultiplicacao += valorCelula(x, i, k) * valorCelula(y, k, j);
            if(valorMultiplicacao)
                montarMatriz(resultado, i, j, valorMultiplicacao);
        }
    return resultado;
}

Matriz* transpostaMatriz(Matriz *x){
    Matriz* resultado;
    int i, j;
    if(x->totalLinha == 0 || x->totalColuna == 0){
        printf("Matriz invalida!! (0 linhas ou colunas)\n");
        return NULL;
    }
    resultado = inicializarMatriz();
    resultado->totalLinha = x->totalColuna;
    resultado->totalColuna = x->totalLinha;
    criarCabecasMatriz(resultado);
    for(i = 1; i <= x->totalLinha; i++)
        for(j = 1; j <= x->totalColuna; j++){
            if(existeCelula(x, i, j)){
                montarMatriz(resultado, j, i, valorCelula(x, i, j));
            }
        }
    return resultado;
}

int isSimetrica(Matriz *x){
    Matriz *transposta;
    int i, j;
    if(x->totalLinha != x->totalColuna){
        printf("Nao eh simetrica!! (nao eh matriz quadrada)\n");
        return 0;
    }
    transposta = transpostaMatriz(x);
    printMatriz(x);
    printf("\n");
    printMatriz(transposta);
    printf("\n");
    for(i = 1; i <= x->totalLinha; i++)
        for(j = 1; j <= x->totalColuna; j++){
            if(existeCelula(x, i, j) && existeCelula(transposta, i, j)){
                if(valorCelula(x, i, j) != valorCelula(transposta, i, j))
                    return 0;
            }
            else
                if(existeCelula(x, i, j))
                    return 0;
            else
                if(existeCelula(transposta, i, j))
                    return 0;
        }
    return 1;
}

void printMatriz(Matriz *x){
    int i, j;
    for(i = 1; i <= x->totalLinha; i++){
        for(j = 1; j <= x->totalColuna; j++){
            if(existeCelula(x, i, j))
                printf("%5d", valorCelula(x, i, j));
            else
                printf("%5d", 0);
        }
        printf("\n");
    }
}
