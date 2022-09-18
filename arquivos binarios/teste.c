#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *file;
    char aux[10];
    int x=10,y;
    file=fopen("teste.txt","a");
    if(file){
        printf("Arquivo aberto com sucesso\n");
        fprintf(file,"%d",x);

    }else{
        printf("Não foi possível abrir o arquivo\n");

    }
    fclose(file);

    file=fopen("teste.txt","r");
    if(file){
        fgets(aux,10,file);
    }else{
        printf("Erro na abertura do arquivo\n");
    }

    y=atoi(aux);

    printf("Y=%d\n",y);
    return 0;
}

