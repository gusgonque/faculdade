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
#include <stdlib.h>

struct no
{
  int info;
  struct no * esq;
  struct no * dir;
};

typedef struct no* arvore;

int vazia (arvore r)
{
  return (r == NULL);
}

arvore insere_arvore_binaria(arvore r, int x)
{
  if(vazia(r))
  {
    r = (struct no*) malloc(sizeof(struct no));
    r->info = x;
    r->esq = NULL;
    r->dir = NULL;
  }
  else
    if(x < r->info)
      r->esq = insere_arvore_binaria(r->esq, x);
  else // x >= r->info
    r->dir = insere_arvore_binaria(r->dir, x);
  return r;
}

void pre_ordem(arvore r)
{
  if(!vazia(r)) {
    printf("%d ", r->info);
    pre_ordem(r->esq);
    pre_ordem(r->dir);
  }
}

int numero_prod()
{
  FILE *arq;
  int i;
  arq = fopen("dados", "rb");

  for ( i = 0; feof (arq) == 0 ; i++)
  fscanf(arq,"%*[^\n]\n");

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
  char c;
  n = numero_prod();

  arq = fopen("dados", "rb");
  if (arq == NULL)
  {
    fclose(arq);
    return -1;
  }

  for ( i = 0 ; i < n ; i++ )
  {

    fscanf( arq , "%d%c" , &x, &c );
    if (x == cod)
    {
      if (c != ';')
      {
        fclose(arq);
        return 0;
      }
      else
      {
        fclose(arq);
        return 1;
      }
    }
    else
      while (c!='\n')
        fscanf(arq,"%c",&c);
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
  printf("\n Produto adicionado com sucesso. Retornando ao menu principal.\n");

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
  fclose(arq);
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
  fclose(arq);
  return mai;
}

int Listar_Produtos()
{
  int n, i, cod, qua, x, j;
  float pre;
  char nom[50], loc[100];
  FILE *arq;

  printf(" Lista de todos os produtos registrados:\n");

  n = numero_prod();
  for ( i = 0 , j = menor_cod() ; j < maior_cod() ; j++ )
    if (busca_cod(j) == 1)
      i++;
  if (i == 0)
  {
    printf(" Nenhum produto registrado. Retornando ao menu principal.\n");
    return 1;
  }

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
  return 0;
}

void Remover_Produto(int cod)
{
  int x;
  char c, s[200];
  FILE *arq, *arq2;

  arq = fopen("dados", "rb");
  arq2 = fopen("dados2", "wb");

  while ( x != cod)
  {
    fscanf( arq , "%d" , &x );
    fprintf( arq2, "%d" , x );
    if ( x != cod )
    {
      fscanf(arq,"%c", &c);
      if (c == ';')
      {
        fscanf( arq , "%[^\n]\n" , &s );
        fprintf( arq2 , ";%s\n" , s );
      }
      else
        fprintf( arq2 , "\n");
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
}

void Alterar_Estoque(int cod, int q)
{
  int x;
  char c, s[200];
  FILE *arq, *arq2;
  arq = fopen("dados", "rb");
  arq2 = fopen("dados2", "wb");

  while ( x != cod )
  {
    fscanf( arq , "%d" , &x );
    fprintf( arq2, "%d" , x );
    if ( x != cod )
    {
      fscanf(arq,"%c", &c);
      if (c == ';')
      {
        fscanf( arq , "%[^\n]\n" , &s );
        fprintf( arq2 , ";%s\n" , s );
      }
      else
        fprintf( arq2 , "\n");
    }
  }

  fscanf(arq, ";%[^;];",&s);
  fprintf(arq2,";%s;",s);

  fscanf(arq, "%*d;");
  fprintf(arq2,"%d;", q);
  while ( feof (arq) == 0 )
  {
    fscanf(arq, "%[^\n]\n", &s);
    fprintf(arq2,"%s\n", s);
  }

  fclose(arq);
  fclose(arq2);
  remove("dados");
  rename("dados2","dados");
}

void Alterar_Preco(int cod, float p)
{
  int x;
  char c, s[200];
  FILE *arq, *arq2;
  arq = fopen("dados", "rb");
  arq2 = fopen("dados2", "wb");

  while ( x != cod)
  {
    fscanf( arq , "%d" , &x );
    fprintf( arq2, "%d" , x );
    if ( x != cod )
    {
      fscanf(arq,"%c", &c);
      if (c == ';')
      {
        fscanf( arq , "%[^\n]\n" , &s );
        fprintf( arq2 , ";%s\n" , s );
      }
      else
        fprintf( arq2 , "\n");
    }
  }

  fscanf(arq, ";%[^;];",&s);
  fprintf(arq2,";%s",s);
  fscanf(arq, "%[^;];",&s);
  fprintf(arq2,";%s;",s);


  fscanf(arq, "%*f;");
  fprintf(arq2,"%.2f;", p);
  while ( feof (arq) == 0 )
  {
    fscanf(arq, "%[^\n]\n", &s);
    fprintf(arq2,"%s\n", s);
  }

  fclose(arq);
  fclose(arq2);
  remove("dados");
  rename("dados2","dados");
}

void Alterar_Loc(int cod, char loc[])
{
  int x;
  char c, s[200];
  FILE *arq, *arq2;
  arq = fopen("dados", "rb");
  arq2 = fopen("dados2", "wb");

  while ( x != cod)
  {
    fscanf( arq , "%d" , &x );
    fprintf( arq2, "%d" , x );
    if ( x != cod )
    {
      fscanf(arq,"%c", &c);
      if (c == ';')
      {
        fscanf( arq , "%[^\n]\n" , &s );
        fprintf( arq2 , ";%s\n" , s );
      }
      else
        fprintf( arq2 , "\n");
    }
  }

  fscanf(arq, ";%[^;];",&s);
  fprintf(arq2,";%s",s);
  fscanf(arq, "%[^;];",&s);
  fprintf(arq2,";%s",s);
  fscanf(arq, "%[^;];",&s);
  fprintf(arq2,";%s;",s);


  fscanf(arq, "%*[^\n]\n");
  fprintf(arq2,"%s\n", loc);

  while ( feof (arq) == 0 )
  {
    fscanf(arq, "%[^\n]\n", &s);
    fprintf(arq2,"%s\n", s);
  }

  fclose(arq);
  fclose(arq2);
  remove("dados");
  rename("dados2","dados");
}

void Alterar_Produto()
{
  int cod, q,x;
  float p;
  char loc[100];

  Listar_Produtos();
  printf(" Digite o codigo do produto a ser alterado.\n - ");
  scanf("%d", &cod);
  while ( busca_cod(cod) != 1) {
    printf(" Codigo invalido. Digite novamente.\n - ");
    scanf("%d", &cod);
  }

  printf(" Digite a opcao desejada:\n");
  printf(" 1 - Alterar estoque.\n");
  printf(" 2 - Alterar preco.\n");
  printf(" 3 - Alterar localizacao.\n - ");
  scanf("%d",&x);

  while (x>3 || x<1)
  {
    printf("Comando invalido. Digite novamente.\n -");
    scanf("%d",&x);
  }

  switch (x)
  {
    case 1:
    {
      printf(" Digite a nova quantidade do produto no estoque.\n - ");
      scanf("%d", &q);
      Alterar_Estoque(cod,q);
      break;
    }
    case 2:
    {
      printf(" Digite o novo preco do produto selecionado.\n - ");
      scanf("%f", &p);
      Alterar_Preco(cod, p);
      break;
    }
    case 3:
    {
      printf("Digite a nova localizacao do produto selecionado.\n - ");
      setbuf(stdin, NULL);
      scanf("%[^\n]", loc);
      Alterar_Loc(cod, loc);
      break;
    }
  }
  printf(" Produto alterado com sucesso. Retornando ao menu principal\n");
}

int Carregar_Arquivo()
{
  int cod, qua;
  char c,s[100], ope, nom[50],loc[100];
  float pre;
  FILE *arq3;

  printf(" Digite o caminho do arquivo a ser carregado a partir do arquivo do codigo fonte.\n - ");
  setbuf(stdin, NULL);
  scanf("%[^\n]", &s);

  arq3 = fopen(s, "rb");

  if (arq3 == NULL)
  {
    printf(" Arquivo nao encontrado. Retornando ao menu principal\n");
    return 0;
  }

  while ( feof (arq3) == 0 )
  {
    fscanf(arq3,"%c;",&ope);
    //printf("ope = %c\n", ope);
    if (ope == 'I')
    {
      fscanf(arq3,"%d;", &cod);
      //printf("cod = %d,buscacod = %d\n", cod, busca_cod(cod));
      switch (busca_cod(cod)) {
        case -1:
        {
          FILE *arq2;
          arq2 = fopen("dados","wb");
          fclose(arq2);

          fscanf(arq3,"%[^;];%d;%f;%[^\n]\n",&nom,&qua,&pre,&loc);
          Insere_Novo_Produto(cod,qua,pre,nom,loc);
          break;
        }
        case 0:
        {
          fscanf(arq3,"%[^;];%d;%f;%[^\n]\n",&nom,&qua,&pre,&loc);
          Insere_Produto_Livre(cod,qua,pre,nom,loc);
          break;
        }
        case 1:
        {
          fscanf(arq3,"%*[^\n]\n");
          break;
        }
        default:
        {
          fscanf(arq3,"%[^;];%d;%f;%[^\n]\n",&nom,&qua,&pre,&loc);
          //printf("%s;%d;%f;%s\n", nom,qua,pre,loc);
          Insere_Novo_Produto(cod,qua,pre,nom,loc);
          break;
        }
      }
    }
    else
      if (ope == 'R')
      {
        fscanf(arq3,"%d\n", &cod);
        //printf("cod = %d\n", cod);
        if (busca_cod(cod) == 1)
          Remover_Produto(cod);
      }
      else
        if (ope == 'A')
        {
          fscanf(arq3,"%d;",&cod);
          if (busca_cod(cod) == 1)
          {
            fscanf(arq3,"%c",&c);
            if (c != ';')
            {
              fseek( arq3 , -1 , SEEK_CUR );
              fscanf( arq3,"%d;", &qua);
              //printf("qua = %d\n", qua);
              Alterar_Estoque(cod,qua);
            }
            fscanf(arq3,"%c", &c);
            if (c != ';')
            {
              fseek( arq3 , -1 , SEEK_CUR );
              fscanf(arq3,"%f;", &pre);
              //printf("pre = %f\n", pre);
              Alterar_Preco(cod,pre);
            }
            fscanf(arq3,"%c", &c);
            if (c != '\n')
            {
              fseek( arq3 , -1 , SEEK_CUR );
              fscanf(arq3,"%[^\n]\n", &loc);
              //printf("loc = %s\n", loc);
              Alterar_Loc(cod,loc);
            }
            fscanf(arq3,"%*[^\n]\n");
          }
        }
        else
          fscanf(arq3,"%*[^\n]\n");
    }
  fclose(arq3);
}

void Info_Produto(int cod)
{
  int x, qua;
  char c, nom[50],loc[100];
  float pre;
  FILE *arq;

  arq = fopen ("dados","rb");
  while ( x != cod)
  {
    fscanf( arq , "%d" , &x );
    if ( x != cod )
    {
      fscanf(arq,"%c", &c);
      if (c == ';')
        fscanf( arq , "%*[^\n]\n" );
      else
        fscanf( arq , "\n");
    }
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

  fclose(arq);
}

int Imprimir_Lista_Livre()
{
  int i,j,n,x;
  FILE *arq;
  char c;
  for ( i = 0 , j = menor_cod() ; j < maior_cod() ; j++ )
    if (busca_cod(j) == 0)
      i++;

  if (i == 0)
  {
    printf(" Nenhuma posicao livre. Retornando ao menu principal.\n");
    return 1;
  }
  n = numero_prod();
  arq = fopen("dados","rb");

  for (i=0; i<n ;  )
  {
    fscanf(arq,"%d",&x);
    if (busca_cod(x) != 0)
    {
      fscanf(arq,"%c", &c);
      if (c == ';')
        fscanf( arq , "%*[^\n]\n" );
      else
        fscanf( arq , "\n" );
      i++;
    }
    else
      printf(" %d esta livre.\n", x);
  }
  fclose(arq);
}

int Imprimir_Arvore()
{

  int i,j,n,x;
  FILE *arq;
  char c;
  arvore arv;
  arv = NULL;

  for ( i = 0 , j = menor_cod() ; j < maior_cod() ; j++ )
    if (busca_cod(j) != -1 && busca_cod(j) != j)
      i++;

  if (i == 0)
  {
    printf(" Nenhum codigo registrado. Retornando ao menu principal.\n");
    return 1;
  }

  n = numero_prod();
  arq = fopen("dados","rb");

  for (i=0; i<n ;  )
  {
    fscanf(arq,"%d",&x);
    arv = insere_arvore_binaria(arv, x);
    if (busca_cod(j) != -1 && busca_cod(j) != j)
    {
      fscanf(arq,"%c", &c);
      if (c == ';')
        fscanf( arq , "%*[^\n]\n" );
      else
        fscanf( arq , "\n" );
      i++;
    }
  }
  fclose(arq);
  pre_ordem(arv);
}

void Imprimir()
{
  int x;
  printf(" Menu de impressao\n\n Digite a opcao desejada:\n");
  printf(" 1 - Imprimir arvore.\n");
  printf(" 2 - Imprimir lista de posicoes livres.\n");
  printf(" 3 - Retornar ao menu anterior.\n - ");
  scanf("%d",&x);

  while (x>3 || x<1)
  {
    printf(" Comando invalido. Digite novamente.\n -");
    scanf("%d",&x);
  }

  switch (x)
  {
    case 1:
    {
      Imprimir_Arvore();
      break;
    }
    case 2:
    {
      Imprimir_Lista_Livre();
      break;
    }
    case 3:
    {
      break;
    }
  }
}

int Menu ()
{
  int x, cod;

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
    printf(" Comando invalido. Digite novamente.\n -");
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
      if (Listar_Produtos())
        return 1;
      else
      {
        printf(" Digite o codigo do produto a ser removido.\n - ");
        scanf("%d", &cod);
        while ( busca_cod(cod) != 1) {
          printf(" Codigo invalido. Digite novamente.\n - ");
          scanf("%d", &cod);
        }
        Remover_Produto(cod);

        printf("\n Produto removido com sucesso. Retornando ao menu principal.\n");
        return 1;
      }
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
      if (Listar_Produtos())
        return 1;
      printf(" Digite o codigo do produto a ser apresentado.\n - ");
      scanf("%d", &cod);

      while (busca_cod (cod) != 1)
      {
        printf(" Codigo nao registrado, digite novamente.\n - ");
        scanf("%d", &cod);
      }
      Info_Produto(cod);
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
      return 0;
    }
  }
}

int main()
{
  while (Menu());
  return 0;
}
