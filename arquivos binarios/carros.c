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

int removeCarro(carros *vetor,int tamanho){
    char texto[20];
    if(tamanho==0){
        printf("\nÉ preciso cadastrar um carro primeiro\n");
    }else{
        printf("\n2-Remover Carro...\n");
        printf("Digite o modelo do carro que deseja remover: ");
        setbuf(stdin,0);
        fgets(texto,20,stdin);
        texto[strlen(texto)-1]='\0';

        if(strcmp("",texto)==0){
            return 2;  
        }

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
                return 1;
            }
        }
        return 0;
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////// função principal //////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(){

    FILE *fp;
    FILE *file;
    carros vetCarros[TAM];
    int nCadastro=0, verifica;
    char escolha[20];
    escolha[0]='1';
    char aux[20];
    fp=fopen("teste.txt","a+");
    
    
    if(fp){
        fgets(aux,20,fp);
        nCadastro=atoi(aux);
    }
    fclose(fp);
    printf("%d\n",nCadastro);
    
    if (nCadastro>0)
    {
        file=fopen("dados.bin","rb");
        if(file){
            fread(vetCarros,sizeof(carros),nCadastro,file);
        }
    }
    //fiz com char pra, caso ocorra erro na digitação da opção, não dê problema de execução
    while(escolha[0]!='0'){
        printf("\n\n---------------------MENU-----------------------");
        printf("\n1-Cadastrar carro\n");
        printf("2-Remover carro\n");
        printf("3-Listar carros de determinado Fabricante\n");
        printf("4-Listar carro mais economico\n");
        printf("5-Listar o carro com maior consumo\n");
        printf("6-Listar o carro mais novo\n");
        printf("0-Sair do programa\n");
        printf("------------------------------------------------\n\n");
        printf("Digite o numero da opção desejada: ");
        scanf("%s",escolha);

        switch(escolha[0]){
            case '1':
                if(nCadastro>=TAM){
                    printf("\nLimite máximo de carros cadastrados!\nRemova algum veículo se quiser continuar cadastrando...\nPressione ENTER se não for remover um carro agora...\n");
                }else{
                    vetCarros[nCadastro]=cadastraCarro(nCadastro);
                    nCadastro++;
                    printf("\nnumero de veículos cadastrados: %d\n",nCadastro);
                    break;
                }
                
            case '2':
                if(nCadastro==0){
                    printf("É necessário cadastrar um carro antes\n");
                }else{
                    verifica = removeCarro(vetCarros,nCadastro);
                    if (verifica==1){
                        nCadastro--;
                    }else if(verifica==0){
                        printf("\nVeículo não encontrado\n");
                    }
                    printf("\nnumero de veículos cadastrados: %d\n",nCadastro);
                }
                break;
            case '3':
                listaModelosFabricante(vetCarros,nCadastro);
                break;
            case '4':
                listaMaisEconomico(vetCarros,nCadastro);
                break;
            case '5':
                listaMaiorConsumo(vetCarros,nCadastro);
                break;
            case '6':
                listaCarroMaisNovo(vetCarros,nCadastro);
                break;
            default:
                break;
        }

    }
    int cont;
    file=fopen("dados.bin","ab");
    if(file){
        cont=fwrite(vetCarros,sizeof(carros),nCadastro,file);
    }
    printf("\n%d arquivos salvos\n",cont);
    fclose(file);

    fp=fopen("teste.txt","w");
    if(fp){
        fprintf(fp,"%d",nCadastro);
    }
    fclose(fp);
    
    return 0;
}