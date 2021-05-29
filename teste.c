#include <stdio.h>

void lerVet(float v[], int n){
    int i;
    for(i = 0; i < n; i++)
        scanf("%f", &v[i]);
}

void comparaVetor(float v1[], float v2[], int n, int j){
    int i, identico = 0;
    if(n == j){
        for(i = 0; i < n; i++)
            if(v1[i] == v2[i]) identico++;
        if(identico == i) printf("IDENTICOS\n");
    }
    else printf("NAO IDENTICOS\n");
}

int main(){
    float v1[100], v2[100];
    int n, j;

    scanf("%d", &n);
    printf("Vetor 1:\n");
    lerVet(v1, n);

    scanf("%d", &j);
    printf("Vetor 2:\n");
    lerVet(v2, j);

    comparaVetor(v1, v2, n, j);

    return 0;
}
