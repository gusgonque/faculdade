/*****************************
* Nome do acadêmico: Gustavo Gonçalves Queiroz
* Nome do arquivo: 5_lista1.c
* Data de elaboração: 31/01
* Resumo:  Dados o número n de alunos de uma turma de Computacao II (C2)
e suas notas da primeira prova, determinar a maior e a menor nota obtidas
por essa turma (Nota máxima = 100 e nota mínima = 0).
// o resumo é uma breve descrição do objetivo do exercício
******************************/

#include <stdio.h>

int main()
{
  int n, i, nota, maior, menor;

  printf("Digite o numero de alunos.\n");
  scanf("%d", &n);

  printf("Digite as notas dos alunos.\n");

  scanf("%d", &nota);
  maior = nota;
  menor = nota;

  for ( i = 1 ; i < n ; i++ )
  {
    scanf("%d", &nota);
    if (nota>maior)
      maior = nota;
    if (nota<menor)
      menor = nota;
  }

  printf("Maior nota = %d\nMenor nota = %d", maior, menor);

  return 0;
}
