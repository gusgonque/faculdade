#include <stdio.h>

void ImprimeTabuada(){
    int i, j;
    printf("Tabuada do 1 ao 9:\n");
    for( i=1 ; i<10 ; i++ ){
        for ( j=1 ; j<10 ; j++ ){
            printf(" %3d ", i*j);
        }
        printf("\n");
    }
}

int main() {
    ImprimeTabuada();

    return 0;
}
