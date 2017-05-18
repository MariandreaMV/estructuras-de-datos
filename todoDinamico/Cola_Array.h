#ifndef COLA_ARRAY_H
#define COLA_ARRAY_H
#include <iostream>
#include "Cola_circular.h"

using namespace std;

template <class T>
class Cola_Array{
	
private:
		
	int FIN, N, TAM;
	T *v;
		
public:
	
	Cola_Array(){}
	Cola_Array(int size);	
	void imprimir();
	void imprimirColaPosicion();
	void imprimirClase();
	void Revertir();
	void sort();
	int agregar(T &obj);
	int eliminar(T & obj);
	int getTamano(){ return TAM; }
	int getFinCola(){ return FIN+1;}
	int getSize(){ return TAM; }
	T eliminar();		
	Cola_Array<T> operator + (Cola_Array<T> otro);
	Cola_Array<T> operator - (Cola_Array<T> otro);
	Cola_circular<T> getColaCircular();


};

template<class T>
Cola_circular<T> Cola_Array<T>::getColaCircular(){

	Cola_circular<T> resultante(this->FIN+1);
	int fin=FIN+1;
	for(int i=0;i<fin;i++){
		T eliminado;
		this->eliminar(eliminado);
		resultante.agregar(eliminado);
	}
	return resultante;
}

//constructor, inicializa valores
template<class T>
Cola_Array<T>::Cola_Array(int size){
	
		FIN=-1;
		TAM=size;
		v=new T [TAM];
}			

//metodo que invierte la cola, lo ultimo pasa a ser lo primero
template<class T>
void Cola_Array<T>::Revertir(){
	
	int n=0;
	int tam=FIN+1;
	cout<<tam<<endl;
	cout<<endl;
	T r[tam];
	while(n<tam){
		T eli;
		this->eliminar(eli);
		r[n]=eli;
		n++;
	}
	n=0;
	int c=tam-1;	
	while(n<tam){
		T eli;
		eli=r[c];c--;
		this->agregar(eli);
		n++;
	}
}

//metodo que mezcla dos cadenas, si una es mayor que la otra
//el resto de la mas larga quedara sobrante
template<class T>
Cola_Array<T> Cola_Array<T>:: operator - (Cola_Array<T> otro){
	
	int t= this->TAM + otro.getSize();
	Cola_Array<T> resultado(t);
	int n=0;
	int n1=0,n2=0;
	bool band=true;//para el intercambio
	while(n < t){
		T eli;
		if(band==true&&n1<this->TAM){
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

//metodo que concatena dos colas, una seguida de la otra
template<class T>
Cola_Array<T> Cola_Array<T>:: operator + (Cola_Array<T> otro){
	
	int t=this->TAM + otro.getTamano();
	Cola_Array<T> resultado(t);
	int n=0;
	while(n<this->TAM){
		T eli;
		this->eliminar(eli);
		resultado.agregar(eli);
		n++;
	}
	n=0;
	while(n<otro.getTamano()){
		T eli;
		otro.eliminar(eli);
	 	resultado.agregar(eli);
	 	n++;
	}
	return resultado;
}

//ordena la cola de forma ascendente
template<class T>
void Cola_Array<T>::sort(){
	
	int a,b,position=0,flag=0;
	T heavy;
	int size=FIN;
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

//anade elementos uno tras de otro
template <class T>
int Cola_Array<T>::agregar(T &obj){
	if(FIN==TAM)return -1 ;//esta lleno
	FIN++;
	v[FIN]=obj;
	return 1;//agregado con exito
}

//metodo que elimina y retorna 1 si fue con exito
//o -1 si no se logro, el elemento eliminado
//queda guardado en el parametro que recibe
template <class T>
int Cola_Array<T>::eliminar(T &obj){
	if(FIN==-1)return -1; //esta vacia
	obj=v[0];
	FIN--;
	for(int i=0;i<=FIN ;i++){
		v[i]=v[i+1];
	}
	return 1;//eliminado con exito
}

//metodo que elimina y retorna el ELEMENTO eliminado
template <class T>
T Cola_Array<T>::eliminar(){
	T obj;
	if(FIN==-1)return NULL; //esta vacia
	obj=v[0];
	FIN--;
	for(int i=0;i<=FIN ;i++){
		v[i]=v[i+1];
	}
	return obj;//eliminado con exito
}

//imprime una seguida de otra
template <class T>
void Cola_Array<T>::imprimir(){
	if(FIN==-1){
		cout<<"cola empty"<<endl;
		return;
	} 
	for(int i=0;i<=FIN;i++){
			cout<<"\t"<<v[i]<<" ";
	}
	cout<<endl;
}

//imprime de forma ascendente
template <class T>
void Cola_Array<T>::imprimirColaPosicion(){
	//cout<<"FIN COLA: "<<FIN<<endl;
	for(int i=0;i<=FIN;i++){
		cout<<"cola["<<i+1<<"] = "<<v[i]<<endl;
	}
}

//imprime la informacion de una clase
//para ello debo tener el metodo informacion en cada clase
template <class T>
void Cola_Array<T>::imprimirClase(){
	for(int i=0;i<=FIN;i++){
		v[i].informacion();
	}
}

#endif
