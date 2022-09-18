#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;

typedef struct{
    char nome[80];
    int codigo; 
}vendedor;

typedef struct{
    int codigo;
    int mes;
    float valor;
}venda;

void cadastraVendedor(vendedor *vendedores, int pos){
    if(pos>=4){
        cout<<"Limite de funcionários atingido...\n"<<endl;
        return;
    }
    else{
        int auxiliar;
        int verificador=0;
        cout<< "Digite o nome do vendedor: ";
        cin>> vendedores[pos].nome;

        do{
        cout<< "Digite o codigo do vendedor: ";
        cin>>auxiliar;
        for(int i=0;i<pos;i++){
            if(vendedores[i].codigo==auxiliar){
                cout<<"Código já está associado a outro vendedor..."<<endl;
                verificador++;
                break;
            }else{
                verificador=0;
            }
        }
        vendedores[pos].codigo=auxiliar;
        }while(verificador!=0);

        cout<<"Vendedor cadastrado com sucesso!!!\n"<<endl;
    }
}

void cadastraVenda(vendedor *vendedores, venda *vendas, int pos, int nVendedores){
    if(nVendedores<=0){
        cout<<"É necessário cadastrar um funcionário antes..."<<endl;
    }else{    
        int verificador;
        int codigo;
        int mes;
        
        //pedir o código e verificar se ele existe
        do{
            cout<<"Digite o código do vendedor: ";
            cin>>codigo;
            //ter uma forma de sair caso tenha algum problema
            if(codigo==-1){
                return;
            }
            for(int i=0;i<nVendedores;i++){
                if(vendedores[i].codigo==codigo){
                    vendas[pos].codigo=codigo;
                    verificador=0;
                    break;
                }else{
                    verificador=1;
                }
            }
            if (verificador==1){
                cout<< "Vendedor não encontrado!"<<endl;
            }
        }while(verificador!=0);
        do{
            cout<<"Digite o mes da venda: ";
            cin>>mes;
            for(int i=0;i<pos;i++){
                if(vendas[i].codigo==codigo&&vendas[i].mes==mes){
                    verificador=1;
                    cout<<"Este vendedor já fechou as vendas deste mes..."<<endl;
                    break;
                }else{
                    verificador=0;
                }
            }
        }while(verificador!=0);
        vendas[pos].mes=mes;

        cout<<"Digite o valor da venda: ";
        cin>>vendas[pos].valor;
    }
}
//Consultar venda de um funcionario em determinado  mês 
void consultar1(vendedor *vendedores, venda *vendas, int nVendas, int nVendedores){
    if(nVendedores<=0){
        cout<<"É necessário cadastrar um funcionário antes..."<<endl;
    }else{    
        int verificador;
        int codigo,mes;
        float totalVendas=0;
        //pedir o código e verificar se ele existe
        do{
            cout<<"Digite o código do vendedor: ";
            cin>>codigo;
            //ter uma forma de sair caso tenha algum problema
            if(codigo==-1){
                return;
            }
            for(int i=0;i<nVendedores;i++){
                if(vendedores[i].codigo==codigo){
                    verificador=0;
                    break;
                }else{
                    verificador=1;
                }
            }
            if (verificador==1){
                cout<< "Vendedor não encontrado!"<<endl;
            }
        }while(verificador!=0);

        do{
            cout<<"Digite o mes da venda: ";
            cin>>mes;
        }while(mes<=0||mes>12);
        for(int i=0;i<nVendas;i++){
            if(vendas[i].codigo==codigo&&vendas[i].mes==mes){
                totalVendas=totalVendas+vendas[i].valor;
            }
        }
        cout<< fixed;
        cout<<setprecision(2);
        cout<<"Total vendido pelo funcionário no mês: R$"<<totalVendas<<endl;
        
    }
    return;
}

//Consultar total de vendas de um determinado funcionario
void consultar2(vendedor *vendedores, venda *vendas, int nVendas, int nVendedores){
    if(nVendedores<=0){
        cout<<"É necessário cadastrar um funcionário antes..."<<endl;
    }else{    
        int verificador;
        int codigo,mes;
        float totalVendas=0;
        //pedir o código e verificar se ele existe
        do{
            cout<<"Digite o código do vendedor: ";
            cin>>codigo;
            //ter uma forma de sair caso tenha algum problema
            if(codigo==-1){
                return;
            }
            for(int i=0;i<nVendedores;i++){
                if(vendedores[i].codigo==codigo){
                    verificador=0;
                    break;
                }else{
                    verificador=1;
                }
            }
            if (verificador==1){
                cout<< "Vendedor não encontrado!"<<endl;
            }
        }while(verificador!=0);

        for(int i=0;i<nVendas;i++){
            if(vendas[i].codigo==codigo){
                totalVendas=totalVendas+vendas[i].valor;
            }
        }
        cout<< fixed;
        cout<<setprecision(2);
        cout<<"Total vendido pelo funcionário no mês: R$"<<totalVendas<<endl;
    }
}

