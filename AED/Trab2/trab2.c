#include "trab2.h"
#include <stdio.h>

void interfacePrincipal(){
    int x;
    printf("Bem vindo a Interface Principal!\nDigite um numero para continuar.\n");
    printf("1 - Interface de registro de usuario. (Inserir/Alterar/Remover)\n");
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
    printf("Bem vindo a interface de registro de profissionais!\nDigite um numero para continuar.\n");
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

    printf("Digite o nome do profissional a ser inserido.\n>");
    scanf("%s", &novPro.nom);

    printf("Digite o CPF do profissional a ser inserido.\n>");
    scanf("%d", &novPro.cpf);

    printf("Digite o numero do registro profissional a ser inserido.\n>");
    scanf("%s", &novPro.numReg);

    printf("Digite o endereco do profissional a ser inserido.\n>");
    scanf("%s", &novPro.end);

    printf("Digite o telefone do profissional a ser inserido.\n>");
    scanf("%d", &novPro.tel);

    inserirProfissional(novPro);
}

void inserirProfissional(profissional pro){
    FILE * arqInd = fopen("arqIndices.bin","rb+");
    if (arqInd == NULL){
        arqInd = fopen("arqIndices.bin","wb");
        fputs("0;1;-1\n",arqInd);
        fprintf(arqInd,"%d\n",pro.cod);
        fputs("0\n",arqInd);
        fclose(arqInd);

        FILE * arqDad = fopen("arqDados.bin","wb");
        fputs("1;-1\n",arqDad);
        fprintf(arqDad,"%d;%s;%lld;%s;%s;%lld\n", pro.cod, pro.nom, pro.cpf, pro.numReg, pro.end, pro.tel);
        fclose(arqDad);
    }
    else{

    }
    printf("Usuario inserido com sucesso!\nRetornando a Interface Principal!~\n");
}
