/*****************************
* Nome do acadêmico: Gustavo Gonçalves Queiroz
* Nome do arquivo: 7_lista1.c
* Data de elaboração: 31/01
* Resumo: Dados n e dois números inteiros positivos i e j diferentes de 0, imprimir em
ordem crescente os n primeiros naturais que são múltiplos de i ou de j e ou de ambos.
Exemplo: Para n = 6 , i = 2 e j = 3 a saída deverá ser : 0,2,3,4,6,8
// o resumo é uma breve descrição do objetivo do exercício
******************************/

#include <stdio.h>

int main()
{
  int n, i, j, k, l;

  printf("Digite n, i e j para determinar os n primeiros naturais que sao multiplos de i ou de j e ou de ambos.\n");
  scanf("%d %d %d", &n, &i, &j);

  for ( k = l = 0 ; l < n ; k++ )
  {
    if ( k%i == 0 )
    {
      printf("%d ", k);
      l++;
    }
    else
      if ( k%j == 0 )
        {
          printf("%d ", k);
          l++;
        }
  }

  return 0;
}
