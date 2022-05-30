#include "matrizEsparsa.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    Matriz *x, *y, *resultado;
    x = inicializarMatriz();
    y = inicializarMatriz();

    lerArquivoMatriz(x, "matriz7.txt");
    lerArquivoMatriz(y, "matriz2.txt");
    resultado = transpostaMatriz(x);

    if(isSimetrica(x))
        printf("SIMETRICA: SIM\n");
    else
        printf("SIMETRICA: NAO\n");




    //criarCabecasMatriz(x); agora dentro do lerArquivoMatriz!!!


    //direita->
    //abaixo->

    printf("linha = %d\n", resultado->cabeca->direita->direita->direita->direita->direita->direita->linha);
    printf("coluna = %d\n", resultado->cabeca->direita->direita->direita->direita->direita->direita->coluna);
    printf("valor = %d\n", resultado->cabeca->direita->direita->direita->direita->direita->direita->valor);

 /*       for(i = 0; i < 3; i++){
        printf("colunaDireita = %d\n", p->coluna);
        printf("linhaDireita = %d\n", p->linha);
        printf("valor = %d\n", p->valor);
        p = p->direita;
    }*/


 /*   printf("totalLinha = %d\n", x->totalLinha);
    printf("totalColuna = %d\n", x->totalColuna);*/



    //x->totalColuna = 0;
    //printf("TotalColuna = %d", x->totalColuna);

    return 0;
}
