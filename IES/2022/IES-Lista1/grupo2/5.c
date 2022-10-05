#include<stdio.h>

int main() {
    int notas[50][2], i, numAlunos;

    for( i=0, notas[0][0]=0 ;  ; i++ ){
        scanf("%d %d", &notas[i][0], &notas[i][1]);
        if( notas[i][0]==50 )
            break;
    }
    numAlunos = i;
    for( i=0 ; i<numAlunos ; i++){
        printf("Media da nota do aluno %d = %d\n", i, (notas[i][0]+notas[i][1])/2);
    }

    return 0;
}
