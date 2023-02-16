#include<iostream>
#ifndef TALLER_H
#define TALLER_H
#include "Tecnicos.h"
using namespace std;


class Taller{
	private:
		string nombre;
		string direccion;
		Tecnicos t[20]; //Composicion. EL Taller TIENE TECNICOS
		int cantidadT; //Cantidad de Tecnicos que tiene el taller
	public:
		//Constructor por Defecto
		Taller();
		//Constructor Con Parametros
		Taller(string,string,Tecnicos [],int);
		
		
		//Set
		void setnombre(string n){nombre=n;}
		void setdireccion(string d){direccion=d;}
		void setcantidadT(int y){cantidadT=y;}
		
		void sett(Tecnicos T[20]){
                 for(int i=0;i<20;i++){
                     t[i]=T[i];  //Modificando el arreglo de tecnicos 
                 }
                }
		//GET
		string getdireccion(){return direccion;}
		string getnombre(){return nombre;}
		int getcantidadT(){return cantidadT;}

          //retornano el arreglo de Tecnicos
	       	Tecnicos *getTecnicos(){
			Tecnicos *T;
                        T=new Tecnicos[cantidadT];//Reservando Memoria  
                        int *a;
                        a=new int[5];
			for(int i=0;i<cantidadT;i++){
                          T[i].setnombre(t[i].getnombre());
                          T[i].setCI(t[i].getCI());
                          T[i].setsalario(t[i].getsalario());
                          a=t[i].getcantE();
                          T[i].setcantE(a);
                          }
			return T;
		}

		//METODOS
		int MejorTecnico();
		//Rellenando EL arreglo de tecnicos de uno en uno
		void RellenarTenico(Tecnicos te,int posic){
			int *T;
            T=te.getcantE();
			t[posic].setnombre(te.getnombre());
			t[posic].setcantE(T);
			t[posic].setsalario(te.getsalario());
			t[posic].setCI(te.getCI());

		}
		Tecnicos getT(int posic){
                   Tecnicos Te;
                   int *a;
            
                   Te.setnombre(t[posic].getnombre());
                   Te.setCI(t[posic].getCI());
                   Te.setsalario(t[posic].getsalario());
                   a=t[posic].getcantE();
                   Te.setcantE(a);

                   return Te;
		}

		bool ComprobarTecnico(string ci){
                   bool a=false;

			for(int i=0;i<cantidadT;i++){
				if(t[i].getCI()==ci){
				   a=true; 	
				}
			}
           return a;               
		}

};
    //Implentacion del Constructor por Defecto
    Taller::Taller(){
  	nombre=" ";
  	direccion=" ";
  	cantidadT=0;
  }
    //Implentacion del Constructor Con Parametros
    Taller::Taller(string n,string d,Tecnicos  Te[20],int c){
  	nombre=n;
  	cantidadT=c;
  	direccion=d;
  }
    
    //IMPLEMENTACION DEL METODO int MejorTecnico();
  int Taller::MejorTecnico(){
  	 int *Sumatoria;
  	 Sumatoria=new int [cantidadT];
  	 	for(int i=0;i<cantidadT;i++){
  	 		Sumatoria[i]=t[i].cantidadequiposreparados();//Llamando al metodo suma de tecnicos	
		}

  	 int mayor=Sumatoria[0];// 7
  	 int posic=0;
  	 for(int i=0;i<cantidadT;i++){
  	 	if(mayor<Sumatoria[i]){
  	 		mayor=Sumatoria[i];
  	 		posic=i;
		   }
	   }
	return posic;
	delete []Sumatoria; 
  }
  #endif