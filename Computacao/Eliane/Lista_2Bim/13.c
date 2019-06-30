#include <stdio.h>
#include <math.h>

int numero_numeros (int x) {
  int num_numeros;
  for ( num_numeros=0 ; x>0 ; x/=10 ) {
    num_numeros++;
  }
  return (num_numeros);
}

void decomposicao (int x) {
  int num_final = x, aux_expoente, aux_num;
  for ( num_final = x ; num_final >= 10 ;  ) {
    for ( aux_expoente = (pow(10,numero_numeros(x))), aux_num = 0 ; aux_expoente >= 0 ; aux_expoente-- ) {
      aux_num += (( num_final / aux_expoente ) * aux_expoente);
    }
    num_final = aux_num;
  }
  printf("%d\n", num_final);
}

int main () {
  int num;
  scanf("%d", &num);
  for (  ; num >= 0 ; scanf("%d", &num) ) {
    decomposicao(num);
  }
}
