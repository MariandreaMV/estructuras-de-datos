#ifndef LISTADOBLEENLAZADA_H
#define LISTADOBLEENLAZADA_H
#include "node.h"

template <class t>
class ListaDobleEnlazada
{
	private:
		node<t> *cabecera; 
	public:
		ListaDobleEnlazada(){cabecera =NULL;}
		int agregar (t elemento);
		int eliminar(t elemento);
		void imprimir();
		
};

template <class t>
int ListaDobleEnlazada<t>::agregar(t elemento){
	
	node<t> *nuevo=new node<t>(elemento);
	node<t> *p=cabecera;
	node<t> *antp;
	
	if(!nuevo) return 0;
	while(p){
		if(nuevo->getInfo()<p->getInfo()) break;
		antp=p;
		p=p->getnext();
	}
	nuevo->setNext(p);
	if(p==cabecera){
		//insercion en cabecera
		if(cabecera) cabecera->setPrevious(nuevo);
		cabecera=nuevo;
	}else{
		if(p){
			//insercion entre dos nodos
			p->getPrevious()->setNext(nuevo);
			nuevo->setPrevious(p->getPrevious());
			p->setPrevious(nuevo);
		}else{
			//insercion al final
			    nuevo->setPrevious(antp);
			    antp->setNext(nuevo);
		}
	
	}
	return 1;
}

template <class t> 
void ListaDobleEnlazada<t>::imprimir(){
	
	node<t> *imprime= cabecera;
	
	 while(imprime){
	 	cout<<imprime->getInfo()<<endl;
	 	imprime=imprime->getnext();
	 }
	
	
}


#endif
