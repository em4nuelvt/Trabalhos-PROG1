#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp;
    int vet[10]={1,2,3,4,5,6,7,8,9,10};

    fp = fopen("exemplo.dat","wb");
    if(fp){
        fwrite(vet,sizeof(int),10,fp);
    }else{
        printf("Erro na abertura do arquivo \n");
        exit(1);
    }
    fclose(fp);

    int vet2[10];

    fp=fopen("exemplo.dat","rb");

    if(fp){
        fread(vet2,sizeof(int),10,fp);
    }else{
        printf("Erro na abertura do arquivo \n");
    }
    fclose(fp);

    int i;

    for(i=0;i<10;i++){
        printf("%d \n",vet2[i]);
    }

    return 0;
}