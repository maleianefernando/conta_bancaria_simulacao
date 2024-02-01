#ifndef IDENTIFICACAO_H_INCLUDED
#define IDENTIIFCACAO_H_INCLUDED

using namespace std;

class Identificacao{

	protected:
		string nome;
		char BI[13];
		string nacionalidade, naturalidade, filiacao[2];

        Identificacao();
        void setNome();
        void setBI();
        void setNacionalidade();
        void setNaturalidade();
        void setFiliacao();
        string getNome();
        char *getBI();
        string getNacionalidade();
        string getNaturalidade();
        void getFiliacao();
};

Identificacao::Identificacao(){
    strcpy(BI, "0000000000000");
}

void Identificacao::setNome(){
    cin>>nome;
}

void Identificacao::setBI(){
    cin>>BI;
}

void Identificacao::setNacionalidade(){
    cin>>nacionalidade;
}

void Identificacao::setNaturalidade(){
    cin>>naturalidade;
}

void Identificacao::setFiliacao(){
    for(int i=0; i<2; i++)
        cin>>filiacao[i];
}

string Identificacao::getNome(){
    return nome;
}

char* Identificacao::getBI(){
        return BI;
}

string Identificacao::getNacionalidade(){
        return nacionalidade;
}

string Identificacao::getNaturalidade(){
    return naturalidade;
}

void Identificacao::getFiliacao(){
    for(int i=0; i<2; i++)
        cout<< filiacao[i]<< "\n";
}


#endif
