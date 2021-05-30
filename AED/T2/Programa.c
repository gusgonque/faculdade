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

parafuso 3mm;500;2.00;prateleira 5A
%s;%d;%f;%s\n

*/

#include <stdio.h>

int numero_prod()
{
  FILE *arq;
  int i;
  arq = fopen("dados", "rb");

  for ( i = 0 ;  feof (arq) == 0 ; i++ )
    fscanf(arq,"%*[^\n]\n");

  //printf("%d linhas nos dados\n", i);

  fclose(arq);
  return i;
}

int busca_cod (int cod)
{
  FILE *arq;
  int i, n, x;
  char s[200];
  n = numero_prod();

  arq = fopen("dados", "rb");
  if (arq == NULL)
  {
    fclose(arq);
    return -1;
  }

  for ( i = 0 ; i < n ; i++ )
  {
    fscanf( arq , "%d%[^\n]\n" , &x, &s );
    //printf(" s0 = [%c]\n", s[0]);
    if (x == cod)
    {
      if (s[0] != ';')
      {
        fclose(arq);
        //printf("cod existe, mas n preenchido\n");
        return 0;
      }
      else
      {
        fclose(arq);
        //printf("cod existe, e preenchido\n");
        return 1;
      }
    }
  }

  fclose (arq);
  return cod;
}

//int Insere_Novo_Produto (int cod,int qua,float pre,char nom[],char loc[]);


void Insere_Produto_Livre (int cod,int qua,float pre,char nom[],char loc[])
{
  FILE *arq;
  int x;
  arq = fopen("dados", "ab+");

  while ( x !=cod )
  {
    fscanf( arq , "%d" , &x );
    printf(".\n");
    if (x!=cod)
      fscanf( arq , "%*[^\n]\n");
  }
  fprintf(arq, "%s;%d;%.2f;%s\n", nom,qua,pre,loc);
  printf("%s;%d;%f;%s\n", nom,qua,pre,loc);
  fclose(arq);
}

int Inserir_Produto ()
{
  int x,cod;

  printf(" Para inserir um novo produto, digite o numero do codigo dele.\n - ");
  scanf("%d", &cod);
  x = busca_cod(cod);

  printf("busca = %d\n", x);

  while ( x == 1 )
  {
    printf(" Codigo ja utilizado por outro produto ou invalido, digite -1 para retornar ao Menu, ou digite outro codigo.\n - ");
    scanf("%d", &cod);
    if (cod == -1)
      return 1;
    x = busca_cod(cod);
  }

  int qua;
  float pre;
  char nom[50], loc[100];

  printf(" Digite o nome do produto.\n - ");
  setbuf(stdin, NULL);
  scanf("%[^\n]", &nom);

  printf(" Digite a quantidade em estoque no momento do produto '%s'.\n - ", nom);
  scanf("%d", &qua);

  printf(" Digite o preco unitario do produto '%s'.\n - ", nom);
  scanf("%f", &pre);

  printf(" Digite a descricao do local em que o produto '%s' se encontra armazenado.\n - ", nom);
  setbuf(stdin, NULL);
  scanf("%[^\n]", &loc);

  if (x==0)
    Insere_Produto_Livre (cod, qua, pre, nom, loc);
//  Insere_Novo_Produto (cod, qua, pre, nom, loc);

  /*
  prod->qua;
  prod->pre;
  prod->nom;
  prod->loc;
  */

  return 1;
}

//void Remover_Produto();
//void Alterar_Produto();
//void Carregar_Arquivo();
//void Info_Produto();
//void Listar_Produtos();
//void Imprimir();

int Menu ()
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
      return Inserir_Produto();
    }
    case 2:
    {
      //Remover_Produto();
      return 1;
    }
    case 3:
    {
      //Alterar_Produto();
      return 1;
    }
    case 4:
    {
      //Carregar_Arquivo();
      return 1;
    }
    case 5:
    {
      //Info_Produto();
      return 1;
    }
    case 6:
    {
      //Listar_Produtos();
      return 1;
    }
    case 7:
    {
      //Imprimir();
      return 1;
    }
    case 8:
    {
      return 0;
    }
  }
}

int main()
{

  while (Menu());

  return 0;
}
