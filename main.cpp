#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <time.h>
#include <cstdlib>
#include <locale>
#include "Conta.h"
#include "Funcionario.h"
#include "PCA.h"
#include "Gestor.h"
#include "Cliente.h"

using namespace std;

int main(){
	setlocale(LC_ALL, "Portuguese");
	int op;
	Gestor g;
	Cliente c;
	cout<<"[1].Gestor\n[2].Cliente\n[3].Sair\n";
	cin>> op;
	system("cls");
	switch(op){
        case 1:{
            if(g.autenticacao())
                g.inicio();
        }break;
        case 2:{
            if(c.autenticacao())
                c.inicio();
            }break;

	}

	return 0;
}
