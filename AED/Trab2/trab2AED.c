#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trab2AED.h"
#include "arvoreBArq.h"
#include "listaSimplesArquivo.h"

// Apresenta a interface principal
// Pré condição: nenhuma
// Pós condição: faz alguma das opções
void interfacePrincipal(){
    int x;
    printf("Bem vindo a Interface Principal!\nDigite um numero para continuar.\n");
    printf("1 - Interface de registro de profissional. (Inserir/Alterar/Remover)\n");
    printf("2 - Carregar arquivo texto.\n");
    printf("3 - Consultar profissional.\n");
    printf("4 - Listar profissionais.\n");
    printf("5 - Imprimir arvoreB.\n");
    printf("6 - Imprimir posicoes livres do arquivo de indices.\n");
    printf("7 - Imprimir posicoes livres do arquivo de dados.\n");
    printf("0 - Finalizar programa.\n");

    printf(">");
    scanf("%d",&x);
    while (x<0 || x>7){
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
            imprimirArvoreB();
            interfacePrincipal();
            break;

        case 6: {
            FILE *arqDad = fopen("arqDados.bin", "rb+");
            if (arqDad != NULL)
                imprimirPosicoesLivresDados(arqDad);
            else
                printf("Arquivo de Dados nao criado.\n");
            fclose(arqDad);
            interfacePrincipal();
            break;
        }
        case 7:{
            FILE *arqInd = fopen("arqIndices.bin", "rb+");
            if (arqInd != NULL)
                imprimirPosicoesLivresIndices(arqInd);
            else
                printf("Arquivo de Indices nao criado.\n");
            fclose(arqInd);
            interfacePrincipal();
            break;
        }
        case 0:
            break;

        default:
            break;
    }
}

// Apresenta a interface de registro do usuário
// Pré condição: x válido
// Pós condição: faz alguma das opções
int interfaceRegistro(){
    int x;
    printf("Bem vindo a interface de Registro de profissionais!\nDigite um numero para continuar.\n");
    printf("1 - Inserir novo profissional.\n");
    printf("2 - Alterar endereco ou telefone de um profissional.\n");
    printf("3 - Remover um profissional.\n");
    printf("0 - Retornar ao menu anterior.\n");

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
// Pré condição: arquivo criado.
// Pós condição: retorna o endereco daquela chave naquele nó do arquivo. Qualquer outro caso retorna -1.
int buscaCodigo(int cod) {
    FILE* arqInd = fopen("arqIndices.bin","rb+");
    if (arqInd == NULL) {
        printf("Arquivo de Indices nao criado.\n");
        return -1;
    }

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

// Faz a interface para o usuário inserir um novo profissional
// Pré condição: nenhuma
// Pós condição: aciona a função inserirProfissional
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

// Insere o profisisonal(chave), na raíz do arq de Indices.
// Pré condição: nenhuma
// Pós condição: Insere o profisisonal(chave), na raíz do arq de Indices.
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
    printf("Usuario inserido com sucesso!\n");
}

// Faz a interface para o usuário alterar um profissional
// Pré condição: arquivo criado
// Pós condição: aciona a função alterarProfissional
void alterarProfissionalManual(){
    profissional pro;
    int x;
    char buffer[CHARMAX];

    FILE* arqInd = fopen("arqIndices.bin","rb+");

    if(arqInd!=NULL) {
        printf("Digite o codigo do usuario que deseja alterar.\n>");
        scanf("%d", &pro.cod);

        if (buscaCodigo(pro.cod) == -1) {
            printf("Codigo nao registrado, tente novamente.\n>");
            scanf("%d", &pro.cod);
        }
        printf("Digite qual a alteracao desejada.\n");
        printf("1 - Alterar telefone.\n");
        printf("2 - Alterar endereco.\n>");
        scanf("%d", &x);
        LER_ESPACO;

        switch (x) {
            case 1:
                printf("Digite o novo telefone.\n>");
                gets(buffer);
                sscanf(buffer, "%[^\n]", &pro.tel);
                alterarProfissional(pro, 0, 1);
                break;
            case 2:
                printf("Digite o novo endereco.\n>");
                gets(buffer);
                sscanf(buffer, "%[^\n]", &pro.end);
                alterarProfissional(pro, 1, 0);
                break;
        }
    } else
        printf("Arquivo de Indices nao criado, retornando ao menu anterior");
}

// Altera o profissional
// Pré condição: arquivo criado
// Pós condição: Altera o profissional
void alterarProfissional(profissional pro, int booEnd, int booTel) {
    FILE* arqInd = fopen("arqIndices.bin","rb+");
    FILE* arqDad = fopen("arqDados.bin","rb+");

    if(arqInd != NULL){
        cabecalhoArvoreB *cab = leCabecalhoArvoreB(arqInd);

        noArvoreB *noArvoreB = leNoArvoreB(arqInd, cab->pos_raiz);
        int posCha, posArqInd;
        noArvoreB = buscaArvoreB(arqInd, noArvoreB, pro.cod, &posCha, &posArqInd);

        noLista *noLista = le_no_lista(arqDad, noArvoreB->ptDado[posCha]);
        if (booEnd) strcpy(noLista->info.end, pro.end);
        if (booTel) strcpy(noLista->info.tel, pro.tel);
        escreve_no(arqDad, noLista, noArvoreB->ptDado[posCha]);

        free(cab);
        fclose(arqInd);
        fclose(arqDad);
        free(noArvoreB);
        free(noLista);
        printf("Usuario alterado com sucesso!\n");
    }
}

// Faz a interface para o usuário remover um profissional
// Pré condição: Arquivo criado
// Pós condição: aciona a função removerProfissional
void removerProfissionalManual(){

}

// Remove um profissional
// Pré condição: Arquivo criado
// Pós condição: Remove o profissional
void removerProfissional(profissional pro){

}

// Carrega o arquivo de funções a serem tratadas pelo programa
// Pré condição: Arquivo criado
// Pós condição: arquivo carregado e funções tratadas
void carregarArquivo(){
    char s[CHARMAX];
    printf("Favor digitar o nome do arquivo a ser carregado. Ex: 'arq.txt'\n");
    scanf("%s",&s);
    printf("nome do arquivo = '%s'\n",s);

    FILE* arq = fopen(s,"r");
    if(arq == NULL)
        printf("Nao foi possivel abrir o arquivo.\n");
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
                    // TODO:RETIRABRANCOS
                    inserirProfissional(*pro);
                }
            } else if(fun == 'A'){
                fgets(buffer,1000,arq);
                sscanf(buffer,"%d%*c%[^;]%*c%[^\n]",&pro->cod,&pro->end,&pro->tel);
                if(buscaCodigo(pro->cod)!=-1) {
                    // TODO:RETIRABRANCOS
                    int booEnd, booTel;
                    booEnd = (pro->end[0]!='\000');
                    booTel = (pro->tel[0]!='\000');
                    alterarProfissional(*pro, booEnd, booTel);
                }
            } else if(fun == 'R'){
                fgets(buffer,1000,arq);
                sscanf(buffer,"%d",&pro->cod);
                removerProfissional(*pro);
            }
            free(pro);
        }



    }

}

