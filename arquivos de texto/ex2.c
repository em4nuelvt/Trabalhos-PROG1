#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *arq;
    char nome1[20],nome2[20],linha[20];
    arq = fopen("teste.txt","w");

    printf("Entre nome1: ");
    fgets(nome1,20,stdin);

    printf("Entre nome2: ");
    fgets(nome2,20,stdin);

    fputs(nome1,arq);
    fputs("\n",arq);
    fputs(nome2,arq);

    fclose(arq);

    /*arq = fopen("teste.txt","r");
    printf("lendo o arquivo:\n");
    fgets(linha,20,arq);*/
    
    return 0;
}