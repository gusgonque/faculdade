#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int area_t(detc)
{
    int a;

    if (detc > 0){

        a = detc/2;
    }
    else if (detc < 0){

        printf("ERRADO!\n");
        printf("Nao existe area desse triangulo, ou seja, nao existe triangulo nesse plano!\n");
    }

    return a;
}


int determinante(int m[3][3]){
    double a1, a2, a3, b1, b2, b3, s1, s2;
    int det;

    a1 = m[0][0]*m[1][1]*m[2][2];
    a2 = m[0][1]*m[1][2]*m[2][0];
    a3 = m[0][2]*m[1][0]*m[2][1];
    b1 = m[0][2]*m[1][1]*m[2][0];
    b2 = m[0][0]*m[1][2]*m[2][1];
    b3 = m[0][1]*m[1][0]*m[2][2];

    s1 = a1 + a2 + a3;
    s2 = b1 + b2 + b3;

    det = s1 - s2;

    printf("A matriz e:\n");
    printf("%d  %d  %d\n", m[0][0], m[0][1], m[0][2]);
    printf("%d  %d  %d\n", m[1][0], m[1][1], m[1][2]);
    printf("%d  %d  %d\n", m[2][0], m[2][1], m[2][2]);
    printf("o det e: %d\n", det);

    return det;
}



void le_matriz(int m[3][3]){
    int i,j;

    for (i=0;i<2;i++){
        for (j=0;j<3;j++){
            printf("Digite o elemento %d,%d:",i,j);
            scanf("%d",&m[i][j]);
        }
    }
}


int main()
{
    int x1,x2,x3,y1,y2,y3;
    int m[3][3]={{x1,x2,x3},{y1,y2,y3},{1,1,1}};
    int detg, a;

    le_matriz(m);
    detg = determinante(m);
    a = area_t(detg);

     printf("A area do triangulo e: %d\n", a);

    return 0;
}
