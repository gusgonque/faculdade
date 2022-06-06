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
            break;
        case 2:
            carregarArquivo();
            interfacePrincipal();
            break;
        case 3:
            consultarProfissional();
            interfacePrincipal();
            break;

        case 4:
            listarProfissionais();
            interfacePrincipal();
            break;

        case 5:
            break;

        case 0:
            break;

        default:
            break;

    }
}

int interfaceRegistro(){
    int x;
    printf("Bem vindo a interface de noArvoreB de profissionais!\nDigite um numero para continuar.\n");
    printf("1 - Inserir novo profissional.\n");
    printf("2 - Alterar endereco ou telefone de um profissional.\n");
    printf("3 - Remover um profissional.\n");
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
            alterarProfissionalManual();
            return 0;
        case 3:
            removerProfissionalManual();
            return 0;
        case 0:
            return 0;

        default:
            return 1;

    }
}

//Busca o codigo na arvore B, se ele existe, retorna o endereco daquela chave naquele nó do arquivo. Qualquer outro caso retorna -1.
int buscaCodigo(int cod) {
    FILE* arqInd = fopen("arqIndices.bin","rb+");
    if (arqInd == NULL)
        return -1;

    cabecalhoArvoreB* cab = leCabecalhoArvoreB(arqInd);
    noArvoreB* noRaiz = leNoArvoreB(arqInd, cab->pos_raiz);
    int posCha, posArq;

    noArvoreB* noBus = buscaArvoreB(arqInd, noRaiz, cod,&posCha,&posArq);

    free(cab);
    free(noRaiz);
    if(!noEhVazio(noBus))
        return posCha;
    else
        return -1;
}

void inserirProfissionalManual(){
    profissional novPro;
    char buffer[CHARMAX];
    printf("Digite o codigo do profissional a ser inserido.\n>");
    scanf("%d",&novPro.cod);
    while (buscaCodigo(novPro.cod) != -1){
        printf("Codigo ja inserido por outro profissional, tente novamente.\n>");
        scanf("%d",&novPro.cod);
    }

    printf("Digite o nome do profissional a ser inserido.\n>");
    LER_ESPACO;
    gets(buffer);
    sscanf(buffer,"%[^\n]",&novPro.nom);

    printf("Digite o CPF do profissional a ser inserido.\n>");
    gets(buffer);
    sscanf(buffer,"%[^\n]", &novPro.cpf);

    printf("Digite o numero de registro do profissional a ser inserido.\n>");
    gets(buffer);
    sscanf(buffer,"%[^\n]", &novPro.numReg);

    printf("Digite o endereco do profissional a ser inserido.\n>");
    gets(buffer);
    sscanf(buffer,"%[^\n]", &novPro.end);

    printf("Digite o telefone do profissional a ser inserido.\n>");
    gets(buffer);
    sscanf(buffer,"%[^\n]", &novPro.tel);

    inserirProfissional(novPro);
}

//Insere o profisisonal(chave), na raíz do arq de Indices.
void inserirProfissional(profissional proNov){
    FILE* arqInd = fopen("arqIndices.bin","rb+");
    FILE* arqDad = fopen("arqDados.bin","rb+");

    if (arqInd == NULL){
        arqInd = fopen("arqIndices.bin","wb+");
        arqDad = fopen("arqDados.bin","wb+");
        criaArvoreVazia(arqInd);
        cria_lista_vazia(arqDad);
    }

    cabecalhoArvoreB* cab = leCabecalhoArvoreB(arqInd);
    int posArqDad;
    posArqDad = insere_lista(arqDad, proNov);

    noArvoreB *noNov = leNoArvoreB(arqInd,cab->pos_raiz);
    insereNo(arqInd, noNov, cab->pos_raiz, proNov.cod, posArqDad);

    fclose(arqInd);
    fclose(arqDad);
    free(noNov);
    free(cab);
    printf("Usuario inserido com sucesso!\nRetornando a Interface Principal!~\n");
}

void alterarProfissionalManual(){
    profissional pro;
    int x;
    char buffer[CHARMAX];

    printf("Digite o codigo do usuario que deseja alterar.\n>");
    scanf("%d", &pro.cod);

    if(buscaCodigo(pro.cod) != -1){
        printf("Digite qual a alteracao desejada.\n");
        printf("1 - Alterar telefone.\n");
        printf("2 - Alterar endereco.\n>");
        scanf("%d", &x);
        LER_ESPACO;

        switch(x) {
            case 1:
                printf("Digite o novo telefone.\n>");
                gets(buffer);
                sscanf(buffer,"%[^\n]", &pro.tel);
                alterarProfissional(pro, 0, 1);
                break;
            case 2:
                printf("Digite o novo endereco.\n>");
                gets(buffer);
                sscanf(buffer,"%[^\n]",&pro.end);
                alterarProfissional(pro, 1, 0);
                break;
        }
    }
}

