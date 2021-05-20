/*
 - Inserir: insere as informações de um produto no cadastro:
    código do produto: representado por um número inteiro
    nome: cadeia de caracteres (50 no máximo)
    quantidade em estoque: número inteiro
    preço unitário: número real com 2 casas decimais
    localização: string contendo a descrição do local em que o produto se encontra armazenado (100 caracteres no máximo)
    Todas as informaçõs para o operação de inserção são obrigatórias.
 - Remover: dado o código de um produto, remove-o do cadastro
 - Alterar Estoque: altera a quantidade em estoque
 - Alterar Preço: altera o preço unitário
 - Alterar Localização: altera a localização do produto
 - Carregar Arquivo texto: faz a carga de um arquivo texto, cujo caminho é informado pelo usuário, contendo operações e respectivas informações a serem aplicadas ao cadastro
 - Informações do produto: a partir do código de um produto específico, imprime suas informações
 - Listar produtos: lista as informações dos produtos do cadastro por ordem crescente de código
 - Imprimir árvore: imprime a árvore binária por níveis (apenas os códigos dos produtos)
 - Imprimir posições livres: imprime a lista de posições livres do arquivo binário


I;20;parafuso 3mm;500;2.00;prateleira 5A
%c%*c%[^;]d%*c%[^;]s%*c%[^;]d%*c%[^;]f%*c%[^;]s

*/
#include <stdio.h>
#include <string.h>

struct no
{
  int cod;
  struct no * esq;
  struct no * dir;
};

typedef struct no* arvore;

int vazio (arvore r) {
return (r == NULL);
}

int main()
{
  char ope, nom[50], loc[100], linha[200];
  int cod, qua;
  float pre;

  scanf("%c%*c", &ope);

  if (ope == 'I') {
    scanf("%d%*c%[^;]%*c%d%*c%f%*c%[^\n]", &cod, &nom, &qua, &pre, &loc);
  }
  printf("%c;%d;%s;%d;%.2f;%s", ope, cod, nom, qua, pre, loc);
  return 0;
}
