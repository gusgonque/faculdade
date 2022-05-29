#include <stdio.h>

void abastecer (int *gas, int g){
  *gas += g;
  if ( *gas > 50) {
    printf("Tanque cheio.\n");
    *gas = 50;
  }
  printf("Carro abastecido com %d litros.\n", *gas);
}

void percorrer (int *gas, int *cam,int c){
  int c2;
  for ( c2 = 0 ; (*gas) > 0 ; c2 += 15 ) {
    (*gas)--;
    if (c2 == c)
      break;
  }
  if (*gas == 0) {
    printf("Gasolina acabou.\n");
  }
  *cam = c2;
  printf("Foram percorridos %d Km.\n", *cam);
}

void retorno (int *gas,int *cam){
  printf("O carro possui %d litros e percorreu %d Km.\n", *gas, *cam);
}

int main() {
  int gas1=0, cam1=0;
  int gas2=0, cam2=0;
  printf("Abastecendo carros.\n");
  abastecer(&gas1,20);
  abastecer(&gas2,30);
  printf("Carros percorrendo.\n");
  percorrer(&gas1,&cam1,200);
  percorrer(&gas2,&cam2,400);
  printf("Retorno de dados.\n");
  retorno(&gas1, &cam1);
  retorno(&gas2, &cam2);

  return 0;
}
