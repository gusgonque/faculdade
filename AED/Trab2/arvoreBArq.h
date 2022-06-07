#ifndef FACULDADE_ARVOREBARQ_H
#define FACULDADE_ARVOREBARQ_H

#include <stdio.h>
#include "trab2AED.h"

// cabecalhoLista do arquivo
typedef struct {
    int pos_raiz; //posição da raiz da arvore
    int pos_topo; // 1a posição não usada noArvoreB fim do arquivo
    int pos_livre; // posição do início da lista de nós livres
} cabecalhoArvoreB;

#define ORDEM 5 // Ordem

typedef struct no {
    int numChaves;
    int chave[ORDEM];
    int ptDado[ORDEM];
    int filho[ORDEM+1];
} noArvoreB;

//Busca a chave info nas chaves e retora 1 se ela está no nó, ou 0 se não está no nó
//o ponteiro posCha contém a posição do nó no vetor de chaves.
//Pré-condição: no criado
//Pós-condilção: retora 1 se a info está no nó, ou 0 se não está no nó
int buscaChave(noArvoreB* no, int info, int * posCha);

//Verifica se o nó é vazio.
//Pré-condição: no criado
//Pós-condilção: retora 1 se o nó é vazio, ou 0 se não
int noEhVazio(noArvoreB* no);

//Verifica se o nó é uma folha na árvore.
//Pré-condição: no criado
//Pós-condilção: retora 1 se o nó é uma folha, ou 0 se não
int eh_folha(noArvoreB* reg);

//Altera o no na posição posArq para o novo no
//Pré-condição: arquivo deve estar aberto e ser um arquivo de arvore B
//Pós-condilção: nó re-escrito no arquivo
void alteraNoArquivo(FILE* arq, noArvoreB* no, int posArq);

//Insere o novo nó no topo do arquivo
//Pré-condição: arquivo deve estar aberto e ser um arquivo de arvore B
//Pós-condilção: nó escrito no arquivo
void escreveTopoArvoreB(FILE* arq, noArvoreB* no);

//lê um nó em uma determinada posição do arquivo
//Pré-condição: arquivo deve estar aberto e ser um arquivo de Arvore B
// posArq deve ser uma posição válida da Arvore B
//Pós-condição: ponteiro para nó lido é retornado
//Ter que liberar a memória após usar o x
noArvoreB* leNoArvoreB(FILE* arq, int posArq);

// Quebra o no (com ehOverflow) e retorna o no criado e a chave cha que deve ser promovida
// Ter que liberar a memória após usar o nonov
// Pré-condição: no valido.
// Pós-condição: retorna o no criado e a chave cha que deve ser promovida
noArvoreB* split(noArvoreB* no, int* cha, int* ptDado);

// Adiciona a chave cha com o filho fil.
// Pré-condição: no valido.
//Pós-condilção: adiciona a chave cha no nó
// o nó deve ser alterado no arquivo após adicionar a chave
void adicionaDireita(noArvoreB* no, int posCha, int cha, int ptDado, int fil);

// Verifica se o nó tem o número máximo de chaves.
//Pré-condição: no valido
//Pós-condilção: retora 1 se o nó tem exesso de chaves, ou 0 se não
int ehOverflow(noArvoreB* no);

//Insere uma chave à Árvore B não vazia
//Pré-condição: arquivo deve estar aberto e ser um arquivo de arvore B
//Pós-condilção: insere o chave no nó
void insere_aux(FILE* arq, noArvoreB* noPai, int posArq, int cha, int ptDado);

// Insere uma chave raiz nó na raíz da árvore B
//Pré-condição: arquivo deve estar aberto e ser um arquivo de arvore B
//Pós-condilção: insere o chave no nó
void insereNo(FILE* arq, noArvoreB* raiz, int posArq, int cha, int ptDado);

//Cria uma Arvore B nova em arquivo
//Pré-condição: arquivo aberto para leitura/escrita
//Pós-condição: arquivo é inicializado com uma Arvore B noEhVazio
void criaArvoreVazia(FILE* arq);

//Lê o cabeçalho da Arvore B e retorna este
//Pré-condição: arquivo aberto para leitura/escrita
//Pós-condição: retorna o cabeçalho lido
//Ter que liberar a memória após usar o cab
cabecalhoArvoreB* leCabecalhoArvoreB(FILE * arq);

//Escreve noArvoreB arquivo o cabeçalho contendo as informações da Arvore B
//Pré-condição: arquivo deve estar aberto e ser um arquivo de Arvore B
//Pós-condilção: cabeçalho escrito noArvoreB arquivo
void escreveCabecalhoArvore(FILE* arq, cabecalhoArvoreB* cab);

//Busca o nó no arquivo de Árvore B, retornando umna chave vazia se não encontrá-lo
//Se encontrar, utilizar as posições para continuar
//Lembrar de liberar memória do nó retornado após utilização.
//Pré-condição: arquivo deve estar aberto e ser um arquivo de Arvore B
//Pós-condilção: retorna o nó que estiver o info
noArvoreB* buscaArvoreB(FILE* arq, noArvoreB* raiz, int info, int* posCha, int* posArqDad);

//Busca um profissional no arquivo de dados pelo arquivo de indices
// Pré condição: Arquivos criados
// Pós condição: apresenta as indormações do usuário buscado.
void consultarProfissionalAux(FILE *arqInd, FILE* arqDad, noArvoreB* no, int indCha);

// Imprime todas as informações dos usuários na chave
// Pré condição: arquivos criados
// Pós condição: chama o consultarProfissionalAux para apresenta as indormações do usuário buscado.
void imprimirProfissionaisNo(FILE* arqInd, FILE* arqDad, noArvoreB* noRaiz);

// Função recursiva que lista todos os profissionais no nó a partir do indice de chave indCha
// Pré condição: arquivos criados
// Pós condição: chama o consultarProfissionalAux para apresenta as indormações dos profissionais.
void listarProfissionaisAux(FILE* arqInd, FILE* arqDad, noArvoreB* noPai, int indCha);

// Imprime os nós da chave
// Pré condição: nó valido
// Pós condição: Imprime os nós da chave
void imprimirCodigosNivelAux(noArvoreB *no);

// chama o imprimirCodigosNivelAux pra imprimir os códigos por nível
// Pré condição: nó valido
// Pós condição:chama o imprimirCodigosNivelAux pra imprimir os códigos  por nível
void imprimirCodigosNivel(FILE* arqInd,noArvoreB* no,int niv);

//void retira(FILE* arq, TipoItem x);

#endif //FACULDADE_ARVOREBARQ_H
