#include <stdio.h>

int main() {
    int s[] = {1,2,3,4,5};
    FILE* arq = fopen("dados.bin","rb+");
    fseek(arq,0,SEEK_SET);
    fwrite(s,sizeof (s),1,arq);
    fclose(arq);
    return 0;
}
