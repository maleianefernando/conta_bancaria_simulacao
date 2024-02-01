#ifndef CONTA_H_INCLUDED
#define CONTA_H_INCLUDED

#include "Identificacao.h"

class Conta: protected Identificacao{
	protected:
		string titular, fonteFinanceira;
		int numero[6];
		double saldo, dividas;
		int pin;
		void gerarNumero();
		bool setPin();

	public:
		Conta();
		bool autenticacao();
		void setFonteFinanceira();
		string getFonteFinanceira();
		void setTitular();
		bool deposito(double valor);
		bool levantamento(double valor);
		bool transferencia(double valor, string Titular);
		void situacaoFinanceira();
		bool emprestimo(double valor);
		double getSaldo();
		string getTitular();
		int getPin();
		void getNumero();
		void receber();
		void dados();
};

bool Conta::autenticacao(){
    bool a = false;
    string nome;
    int pin;
    fstream Cliente;
    Cliente.open("clientes.txt", ios::in);
    if(!Cliente){
        cout<<"Ficheiro não encontrado\n";
        return false;
    }
    cout<<"Nome: ";
    cin>>nome;
    cout<<"Pin: ";
    cin>>pin;
    while(Cliente>>Conta::nome>>filiacao[0]>>filiacao[1]>>BI>>nacionalidade>>naturalidade>>fonteFinanceira>>Conta::pin){
        if(nome == Conta::nome){
            if(pin == Conta::pin){
                a = true;
            }
        }
    }
    if( a == false){
        cout<<"Credencias não encontradas:\n";
        a = false;
    }
    return a;
}

void Conta::setFonteFinanceira(){
    cin>>fonteFinanceira;
}

string Conta::getFonteFinanceira(){
    return fonteFinanceira;
}

void Conta::receber(){

}

bool Conta::transferencia(double valor, string Titular){
	int taxa;
	bool a;
	string linha;
	fstream file;
	file.open("clientes.txt", ios::in);

	if(valor >= 50){
	    if(valor <= 100){
		taxa = 5;
	    }else if(valor > 100 && (valor <= 500)){
	        taxa = 10;
	    }else if(valor > 500 && (valor <= 1000)){
	        taxa = 12;
	    }else if(valor > 1000 && (valor <= 2000)){
	        taxa = 17;
	    }else if(valor > 2000 && (valor <= 5000)){
	        taxa = 22;
	    }else if(valor > 5000){
	        taxa = 35;
	    }

        while(file>>nome>>filiacao[0]>>filiacao[1]>>BI>>nacionalidade>>naturalidade>>fonteFinanceira>>pin){
            if(nome == Titular){
                valor += taxa;
                this->saldo -= valor;
                file.close();
                a = true;
                break;
            }
        }
	}else{
		a = false;
	}
	return a;
}

Conta::Conta(){
    pin = 0;
	gerarNumero();
	titular = "titular";
	saldo = 0;
	dividas = 0;
}

void Conta::getNumero(){
	for(int i = 0; i < 6; i++){
		cout<<numero[i];
	}
}

bool Conta::setPin(){
    bool a;
    int pin[2];
    cout<<"Defina o seu PIN: ";
    cin>>pin[0];
    cout<<"Confirme o PIN: ";
    cin>>pin[1];
    if(pin[0] == pin[1]){
        Conta::pin = pin[0];
        return true;
    }else{
        cout<<"PIN não confirmado"<<endl;
        return false;
    }

    return a;
}

int Conta::getPin(){
    return pin;
}

void Conta::setTitular(){
	titular = nome;
}

string Conta::getTitular(){
	return titular;
}

void Conta::gerarNumero(){
	srand(time(NULL));
	for(int i = 0; i < 6; i++){
    	numero[i] = rand()%9;
	}
}

bool Conta::deposito(double valor){
	if (valor > 50){
		saldo += valor;
		return true;
	}else{
		return false;
	}
}

bool Conta::levantamento(double valor){
    bool a;
    int taxa = 0;

	if(valor >= 50){
	    if(valor <= 100){
		taxa = 10;
	    }else if(valor > 100 && (valor <= 500)){
	        taxa = 20;
	    }else if(valor > 500 && (valor <= 1000)){
	        taxa = 25;
	    }else if(valor > 1000 && (valor <= 2000)){
	        taxa = 35;
	    }else if(valor > 2000 && (valor <= 5000)){
	        taxa = 45;
	    }else if(valor > 5000){
	        taxa = 70;
	    }
    }

    valor += taxa;

    if(valor <= saldo &&  valor > 50){
	saldo -= valor;
	a = true;
    }else if(valor > saldo || valor < 50){
	saldo = saldo;
	a = false;
    }

    return a;
}

double Conta::getSaldo(){
	return saldo;
}

void Conta::situacaoFinanceira(){
    cout<<"Saldo atual: "<<getSaldo()<<endl;
    cout<<"Dividas: "<<dividas<<endl;
}

bool Conta::emprestimo(double valor){
    bool a;

    if(valor > 500 && valor < 10000){
        saldo += valor;
        a = true;
    }else{
        a = false;
    }

    return a;
}
#endif
