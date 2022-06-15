#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "trab3AED.h"
#include "arvoreTRIE_TST.h"


// Interface Principal
void interfacePrincipal(TST_TRIE *dicionario){
    int x;
    printf("Bem vindo a Interface Principal!\nDigite um numero para continuar.\n");
    printf("1 - Consultar palavra.\n");
    printf("2 - Imprimir dicionario.\n");
    printf("3 - Carregar arquivo de stopwords.\n");
    printf("4 - Consultar palavra semelhante.\n");
    printf("0 - Finalizar programa.\n");

    printf(">");
    scanf("%d",&x);
    while (x<0 || x>4){
        printf("Comando invalido. Digite novamente.\n");
        printf(">");
        scanf("%d",&x);
    }

    switch (x) {
        case 1:
            consultarPalavra(*dicionario);
            interfacePrincipal(dicionario);
            break;
        case 2:
            imprimirDicionario(*dicionario);
            interfacePrincipal(dicionario);
            break;
        case 3:
            carregarStopWords(dicionario);
            interfacePrincipal(dicionario);
            break;
        case 4:

            interfacePrincipal(dicionario);
            break;
        case 0:
            break;

        default:
            break;
    }
}

// Verifica se a palavra é valida
int ehPalavraValida(char* str) {
    if((*str) != '\0') {
        *str = tolower(*str);
        return (islower(*str) && ehPalavraValida(++str));
    } else
        return 1;
}

// Carrega o arquivo do dicionário
void carregarDicionario(TST_TRIE *dicionario) {
    printf("Carregando arquivo 'dicionario.txt'\n");
    FILE* arq = fopen("dicionario.txt","r");
    if (arq == NULL) {
        printf("Nao foi possivel carregar o arquivo, por favor revisar o arquivo.\n");
        dicionario = NULL;
    } else {
        char buffer[MAXCHAR], str[MAXCHAR];
        int valor = 1;
        while (feof(arq)==0) {
            fgets(buffer, MAXCHAR, arq);
            sscanf(buffer," %s", str);
            if(ehPalavraValida(str)){
                inserirTST(dicionario, str, valor);
                valor++;
            }
        }
        printf("Arquivo carregado com sucesso!\n");
    }
}

// Função auxiliar à consulta de palavra que percorre o nó e retorna o nó em que o prefixo termina.
// Pré-Condição: pref tem que ser um prefixo em nó.
TST_TRIE consultarPalavraAux(TST_TRIE no, char* pref) {
    if(*(pref + 1) == '\0')
        return no;
    if(*pref == no->ch)
        return consultarPalavraAux(no->igual, pref + 1);
    if(*pref > no->ch)
        return consultarPalavraAux(no->maior, pref + 1);
    return consultarPalavraAux(no->menor, pref + 1);
}

// Função auxiliar à consulta de palavra que percorre o nó na ordem in-ordem e imprime até MAX palavras que encontrar.
void consultarPalavraAux2(TST_TRIE no, char *pref, int* i, int MAX) {
    char strAux[MAXCHAR];
    strcpy(strAux, pref);
    int tam = strlen(strAux);
    if(*i<MAX && !ehVazio(no)) {
        if(no->valor != -1) {
            (*i)++;
            printf("%s\n", pref);
        }if(*i<MAX && !ehFolha(no)){
            if(!ehVazio(no->menor)){
                strAux[tam-1] = no->menor->ch;
                consultarPalavraAux2(no->menor, strAux, i, MAX);
            }if(*i<MAX && !ehVazio(no->igual)){
                strAux[tam-1] = no->ch;
                strAux[tam] = no->igual->ch;
                strAux[tam+1] = '\0';
                consultarPalavraAux2(no->igual, strAux, i, MAX);
            }if(*i<MAX && !ehVazio(no->maior)){
                strAux[tam-1] = no->maior->ch;
                strAux[tam] = '\0';
                consultarPalavraAux2(no->maior, strAux, i, MAX);
            }
        }
    }

}

// Consulta as palavras que tiverem o prefisso
void consultarPalavra(TST_TRIE dicionario) {
    char pref[MAXCHAR];
    printf("Digite a palavra que deseja consultar.\n>");
    scanf(" %s",pref);
    if(buscaTST(&dicionario,pref) == 0)
        printf("Prefixo nao tem palavras no dicionario");
    else{
        TST_TRIE no = consultarPalavraAux(dicionario,pref);
        int i=0;
        printf("Palavras que comecam com o prefixo %s:\n", pref);
        consultarPalavraAux2(no, pref, &i, 10);
    }
    printf("\n");
}

// Imprime todas as palavras no dicionario
void imprimirDicionario(TST_TRIE dicionario){
    int i = 0;
    char strAux[2] = "0";
    consultarPalavraAux2(dicionario, strAux, &i, 100000); // LIMITE DE 100000 PALAVRAS NO DICIONARIO....
    printf("\n");
}

// Carrega o arquivo de palavras a serem removidas do dicionario
void carregarStopWords(TST_TRIE *dicionario){
    printf("Carregando arquivo 'stopwords.txt'\n");
    FILE* arq = fopen("stopwords.txt","r");
    if (arq == NULL) {
        printf("Nao foi possivel carregar o arquivo, por favor revisar o arquivo.\n");
    } else {
        char buffer[MAXCHAR], str[MAXCHAR];
        while (feof(arq)==0) {
            fgets(buffer, MAXCHAR, arq);
            sscanf(buffer," %s", str);
            if(ehPalavraValida(str))
                removerTST(dicionario,str);
        }
        printf("Arquivo carregado com sucesso!\n");
    }
}