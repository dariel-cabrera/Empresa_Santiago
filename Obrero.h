#include<iostream>
#include"Tecnicos.h"
using namespace std;

class Obrero:public Tecnicos{
	private:
	int annoS; //Años de servicios
		
	public:
	Obrero(){
		annoS=0;
	}
	Obrero(int aS,Tecnicos Y):Tecnicos(Y){
	   annoS=aS;	
	}
	
	void CalcularSalario(){
	  setsalario(getsalario()+ (annoS *0.10));		
	}
	
	
};