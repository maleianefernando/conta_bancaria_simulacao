#ifndef CLIENTE_H
#define CLIENTE_H


class Cliente: public Conta{
    public:
        Cliente():Conta(){

        }
        bool cadastrar();
        bool displayData();
        void armazenar();
        void inicio();
    protected:

    private:
};

bool Cliente::cadastrar(){
    system("cls");

    cout<<"\t\t\t\t\tDADOS PESSOAIS\n";
    cout<<"Nome: ";
    setNome();
    if(getNome() == "sair"){
        return false;
    }
    setTitular();
    cout<<"Filiacao: ";
    setFiliacao();
    cout<<"Numero de BI: ";
    setBI();
    cout<<"Nacionalidade: ";
    setNacionalidade();
    cout<<"Naturalidade: ";
    setNaturalidade();
    cout<<"Fonte de dinheiro: ";
    setFonteFinanceira();
    while(setPin() == false){
        system("cls");
        setPin();
    }
    return true;
}

bool Cliente::displayData(){
    fstream file;
    file.open("clientes.txt", ios::in);

    if(!file){
        cout<<"Ficheiro não encontrado";
        return false;
    }

    while(file>>nome>>filiacao[0]>>filiacao[1]>>BI>>nacionalidade>>naturalidade>>fonteFinanceira>>pin){
        cout<<setiosflags(ios::left)<<setw(20)<<getNome()<<setw(20)<<filiacao[0]<<setw(20)<<filiacao[1]<<setw(15)
            <<getBI()<<setw(20)<<getNacionalidade()<<setw(20)<<getNaturalidade()<<setw(20)<<getFonteFinanceira()<<endl;
    }
    file.close();
    return true;
}

void Cliente::armazenar(){
    fstream file;
    file.open("clientes.txt", ios::out|ios::app);

    if(!file){
        cout<<"Dados não encontrados";
        abort();
    }

    while(cadastrar()){
    file<<setiosflags(ios::left)<<setw(20)<<getNome()<<setw(20)<<filiacao[0]<<setw(20)<<filiacao[1]<<setw(15)
        <<getBI()<<setw(20)<<getNacionalidade()<<setw(20)<<getNaturalidade()<<setw(20)<<getFonteFinanceira()<<setw(6)<<getPin()<<endl;
        file<<flush;
    }

    file.close();
}

void Cliente::inicio(){
    int var, resp;
    system("cls");
    do{
        cout<<"[1].Consultar saldo\n[2].Depositar\n[3].Levantamento\n[4].Tranferir dinheiro\n[5].Situação financeira\n[6].Emprestimo Bancario\n";
        cin>>var;
        system("cls");
        switch(var){
            case 1:{
                system("cls");
                cout<<"O teu saldo é: "<<getSaldo()<<".\nEFS_Bank, ao seu dispôr!";
            }break;
            case 2:{
                system("cls");
                double valor;
                cout<<"Informe o valor: ";
                cin>>valor;
                if(deposito(valor)){
                    cout<<"\nDepositou com sucesso "<<valor<<"MZN na sua conta.\nEFS_Bank, ao seu dispôr!"<<endl;
                }
            }break;
            case 3:{
                system("cls");
                double valor;
                cout<<"Informe o valor: ";
                cin>>valor;
                if(levantamento(valor)){
                    cout<<"\nLevantou com sucesso "<<valor<<"MZN da sua conta.\nEFSBank, ao seu dispôr!"<<endl;
                }else{
                cout<<"\nSaldo insufuciente";
                }
            }break;
            case 4:{
                system("cls");
                double valor;
                string receptor;
                cout<<"Informe o valor: ";
                cin>>valor;
                cout<<"Titular do destinatario: ";
                cin>>receptor;
                if(transferencia(valor, receptor)){
                    cout<<"Transferiu com sucesso "<<valor<<" MZN para "<<receptor<<endl;
                }else{
                    cout<<"O saldo é insuficiente ou o destinatário não existe"<<endl;
                }
            }break;
            case 5:{
                system("cls");
                situacaoFinanceira();
            }break;
            case 6:{
                system("cls");
                double valor;
                cout<<"Informe o valor: ";
                cin>>valor;
                if(emprestimo(valor)){
                        system("cls");
                    cout<<"Recebeu na sua conta um emprestimo de "<<valor<<" MZN na sua conta!"<<endl;
                }else{
                    cout<<"Não pode pedir emprestimo desse valor"<<endl;
                }
            }
        }
        cout<<"\n\n[1].Voltar\n[2].Sair\n";
        cin>> resp;
        system("cls");

    }while( resp == 1);
}

#endif // CLIENTE_H
