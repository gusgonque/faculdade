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
%c%*c
%d%*c%[^;]%*c%d%*c%f%*c%[^\n]


*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct no
{
  int cod;
  int qua;
  float pre;
  char nom[50], loc[100];

  struct no * esq;
  struct no * dir;
};
typedef struct no* arvPro;

void criar_arvore (arvPro *r)
{
    *r = NULL;
}

int vazia (arvPro r)
{
  return (r == NULL);
}

arvPro busca_arvore_binaria (arvPro r, int cod)
{
  if(vazia(r))
    return NULL;
  if(r->cod > cod)
    return busca_arvore_binaria(r->esq, cod);
  if(r->cod < cod)
    return busca_arvore_binaria(r->dir, cod);
  return r;
}

// Pr´e-condi¸c~ao: ´arvore n~ao vazia
int maximo(arvPro r)
{
  while(r->dir != NULL)
    r = r->dir;
  return r->cod;
}

// Pr´e-condi¸c~ao: ´arvore n~ao vazia
int minimo(arvPro r)
{
  while(r->esq != NULL)
    r = r->esq;
  return r->cod;
}

arvPro remove_arvore_binaria (arvPro r, int x)
{
  if(vazia(r))
    return NULL;
    if(x < r->cod)
      r->esq = remove_arvore_binaria(r->esq, x);
    else if(x > r->cod)
      r->dir = remove_arvore_binaria(r->dir, x);
    else // x == r->cod
    if(r->esq == NULL && r->dir == NULL)
    { // ´e n´o folha
      free(r);
      r = NULL;
    }
    else if(r->esq == NULL)
    { // s´o tem filho da direita
      r->cod = minimo(r->dir);
      r->dir = remove_arvore_binaria(r->dir,r->cod);
    }
    else
    { // tem 2 filhos ou s´o o da esquerda
      r->cod = maximo(r->esq);
      r->esq = remove_arvore_binaria(r->esq,r->cod);
    }
    return r;
}

arvPro insere_arvore_binaria(arvPro r, int x)
{

  if(vazia(r))
  {
    r = (struct no*) malloc(sizeof(struct no));
    r->cod = x;
    r->esq = NULL;
    r->dir = NULL;
  }
  else
  if(x < r->cod)
    r->esq = insere_arvore_binaria(r->esq, x);
  else // x >= r->cod
    r->dir = insere_arvore_binaria(r->dir, x);
  return r;
}

/*
int encontrar_elemento (int element)
{
    // Procura o elemento na árvore
    // O(log n)


    Node* temp = root;
    int parar=0;

    if(root==NULL){
      return false;
    }else if(temp->left== NULL && temp->right==NULL){
      if(temp->value == element){
        return true;
      }else{
        return false;
      }
    }else if(temp->value==element){
      return true;
    }else{
    while(parar==0){
      if(temp->value < element){
        if(temp->left == NULL){
          parar++;
          if (temp->value==element){
            break;
            return true;
          }else{
          return false;
          }
        }else{
          temp=temp->right;
          if (temp->value== element){
            return true;
            break;
          }
        }

      }else if(temp->value > element){
        if(temp->right== NULL){
          parar++;
          if (temp->value==element){
            return true;
            break;
          }else{
          return false;
          }
        }else{
          temp=temp->left;
          if (temp->value== element){
            return true;
            break;
          }
        }
      }
    }
  }
}
*/

int Inserir_Produto (arvPro prod)
{
  int x;
  arvPro Teste;
  criar_arvore(&Teste);

  printf(" Para inserir um novo produto, digite o numero do codigo dele.\n - ");
  scanf("%d", &x);

  Teste = busca_arvore_binaria (prod,x);

  printf("!vazia = %d\n", !vazia(Teste));

  if (!vazia(Teste))
    while ( Teste->cod == prod->cod )
    {
      printf(" Codigo ja utilizado por outro produto ou invalido, digite -1 para retornar ao Menu, ou digite outro codigo.\n - ");
      scanf("%d", &x);
      if (x == -1)
        return 1;
      Teste = busca_arvore_binaria (prod,x);
    }

  prod = insere_arvore_binaria(prod, x);
  printf(" prod->cod = %d\n", prod->cod);

  /*
  prod->qua;
  prod->pre;
  prod->nom;
  prod->loc;
  */

  return 1;
}

void Remover_Produto();
void Alterar_Produto();
void Carregar_Arquivo();
void Info_Produto();
void Listar_Produtos();
void Imprimir();

int Menu (arvPro prod)
{
  int x;

  printf("\n Menu Principal\n\n Digite a opcao desejada:\n");
  printf(" 1 - Inserir um produto.\n");
  printf(" 2 - Remover um produto.\n");
  printf(" 3 - Menu de alteracao de produtos.\n");
  printf(" 4 - Carregar arquivo texto.\n");
  printf(" 5 - Informacoes do produto.\n");
  printf(" 6 - Listar produtos.\n");
  printf(" 7 - Menu de impressao.\n");
  printf(" 8 - Encerrar programa.\n");
  printf(" - ");
  scanf("%d",&x);

  while (x>8 || x<1)
  {
    printf("Comando invalido. Digite novamente.\n -");
    scanf("%d",&x);
  }

  switch (x)
  {
    case 1:
    {
      return Inserir_Produto(prod);
    }
    case 2:
    {
      Remover_Produto();
      return 1;
    }
    case 3:
    {
      Alterar_Produto();
      return 1;
    }
    case 4:
    {
      Carregar_Arquivo();
      return 1;
    }
    case 5:
    {
      Info_Produto();
      return 1;
    }
    case 6:
    {
      Listar_Produtos();
      return 1;
    }
    case 7:
    {
      Imprimir();
      return 1;
    }
    case 8:
    {
      free(prod);
      return 0;
    }
  }
}

int main()
{
  arvPro produtos;
  char ;
  criar_arvore (&produtos);

  while (Menu(produtos));

  return 0;
}
