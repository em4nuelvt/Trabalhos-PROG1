#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#define NUM 3
typedef struct dma{
    int dia;
    int mes; 
    int ano;
}data;


int main(){
    data d;
    int i;

printf("Digite o dia: ");
scanf("%d",&d.dia);

printf("Digite o mes: ");
scanf("%d",&d.mes);

printf("Digite o ano: ");
scanf("%d",&d.ano);

printf("Data:%d/%d/%d\n",d.dia,d.mes,d.ano);

    return 0; 
}