#ifndef FACULDADE_TRAB2_H_INCLUDED
#define FACULDADE_TRAB2_H_INCLUDED

#include "arvoreBArq.h"

#define CHARMAX 100
#define LER_ESPACO setbuf(stdin, NULL) // Mecessário para usar o gets


typedef struct{
    int cod;
    char nom[50];
    char cpf[12];
    char numReg[30];
    char end[CHARMAX];
    char tel[15];
} profissional;

// Apresenta a interface principal
// Pré condição: nenhuma
// Pós condição: faz alguma das opções
void interfacePrincipal();

// Apresenta a interface de registro do usuário
// Pré condição: x válido
// Pós condição: faz alguma das opções
int interfaceRegistro();

//Busca o codigo na arvore B, se ele existe, retorna o endereco daquela chave naquele nó do arquivo. Qualquer outro caso retorna -1.
// Pré condição: arquivo criado.
// Pós condição: retorna o endereco daquela chave naquele nó do arquivo. Qualquer outro caso retorna -1.
int buscaCodigo(int cod);

// Faz a interface para o usuário inserir um novo profissional
// Pré condição: nenhuma
// Pós condição: aciona a função inserirProfissional
void inserirProfissionalManual();

// Insere o profisisonal(chave), na raíz do arq de Indices.
// Pré condição: nenhuma
// Pós condição: Insere o profisisonal(chave), na raíz do arq de Indices.
void inserirProfissional(profissional proNov);

// Faz a interface para o usuário alterar um profissional
// Pré condição: arquivo criado
// Pós condição: aciona a função alterarProfissional
void alterarProfissionalManual();

// Altera o profissional
// Pré condição: arquivo criado
// Pós condição: Altera o profissional
void alterarProfissional(profissional pro, int booEnd, int booTel);

// Faz a interface para o usuário remover um profissional
// Pré condição: Arquivo criado
// Pós condição: aciona a função removerProfissional
void removerProfissionalManual();

// Remove um profissional
// Pré condição: Arquivo criado
// Pós condição: Remove o profissional
void removerProfissional(profissional pro);

// Carrega o arquivo de funções a serem tratadas pelo programa
// Pré condição: Arquivo criado
// Pós condição: arquivo carregado e funções tratadas
void carregarArquivo();

//Busca um profissional no arquivo de dados pelo arquivo de indices
// Pré condição: Arquivos criados
// Pós condição: apresenta as indormações do usuário buscado.
void consultarProfissional();

// Chama a função listarProfissionaisAux
// Pré condição: arquivos criados
// Pós condição: Chama a função listarProfissionaisAux para apresenta as indormações dos profissionais.
void listarProfissionais();

// Imprime os nós por nível
// Pré condição: arquivos criados
// Pós condição: Imprime os nós por nível
void imprimirArvoreB();

// Imprime os nós livres da lista de Dados
// Pré condição: arquivos criados
// Pós condição: Imprime os nós
void imprimirPosicoesLivresDados(FILE* arqDad);

// Imprime os nós livres da árvore de Índices
// Pré condição: arquivos criados
// Pós condição: Imprime os nós
void imprimirPosicoesLivresIndices(FILE* arqInd);

#endif //FACULDADE_TRAB2_H_INCLUDED
