#include<iostream>
#ifndef MUNICIPIO_H
#define MUNICIPIO_H
#include"Empresa.h"
#include"CI.h"
#include"Poblacion.h"
using namespace std;

class Municipio{
	private:
		string nombre;
		int cantidadEmpresa;  		//Cantidad de Talleres Empresa
		int cantidadMaxEmpresa;
		Empresa E[20];
		int cantidadPoblacion; 		//Cantidad de Talleres de Poblacion
		int cantidadMaxPoblacion;
		Poblacion P[20];
		CI DI[200];
		
		
	public:
	//Constructor por Defecto
	Municipio()	;
	//Constructor Con Parametros
	Municipio(string n,int, int, Empresa e [20],int,int,Poblacion p [20]);


	//SET
	void setcantidadEmpresa(int cE)			{cantidadEmpresa=cE;}
	void setcantidadPoblacion(int cP)		{cantidadPoblacion=cP;}
	void setcantidadMaxEmpresa(int cME)		{cantidadMaxEmpresa=cME;}
	void setcantidadMaxPoblacion (int cMP)	{cantidadMaxPoblacion=cMP;}


	//GET
	int getcantidadEmpresa()				{return cantidadEmpresa;}
	int getcantidadPoblacion()				{return cantidadPoblacion;}
	int getcantidadMaxEmpresa()				{return cantidadMaxEmpresa;}
	int getcantidadMaxPoblacion ()		    {return cantidadMaxPoblacion;}

	//Metodos de Agregar Talleres
	
	void AgregarEmpresa(Empresa N,int posic);
	void AgregarPoblacion(Poblacion Po,int posic);

    //Metodos para retornar un taller en especifico
	//de tipo empresa y poblacion.
	Empresa getE(int );
	Poblacion getP(int);
	
	//Metodos 
	int  CantidadSolitudesEmpresa();
	string Buscar(string );
	
	//Metodos para comprobar el Carnet de identidad
    void setCI(string ci,int posic){
       DI[posic]=ci;	
	}
	bool Encontrar(string ci);
	
	
	bool EncontrarCuenta(string c);
};
	//Implemenación del Constructor por Defecto
    Municipio::Municipio(){
  	nombre="Santiago de Cuba";
  	cantidadEmpresa=0;
	cantidadMaxEmpresa=10;

    cantidadPoblacion=0;
	cantidadMaxPoblacion=20;
        for(int i=0;i<200;i++){
           DI[i][0]="0";
           DI[i][1]="0";
        }
        for(int i=0;i<100;i++){
           cuenta[i][0]="0";
           cuenta[i][1]="0";
        }

  }
    //Implemenación del Constructor Con Parametros
  Municipio::Municipio(string n,int cE, int CME, Empresa  e[20],int cP,int CMP,Poblacion p[20]){
  	nombre=n;
  	cantidadEmpresa=cE;
	cantidadMaxEmpresa=CME;
	cantidadPoblacion=cP;
	cantidadMaxPoblacion=CMP;
	for(int i=0;i<cantidadPoblacion;i++){
		P[i]=p[i];
	}
	for(int i=0;i<cantidadEmpresa;i++){
		E[i]=e[i];
	}
  }
	
	//Implementacion del metodo AgregarEmpresa
        void  Municipio::AgregarEmpresa(Empresa N,int posic){
        E[posic].setnombre(N.getnombre());
        E[posic].setdireccion(N.getdireccion());
        E[posic].setcantidadT(N.getcantidadT());
        E[posic].setcuentaB(N.getcuentaB());
        E[posic].setcantSolic(N.getcantSolic());
        E[posic].setdeposito(N.getdeposito());
        //  Generamos el arreglo de tecnicos obtenidos uno a uno
            Tecnicos tec;
            for(int i=0;i<N.getcantidadT();i++){
                tec=N.getT(i);
                E[posic].RellenarTenico(tec,i);
            }

	}
	
	
	//Implementacion del metodo AgregarPoblacion
	void Municipio:: AgregarPoblacion(Poblacion Po,int posic){
		P[posic].setnombre(Po.getnombre());
		P[posic].setdireccion(Po.getdireccion());
		P[posic].setcantidadT(Po.getcantidadT());
		P[posic].setconsejo(Po.getconsejo());
                //  Generamos el arreglo de tecnicos obtenidos uno a uno
            Tecnicos tec;
            for(int i=0;i<Po.getcantidadT();i++){
                tec=Po.getT(i);
                P[posic].RellenarTenico(tec,i);
            }

	}
		
	Empresa Municipio::getE(int posic){
		Empresa Es;
		    int *a=E[posic].getcantSolic();
			Es.setnombre(E[posic].getnombre());
			Es.setdireccion(E[posic].getdireccion());
			Es.setcantidadT(E[posic].getcantidadT());
			Es.setcuentaB(E[posic].getcuentaB());
			Es.setdeposito(E[posic].getdeposito());
			Es.setcantSolic(a);
			//  Generamos el arreglo de tecnicos obtenidos uno a uno
            Tecnicos tec;
            for(int i=0;i<Es.getcantidadT();i++){
                tec=E[posic].getT(i);
                Es.RellenarTenico(tec,i);
            }
		
		return Es;
	}
	
	//Implementacion del metodo getP
	Poblacion Municipio::getP(int posic){
		Poblacion Po;
        Po.setnombre(P[posic].getnombre() );
        Po.setconsejo(P[posic].getconsejo());
        Po.setdireccion(P[posic].getdireccion());
        Po.setcantidadT(P[posic].getcantidadT());
        //  Generamos el arreglo de tecnicos obtenidos uno a uno
            Tecnicos tec;
            for(int i=0;i<Po.getcantidadT();i++){
                tec=P[posic].getT(i);
                Po.RellenarTenico(tec,i);
            }

		return Po;
	}
 
	//Implementacion del metodo CantidadSolitudesEmpresa();
	 int Municipio::CantidadSolitudesEmpresa(){
	 	int* Sumatoria;
	 	Sumatoria=new int[cantidadEmpresa];
	 	
	 	for(int i=0;i<cantidadEmpresa;i++){
	 		Sumatoria[i]=E[i].cantidadSolicitudes();
	 	}
	 	int suma=0;
	 	for(int i=0;i<cantidadEmpresa;i++){
	 		suma+=Sumatoria[i];
	 	}
	 	return suma;
	 }
    //Implementacion del metodo buscar el taller en el  consejo Popular entrado
	 string Municipio::Buscar(string c){
                int posic=-1;
	 	string n;
	 	for(int i=0;i<cantidadPoblacion;i++){
	 		if(c==P[i].getconsejo()){ //Comparando 
	 			c=P[i].getconsejo();
	 			posic=i;break;
			 }
		 }
                 if(posic==-1){
                  n="No hay talleres";
                 }
                 else{
                 n=P[posic].getnombre();
                 }
		 return n;
	 }
	
    //Implementacion del metodo bool Muncipio
        bool Municipio :: Encontrar(string ci){
            bool a=false;
            for(int i=0;i<200;i++){
                if(DI[i]==ci){
                a=true;break;
              }
          }
          return a;
        }
        
    	
	
	bool Municipio::EncontrarCuenta(string c){
	    bool a=false;
            for(int i=0;i<100;i++){
                if(cuenta[i][0]==c){
                a=true;break;
              }
          }
          return a;	
	}
    
	
  #endif	
  
  	