//Busca um profissional no arquivo de dados pelo arquivo de indices
// Pré condição: Arquivos criados
// Pós condição: apresenta as indormações do usuário buscado.
void consultarProfissionalAux(FILE* arqInd, FILE* arqDad, noArvoreB* no, int indCha) {
    int posCha, posArqInd;
    no = buscaArvoreB(arqInd, no, no->chave[indCha], &posCha, &posArqInd);
    noLista* noLista = le_no_lista(arqDad, no->ptDado[posCha]);
    printf("Codigo: %d\nNome: %s\nCPF: %s\nNumero do Registro Profissional: %s\nEndereco: %s\nTelefone: %s\n--/--\n", no->chave[indCha], noLista->info.nom, noLista->info.cpf, noLista->info.numReg, noLista->info.end, noLista->info.tel);
    free(noLista);
}

// Apresenta a interface de busca do usuário
// Pré condição: arquivos criados
// Pós condição: chama o consultarProfissionalAux para apresenta as indormações do usuário buscado.
void consultarProfissional(){
    profissional pro;
    int posCha, posArqDad;

    FILE* arqInd = fopen("arqIndices.bin","rb+");

    if(arqInd!=NULL) {

        printf("Digite o codigo do profissional a ser consultado.\n>");
        scanf("%d", &pro.cod);
        while ( buscaCodigo(pro.cod) == -1) {
            printf("Profissional nao encontrado, tente novamente.\n>");
            scanf("%d", &pro.cod);
        }

        if (pro.cod != -1) {
            FILE *arqDad = fopen("arqDados.bin", "rb+");

            if (arqInd != NULL) {
                cabecalhoArvoreB *cab = leCabecalhoArvoreB(arqInd);
                noArvoreB *no = buscaArvoreB(arqInd, leNoArvoreB(arqInd, cab->pos_raiz), pro.cod, &posCha, &posArqDad);
                consultarProfissionalAux(arqInd, arqDad, no, buscaCodigo(pro.cod));
                free(cab);
                free(no);
            }
            fclose(arqDad);
        }
    }
    fclose(arqInd);
}

// Imprime todas as informações dos usuários na chave
// Pré condição: arquivos criados
// Pós condição: chama o consultarProfissionalAux para apresenta as indormações do usuário buscado.
void imprimirProfissionaisNo(FILE* arqInd, FILE* arqDad, noArvoreB* noRaiz){
    int i;
    for (i = 0; i < noRaiz->numChaves; ++i)
        consultarProfissionalAux(arqInd, arqDad, noRaiz, i);
}

