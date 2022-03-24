struct no {
  int info; // informação armazenada
  struct no * esq; // subárvore esquerda
  struct no * dir; // subárvore direita
  int fb; // fator de balanceamento
};
typedef struct no* arvoreAVL; //árvore é um ponteiro para um nó

arvoreAVL rotacaoEsquerda(arvoreAVL p) {
  arvoreAVL u = p->dir;
  arvoreAVL t2 = u->esq;
  u->esq = p;
  p->dir = t2;
  return u;
}

arvoreAVL rotacaoDireitaEsquerda(arvoreAVL p) {
  arvoreAVL u = p->dir;
  arvoreAVL v = u->esq;
  arvoreAVL t2 = v->esq;
  arvoreAVL t3 = v->dir;
  p->dir = t2;
  u->esq = t3;
  v->esq = p;
  v->dir = u;
  return v;
}

int insercao(arvoreAVL* r, int x) {
  if(vazia(*r)) { // caso 1: ´arvore vazia
    *r = (arvoreAVL) malloc(sizeof(struct no));
    (*r)->info = x;
    (*r)->esq = (*r)->dir = NULL;
    (*r)->fb = 0;
    return 1;
  }
  // ´arvore n~ao vazia
  if(x < (*r)->info){ // caso 2: inserir na ´arvore esquerda
    if(insercao(&((*r)->esq), x)) {
      switch((*r)->fb){
        case -1: (*r)->fb = 0; return 0;
        case 0: (*r)->fb = 1; return 1;
        case 1: //rebalancear
          if((*r)->esq->fb >= 0) {
            *r = rotacaoDireita(*r);
            (*r)->dir->fb = 0;
          } else {
            *r = rotacaoEsquerdaDireita(*r);
            switch((*r)->fb) {
              case -1: (*r)->esq->fb = 1; (*r)->dir->fb = 0; break;
              case 0: (*r)->esq->fb = 0; (*r)->dir->fb = 0; break;
              case 1: (*r)->esq->fb = 0; (*r)->dir->fb = -1; break;
            }
          }
          (*r)->fb = 0; // atualiza FB da nova raiz
          return 0;
      }
    }
  }
  else if(insercao(&((*r)->dir), x)){ // caso 3: inserir na ´arvore direita
    switch((*r)->fb){
      case 1: (*r)->fb = 0; return 0;
      case 0: (*r)->fb = -1; return 1;
      case -1: //rebalancear
        if((*r)->dir->fb <= 0){
          *r = rotacaoEsquerda(*r);
          (*r)->esq->fb = 0;
        } else {
          *r = rotacaoDireitaEsquerda(*r);
          switch((*r)->fb) {
            case -1: (*r)->esq->fb = 1; (*r)->dir->fb = 0; break;
            case 0: (*r)->esq->fb = 0; (*r)->dir->fb = 0; break;
            case 1: (*r)->esq->fb = 0; (*r)->dir->fb = -1; break;
          }
        }
        (*r)->fb = 0;
        return 0;
    }
  }
}
