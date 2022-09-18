#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 100

typedef struct carroMod {
    char modelo[20];
    char fabricante[20];
    int ano;
    float consumo;
}carros;

carros cadastraCarro(int tamanho){
    if(tamanho>=TAM){
        printf("\nLimite de cadastros atingido\n");
    }else{
        carros carro;
        printf("\nDigite o modelo do carro: ");
        setbuf(stdin,0);
        fgets(carro.modelo,20,stdin);
        carro.modelo[strlen(carro.modelo)-1]='\0';

        printf("Digite o fabricante do carro: ");
        fgets(carro.fabricante,20,stdin);
        carro.fabricante[strlen(carro.fabricante)-1]='\0';

        printf("Digite o ano do carro: ");
        scanf("%d",&carro.ano);

        printf("Digite o consumo do carro: ");
        scanf("%f",&carro.consumo);

        return carro;
    }

}
void listaModelosFabricante(carros *vetor, int tamanho){
    char texto[20]; int contador=0;
    printf("\n3-Lista os modelos...\n");
    printf("Digite o nome do fabricante: ");
    setbuf(stdin,0);
    fgets(texto,20,stdin);
    texto[strlen(texto)-1]='\0';
    printf("\n%s:\n",texto);

    for(int i=0;i<tamanho;i++){
        if(strcmp(texto,vetor[i].fabricante)==0){
            printf("%s\n",vetor[i].modelo);
            contador++;
        }
    }
    if (contador==0)
    {
        printf("Não há nenhum veículo deste fabricante\n");
    }
    

}
void listaMaisEconomico( carros *vetor, int tamanho){
    int aux=-1, maisEconomico;
    if(tamanho==0){
        printf("\nÉ necessário cadastrar um carro primeiro\n");
    }else{
        for(int i=0;i<tamanho;i++){
        if(vetor[i].consumo>aux){
            aux=vetor[i].consumo;
            maisEconomico=i;
        }
    }
        printf("\n4-Carro mais econômico...\n");
        printf("O carro mais economico é o %s\n",vetor[maisEconomico].modelo);
    }
}

void listaMaiorConsumo(carros *vetor, int tamanho){
    int aux=1000, maiorConsumo;
    if(tamanho==0){
        printf("\nÉ necessŕio cadastrar um veículo primeiro\n");
    }else{
        for(int i=0;i<tamanho;i++){
        if(vetor[i].consumo<aux){
            aux=vetor[i].consumo;
            maiorConsumo=i;
        }
    }
        printf("\n5-Carro de maior consumo...");
        printf("\nO carro de maior consumo é o %s\n",vetor[maiorConsumo].modelo);
    }
}

void listaCarroMaisNovo(carros *vetor, int tamanho){
    int aux=0, maiorAno;
    if(tamanho==0){
        printf("\nÉ necessário cadastrar um veículo primeiro\n");
    }else{
        for(int i=0;i<tamanho;i++){
        if(vetor[i].ano>aux){
            aux=vetor[i].ano;
            maiorAno=i;
        }
    }
        printf("\n6-Carro mais novo...\n");
        printf("O carro mais novo é o %s \n",vetor[maiorAno].modelo);
    }
}

void removeCarro(carros *vetor,int tamanho){
    char texto[20];
    if(tamanho==0){
        printf("\nÉ preciso cadastrar um carro primeiro\n");
    }else{
        printf("\n2-Remover Carro...\n");
        printf("Digite o modelo do carro que deseja remover: ");
        setbuf(stdin,0);
        fgets(texto,20,stdin);
        texto[strlen(texto)-1]='\0';
        for(int i=0;i<tamanho;i++){
            if(strcmp(vetor[i].modelo,texto)==0){
                for(int j=i;j<tamanho-1;j++){
                    vetor[j]=vetor[j+1];
                }
                vetor[tamanho-1].ano=0;
                vetor[tamanho-1].consumo=0;
                vetor[tamanho-1].fabricante[0]='\0';
                vetor[tamanho-1].modelo[0]='\0';
                printf("Veículo removido com sucesso!!!\n");
                return;
            }else{
                printf("\nModelo não encontrado\n");
            }
        }
    }
}

int main(){
FILE *file;
carros vetCarros[TAM];
int nCadastro=0, escolha=1;

/*file=fopen("dados.dat","rb");
if(file){
    nCadastro=fread(vetCarros,sizeof(carros),TAM,file);
}else{
    nCadastro=0;    
}
fclose(file);*/

while(escolha!=0){
    printf("\n\n1-Cadastrar carro\n");
    printf("2-Remover carro\n");
    printf("3-Listar carros de determinado Fabricante\n");
    printf("4-Listar carro mais economico\n");
    printf("5-Listar o carro com maior consumo\n");
    printf("6-Listar o carro mais novo\n");
    printf("0-Sair do programa\n\n");
    printf("Digite o numero da opção desejada: ");
    scanf("%d",&escolha);

    switch(escolha){
        case 1:
            vetCarros[nCadastro]=cadastraCarro(nCadastro);
            nCadastro++;
            printf("\nnumero de veículos cadastrados: %d\n",nCadastro);
            break;
        case 2:
            removeCarro(vetCarros,nCadastro);
            nCadastro--;
            printf("\nnumero de veículos cadastrados: %d\n",nCadastro);
            break;
        case 3:
            listaModelosFabricante(vetCarros,nCadastro);
            break;
        case 4:
            listaMaisEconomico(vetCarros,nCadastro);
            break;
        case 5:
            listaMaiorConsumo(vetCarros,nCadastro);
            break;
        case 6:
            listaCarroMaisNovo(vetCarros,nCadastro);
            break;
    }

}
int cont;
file=fopen("dados.dat","wb");
if(file){
    cont=fwrite(vetCarros,sizeof(carros),nCadastro,file);
}
printf("\n%d arquivos salvos\n",cont);


    return 0;
}
