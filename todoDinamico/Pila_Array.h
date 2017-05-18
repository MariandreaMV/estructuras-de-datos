#ifndef PILA_ARRAY_H
#define PILA_ARRAY_H
#include "Cola_Array.h"
#include <iostream>



using namespace std;

template <class T>
class Pila_Array{
	
private:
		
	T *v;
	int size, tope;
		
public:
		
	Pila_Array(){}
	Pila_Array(int tam);		
	void Revertir();
	void sort();	
	void imprimir(int columnas);	
	void imprimir();
	int getTopePila(){ return tope+1;}
	int getTamanoPila(){ return size; }
	int getSize(){ return size; }
	int agregar(T &in);
	int eliminar(T &in);
	Pila_Array<T> operator + (Pila_Array<T> otro);
	Pila_Array<T> operator - (Pila_Array<T> otro);
	T eliminar();
	Cola_Array<T> getCola();
	
};

//convierte la pila en una cola
template<class T>
Cola_Array<T> Pila_Array<T>:: getCola(){
		
	int n=0;
	Cola_Array<T> retorno(size+1);
	while(n<=size){
		T eli;
		this->eliminar(eli);
		retorno.agregar(eli);
		n++;
	}
	retorno.Revertir();
	return retorno;
}

//constructor, inicializa todos los atributos
template<class T>
Pila_Array<T>::Pila_Array(int tam){
	
	size=tam;
	v= new T [size];
	tope=-1;
}

//el metodo invierte la pila
template<class T>
void Pila_Array<T>::Revertir(){
	int n=0;
	int tam=tope+1;
	T m[tam];
	while(n<tam){
		T eli;
		this->eliminar(eli);
		cout<<eli<<endl;
		m[n]=eli;
		n++;
	}
	n=0;	
	while(n<tam){
		T eli;
		eli=m[n];
		this->agregar(eli);
		n++;
	}
}

//ordena la pila de forma ascendente
template<class T>
void Pila_Array<T>::sort(){
	
	int a,b,position=0,flag=0;
	T heavy;
	size--;
	for(b=size;b>=0;b--){
		heavy=v[0];position=0;
		for(a=0;a<=b;a++){
			if(v[a]>heavy){
				heavy=v[a];
				position=a;	
			}
		}
		T aux=v[b];
		v[b]=v[position];
		v[position]=aux;	
	}		
}

//concatena dos pilas una seguida de la otra
template<class T>
Pila_Array<T> Pila_Array<T>:: operator + (Pila_Array<T> otro){
	
	int t= this->size + otro.getTamanoPila();
	Pila_Array<T> resultado(t);
	int n=0;
	this->Revertir();
	otro.Revertir();
	while(n < this->size){
		T eli;
		this->eliminar(eli);
		resultado.agregar(eli);
		n++;
	}
	n=0;
	while(n<otro.getSize()){
		T eli;
	 	otro.eliminar(eli);
	 	resultado.agregar(eli);
		n++;
	}
	
	return resultado;		
}

//mezcla dos pilas
template<class T>
Pila_Array<T> Pila_Array<T>:: operator - (Pila_Array<T> otro){
	
	int t= this->size + otro.getSize();
	this->Revertir();
	otro.Revertir();
	Pila_Array<T> resultado(t);
	int n=0;
	int n1=0,n2=0;
	bool band=true;//para el intercambio
	while(n < t){
		T eli;
		if(band==true&&n1<this->size){
			this->eliminar(eli);
			resultado.agregar(eli);
			n1++;band=false;
			n++;
		}else{
			if(n2<otro.getSize()){
				otro.eliminar(eli);
				resultado.agregar(eli);
				n2++;
				n++;
			}
		band=true;
		}	
	}
	
	return resultado;
}

//agregando uno seguido del otro
template<class T>
int Pila_Array<T>:: agregar(T &in){
	
	if(tope<(size-1)){
		tope++;
		v[tope] = in;
		return tope;
	}
	cout <<"PILA LLENA"<<endl;
	return -1;	//no se agrego		
}

//elimina elemento y lo guarda en el parametro
template<class T>
int Pila_Array<T>::eliminar(T &in){
	
	if(tope!=-1){
		in=v[tope];
		tope--;
		return tope;
	}
	//	cout<<"PILA VACIA"<<endl;
	return -1;//no se elimino
}

//elimina elemento y lo retorna
template<class T>
T Pila_Array<T>::eliminar(){
	
	T in;
	if(tope!=-1){
		in=v[tope];
		tope--;
		return in;
	}
	cout<<"PILA VACIA"<<endl;
	return NULL;//no se elimino
}

//imprime en columnas
template<class T>
void Pila_Array<T>::imprimir(int columnas){

	int c=0;
	for(int i=0; i<=tope;i++){
		cout<<"\t"<<v[i];
		c++;
		if(c==columnas){
			c=0;
			cout<<endl;
		}
	}
	cout<<endl;
}

//imprime uno seguido del otro
template<class T>
void Pila_Array<T>::imprimir(){
	
	if(tope==-1){
		cout<<"pila empty"<<endl;
		return;
	}
	for(int i=0; i<=tope;i++){
		cout<<"\t"<<v[i]<<" ";
	}
	cout<<endl;
}
#endif
