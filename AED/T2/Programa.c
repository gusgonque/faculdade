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
/*
-1 = arq n existe
0 = cod livre
1 = cod preenchido
cod = cod disponivel
*/
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

void Insere_Novo_Produto (int cod,int qua,float pre,char nom[],char loc[])
{
  FILE *arq;
  int x, i;
  char s[200];

  arq = fopen("dados", "rb+");
  while ( feof (arq) == 0 )
    fscanf( arq , "%*[^\n]\n");
  fprintf(arq, "%d;%s;%d;%.2f;%s\n",cod, nom,qua,pre,loc);

  fclose(arq);
  printf("\n Produto adicionado com sucesso. Retornando ao menu principal.\n");
}

void Insere_Produto_Livre (int cod,int qua,float pre,char nom[],char loc[])
{
  int x, i;
  char s[200];
  FILE *arq, *arq2;
  arq = fopen("dados", "rb");
  arq2 = fopen("dados2", "wb");

  while ( x !=cod )
  {
    fscanf( arq , "%d" , &x );
    fprintf( arq2 , "%d" , x );
    if (x!=cod)
    {
      fscanf( arq , "%[^\n]\n", &s);
      fprintf(arq2,"%s\n", s);
    }
  }

  fprintf(arq2, ";%s;%d;%.2f;%s", nom,qua,pre,loc);

  while ( feof (arq) == 0 )
  {
    fscanf(arq, "%[^\n]\n", &s);
    fprintf(arq2,"%s\n", s);
  }

  fclose(arq);
  fclose(arq2);
  remove("dados");
  rename("dados2","dados");
  printf("\n Produto adicionado com sucesso. Retornando ao menu principal.\n");
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
  else
    Insere_Novo_Produto (cod, qua, pre, nom, loc);

  return 1;
}

int menor_cod()
{
  int x, men, i;
  FILE *arq;

  arq = fopen("dados", "rb");
  fscanf (arq,"%d", &men);
  fscanf (arq,"%*[^\n]\n");
  for ( i = 0; i < numero_prod()-1; i++)
  {
    fscanf (arq,"%d", &x);
    fscanf (arq,"%*[^\n]\n");
    if (x<men)
      men = x;
  }
  //printf("men = %d\n", men);
  return men;
}

int maior_cod()
{
  int x, mai, i;
  FILE *arq;

  arq = fopen("dados", "rb");
  fscanf (arq,"%d", &mai);
  fscanf (arq,"%*[^\n]\n");
  for ( i = 0; i < numero_prod()-1; i++)
  {
    fscanf (arq,"%d", &x);
    fscanf (arq,"%*[^\n]\n");
    if (x>mai)
      mai = x;
  }
  //printf("mai = %d\n", mai);
  return mai;
}

void Listar_Produtos()
{
  int n, i, cod, qua, x, j;
  float pre;
  char c, nom[50], loc[100];
  FILE *arq;

  printf(" Lista de todos os produtos registrados:\n");

  n = numero_prod();
  arq = fopen("dados", "rb");
  for ( i = 0, j = cod = menor_cod() ; i < n ; i++ )
  {
    for ( cod = j ; j < maior_cod() ; cod++ )
      if ( busca_cod(cod) == 1 )
      {
        j = cod;
        rewind(arq);

        while ( x != cod)
        {
          fscanf( arq , "%d" , &x );
          if ( x != cod )
            fscanf( arq , "%*[^\n]\n");
        }
        printf(" - Codigo %d:\n", cod);

        fscanf( arq , ";%[^;]", &nom);
        printf(" Nome: %s\n", nom);

        fscanf( arq , ";%d", &qua);
        printf(" Quantidade: %d\n", qua);

        fscanf( arq , ";%f", &pre);
        printf(" Preco: %.2f\n", pre);

        fscanf( arq , ";%[^\n]", &loc);
        printf(" Localizacao: %s\n\n", loc);
      }
  }
  fclose(arq);
}

void Remover_Produto()
{
  int cod, x;
  char s[200];
  FILE *arq, *arq2;

  Listar_Produtos();
  printf(" Digite o codigo do produto a ser removido.\n - ");
  scanf("%d", &cod);

  arq = fopen("dados", "rb");
  arq2 = fopen("dados2", "wb");

  while ( x != cod)
  {

    fscanf( arq , "%d" , &x );
    fprintf( arq2, "%d" , x );
    if ( x != cod )
    {
      fscanf( arq , "%[^\n]\n" , &s );
      fprintf( arq2 , "%s\n" , s );
    }
  }
  fscanf(arq, "%*[^\n]\n");
  fprintf(arq2, "\n");
  while ( feof (arq) == 0 )
  {
    fscanf(arq, "%[^\n]\n", &s);
    fprintf(arq2,"%s\n", s);
  }

  fclose(arq);
  fclose(arq2);
  remove("dados");
  rename("dados2","dados");
  printf("\n Produto removido com sucesso. Retornando ao menu principal.\n");
}

//void Alterar_Produto();
//void Carregar_Arquivo();
//void Info_Produto();
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
      Remover_Produto();
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
      Listar_Produtos();
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