// Função recursiva que lista todos os profissionais no nó a partir do indice de chave indCha
// Pré condição: arquivos criados
// Pós condição: chama o consultarProfissionalAux para apresenta as indormações dos profissionais.
void listarProfissionaisAux(FILE* arqInd, FILE* arqDad, noArvoreB* noPai, int indCha){
    if (eh_folha(noPai))
        imprimirProfissionaisNo(arqInd, arqDad, noPai);
    else{
        noArvoreB * noFilho = leNoArvoreB(arqInd,noPai->filho[indCha]);
        listarProfissionaisAux(arqInd,arqDad,noFilho,0);
        consultarProfissionalAux(arqInd, arqDad, noPai, indCha);
        if(indCha < noPai->numChaves-1)
            listarProfissionaisAux(arqInd,arqDad,noPai,indCha+1);
        if (indCha == noPai->numChaves-1){
            noFilho = leNoArvoreB(arqInd,noPai->filho[indCha+1]);
            listarProfissionaisAux(arqInd,arqDad,noFilho,0);
        }
        free(noFilho);
    }
}

// Chama a função listarProfissionaisAux
// Pré condição: arquivos criados
// Pós condição: Chama a função listarProfissionaisAux para apresenta as indormações dos profissionais.
void listarProfissionais(){
    FILE* arqInd = fopen("arqIndices.bin","rb+");
    FILE* arqDad = fopen("arqDados.bin","rb+");

    if(arqInd!=NULL){
        cabecalhoArvoreB *cab = leCabecalhoArvoreB(arqInd);
        noArvoreB *noRaiz = leNoArvoreB(arqInd, cab->pos_raiz);
        listarProfissionaisAux(arqInd, arqDad, noRaiz, 0);

        free(noRaiz);
        free(cab);
    }
    else
        printf("Arquivo de Indices nao criado.\n");

    fclose(arqInd);
    fclose(arqDad);
}

// Imprime os nós da chave
// Pré condição: nó valido
// Pós condição: Imprime os nós da chave
void imprimirCodigosNivelAux(noArvoreB *no) {
    int i;
    printf("[");
    for ( i = 0; i < no->numChaves; ++i) {
        printf("%d", no->chave[i]);
        if(i!=no->numChaves-1)
            printf(" , ");
    }
    printf("] ");
}

// chama o imprimirCodigosNivelAux pra imprimir os códigos por nível
// Pré condição: nó valido
// Pós condição:chama o imprimirCodigosNivelAux pra imprimir os códigos  por nível
void imprimirCodigosNivel(FILE* arqInd,noArvoreB* no,int niv){
    int i;
    imprimirCodigosNivelAux(no);
    if(!eh_folha(no)) {
        printf("\n");
        for (i = 0; i <= no->numChaves; ++i) {
            noArvoreB *noFil = leNoArvoreB(arqInd, no->filho[i]);
            imprimirCodigosNivel(arqInd, noFil, niv + 1);
            free(noFil);
        }
    }
}

// Imprime os nós por nível
// Pré condição: arquivos criados
// Pós condição: Imprime os nós por nível
void imprimirArvoreB(){
    FILE* arqInd = fopen("arqIndices.bin","rb+");

    if(arqInd!=NULL){
        cabecalhoArvoreB *cab = leCabecalhoArvoreB(arqInd);
        noArvoreB *noRaiz = leNoArvoreB(arqInd, cab->pos_raiz);

        imprimirCodigosNivel(arqInd,noRaiz,0);
        printf("\n");

        free(noRaiz);
        free(cab);
    }
    else
        printf("Arquivo de Indices nao criado.\n");

    fclose(arqInd);
}

// Imprime os nós livres da lista de Dados
// Pré condição: arquivos criados
// Pós condição: Imprime os nós
void imprimirPosicoesLivresDados(FILE* arqDad){
    cabecalhoLista* cab = le_cabecalho_lista(arqDad);
    if(cab->pos_livre != -1) {
        printf("Posicoes livres no arquivo de Dados: ");
        int posArq = cab->pos_livre;
        noLista* no = le_no_lista(arqDad, posArq);
        while (no->info.cod != -1) {
            printf("%d ", posArq);
            no = le_no_lista(arqDad, no->info.cod);
            posArq = no->info.cod;
        }
        free(no);
        printf("\n");
    }
    else
        printf("Nao ha posicoes livres no arquivo de Dados.\n");
    free(cab);
}

// Imprime os nós livres da árvore de Índices
// Pré condição: arquivos criados
// Pós condição: Imprime os nós
void imprimirPosicoesLivresIndices(FILE* arqInd){
    cabecalhoArvoreB* cab = leCabecalhoArvoreB(arqInd);
    if(cab->pos_livre != -1) {
        printf("Posicoes livres no arquivo de Indices: ");
        int posArq = cab->pos_livre;
        noArvoreB* no = leNoArvoreB(arqInd, posArq);
        while (no->numChaves != -1) {
            printf("%d ", posArq);
            no = leNoArvoreB(arqInd, no->numChaves);
            posArq = no->numChaves;
        }
        free(no);
        printf("\n");
    }
    else
        printf("Nao ha posicoes livres no arquivo de Indices.\n");
    free(cab);
}