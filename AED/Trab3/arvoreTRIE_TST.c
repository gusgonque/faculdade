//
// Created by Gustavo on 07/06/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include "arvoreTRIE_TST.h"

// Verifica se o nó é vazio.
int ehVazio(TST_TRIE no){
    return (no == NULL);
}

// Verifica se o próximo caracter da string é \0.
int acabouString(char *str){
    return *(str + 1) == '\0';
}

//Insere no nó a string.
// Pré condição: valor tem que ser maior do que 0.
TST_TRIE inseirTST(TST_TRIE no, char *str, int* valor){
    if(ehVazio(no)){ // nó vazio
        if((*str) != '\0') { // fim da string
            no = (TST_TRIE) malloc(sizeof (TST_TRIE));
            no->ch = (*str);
            no->valor = ( acabouString(str) ? (*valor) : -1 ); // Se for a última letra adiciona o valor.
            no->maior = NULL;
            no->menor = NULL;
            no->igual = NULL;
            no->igual = inseirTST(no->igual, str + 1, valor);
        } else
            no = NULL;
        return no;
    } else if((*str) == no->ch){ // caracter maior lexicograficamente
        if(acabouString(str))
            no->valor = *valor;
        else
            no->igual = inseirTST(no->igual, str+1, valor);
        return no;
    } else if((*str) > no->ch){ // caracter maior lexicograficamente
        no->maior = inseirTST(no->maior, str, valor);
        return no;
    } else { // caracter menor lexicograficamente
        no->menor = inseirTST(no->menor, str, valor);
        return no;
    }
}

// Busca a string no nó e retorna 0 se não é possível continuar a busca, ou o valor do nó que termina a string.
int buscaTST(TST_TRIE no, char *str){
    if(ehVazio(no))
        return 0;
    if((*str) == no->ch)
        return (acabouString(str) ? no->valor : buscaTST(no->igual, str + 1));
    if((*str) > no->ch)
        return buscaTST(no->maior, str);
    return buscaTST(no->menor, str);
}

// Verifica se todas as ramificações do nó são vazias.
int ehFolha(TST_TRIE no){
    return (ehVazio(no->menor) && ehVazio(no->maior) && ehVazio(no->igual));
}

// Função auxiliar do remover, para se removeu o depois do próximo e o próximo não tiver nenhuma palavra registrada.
void removerTSTaux(TST_TRIE no){
    if(!ehVazio(no) && ehFolha(no) && (no->valor == -1)) {
        free(no);
        no = NULL;
    }
}

// Remove da árvore a string str, se tiver
void removerTST(TST_TRIE no, char *str){
    if(buscaTST(no,str) > 0){ // só vai remover se a palavra estiver no nó
        if(acabouString(str)){
            if(ehFolha(no)){
                free(no);
                no = NULL;
            } else
                no->valor = -1;
        } else if(no->ch == (*str)){ // se a palavra for mais embaixo
            removerTST(no->igual, str + 1);
            removerTSTaux(no->igual);
        } else if((*str) > no->ch){
            removerTST(no->maior, str);
            removerTSTaux(no->maior);
        } else{
            removerTST(no->menor, str);
            removerTSTaux(no->menor);
        }
    }
}