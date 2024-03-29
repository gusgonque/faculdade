#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "trab3AED.h"
#include "arvoreTRIE_TST.h"


// Interface Principal.
// Pré-Condição: dicionário tem que ser um nó TST válido.
// Pós-Condição: 'Interface' do menu aberto para o usuário escolher uma ação.
void interfacePrincipal(TST_TRIE *dicionario){
    int x;
    printf("Menu Principal!\nDigite um numero para continuar.\n");
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
            consultaSemelhante(*dicionario);
            interfacePrincipal(dicionario);
            break;
        case 0:
            break;

        default:
            break;
    }
}

// Verifica se a palavra é valida.
// Pré-Condição: String str deve existir.
// Pós-Condição: Transforma todos os caracteres em letras minúsculas e retorna um teste de ter apenas letras minúsculas (1) ou não (0).
int ehPalavraValida(char* str) {
    if((*str) != '\0') {
        *str = tolower(*str);
        return (islower(*str) && ehPalavraValida(++str));
    } else
        return 1;
}

// Carrega o arquivo do dicionário.
// Pré-Condição: Nó dicionário tem que ser um nó TST válido.
// Pós-Condição: Nó dicionário carregado com as palavras do arquivo.
void carregarDicionario(TST_TRIE * dicionario) {
    char *arqDicicionario = (char *) malloc(50 * sizeof(char));

    printf("Entre com o nome do arquivo dicionario:\n> ");
    scanf("%[^\n]%*c", arqDicicionario);
    arqDicicionario = (char *) realloc(arqDicicionario, sizeof(arqDicicionario));

    FILE* arq = fopen(arqDicicionario,"r");
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
        printf("Arquivo carregado com sucesso!\n\n");
        free(arqDicicionario);

    }
}

// Função auxiliar à consulta de palavra que percorre o nó.
// Pré-Condição: String pref tem que ser um prefixo em nó.
// Pós-Condição: Retorna o nó em que o prefixo termina.
TST_TRIE consultarPalavraAux(TST_TRIE no, char* pref) {
    if(*pref == no->ch) {
        if (*(pref + 1) == '\0')
            return no;
        return consultarPalavraAux(no->igual, pref + 1);
    } if(*pref > no->ch)
        return consultarPalavraAux(no->maior, pref);
    return consultarPalavraAux(no->menor, pref);
}

// Função auxiliar à consulta de palavra que percorre o nó na ordem in-ordem.
// Pré-Condição: String pref tem que ser um prefixo em nó.
// Pós-Condição: Imprime até MAX palavras que encontrar, em ordem alfabética.
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

// Consulta as palavras que tiverem o prefisso.
// Pré-Condição: Nó dicionário tem que ser um nó TST válido.
// Pós-Condição: Imprime as palavras que encontrar no dicionário, em ordem alfabética.
void consultarPalavra(TST_TRIE dicionario) {
    char *pref =  (char *) malloc(MAXCHAR * sizeof(char));

    printf("Digite a palavra que deseja consultar.\n>");
    scanf("%s",pref);
    pref = (char *) realloc(pref, sizeof(pref));
    if(!ehPalavraValida(pref))
        printf("Palavra invalida.\n\n");
    else {
        if (buscaTST(&dicionario, pref) == 0)
            printf("Prefixo nao tem palavras no dicionario\n");
        else {
            TST_TRIE no = consultarPalavraAux(dicionario, pref);
            int i = 0;
            printf("Palavras que comecam com o prefixo %s:\n", pref);
            consultarPalavraAux2(no, pref, &i, 10);
        }
        printf("\n");
    }
    free(pref);
}

// Imprime todas as palavras no dicionario.
// Pré-Condição: Nó dicionário tem que ser um nó TST válido.
// Pós-Condição: Imprime as palavras do dicionário, em ordem alfabética.
void imprimirDicionario(TST_TRIE dicionario){
    int i = 0;
    char strAux[2] = "0";
    consultarPalavraAux2(dicionario, strAux, &i, 100000); // LIMITE DE 100000 PALAVRAS NO DICIONARIO...
    printf("\n");
}

// Carrega o arquivo de palavras a serem removidas do dicionario.
// Pré-Condição: Nó dicionário tem que ser um nó TST válido.
// Pós-Condição: Remove palavras do dicionário, de acordo com o arquivo.
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

// Consulta as palavras semelhantes à digitada pelo usuário, pelo algoritmo de Levenshtein.
// Pré-Condição: Nó dicionário tem que ser um nó TST válido.
// Pós-Condição: Imprime as palavras semelhantes à escolhida.
void consultaSemelhante(TST_TRIE dicionario){
    char *strW = (char *) malloc(MAXCHAR * sizeof(char)), *strAux = (char *) malloc( sizeof(char));
    int n;

    printf("Digite a palvra e a distancia (0-3) que deseja consultar.\n>");
    scanf("%s", strW);
    printf(">");
    scanf("%d",&n);
    while(n > 3 || n < 0){
        printf("Valor invalido!! Insira a distancia novamente.\n>");
        scanf("%d", &n);
    }

    strW = (char *) realloc(strW, sizeof(strW));
    *strAux = '\0';
    if(!ehPalavraValida(strW))
        printf("Palavra invalida.\n");
    else {
        printf("Palavras semelhantes:\n");
        consultarSemelhanteTST(dicionario, strAux, strW, n);
    }
    printf("\n");
    free(strW);
    free(strAux);
}
