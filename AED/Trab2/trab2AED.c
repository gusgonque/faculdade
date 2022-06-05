#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trab2AED.h"
#include "arvoreBArq.h"
#include "listaSimplesArquivo.h"

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
            carregarArquivo();
            interfacePrincipal();
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

//Busca o codigo na arvore B, se ele existe, retorna o endereco do nó no arquivo. Qualquer outro caso retorna -1.
int buscaCodigo(int cod) {
    FILE* arqInd = fopen("arqIndices.bin","rb+");
    if (arqInd == NULL)
        return -1;

    cabecalhoArvoreB* cab = leCabecalhoArvoreB(arqInd);
    noArvoreB* noRaiz = leNoArvoreB(arqInd, cab->pos_raiz);
    int posCha, posArq;

    noArvoreB* noBus = buscaArvoreB(arqInd, noRaiz, cod,&posCha,&posArq);

    if(!noEhVazio(noBus))
        return posArq;
    else
        return -1;
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
    scanf("%s", &novPro.cpf);

    printf("Digite o numero de registro do profissional a ser inserido.\n>");
    scanf("%s", &novPro.numReg);

    printf("Digite o endereco do profissional a ser inserido.\n>");
    scanf("%s", &novPro.end);

    printf("Digite o telefone do profissional a ser inserido.\n>");
    scanf("%s", &novPro.tel);

    inserirProfissional(novPro);
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

    int posArq;
    posArq = insere_lista(arqDad,proNov);

    noArvoreB *noNov = malloc(sizeof(noArvoreB));
    noNov->numChaves = 0;
    insereNo(arqInd,noNov,posArq,proNov.cod,posArq);

    fclose(arqInd);
    fclose(arqDad);
    free(noNov);
    printf("Usuario inserido com sucesso!\nRetornando a Interface Principal!~\n");
}

void alterarProfissional(profissional pro, int booEnd, int booTel) {
    int posArqInd = buscaCodigo(pro.cod);

    FILE* arqInd = fopen("arqIndices.bin","rb+");
    FILE* arqDad = fopen("arqDados.bin","rb+");

    noArvoreB* noArvoreB = leNoArvoreB(arqInd,posArqInd);
    int posCha;
    buscaArvoreB(arqInd, noArvoreB, pro.cod,&posCha,&posArqInd);

    noLista* noLista = le_no_lista(arqDad,noArvoreB->ptDado[posCha]);
    if (booEnd) strcpy(noLista->info.end,pro.end);
    if (booTel) strcpy(noLista->info.tel,pro.tel);
    escreve_no(arqDad,noLista,noArvoreB->ptDado[posCha]);

    fclose(arqInd);
    fclose(arqDad);
    free(noArvoreB);
    free(noLista);
}

void removerProfissional(profissional pro){

}

void carregarArquivo(){
    char s[CHARMAX];
    printf("Favor digitar o nome do arquivo a ser carregado. Ex: 'arq.txt'\n");
    scanf("%s",&s);
    printf("nome do arquivo = '%s'\n",s);

    FILE* arq = fopen(s,"r");
    if(arq == NULL)
        printf("Nao foi possivel abrir o arquivo, favor verificar o nome e tentar novamente.\n");
    else{
        while(feof(arq)==0) {
            char fun;
            char buffer[1000];
            profissional* pro = malloc(sizeof(profissional));
            fscanf(arq, "%c%*c", &fun);
            if(fun == 'I'){
                fgets(buffer,1000,arq);
                sscanf(buffer,"%d;[^]");
                if(buscaCodigo(pro->cod)==-1) {
                    printf("Inserindo profissional.\n");
                    // TODO:RETIRABRANCOS
                    inserirProfissional(*pro);
                }
            } else if(fun == 'A'){
                fscanf(arq,"%d%*c%[^;]%*c%[^\n]",pro->cod,pro->end,pro->tel);
                if(buscaCodigo(pro->cod)!=-1) {
                    printf("Alterando profissional.\n");
                    // TODO:RETIRABRANCOS
                    int booEnd, booTel;
                    booEnd = (pro->end[0]!='\0');
                    booTel = (pro->tel[0]!='\0');
                    alterarProfissional(*pro, booEnd, booTel);
                }
            } else if(fun == 'R'){
                printf("Removendo profissional.\n");
                fscanf(arq,"%d",pro->cod);
                removerProfissional(*pro);
            }

        }



    }

}
