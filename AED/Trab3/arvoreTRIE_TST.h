#ifndef FACULDADE_ARVORETRIE_TST_H
#define FACULDADE_ARVORETRIE_TST_H

typedef struct noTST {
    char ch; //caracter da TRIE
    int valor; // valor associado à chave
    struct noTST * menor; // antes de ch na ordem lexicográfica
    struct noTST * igual;
    struct noTST * maior; // depois de ch na ordem lexicográfica
} noTST_TRIE;

typedef noTST_TRIE * TST_TRIE;

// Verifica se o nó é vazio.
// Pré-Condição: Nó TST válido.
// Pós-Condição: Retorna o resultado do teste do nó ser vazio (1) ou não (0).
int ehVazio(TST_TRIE no);

// Verifica se o próximo caracter da string é \0.
// Pré-Condição: String válida.
// Pós-Condição: Retorna o resultado do teste da string ter acabado (1) ou não (0).
int acabouString(char *str);

// Insere no nó a string.
// Pré-condição: valor tem que ser maior do que 0.
// Pós-Condição: Insere a string str no nó, pelo algorítmo TST com o valor indicando fim de uma palavra.
void inserirTST(TST_TRIE * no, char * str, int valor);

// Busca a string no nó.
// Pré-Condição: Nó TST válido.
// Pós-Condição: Retorna 0 se não é possível continuar a busca, ou o valor do nó que termina a string.
int buscaTST(TST_TRIE *no, char *str);

// Verifica se todas as ramificações do nó são vazias.
// Pré-Condição: Nó TST válido.
// Pós-Condição: Retorna o resultado do teste do nó ser folha (1) ou não (0).
int ehFolha(TST_TRIE no);

// Função auxiliar do removerTST que remove o nó pai do nó removido se aquele for folha e não tiver valor definido.
// Pré-Condição: Nó TST válido.
// Pós-Condição: Remove o nó pai do nó removido se aquele for folha e não tiver valor definido.
void removerTSTaux(TST_TRIE *no);

// Remove da árvore a string str, se tiver.
// Pré-Condição: Nó TST válido.
// Pós-Condição: Remove da árvore a string str, se tiver.
void removerTST(TST_TRIE *no, char *str);

// Retorna o menor valor entre os parâmetros.
// Pré-Condição: Parâmetros devem ser números válidos.
// Pós-Condição: Retorna o menor valor entre os parâmetros.
int min (int a, int b, int c);

// Calcula a distância de semelhança entre duas strings pelo algorítmo de Levenshtein.
// Pré-Condição: Parâmetros devem ser strings válidas.
// Pós-Condição: Retorna a distância de semelhança das strings.
int distanciaLevenshtein (char * str1, char * str2);

// Percorre o nó e consulta as palavras semelhantes à string strW, com valor de distância de semelhança n.
// Pré-Condição: Parâmetros devem ser válidas.
// Pós-Condição: Imprime as palavras semelhantes.
void consultarSemelhanteTST(TST_TRIE no, char *str, char *strW, int n);

#endif //FACULDADE_ARVORETRIE_TST_H
