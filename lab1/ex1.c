#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct telefone{
    int ddd;
    int numero;
}telefone;

typedef struct aniversario{
    int dia;
    int mes;
    int ano;
}aniversario;

typedef struct contato{
    char nome[40];
    char email[80];
    char observacao[100];
    telefone tel;
    aniversario data;
}contato;

void cadastraContato(contato *contatos,int pos){
    printf("Cadastrar um contato: \n\n");

    printf("Digite o nome do contato: ");
    setbuf(stdin,0);
    fgets(contatos[pos].nome,40,stdin);
    contatos[pos].nome[strlen(contatos[pos].nome)-1]='\0';

    printf("Digite o email do contato: ");
    setbuf(stdin,0);
    fgets(contatos[pos].email,80,stdin);
    contatos[pos].email[strlen(contatos[pos].email)-1]='\0';

    printf("Digite o DDD do contato: ");
    scanf("%d", &contatos[pos].tel.ddd);
    printf("Digite o numero do contato: ");
    scanf("%d", &contatos[pos].tel.numero);

    do{
    printf("Digite o dia do aniversario: ");
    scanf("%d", &contatos[pos].data.dia);
    }while(contatos[pos].data.dia<0||(*contatos).data.dia>31);
    do{
    printf("Digite o mês do aniversario: ");
    scanf("%d", &contatos[pos].data.mes);
    }while(contatos[pos].data.mes>12 ||contatos[pos].data.mes<0);
    printf("Digite o ano do aniversário: ");
    scanf("%d", &contatos[pos].data.ano);

    printf("Digite alguma observacao: ");
    setbuf(stdin,0);
    fgets(contatos[pos].observacao,100,stdin);
    contatos[pos].observacao[strlen(contatos[pos].observacao)-1]='\0';

    printf("\nCadastro realizado!!!\n");

    return;
}

void alterarContato(contato*contatos,int pos){
    char texto[40];
    int verifica;

    printf("Alterar contato...\n");
    if(pos==0){
        printf("É preciso cadastrar um contato antes...\n");
    }else{
        printf("Digite o nome do contato que deseja alterar: ");
        setbuf(stdin,0);
        fgets(texto,40,stdin);
        texto[strlen(texto)-1]='\0';

        for(int i=0;i<pos;i++){
            if (strcmp(texto,contatos[i].nome)==0){
                printf("Digite o nome do contato: ");
                setbuf(stdin,0);
                fgets(contatos[i].nome,40,stdin);
                contatos[i].nome[strlen(contatos[i].nome)-1]='\0';

                printf("Digite o email do contato: ");
                setbuf(stdin,0);
                fgets(contatos[i].email,80,stdin);
                contatos[i].email[strlen(contatos[i].email)-1]='\0';

                printf("Digite o DDD do contato: ");
                scanf("%d", &contatos[i].tel.ddd);
                printf("Digite o numero do contato: ");
                scanf("%d", &contatos[i].tel.numero);

                do{
                printf("Digite o dia do aniversario: ");
                scanf("%d", &contatos[i].data.dia);
                }while(contatos[i].data.dia<0||(*contatos).data.dia>31);
                do{
                printf("Digite o mês do aniversario: ");
                scanf("%d", &contatos[i].data.mes);
                }while(contatos[i].data.mes>12 ||contatos[i].data.mes<0);
                printf("Digite o ano do aniversário: ");
                scanf("%d", &contatos[i].data.ano);

                printf("Digite alguma observacao: ");
                setbuf(stdin,0);
                fgets(contatos[i].observacao,100,stdin);
                contatos[i].observacao[strlen(contatos[i].observacao)-1]='\0';
                verifica=1;
                break;
            }
        }
        if(verifica!=1){
            printf("Contato não encontrado");
        }
    }
}

