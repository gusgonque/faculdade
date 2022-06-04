#include <stdio.h>
#include "trab2AED.h"
#include "arvoreBArq.h"
#include "listaEncadeadaArquivo.h"

void interfacePrincipal(){
    int x;
    printf("Bem vindo a Interface Principal!\nDigite um numero para continuar.\n");
    printf("1 - Interface de noArvoreB de usuario. (Inserir/Alterar/Remover)\n");
    printf("2 - Carregar arquivo texto.\n");
    printf("3 - Consultar profissional.\n");
    printf("4 - Listar profissionais.\n");
    printf("5 - Interface da arvore.\n");
    printf("0 - Finalizar programa.\n");

    printf(">");
    scanf("%d",&x);
    while (x<0 || x>5){
        printf("Comando invalido. Digite novamente.\n");
        printf(">");
        scanf("%d",&x);
    }

    switch (x) {
        case 1:
            if (!interfaceRegistro())
                interfacePrincipal();
        case 2:

        case 3:

        case 4:

        case 5:

        case 0:

        default:;

    }
}

int interfaceRegistro(){
    int x;
    printf("Bem vindo a interface de noArvoreB de profissionais!\nDigite um numero para continuar.\n");
    printf("1 - Inserir novo profissional.\n");
    printf("2 - Alterar endereco de um profissional.\n");
    printf("3 - Alterar telefone de um profissional.\n");
    printf("4 - Remover um profissional.\n");
    printf("0 - retornar ao menu anterior.\n");

    printf(">");
    scanf("%d",&x);
    while (x<0 || x>4){
        printf("Comando invalido. Digite novamente.\n");
        printf(">");
        scanf("%d",&x);
    }

    switch (x) {
        case 1:
            inserirProfissionalManual();
            return 0;
        case 2:

        case 3:

        case 4:

        case 5:

        case 0:
            return 0;

        default:
            return 1;

    }
}

void inserirProfissionalManual(){
    profissional novPro;
    printf("Digite o codigo do profissional a ser inserido.\n>");
    scanf("%d",&novPro.cod);
    while (buscaCodigo(novPro.cod) != -1){
        printf("Codigo ja inserido por outro profissional, tente novamente.\n>");
        scanf("%d",&novPro.cod);
    }

    printf("Digite o nome do profissional a ser inserido.\n>");
    scanf("%s", &novPro.nom);

    printf("Digite o CPF do profissional a ser inserido.\n>");
    scanf("%d", &novPro.cpf);

    printf("Digite o numero do noArvoreB profissional a ser inserido.\n>");
    scanf("%s", &novPro.numReg);

    printf("Digite o endereco do profissional a ser inserido.\n>");
    scanf("%s", &novPro.end);

    printf("Digite o telefone do profissional a ser inserido.\n>");
    scanf("%d", &novPro.tel);

    inserirProfissional(novPro);
}

void inserirProfissionalArquivo(){//TODO: fazer a funcao inserirProfissionalArquivo.

}

void inserirProfissional(profissional proNov){
    FILE* arqInd = fopen("arqIndices.bin","rb+");
    FILE* arqDad = fopen("arqDados.bin","rb+");

    if (arqInd == NULL){
        arqInd = fopen("arqIndices.bin","wb+");
        arqDad = fopen("arqDados.bin","wb+");
        criaArvoreVazia(arqInd);
        cria_lista_vazia(arqDad);
    }

//TODO: FAZER ESSA FUNÇÃO!!!!!!!!!

    fclose(arqInd);
    fclose(arqDad);
    printf("Usuario inserido com sucesso!\nRetornando a Interface Principal!~\n");
}
