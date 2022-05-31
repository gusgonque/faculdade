#include "trab2.h"
#include <stdio.h>

void interfacePrincipal(){
    int x, i;
    printf("Bem vindo a interface principal!\nDigite um numero para continuar.\n");
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

        case 0: ;

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
    }
    return 1;
}

int verificarNumero(long long int x){

}

int verificarSting(char s[]){

}

void inserirProfissionalManual(){
    profissional novPro;
    printf("Digite o codigo do profissional a ser inserido.\n>");
    scanf("%d",&novPro.cod);
    if(!verificarNumero(novPro.cod)){
        printf("Nao e possivel usar esse codigo. Tente novamente.\n>");
        scanf("%d", &novPro.cod);
    }

    printf("Digite o nome do profissional a ser inserido.\n>");
    scanf("%s", &novPro.nom);

    printf("Digite o CPF do profissional a ser inserido.\n>");
    scanf("%d", &novPro.cpf);
    if(!verificarNumero(novPro.cpf)){
        printf("Nao e possivel usar esse CPF. Tente novamente.\n>");
        scanf("%d", &novPro.cpf);
    }

    printf("Digite o numero do registro profissional a ser inserido.\n>");
    scanf("%s", &novPro.numReg);
    if(!verificarSting(novPro.numReg)){
        printf("Nao e possivel usar esse numero. Tente novamente.\n>");
        scanf("%d", &novPro.numReg);
    }

    printf("Digite o nome do profissional a ser inserido.\n>");
    scanf("%s", &novPro.nom);

    printf("Digite o endereco do profissional a ser inserido.\n>");
    scanf("%s", &novPro.end);
    if(!verificarSting(novPro.end)){
        printf("Nao e possivel usar esse CPF. Tente novamente.\n>");
        scanf("%s", &novPro.end);
    }

}