void vendedorQueMaisVendeu(vendedor *vendedores, venda *vendas, int nVendas, int nVendedores){
    if(nVendedores<=0){
        cout<<"É preciso cadastrar um vendedor antes"<<endl;
    }
    else{
        int mes;
        int quemVendeuMais;
        float auxiliarTotal=0,total=0;

        do{
            cout<<"Digite o mes da venda: ";
            cin>>mes;
        }while(mes<=0||mes>12);

        for(int i=0;i<nVendedores;i++){
            for(int j=0;j<nVendas;j++){
                if(vendas[j].mes==mes&&vendas[j].codigo==vendedores[i].codigo){
                    total=total+vendas[j].valor;
                }
            }
            if(total>auxiliarTotal){
                auxiliarTotal=total;
                quemVendeuMais=vendedores[i].codigo;
                
            }
            total=0;
            
        }
        cout<<"Quem vendeu mais foi o vendedor "<<quemVendeuMais<<"."<<endl;
    }

    return;
}

void mostraMesComMaisVendas(venda *vendas,int nVendas,int nVendedores){
    if(nVendedores<=0){
        cout<<"É necessário cadastrar um vendedor primeiro...\n"<<endl;
    }
    else{
        int mesMaior=0;
        float somaAux=0;
        float somaMes=0;
        for(int mes=1;mes<13;mes++){
            for(int i=0;i<nVendas;i++){
                if(vendas[i].mes==mes){
                    somaMes=somaMes+ vendas[i].valor;
                }
            }
            if(somaMes>somaAux){
                mesMaior=mes;
                somaAux=somaMes;

            }
            somaMes=0;
        }
        cout<<"Mes com mais vendas: ";
        switch(mesMaior){
            case 1:
                cout<<"Janeiro"<<endl;
                break;
            case 2:
                cout<<"Fevereiro"<<endl;
                break;
            case 3:
                cout<<"Março"<<endl;
                break;
            case 4:
                cout<<"Abril"<<endl;
                break;
            case 5:
                cout<<"Maio"<<endl;
                break;
            case 6:
                cout<<"Junho"<<endl;
                break;
            case 7:
                cout<<"Julho"<<endl;
                break;
            case 8:
                cout<<"Agosto"<<endl;
                break;
            case 9:
                cout<<"Setembro"<<endl;
                break;
            case 10:
                cout<<"Outubro"<<endl;
                break;
            case 11:
                cout<<"Novembro"<<endl;
                break;
            case 12:
                cout<<"Dezembro"<<endl;
                break;
        }
    }
    return;
    
}




int main(){

    int escolha;
    int tam=100;
    int nFuncionarios=0;
    int nVendas=0;
    int controlador;
    
    vendedor vendedores[4];
    venda *vendas= (venda*)malloc(sizeof(venda)*100);
    for(int i=0;i<100;i++){
        vendas[i].valor=0.0;
    }

    do{
        cout<<"-------------------------MENU------------------------------"<<endl;
        cout<<"1- Cadastrar vendedor"<<endl;
        cout<<"2- Cadastrar venda"<<endl;
        cout<<"3- Consultar venda de um funcionario em determinado  mês "<<endl;
        cout<<"4- Consultar total de vendas de um determinado vendedor"<<endl;
        cout<<"5- Mostrar vendedor que mais vendeu em determinado mês"<<endl;
        cout<<"6- Mostrar mes com mais vendas"<<endl;
        cout<<"0- Sair do programa"<<endl;
        cout<<"-----------------------------------------------------------"<<endl;

        cout<<"Digite a opão desejada: " ;
        cin>>escolha;
        cout<< "\n\n";

        switch(escolha){
            case 1:
                if(nFuncionarios<=4){
                    cadastraVendedor(vendedores,nFuncionarios);
                    nFuncionarios++;
                }else if(nFuncionarios>4){
                    cout << "Número máximo de funcionários cadastrados" <<endl;
                }
                break;
            case 2:
                if(nVendas<=100){
                    cadastraVenda(vendedores,vendas,nVendas,nFuncionarios);
                    nVendas++;
                }else{
                    vendas= (venda*)realloc(vendas,sizeof(venda)*(tam+1));
                    vendas[tam].valor=0.0;
                    tam++;
                    nVendas++;
                }
                break;
            case 3:
                consultar1(vendedores,vendas,nVendas,nFuncionarios);
                break;
            case 4:
                consultar2(vendedores,vendas,nVendas,nFuncionarios);
                break;
            case 5:
                vendedorQueMaisVendeu(vendedores,vendas,nVendas,nFuncionarios);
                break;
            case 6: 
                mostraMesComMaisVendas(vendas,nVendas,nFuncionarios);
                break; 
            case 0:
                break;
        }

    }while(escolha!=0);

    
}