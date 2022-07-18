#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvoreTRIE_TST.h"

// Verifica se o nó é vazio.
// Pré-Condição: Nó TST válido.
// Pós-Condição: Retorna o resultado do teste do nó ser vazio (1) ou não (0).
int ehVazio(TST_TRIE no){
    return (no == NULL);
}

// Verifica se o próximo caracter da string é \0.
// Pré-Condição: String válida.
// Pós-Condição: Retorna o resultado do teste da string ter acabado (1) ou não (0).
int acabouString(char *str){
    return *(str + 1) == '\0';
}

// Insere no nó a string.
// Pré-condição: valor tem que ser maior do que 0.
// Pós-Condição: Insere a string str no nó, pelo algorítmo TST com o valor indicando fim de uma palavra.
void inserirTST(TST_TRIE * no, char * str, int valor) {
    if(ehVazio(*no)){ // nó vazio
        if((*str) != '\0') { // fim da string
            (*no) = (noTST_TRIE*) malloc(sizeof (noTST_TRIE));
            (*no)->ch = (*str);
            (*no)->valor = (acabouString(str) ? (valor) : -1 ); // Se for a última letra adiciona o valor.
            (*no)->maior = NULL;
            (*no)->menor = NULL;
            (*no)->igual = NULL;
            inserirTST(&(*no)->igual, str + 1, valor);
        } else
            (*no) = NULL;
    } else if((*str) == (*no)->ch){ // caracter igual lexicograficamente
        if(acabouString(str))
            (*no)->valor = valor;
        else
            inserirTST(&(*no)->igual, str+1, valor);
    } else if((*str) > (*no)->ch){ // caracter maior lexicograficamente
        inserirTST(&(*no)->maior, str, valor);
    } else { // caracter menor lexicograficamente
        inserirTST(&(*no)->menor, str, valor);
    }
}

// Busca a string no nó.
// Pré-Condição: Nó TST válido.
// Pós-Condição: Retorna 0 se não é possível continuar a busca, ou o valor do nó que termina a string.
int buscaTST(TST_TRIE *no, char *str){
    if(ehVazio(*no))
        return 0;
    if((*str) == (*no)->ch)
        return (acabouString(str) ? (*no)->valor : buscaTST(&(*no)->igual, str+1));
    if((*str) > (*no)->ch)
        return buscaTST(&(*no)->maior, str);
    return buscaTST(&(*no)->menor, str);
}

// Verifica se todas as ramificações do nó são vazias.
// Pré-Condição: Nó TST válido.
// Pós-Condição: Retorna o resultado do teste do nó ser folha (1) ou não (0).
int ehFolha(TST_TRIE no){
    return (ehVazio(no->menor) && ehVazio(no->maior) && ehVazio(no->igual));
}

// Função auxiliar do removerTST que remove o nó pai do nó removido se aquele for folha e não tiver valor definido.
// Pré-Condição: Nó TST válido.
// Pós-Condição: Remove o nó pai do nó removido se aquele for folha e não tiver valor definido.
void removerTSTaux(TST_TRIE *no) {
    if (!ehVazio(*no) && ehFolha(*no) && ((*no)->valor == -1)) {
        free(*no);
        (*no) = NULL;
    }
}

// Remove da árvore a string str, se tiver.
// Pré-Condição: Nó TST válido.
// Pós-Condição: Remove da árvore a string str, se tiver.
void removerTST(TST_TRIE * no, char *str) {
    if (buscaTST(no, str) > 0) { // só vai remover se a palavra estiver no nó
        if (acabouString(str)) {
            if (ehFolha(*no)) {
                free(*no);
                (*no) = NULL;
            } else // Mao eh folha
                (*no)->valor = -1;
        } else if ((*str) == (*no)->ch) { // se a palavra for mais embaixo
            removerTST(&(*no)->igual, str + 1);
        } else if ((*str) > (*no)->ch) {
            removerTST(&(*no)->maior, str);
        } else
            removerTST(&(*no)->menor, str);
        removerTSTaux(no);
    }
}

// Retorna o menor valor entre os parâmetros.
// Pré-Condição: Parâmetros devem ser números válidos.
// Pós-Condição: Retorna o menor valor entre os parâmetros.
int min(int a, int b, int c){
    if(a <= b && a <= c)
        return a;
    else if(b <= a && b <= c)
        return b;
    return c;
}

// Calcula a distância de semelhança entre duas strings pelo algorítmo de Levenshtein.
// Pré-Condição: Parâmetros devem ser strings válidas.
// Pós-Condição: Retorna a distância de semelhança das strings.
int distanciaLevenshtein (char * str1, char * str2){
    unsigned int  x, y, str1len, str2len;
    str1len = strlen(str1);
    str2len = strlen(str2);
    unsigned int matrix[str2len+1][str1len+1];
    matrix[0][0] = 0;
    for (x = 1; x <= str2len; x++)
        matrix[x][0] = matrix[x-1][0] + 1;
    for (y = 1; y <= str1len; y++)
        matrix[0][y] = matrix[0][y-1] + 1;
    for (x = 1; x <= str2len; x++)
        for (y = 1; y <= str1len; y++)
            matrix[x][y] = min(matrix[x-1][y] + 1, matrix[x][y-1] + 1, matrix[x-1][y-1] + (str1[y-1] == str2[x-1] ? 0 : 1));

    return(matrix[str2len][str1len]);
}

// Percorre o nó e consulta as palavras semelhantes à string strW, com valor de distância de semelhança n.
// Pré-Condição: Parâmetros devem ser válidas.
// Pós-Condição: Imprime as palavras semelhantes.
void consultarSemelhanteTST(TST_TRIE no, char *str, char *strW, int n) {
    if(!ehVazio(no)) {
        consultarSemelhanteTST((no->menor),str,strW,n);

        int aux = strlen(str);
        str = (char *) realloc(str, sizeof(str)+1);
        *(str + aux) = no->ch;
        *(str + aux + 1) = '\0';

        if((no->valor != -1) && (distanciaLevenshtein(str, strW) <= n))
            printf("%s\n", str);
        consultarSemelhanteTST((no->igual),str,strW,n);

        *(str + aux) = '\0';
        strW = (char *) realloc(strW, sizeof(strW));
        consultarSemelhanteTST((no->maior),str,strW,n);
    }
}