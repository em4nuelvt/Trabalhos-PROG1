#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *fp;
    fp = fopen ("exemplo.txt","w");
    
    if (!fp){
        printf("Erro na abertura do arquivo \n");
        exit(1);

    }
    return 0;
}