#include <stdio.h>
#include <ctype.h>

void palavraMaiuscula(char *fnm){
    FILE *f; int i, flag = 0; char aux;
    f = fopen(fnm, "r+");
    fscanf(f, "%c", &aux);
    if(isalpha(aux)) aux = toupper(aux), fseek(f, 0, SEEK_SET), fprintf(f, "%c", aux);
    for(i = 0; fscanf(f, "%c", &aux) != EOF; i++){
        //if(flag) aux = toupper(aux), fseek(f, 0, SEEK_CUR), fprintf(f, "%c", aux), flag = 0;
        //else{
            //if(!isalpha(aux)) flag = 1;
            //fscanf(f, "%c", &aux);
            //i = ftell(f);
            fseek(f, -1, SEEK_CUR);
        //    printf("aux = %c\n", aux);
            fprintf(f, "%c", toupper(aux));
            //fseek(f, 0, SEEK_CUR);
        //}



    }





//    aux = toupper(aux);
//    fseek(f, 0, SEEK_SET);
//    fprintf(f, "%c", aux);
//    printf("%c", aux);


    fclose(f);
}



int main(){
    palavraMaiuscula("dados.txt");

    return 0;
}
