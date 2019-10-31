#include <stdio.h>
#define MAX 50

typedef struct
{
  char modelo [MAX];
  char tipo [MAX];
  float preco;
} Veiculo;

void Ler_Dados (Veiculo veic[MAX])
{
  int i;
  for ( i=0 ; i<5 ; i++ )
  {
    scanf("%[^\n]%*c", &veic[i].modelo);
    scanf("%[^\n]", &veic[i].tipo);
    scanf("%f%*c", &veic[i].preco);
  }
}

void Mostrar_Dados (Veiculo veic[MAX])
{
  int i;
  for ( i=0 ; i<5 ; i++ )
  {
    puts(veic[i].modelo);
    puts(veic[i].tipo);
    printf("%f\n", veic[i].preco);
  }
}

int main ()
{
  Veiculo v[MAX];
  Ler_Dados (v);
  Mostrar_Dados (v);
  return 0;
}
