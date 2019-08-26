#include <stdio.h>
#include <math.h>

void Construindo_Casas (int a, int b, int c) {
    int resultado, area, lado_perfeito, area_perfeita;
    area = a*b;
    area_perfeita = (area * (100.0/c));
    lado_perfeito = pow(area_perfeita,0.5);
    resultado = lado_perfeito;
    printf("%d\n",resultado);
}

int main () {
    int lado_a, lado_b, porcentagem;
    scanf("%d", &lado_a);
    for (  ; lado_a!=0 ; scanf("%d", &lado_a) ) {
        scanf("%d %d", &lado_b, &porcentagem);
        Construindo_Casas(lado_a,lado_b,porcentagem);
    }
    return 0;
}
