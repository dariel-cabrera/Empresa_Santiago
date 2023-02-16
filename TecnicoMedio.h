#include<iostream>
#include"Tecnicos.h"
using namespace std;

class TecnicoMedio:public Tecnicos{
    private:
     int cantidadA;
     int AnnosS;	
	
	public:
	TecnicoMedio(){
	  cantidadA=0;
	  AnnosS=0;	
	}
	
	TecnicoMedio(int cA, int aS,Tecnicos T ):Tecnicos(T){
	   cantidadA=cA;
	   AnnosS=aS;	
	}
	
	void CalcularSalario(){
	 	
	 setsalario(getsalario()+(AnnosS*0.20)+(cantidadA*0.5))	;
	}	
};