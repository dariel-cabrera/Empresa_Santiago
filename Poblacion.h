#include<iostream>
#ifndef POBLACION_H
#define POBLACION_H
#include "Taller.h"
using namespace std;

class Poblacion:public Taller{
	private:	
		string consejo;	
	public:
		Poblacion(){
			consejo=" ";
		}
		Poblacion(string c,Taller T) :Taller(T){
			consejo=c;
		}
		void setconsejo(string c){consejo =c;}
		string getconsejo(){return consejo;}
};
#endif