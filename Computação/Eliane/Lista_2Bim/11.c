#include <stdio.h>
#include <math.h>

int numero_numeros (int x) {
  int num_numeros;
  for ( num_numeros=0 ; x>0 ; x/=10 ) {
    num_numeros++;
  }
  return (num_numeros-1);
}

void encriptografia_numero_letra (int x) {
  int letra, num_numeros, aux_expoente, aux_x;
  for ( num_numeros=numero_numeros(x), aux_x=x ; num_numeros>=0 ; num_numeros--) {
    aux_expoente=pow(10,num_numeros);
    printf("%c", 'A'+(aux_x/aux_expoente));
    aux_x-= ((aux_x / aux_expoente) * aux_expoente);
  }
  printf("\n");
}

int main () {
  int num;
  scanf ("%d", &num);
  for (num; num >= 0; scanf ("%d", &num)) {
    encriptografia_numero_letra(num);
  }
  return 0;
}