void alterarProfissional(profissional pro, int booEnd, int booTel) {
    FILE* arqInd = fopen("arqIndices.bin","rb+");
    FILE* arqDad = fopen("arqDados.bin","rb+");

    cabecalhoArvoreB* cab = leCabecalhoArvoreB(arqInd);

    noArvoreB* noArvoreB = leNoArvoreB(arqInd,cab->pos_raiz);
    int posCha, posArqInd;
    noArvoreB = buscaArvoreB(arqInd, noArvoreB, pro.cod,&posCha,&posArqInd);

    noLista* noLista = le_no_lista(arqDad,noArvoreB->ptDado[posCha]);
    if (booEnd) strcpy(noLista->info.end,pro.end);
    if (booTel) strcpy(noLista->info.tel,pro.tel);
    escreve_no(arqDad,noLista,noArvoreB->ptDado[posCha]);

    free(cab);
    fclose(arqInd);
    fclose(arqDad);
    free(noArvoreB);
    free(noLista);
}

void removerProfissionalManual(){

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
                sscanf(buffer,"%d;%[^;];%[^;];%[^;];%[^;];%[^\n]",&pro->cod,&pro->nom,&pro->cpf,&pro->numReg,&pro->end,&pro->tel);
                if(buscaCodigo(pro->cod)==-1) {
                    printf("Inserindo profissional.\n");
                    // TODO:RETIRABRANCOS
                    inserirProfissional(*pro);
                }
            } else if(fun == 'A'){
                fgets(buffer,1000,arq);
                sscanf(buffer,"%d%*c%[^;]%*c%[^\n]",&pro->cod,&pro->end,&pro->tel);
                if(buscaCodigo(pro->cod)!=-1) {
                    printf("Alterando profissional.\n");
                    // TODO:RETIRABRANCOS
                    int booEnd, booTel;
                    booEnd = (pro->end[0]!='\000');
                    booTel = (pro->tel[0]!='\000');
                    alterarProfissional(*pro, booEnd, booTel);
                }
            } else if(fun == 'R'){
                fgets(buffer,1000,arq);
                sscanf(buffer,"%d",&pro->cod);
                printf("Removendo profissional.\n");
                removerProfissional(*pro);
            }
            free(pro);
        }



    }

}

void consultarProfissionalAux(FILE* arqInd, FILE* arqDad, noArvoreB* no, int i) {
    int posCha, posArqInd;
    no = buscaArvoreB(arqInd, no, no->chave[i], &posCha, &posArqInd);
    noLista* noLista = le_no_lista(arqDad, no->ptDado[posCha]);
    printf("Codigo: %d\nNome: %s\nCPF: %11s\nNumero do Registro Profissional: %s\nEndereco: %s\nTelefone: %11s\n", no->chave[i],noLista->info.nom, noLista->info.cpf, noLista->info.numReg, noLista->info.end, noLista->info.tel);
    free(noLista);
}

void consultarProfissional(){

    profissional pro;

    printf("Digite o codigo do profissional a ser consultado.\n>");
    scanf("%d",&pro.cod);
    while (buscaCodigo(pro.cod) == -1){
        printf("Profissional nao encontrado, tente novamente.\n>");
        scanf("%d",&pro.cod);
    }


    FILE* arqInd = fopen("arqIndices.bin","rb+");
    FILE* arqDad = fopen("arqDados.bin","rb+");

    cabecalhoArvoreB* cab = leCabecalhoArvoreB(arqInd);

    noArvoreB* noArvoreB = leNoArvoreB(arqInd,cab->pos_raiz);
    consultarProfissionalAux(arqInd, arqDad, noArvoreB, pro.cod);
    free(cab);

    fclose(arqInd);
    fclose(arqDad);
    free(noArvoreB);

}

void imprimirNo(FILE* arqInd, FILE* arqDad, noArvoreB* noRaiz){
    int i;
    for (i = 0; i < noRaiz->numChaves; ++i)
        consultarProfissionalAux(arqInd, arqDad, noRaiz, i);
}

void listarProfissionaisAux(FILE* arqInd, FILE* arqDad, noArvoreB* noPai, int indCha){
    int posCha, posArqInd;
    if (eh_folha(noPai))
        imprimirNo(arqInd, arqDad, noPai);
    else{
        if(indCha < noPai->numChaves){
            noArvoreB * noFilho = leNoArvoreB(arqInd,noPai->filho[indCha]);
            listarProfissionaisAux(arqInd,arqDad,noFilho,0);
        }
        if(indCha != noPai->numChaves)
            consultarProfissionalAux(arqInd, arqDad, noPai, indCha);
        else {
            noArvoreB * noFilho = buscaArvoreB(arqInd, noPai, noPai->filho[indCha+1], &posCha, &posArqInd);
            listarProfissionaisAux(arqInd,arqDad,noFilho,0);
        }
    }
}

void listarProfissionais(){
    int i, posCha, posArqInd;
    FILE* arqInd = fopen("arqIndices.bin","rb+");
    FILE* arqDad = fopen("arqDados.bin","rb+");

    cabecalhoArvoreB* cab = leCabecalhoArvoreB(arqInd);
    noArvoreB* noRaiz = leNoArvoreB(arqInd, cab->pos_raiz);

    for ( i = 0; i <= noRaiz->numChaves; ++i)
        listarProfissionaisAux(arqInd, arqDad, noRaiz, 0);

    free(cab);
    fclose(arqInd);
    fclose(arqDad);
    free(noRaiz);
}