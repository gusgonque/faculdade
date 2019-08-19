#include <stdio.h>
#include <math.h>

void Construindo_Casas (int a, int b, int c) {
    int resultado, area, lado_perfeito;
    area = a*b;
    lado_perfeito = sqrt(area * (100/c));
    resultado = lado_perfeito;
    printf("%d\n",resultado);
}

int main () {
    int lado_a, lado_b, porcentagem;
    scanf("%d", &lado_a);
    for (  ; lado_a!=0 ;  ) {
        scanf("%d %d", &lado_b, &porcentagem);
        Construindo_Casas(lado_a,lado_b,porcentagem);
        scanf("%d", &lado_a);
    }
    return 0;
}
