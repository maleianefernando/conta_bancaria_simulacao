#include<iostream>
#include<string>
#include<cstring>

using namespace std;

class conta{
	protected:
		string titular;
		int numero;
		double saldo;
		string fonteFinanceira;
		int pin;
		
	public:		
		void extrato(){
			cout<<"Extrato da conta:"<<endl;
			cout<<"Titular:"<<titular<<endl;
			cout<<"Numero:"<<numero<<endl;
			cout<<"Saldo:"<<saldo<<endl;
		}
		
		void situacaoFinanceira(){
			cout<<"Situacao financeira da conta:"<<endl;
			cout<<"Titular:"<<titular<<endl;
			cout<<"Saldo:"<<saldo<<endl;
				}
		
		bool emprestimo(double valor){
			if(valor > 100 ){
				return true;
			}
			return false;
		}
		
};

class contaPoupanca : public conta {
	private:
		double meta;
		
		public:
		//	contaPoupanca(std::string titular, const int numero, double saldo, std::string fonteFinanceira, int pin, double meta) : conta(titular, numero, saldo, fonteFinanceira, pin), meta(meta){
		//	}
			
			bool levantamento(double valor){
				if(valor > 0 && saldo >= valor && saldo - valor >= meta){
					saldo -= valor;
					return true;
				}
				return false;
			}
};

int main(){
	conta c;
	c.getteres();
	c.situacaoFinanceira();
	c.extrato();
	
	
	string titular, fonteFinanceira;
	int numero;
	double saldo, meta;
	int pin;
	
	cout<<"                                                            "<<endl<<endl;
	
	cout<<"Criar uma nova conta:"<<endl;
	cout<<"Titular:";
	getline(cin, titular);
	cout<<"Numero:"<<endl;
	cin>>numero;
	cout<<"Saldo:";
	cin>> saldo;
	return 0;
}
