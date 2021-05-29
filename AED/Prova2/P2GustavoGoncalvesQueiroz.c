#include <stdio.h>
#include <stdlib.h>

//estrutura de n´o para ´arvore bin´aria
struct no
{
  int info;
  struct no * esq;
  struct no * dir;
};

typedef struct no* arvore;

// retorna 1 se a ´arvore ´e vazia, 0 caso contr´ario
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

int busca_arvb_elemento (arvore r, int info)
{
  if(vazia(r))
    return -1;
  if(r->info > info)
    return busca_arvb_elemento (r->esq,info);
  if(r->info < info)
    return busca_arvb_elemento (r->dir, info);
  return info;
}

void imprime_entre(arvore r, int a, int b)
{
  int i;
  for ( i = a+1; i<b ; i++ )
    if (busca_arvb_elemento (r,i) != -1)
      printf("%d ", busca_arvb_elemento (r,i));
  printf("\n");
}

int minimo(arvore r)
{
  while(r->esq != NULL)
    r = r->esq;
  return r->info;
}

int maximo(arvore r)
{
  while(r->dir != NULL)
    r = r->dir;
  return r->info;
}

int diferenca_ref(arvore r, int k)
{
  int i, men, mai;
  for ( i = minimo(r), men = 0 ; i<k ; i++)
    men += (busca_arvb_elemento (r,i) == -1 ? 0 : busca_arvb_elemento (r,i));
  for ( i = k+1, mai = 0 ; i <= maximo(r) ; i++)
    mai += (busca_arvb_elemento (r,i) == -1 ? 0 : busca_arvb_elemento (r,i));
  printf("Diferenca = %d\n", mai - men);
}

int calc_AVL (arvore r)
{
  if (r == NULL)
    return 0;
  int s;
  s = 0;
  if (r->esq != NULL)
    s += 1 + calc_AVL(r->esq);
  if (r->dir != NULL)
    s += -1 + calc_AVL(r->dir);
  return s;
}

int eh_AVL(arvore r)
{
  int s;
  s = calc_AVL(r);
  return (s<=1 && s>=-1);
}

int main()
{
  arvore arv;
  arv = NULL;
  int x, a, b, k;

  printf("Insira os elementos da arvore binaria que sera usada em todos os exercicios. Digite -1 para finalizar a arvore.\n");

  scanf("%d", &x);
  while (x != -1)
  {
    arv = insere_arvore_binaria(arv,x);
    scanf("%d", &x);
  }
  printf("Digite a e b para a questao 1.\n");
  scanf("%d %d", &a, &b);
  imprime_entre (arv,a,b);

  printf("Digite k para a questao 2.\n");
  scanf("%d", &k);
  diferenca_ref (arv,k);

  printf("Para a questao 3, o resultado eh %d\n", eh_AVL(arv));

  return 0;
}
