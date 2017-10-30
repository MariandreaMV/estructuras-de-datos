#ifndef OPERACION_H
#define OPERACION_H
#include <typeinfo>
#include "MyLinkedList.h"


template <class T>
class Operacion
{	
	private:
		string accion, tipo,original,tipoD;
		T elemento1, elemento2,final;
		
	public:
		Operacion( T element1, T element2 ,string ac,string tip,string ori,string tipD);
		Operacion(T element1,string ac,string tip,string ori,string tipD);
		
		void concatenar();
		void mezclar();
		
		void revertir();
		void ordenar();
		void convertir();
		T getEstructura();
		
	protected:
};


template<class T>
void Operacion<T>::convertir(){
	final=elemento1;
}

template<class T>
T Operacion<T>::getEstructura(){
	
//	final.imprimir();
//	cout<<endl;
	return final;

}

template<class T>
Operacion<T>::Operacion(T element1, T element2,string ac,string tip,string ori,string tipD){
	original=ori;
	accion=ac;
	tipo=tip;
	this->tipoD=tipD;
	elemento1=element1;
	elemento2=element2;
	/*
	cout<<"elemento 1: "<<endl;
	elemento1.imprimir();
	cout<<endl;
	cout<<"elemento 2: "<<endl;
	elemento2.imprimir();
	cout<<endl;	
	*/
	if(accion=="concatenar") concatenar();
	if(accion=="mezclar") mezclar();
}

template<class T>
Operacion<T>::Operacion(T element,string ac,string tip,string ori,string tipD){
	original=ori;
	accion=ac;
	tipo=tip;
	this->tipoD=tipD;
	elemento1=element;
	/*
	cout<<"unico elemento: "<<endl;
	elemento1.imprimir();*/
	if(accion=="revertir") revertir();
	if(accion=="ordenar") ordenar();
	if(accion=="convertir") convertir();
	cout<<endl;
}

template<class T>
void Operacion<T>::concatenar(){	//concatena lo que sea, listas,colas o pilas.

	cout<<endl;
	cout<<"ELEMENTOS CONCATENADOS"<<endl;
	
	T resultante;
	
	int tamanio=elemento1.getsize()+elemento2.getsize();
	resultante= elemento1 + elemento2 ;//sobrecargue el operados + para concatenar las dos estructuras del mismo tipo;
	
	resultante.imprimir();
	final=resultante;
	cout<<endl;
}

template <class T>
void Operacion<T>::ordenar(){
	
	cout<<endl;
	elemento1.sort();
	cout<<"ELEMENTO ORDENADO: "<<endl;
	elemento1.imprimir();
	cout<<endl;
	final=elemento1;
	
}


template <class T>
void Operacion<T>::mezclar(){
	
	cout<<endl;
	T resultado;
	resultado=elemento1-elemento2;//sobrecargue el operador - para mezclar las dos estructuras del mismo tipo;
	cout<<"ELEMENTOS MEZCLADOS"<<endl;
	resultado.imprimir();
//	cout<<"termino de mezclar"<<endl;
	final=resultado;
	cout<<endl;
}

template<class T>
void Operacion<T>::revertir(){
 	
	cout<<endl;
	elemento1.Revertir();
	cout<<"ELEMENTO AL REVERSO: "<<endl;
	elemento1.imprimir();
	final=elemento1;
}
#endif
