#include <stdio.h>

int main (){
  int gols_inter, gols_gremio, novo_grenal, num_inter, num_gremio, num_empates, num_grenais;
  for ( num_inter = 0, num_gremio = 0, num_empates = 0, novo_grenal = 1, num_grenais = 0 ; novo_grenal != 2 ; num_grenais ++ ) {
    scanf ("%d %d", &gols_inter, &gols_gremio);
    if (gols_inter > gols_gremio)
      num_inter ++;
    else
      if (gols_gremio > gols_inter)
        num_gremio ++;
      else
        num_empates ++;
    printf ("Novo grenal (1-sim 2-nao)\n");
    scanf ("%d", &novo_grenal);
  }
  printf ("%d grenais\n", num_grenais);
  printf ("Inter:%d\n", num_inter);
  printf ("Gremio:%d\n", num_gremio);
  printf ("Empates:%d\n", num_empates);
  if (num_inter > num_gremio)
    printf ("Inter venceu mais\n");
  else
    if (num_gremio > num_inter)
      printf ("Gremio venceu mais\n");
    else
      printf ("Nao houve vencedor\n");
  return 0;
}
