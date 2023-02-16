#include<iostream>
#ifndef TENICOS_H
#define TENICOS_H
using namespace std;

 class Tecnicos{
	private:
		string nombreTc;
		int cantE[5]; //Cantidad de Equipos reparados en la semana
		string CI; 
		float salario;
		
	public:
		//Constructor por Defecto
		Tecnicos();
		//Constructor con Parametros
		Tecnicos(string,int [],string ci,float);
		

		//Set
		void setnombre(string n){nombreTc=n;}
		void setcantE(int cE[5]);
		void setsalario(float S){salario=S;}
		void setCI(string ci)      {CI=ci;}

		//Get
		string getnombre(){return nombreTc;}
		int * getcantE();
		float getsalario(){return salario;}
		string getCI()			{return CI;}
		
		int cantidadequiposreparados();
		
		virtual void CalcularSalario(){
			setsalario(2000);
		} 
		
        //Metodo para guardar la cantidad equipos en una posicion del arreglo 
		void setcantEquipos(int posic,int cant){
		cantE[posic]=cant; //Posic es el dia de la semanana 
		}

};
	//Implentacion del Constructor por Defecto
	Tecnicos::Tecnicos(){
		nombreTc="";
		CI="";
		for(int i=0;i<5;i++)
        {
         cantE[i]=0;
		}
	}
	//Implentacion del Constructor con Parametros
	Tecnicos::Tecnicos(string n,int cE[5],string ci,float S){
		nombreTc=n;
		CI=ci;
		for(int i=0;i<5;i++){
			cantE[i]=cE[i];
		}
		salario=S;

	}

	void Tecnicos::setcantE(int cE[5]){
	    for(int i=0;i<5;i++){
	    	cantE[i]=cE[i];
		}
	}

    int * Tecnicos::getcantE(){
    	int * cE;
    	cE=new int[5];//Reservando memoria 
    	for(int i=0;i<5;i++){
    		cE[i]=cantE[i];
		}
		return cE;
	   delete [] cE;
	}
	//Metodo 
	int Tecnicos::cantidadequiposreparados(){
		int suma=0;
		for(int i=0;i<5;i++){
			suma+=cantE[i];
		}
		return suma;
	}
#endif