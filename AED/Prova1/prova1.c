#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct no //estrutura de n´o para lista encadeada
{
  int info;
  struct no * prox;
}
Lista;

// retorna 1 se a lista ´e vazia, 0 caso contr´ario
int vazia(Lista * l)
{
  return (l == NULL);
}

// insere um elemento na cabe¸ca
Lista* inserir(Lista* l, int info)
{
  Lista* aux = (Lista*) malloc(sizeof(Lista));
  aux->info = info;
  aux->prox = l; //encadeia com a cabe¸ca da lista
  return aux; //retorna a nova cabe¸ca

}

// inverte a lista
Lista* inverter (Lista* l)
{
  Lista* t = l; Lista* y = l;
  Lista* invertida = NULL;
  while (!vazia(y))
  {
      t = y->prox;
      y->prox = invertida;
      invertida = y;
      y = t;
  }
  return invertida;
}

// remove o elemento seguinte a info_ref l = [5; 11; 7; 3; 8] / info_ref = 5
Lista* remover_apos (Lista* l, int info_ref)
{
  Lista* y = l;
  Lista* t = l->prox;
  if ( (!vazia(y)) && (!vazia(t)) )
    if (y->info == info_ref)
    {
      free(t);
      l->prox = t->prox;
    }
    else
      l->prox = remover_apos(t,info_ref);
  return l;
}

// retorna uma lista com os elementos cujas posi¸c~oes s~ao m´ultiplas de n
Lista* filtrar(Lista* l, int n)
{
  Lista* y = l;
  if (!vazia(y))
    if (!(y%n))
    {
      free(y);
      l->prox = y->prox;
    }
    else
      l->prox = filtrar(y->prox,n);
  return l;
}

// faz a soma de 2 n´umeros inteiros positivos representados por listas
Lista* somar(Lista* l1, Lista* l2)
{
  Lista* x1 = l1, y1 = l2, xr;
  int x,y,z,i;

  for ( i = x = 0 ; !vazia(x1) ; i++ )
  {
    x = (x*10) + x1->info;
    x1 = x1->prox;
  }
  for ( i = y = 0; !vazia(y1) ; i++ )
  {
    y = (y*10) + y1->info;
    y1 = y1->prox;
  }

  for ( z=x+y ; z>0 ; z=z/10 )
    inserir(xr, z%10);

  return xr;
}

//Ex
typedef struct no
{
  Lista lista;
  struct no * prox;
}
Lista_Lista;
Lista* lista_de_somas(Lista_Lista* ll)
{
  Lista_Lista* ll1 = ll;
  Lista* l1, lr;
  int r;

  if (ll1 == NULL)
    return 0;

  while ( !(ll1 == NULL) )
  {
    for ( r = 0, l1 = ll1->lista ; !vazia(l1) ;  )
    {
      r += l1->info;
      l1 = l1->prox;
    }
    lr = inserir(lr, r);
    ll1 = ll1->prox;
  }
  inverter (lr);

  return lr;
}
