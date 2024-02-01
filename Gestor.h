#ifndef GESTOR_H
#define GESTOR_H
#include "Cliente.h"
class Gestor: virtual protected Funcionario{
    Cliente cliente;
    public:
        Gestor():Funcionario(){
            nome = "Gestor";
            pin = 2004;
        }

    void inicio();
    bool autenticacao();
};

bool Gestor::autenticacao(){
    bool a = false;
    string nome;
    int pin;
    cout<<"Nome: ";
    cin>>nome;
    cout<<"Pin: ";
    cin>>pin;
    if(nome == Gestor::nome){
        if(pin == Gestor::pin){
            a = true;
        }
    }
    if( a == false){
        cout<<"Credencias não encontradas:\n";
        a = false;
    }
    return a;
}

void Gestor::inicio(){
    int var, resp;
    system("cls");
        cout<<"\t\t\t\t\t\tGESTOR"<<endl;
        do{
        cout<<"[1].Gestao de clientes\n[2].Gestao de Funcionarios"<<endl;
        cin>>var;
        system("cls");
        switch(var){
            case 1:{
                cout<<"[1].Cadastrar clientes\n[2].Dados bancarios de clientes\n";
                cin>>var;
                system("cls");
                switch(var){
                    case 1: cliente.armazenar(); break;
                    case 2: {
                        cout<<setiosflags(ios::left)<<setw(20)<<"NOME"<<setw(20)<<"PAI"<<setw(20)<<"MÃE"<<setw(15)
                        <<"BI"<<setw(20)<<"NACIONALIDADE"<<setw(20)<<"NATURALIDADE"<<setw(20)<<"FONTE FINANCEIRA"<<endl;
                        cliente.displayData();
                    }break;
                }
            }break;
            case 2:{
                cout<<"[1].Cadastrar Funcionario\n[2].Funcionarios cadastrados\n[3].Pagar salario\n"<<endl;
                cin>>var;
                system("cls");
                switch(var){
                    case 1: while(inDados()); break;
                    case 2:{
                        cout<<setiosflags(ios::left)<<setw(5)<<"ID"<<setw(20)<<"NOME"<<setw(20)<<"PAI"<<setw(20)<<"MÃE"<<setw(15)
                            <<"BI"<<setw(16)<<"NACIONALIDADE"<<setw(16)<<"NATURALIDADE"<<setw(20)<<"FONTE FINANCEIRA"<<setw(15)<<"EXPÊRIENCIA"
                            <<setw(18)<<"NÍVEL ACADÊMICO"<<setw(20)<<"ÁREA DE TRABALHO"<<setw(6)<<"SALÁRIO"<<endl;
                        outDados();
                    }break;
                    case 3: ; break;
                }
            }break;
            cout<<"\n\n[1].Voltar\n[2].Sair\n";
            cin>> resp;
            system("cls");

        }
    }while(resp==1);
}

#endif // GESTOR_H
