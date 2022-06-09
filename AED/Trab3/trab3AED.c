#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "trab3AED.h"
#include "arvoreTRIE_TST.h"


// Interface Principal
void interfacePrincipal(TST_TRIE dicionario){
    int x;
    printf("Bem vindo a Interface Principal!\nDigite um numero para continuar.\n");
    printf("1 - Consultar palavra.\n");
    printf("2 - Imprimir dicionario.\n");
    printf("3 - Carregar arquivo de stopwords.\n");
    printf("4 - Consultar palavra semelhante.\n");
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
            consultarPalavra(dicionario);
            interfacePrincipal(dicionario);
            break;
        case 2:

            break;
        case 3:

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
TST_TRIE carregarDicionario(){
    printf("Carregando arquivo 'dicionario.txt'\n");
    FILE* arq = fopen("dicionario.txt","r");
    if (arq == NULL) {
        printf("Nao foi possivel carregar o arquivo, por favor revisar o arquivo.\n");
        return NULL;
    } else {
        char buffer[MAXCHAR], str[MAXCHAR];
        int valor = 0;
        TST_TRIE noRaiz;
        while (feof(arq)==0) {
            fgets(buffer, MAXCHAR, arq);
            sscanf(buffer," %s", &str);
            if(ehPalavraValida(str)){
                noRaiz = inseirTST(noRaiz, str, &valor);
                valor++;
            }
        }
        printf("Arquivo carregado com sucesso!\n");
        return noRaiz;
    }
}

// Função auxiliar à consulta de palavra que percorre o nó e retorna o nó em que o prefixo termina.
// Pré-Condição: str tem que ser um prefixo em nó.
TST_TRIE consultarPalavraAux(TST_TRIE no, char* str) {
    if(*(str+1) == '\0')
        return no;
    if(*(str+1) == no->ch)
        return consultarPalavraAux(no->igual,str+1);
    if(*(str+1) > no->ch)
        return consultarPalavraAux(no->maior,str+1);
    return consultarPalavraAux(no->menor,str+1);
}

// Função auxiliar à consulta de palavra que percorre o nó na ordem in-ordem e imprime até MAX palavras que encontrar.
void consultarPalavraAux2(TST_TRIE no, char *str, int i, int MAX) {
    char strAux[MAXCHAR];
    if(ehFolha(no) && no->valor != -1){
        strcat(strAux, str);
        strcat(strAux, &(no->ch));//todo testar
        printf("%s",strAux);
    } else if (!ehFolha(no)){

    }
}

// Consulta as palavras que tiverem o prefisso
void consultarPalavra(TST_TRIE dicionario) {
    char str;
    printf("Digite a palavra que deseja consultar.\n");
    scanf(" %s",&str);
    if(buscaTST(dicionario,&str) == 0)
        printf("Prefixo nao tem palavras no dicionario");
    else {
        TST_TRIE noAux = consultarPalavraAux(dicionario, &str);

    }
}
