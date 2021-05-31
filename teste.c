#include <stdio.h>

#define espaco 5


typedef struct no{
   int valor;          // valor of the no
   struct no *esquerda;  // esquerda no
   struct no *direita; // direita no
};

typedef struct no* arvore;

void desenha_arvore_horiz(arvore r, int depth, char *path, int direita)
{
    if (r== NULL)
        return;

    depth++;

    // start with direita no
    desenha_arvore_horiz(r->direita, depth, path, 1);

    // set | draw map
    path[depth-2] = 0;

    if(direita)
        path[depth-2] = 1;

    if(r->esquerda)
        path[depth-1] = 1;

    // print root after spacing
    printf("\n");

    for(int i=0; i<depth-1; i++)
    {
      if(i == depth-2)
          printf("+");
      else if(path[i])
          printf("|");
      else
          printf(" ");

      for(int j=1; j<espaco; j++)
      if(i < depth-2)
          printf(" ");
      else
          printf("-");
    }

    printf("%d\n", r->valor);

    // vertical espacors below
    for(int i=0; i<depth; i++)
    {
      if(path[i])
          printf("|");
      else
          printf(" ");

      for(int j=1; j<espaco; j++)
          printf(" ");
    }

    // go to esquerda no
    desenha_arvore_horiz(r->esquerda, depth, path, 0);
}

//primary fuction
void draw_arvore_hor(arvore r)
{
    // should check if we don't exceed this somehow..
    char path[255] = {};

    //initial depth is 0
    desenha_arvore_horiz(r, 0, path, 0);
}



arvore n1, n2, n3, n4, n5, n6, n7;

int main()
{
  n1.valor = 1;
  n2.valor = 2;
  n3.valor = 3;
  n4.valor = 4;
  n5.valor = 5;
  n6.valor = 6;
  n7.valor = 7;

  n1.direita = &n2;
  n1.esquerda = &n3;
  //n2.direita = &n4;
  //n2.esquerda = &n5;
  n3.direita = &n6;
  n3.esquerda = &n7;

  n2.direita = &n3;
  n2.esquerda = &n3;

  draw_arvore_hor(&n1);
  getchar();

  return 0;
}
