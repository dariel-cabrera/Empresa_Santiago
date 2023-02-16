#include<iostream>
#ifndef EMPRESA_H
#define EMPRESA_H
#include "Taller.h"
using namespace std;

class Empresa:public Taller {
	private:
		string cuentaB; //Cuenta Bancaria
		int cantSolic[5]; //Cantidad de solicitudes atendididas en la semana
		float deposito;
	public:
		Empresa();
		Empresa(string ,int [],float,Taller);
		
		//SET
		void setcuentaB(string cB)		{cuentaB=cB;}
		void setcantSolic(int cS[5]);
		void setcantS(int posic,int cant);
		void setdeposito(float dP)	{deposito=dP;}
		
		//GET
		string getcuentaB()			{return cuentaB;}
		float getdeposito()			{return deposito;}
		int * getcantSolic();
		//Metodos
		int cantidadSolicitudes();
		
};
	Empresa::Empresa(){
		cuentaB=" ";
		deposito=0;
		for(int i=0;i<5;i++){
			cantSolic[i]=0;
			}
		}
	
	Empresa::Empresa(string cB,int cS[5],float dP,Taller  T):Taller(T){
		 cuentaB=cB; 
		 for(int i=0;i<5;i++){
			cantSolic[i]=cS[i];
			}
		deposito=dP;
	}
		 
	
	void Empresa::setcantSolic(int cS[5]){
		for(int i=0;i<5;i++){
			cantSolic[i]=cS[i];
			}
		}
	void Empresa::setcantS(int posic,int cant){
		cantSolic[posic]=cant;
		}
	
	int * Empresa::getcantSolic(){
		int * cS;
		cS=new int[5];
		for(int i=0;i<5;i++){
			cS[i]=cantSolic[i];
		}
		return cS;
		//delete [] cS;
	}
	int Empresa::cantidadSolicitudes(){
		int suma=0;
		for(int i=0;i<5;i++){
			suma +=cantSolic[i];
		}
		return suma;
	}
#endif   