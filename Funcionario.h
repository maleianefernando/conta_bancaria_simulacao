#ifndef FUNCIONARIO_H_INCLUDED
#define FUNCIONARIO_H_INCLUDED

using namespace std;

class Funcionario: protected Conta{
	protected:
		int id;
		double salario, bonus;
		string experiencia, areaDeTrabalho, nivelAcademico;

	public:
	    Funcionario();
		void setId();
		bool pagarSalario();
		void setExperiencia();
		void setArea();
		void setNivelAcademico();
		void setBonus();
		bool setSalario();
		int getId();
		double getSalario();
		string getExperiencia();
		string getArea();
		string getNivelAcademico();
		double bonificacao();
		virtual void outDados();
		virtual bool inDados();
};

Funcionario::Funcionario():Conta(){
    gerarNumero();
    fonteFinanceira = "Banco";
    salario = 0;
    bonus = 0;
}

void Funcionario::setId(){
	cin>>id;
}

bool Funcionario::setSalario(){
    bool a;
    do{
    cin>> salario;
    if(salario<5000){
        a = false;
    }else{
        a = true;
    }
    return a;
    }while(a == false);
}

bool Funcionario::pagarSalario(){
    double valor;
    cin>> valor;
	if(valor == salario){
        saldo += salario;
        return true;
	}else{
        return false;
	}
}

void Funcionario::setExperiencia(){
	cin>>experiencia;
}

void Funcionario::setArea(){
	cin>>areaDeTrabalho;
}

void Funcionario::setNivelAcademico(){
	cin>>nivelAcademico;
}

int Funcionario::getId(){
	return id;
}

double Funcionario::getSalario(){
	return salario;
}

string Funcionario::getExperiencia(){
	return experiencia;
}

string Funcionario::getArea(){
	return areaDeTrabalho;
}

string Funcionario::getNivelAcademico(){
	return nivelAcademico;
}

void Funcionario::setBonus(){
	bonus = getSalario()*0.15;
	salario += bonus;
}

double Funcionario::bonificacao(){
	return bonus;
}

bool Funcionario::inDados(){
    fstream file, Cliente;
    file.open("funcionarios.txt", ios::out|ios::app);
    Cliente.open("clientes.txt", ios::app);
    cout<<"\t\t\t\t\t\tDADOS PESSOAIS"<< endl;
    cout<<"Nome: ";
    setNome();
    if(getNome() == "sair"){
        file.close();
        Cliente.close();
        return false;
    }else{
        cout<<"Nr do BI: ";
        setBI();
        cout<<"Nacionalidade: ";
        setNacionalidade();
        cout<<"Naturalidade: ";
        setNaturalidade();
        cout<<"Filiacao:"<<endl;
        setFiliacao();
        system("cls");
        cout<<"\t\t\t\tDADOS PROFISSIONAIS"<< endl;
        cout<<"ID: ";
        setId();
        cout<<"Experiencia: ";
        setExperiencia();
        cout<<"Nivel academico: ";
        setNivelAcademico();
        cout<<"Area de trabalho: ";
        setArea();
        cout<<"Salario: ";
        setSalario();
        setPin();

        file<<setiosflags(ios::left)<<setw(5)<<getId()<<setw(20)<<getNome()<<setw(20)<<filiacao[0]<<setw(20)<<filiacao[1]<<setw(15)
            <<getBI()<<setw(16)<<getNacionalidade()<<setw(16)<<getNaturalidade()<<setw(20)<<getFonteFinanceira()
            <<setw(15)<<getExperiencia()<<setw(18)<<getNivelAcademico()<<setw(20)<<getArea()<<setw(6)<<getSalario()<<endl;
            file<<flush;

        Cliente<<setiosflags(ios::left)<<setw(20)<<getNome()<<setw(20)<<filiacao[0]<<setw(20)<<filiacao[1]<<setw(15)
            <<getBI()<<setw(20)<<getNacionalidade()<<setw(20)<<getNaturalidade()<<setw(20)<<getFonteFinanceira()<<setw(6)<<getPin()<<endl;
            file<<flush;

        Cliente.close();
        file.close();
        return true;
    }
}

void Funcionario::outDados(){
    ifstream file;
    file.open("funcionarios.txt", ios::in);

    while(file>>id>>nome>>filiacao[0]>>filiacao[1]>>BI>>nacionalidade>>naturalidade>>fonteFinanceira>>experiencia>>nivelAcademico>>areaDeTrabalho>>salario){

        cout<<setiosflags(ios::left)<<setw(5)<<id<<setw(20)<<nome<<setw(20)<<filiacao[0]<<setw(20)<<filiacao[1]<<setw(15)
            <<BI<<setw(16)<<nacionalidade<<setw(16)<<naturalidade<<setw(20)<<fonteFinanceira<<setw(15)<<experiencia
            <<setw(18)<<nivelAcademico<<setw(20)<<areaDeTrabalho<<setw(6)<<salario<<endl;
    }
    file.close();
}

#endif
