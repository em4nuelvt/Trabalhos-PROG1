#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *fp;
    int vet[1000],i;

    for (i=0;i<1000;i++){
        vet[i]=i;
    }

    fp=fopen("exemplo.dat","wb");

    if(fp){
        fwrite(vet,sizeof(int),1000,fp);
    }

    fclose(fp);

    int vet2[10];
    fp=fopen("exemplo.dat","rb");

    if(fp){
        while(1){
            fread(vet2,sizeof(int),10,fp);
            if(feof(fp)){
                break;
            }
            for(i=0;i<10;i++){
                printf("\nvet2[%d]=%d",i,vet2[i]);
            }
        }
    }
    fclose(fp);
    return 0;
}