void removerContato(contato *contatos, int* tamanho, int* tam){
    char texto[40];
    int verifica;
    printf("Remover um contato: \n\n");
    printf("DIgite o nome do contato que deseja remover: ");
    setbuf(stdin,0);
    fgets(texto,40,stdin);
    texto[strlen(texto)-1]='\0';

    for(int i=0;i<*tamanho;i++){
        if(strcmp(texto,contatos[i].nome)==0){
            for(int j=i;j<*tamanho-1;j++){
                contatos[j]=contatos[j+1];
            }
            contatos=(contato*)realloc(contatos,sizeof(contato)*(*tam-1));
            *tam=*tam-1;
            verifica=1;
            *tamanho--;
            break;
        }

    }
    if (verifica!=1)
    {
        printf("\nContato não encontrado\n");
    } else{
        printf("\nContato removido com sucesso!!!\n");
    }
    return;

}

void procuraContato(contato *contatos, int tamanho){
    char texto[40];
    int verifica;
    printf("Procurar um contato...\n");
    printf("DIgite o nome do contato que está buscando: ");
    setbuf(stdin,0);
    fgets(texto,40,stdin);
    texto[strlen(texto)-1]='\0';

    for(int i=0;i<tamanho;i++){
        if(strcmp(texto,contatos[i].nome)==0){
            printf("Nome: %s\n",contatos[i].nome);
            printf("E-mail: %s\n",contatos[i].email);
            printf("Telefone: %d %d\n",contatos[i].tel.ddd,contatos[i].tel.numero);
            printf("Aniversário: %d/%d/%d\n",contatos[i].data.dia,contatos[i].data.mes,contatos[i].data.ano);
            printf("Observação: %s\n",contatos[i].observacao);
            verifica=1;
            break;
        }
    }
    if (verifica!=1)
    {
        printf("Contato não encontrado\n");
    }

    return;
}

void imprimeContatos(contato *contatos, int tamanho){
    for(int cont=0;cont<tamanho;cont++){
        printf("\nContato %d:\n",cont);
        printf("Nome: %s\n",contatos[cont].nome);
        printf("E-mail: %s\n",contatos[cont].email);
        printf("Telefone: %d %d\n",contatos[cont].tel.ddd,contatos[cont].tel.numero);
        printf("Data de aniversário:%d/%d/%d \n\n",contatos[cont].data.dia,contatos[cont].data.mes,contatos[cont].data.ano);
        printf("Observação: %s\n",contatos[cont].observacao);

    }
    return;
}

int main(){
    int tam;
    int nContatos=0;

    printf("Digite o tamanho inicial da agenda de contatos: ");
    scanf("%d",&tam);

    contato *contatos= (contato*)malloc(sizeof(contato)*tam);

    int escolha; 
    do{
        printf("\n\n---------------------AGENDA DE CONTATOS-----------------------");
        printf("\nOpções:");
        printf("\n1-Cadastrar contato\n");
        printf("2-Remover contato\n");
        printf("3-Alterar contato\n");
        printf("4-Pesquisar contato\n");
        printf("5-Imprimir contatos\n");
        printf("0-Sair do programa\n");
        printf("---------------------------------------------------------------\n");
        printf("Numero de contatos cadastrados: %d\nTamanho limite da agenda:%d\n\n",nContatos,tam);
        printf("Digite o numero da opção desejada: ");
        scanf("%d",&escolha);
        
        switch (escolha){
            case 1:
                
                if(nContatos>=tam){
                    printf("Limite atingido... Aumentando o tamanho da lista... \n");
                    contatos=(contato*)realloc(contatos,sizeof(contato)*(tam++)); 
                    cadastraContato(contatos,nContatos);
                    nContatos++; 
                        
                }else{ 
                    cadastraContato(contatos,nContatos);
                    nContatos++;
                }
                break; 
                
            case 2:
                if(nContatos==0){
                    printf("\nÉ necessário adicionar um contato antes!!!\n");
                }else{
                    removerContato(contatos,&nContatos,&tam);
                    nContatos--;
                }
                break;
            case 3:
                alterarContato(contatos,nContatos);
                break;
            case 4:
                procuraContato(contatos,nContatos);
                break;
            case 5:
                imprimeContatos(contatos,nContatos);
                break;
            case 0:
                printf("\nSaindo...\nFim da execução do programa.\n\n");
                break;
        }   
    }while(escolha!=0);
    return 0;
}