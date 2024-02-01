#ifndef PCA_H_INCLDUED
#define PCA_H_INCLUDED

#include "Funcionario.h"

class PCA: private Funcionario{
    public:
        PCA():Funcionario(){

        }

	protected:
		void setBonus(){
			bonus = getSalario()*0.25;
			salario += bonus;
		}

        bool setSalario(){
            bool a;
            do{
            cin>> salario;
            if(salario<35000){
                a = false;
            }else{
                a = true;
            }
            return a;
            }while(a == false);
        }
};

#endif
