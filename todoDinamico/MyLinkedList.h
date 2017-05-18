
#ifndef MYLINKEDLIST_H
#define MYLINKEDLIST_H
#include <iostream>
#include <stdlib.h>
#include "node.h"
#include "Pila_Array.h"

using namespace std;

template <class t>
class MyLinkedList{	

private:
	
	node<t>* head;
	int size;
	
public:
	
	MyLinkedList();
	void convertirColaArray_Lista(Cola_Array<t> cola);
	void convertirPila_Lista(Pila_Array<t> pila);
	void agregarPrimero(t elemento);
	void agregar(t element);
	void agregarOrdenado(t element);
	void eliminarPrimero(t &eliminado);
	void eliminarUltimo(t &eliminado);
	void eliminarElemento(t eliminar);	
  	void Revertir(); 	
 	void sort();
 	void imprimir();
  	int getSize(){ return size; }
  	bool isEmpty();
  	t getCabeza(){ return head->getInfo(); }
	node<t>* lastNode();
	node<t>* search(t element);
	Cola_circular<t> getColaCircular();
	Cola_Array<t> getCola();
  	Pila_Array<t> getPila();
	MyLinkedList<t> operator + (MyLinkedList<t> otro);
  	MyLinkedList<t> operator - (MyLinkedList<t> otro);
  	
  	
};

//metodo que recibe una cola array y se convierte en esta lista
template<class t>
void MyLinkedList<t>::convertirColaArray_Lista(Cola_Array<t> cola){
	
	int tam=cola.getFinCola();
	for(int i=0;i<tam;i++){
		t eliminado;
		cola.eliminar(eliminado);
		this->agregar(eliminado);
	}
	
}

//metodo que recibe una pila y se convierte en esta lista
template<class t>
void MyLinkedList<t>::convertirPila_Lista(Pila_Array<t> pila){
	
	int tam=pila.getTopePila();

	for(int i=0;i<tam;i++){
		t eliminado;
		pila.eliminar(eliminado);
		cout<<"eliminado: "<<eliminado<<endl;
		this->agregar(eliminado);
	}
	this->Revertir();
}

//retorno una cola circular con los datos de esta lista
template<class t>
Cola_circular<t> MyLinkedList<t>::getColaCircular(){
	
	Cola_Array<t> resultante;
	Cola_circular<t> salida;
	resultante=this->getCola();
	salida=resultante.getColaCircular();
	return salida;
}

//retorna la lista convertida en pila
template<class t>
Pila_Array<t> MyLinkedList<t>::getPila(){
	
	int n=0;
	int tam=this->size;
	Pila_Array<t> retorno(tam);
	
	while(n<tam){
		t eli;
		this->eliminarPrimero(eli);
		///	cout<<eli<<endl;
		retorno.agregar(eli);
		n++;
	}
	return retorno;
}

//retorna la lista convertida en cola
template<class t>
Cola_Array<t> MyLinkedList<t>::getCola(){
		
	int n=0;
	int tam=this->size;
	Cola_Array<t> retorno(tam);
	
	while(n<tam){
		t eli;
		this->eliminarPrimero(eli);
		///	cout<<eli<<endl;
		retorno.agregar(eli);
		n++;
	}
	return retorno;
}

//constructor inicializa valores
template <class t>
MyLinkedList<t>::MyLinkedList(){
  head = NULL;
  size=0;
}

//retorna TRUE en caso de que la lista este vacia
template <class t>
bool MyLinkedList<t>::isEmpty(){
  return (head == NULL)? true : false;
}

//invierte mi lista
template <class t>
void MyLinkedList<t>::Revertir(){
		int n=0;
		int tam=size;
		t m[tam];		
		while(n<tam){
			t eli;
			this->eliminarUltimo(eli);
			m[n]=eli;
			n++;
		}	
		n=0;
		while(n<tam){
			t eli;
			eli=m[n];
			this->agregar(eli);
			n++;
		}		
}

//ordena mi lista actual
template <class t>
void MyLinkedList<t>::sort(){
	int n=0;
	int tam=this->size;
		t m[tam];
		while(n<tam){
			t eli;
			this->eliminarUltimo(eli);
			m[n]=eli;
			n++;
		}		
		n=0;
		while(n<tam){
			t eli;
			eli=m[n];
			this->agregarOrdenado(eli);
			n++;
		}		
}

//agrega el elemento de primero en la lista,
//es decir pasa a ser la cabecera
template <class t>
void MyLinkedList<t>::agregarPrimero(t elemento){
  node<t>* newNode;
  newNode = new node<t>;
  newNode->setInfo(elemento);
  newNode->setNext(head);
  head = newNode;
  size++;
}

//retorna el ultimo NODO de la lista
template <class t>
node<t>* MyLinkedList<t>::lastNode(){
  node<t>* p = head;
  if (!p) {
    //cout << "List is empty" << endl;
    return NULL;
  }
  while (p->getnext() != NULL) {
    p = p->getnext();
  }
  return p;
}

//intercala dos listas, retorna la lista resultante
//de acabarse una, la otra termina de pasarse
template <class t>
MyLinkedList<t> MyLinkedList<t>::operator - (MyLinkedList<t> otro){
	
	int g= this->size + otro.getSize();
	MyLinkedList<t> resultado;
	int n=0;
	int n1=0,n2=0;
	int tam1=this->size,tam2=otro.getSize();
	bool band=true;
	
	while(n < g){
		t eli;
		if(band==true&&n1<tam1){
			this->eliminarPrimero(eli);
			resultado.agregar(eli);
			n1++;band=false;
			n++;
		}else{
			if(n2<tam2){
				otro.eliminarPrimero(eli);
				resultado.agregar(eli);
				n2++;
				n++;
			}
			band=true;	
		}				
	}
	return resultado;
}

//metodo que concatena dos listas
//una seguida de la otra y retorna 
//una lista resultante
template <class t>
MyLinkedList<t> MyLinkedList<t>::operator+(MyLinkedList<t> otro){

	MyLinkedList<t> resultado;
	
	int n=0;
	int tam1=this->size;
	int tam2= otro.getSize();
	while(n<tam1){
		t eli;
		this->eliminarPrimero(eli);
	 	resultado.agregar(eli);
		n++;
	}
	n=0;
	while(n<tam2){
		t eli;
		otro.eliminarPrimero(eli);
		resultado.agregar(eli);
		n++;
	}

	return resultado;	
}

//agrega en la ultima posicion el elemento
template <class t>
void MyLinkedList<t>::agregar(t element){
	
	if(head==NULL){
	  node<t>* newNode;
	  newNode = new node<t>;
	  newNode->setInfo(element);
	  head = newNode;
	}else{
	
	  node<t>* last = this->lastNode();
	  node<t>* newNode;
	  newNode = new node<t>();
	  newNode->setInfo(element);
	  last->setNext(newNode);
	}
	size++;
}


//este metodo elimina la cabecera, el elemento eliminado queda
//guardado en la variable que paso por referencia
// si la lista esta vacia el eliminado es -1
//y se va actualizando el tamano de la lista
template <class t>
void MyLinkedList<t>::eliminarPrimero(t &eliminado){

	node<t>* aux = head;
	
	if (!aux) {
    	cout << "List is empty" << endl;
    	size=0;
    	eliminado=-1;
		return;
	}
	eliminado=head->getInfo();
	head = head->getnext();
	delete aux;
	if(!head){
	//	cout<<"lista quedo vacia entonces no tiene cabecera"<<endl;
		size=0;
		return;
	}else{
		size--;
  		return;
	}
}

//elimina el ultimo elemento de la pila 
//si la pila esta vacia entonces el elemento que guarda la variable 
//eliminada (el que envio por referencia) es -1
//de igual forma va actualizando el tamano de la pila
template <class t>
void MyLinkedList<t>::eliminarUltimo(t &eliminado){
  
	node<t>* aux;
	node<t>* p = head;
  
	if (!p) {
    cout << "List is empty" << endl;
    eliminado=-1;
    size=0;
    return;
 	}
	if(head->getnext() == NULL){
	//	cout<<"quedo vacia la lista"<<endl;
		eliminado=head->getInfo();
		head = NULL;
		size=0;
		return;
	}
	while (p->getnext()->getnext()!= NULL) {
		p = p->getnext();
    
	}	
	aux = p->getnext();
	size--;
	eliminado=aux->getInfo();
	p->setNext(NULL);
	delete aux;
}

//este metodo elimina el elemento que le envia por parametro
//si lo encuentra se modifica la lista y el que queria eliminar
//lo elimina
template<class t>
void MyLinkedList<t>::eliminarElemento(t eliminar){

	node<t>* p=head;
	node <t>* anterior=NULL;
	if (!p) {
		// cout << "List is empty" << endl;
		return;
	}
	for(p = head; p != NULL; p = p->getnext()){
	//	cout<<"p info= "<<(p->getInfo())<<" eliminar: "<<eliminar<<endl;
		if (p->getInfo() == eliminar) {
		//	cout<<"lo entontro"<<endl;
			if(anterior==NULL){
				head=p->getnext();
				size--;
				delete p;
				return;
			}
			anterior->setNext(p->getnext());
			size--;
			delete p;
      		return;
   		}
   		anterior=p;
  	}
  return;
	 
}

//retorna el elemento buscado
//el nodo perteneciente a ese contenido
template <class t>
node<t>* MyLinkedList<t>::search(t element){
  node<t>* p;

  if (!p) {
   // cout << "List is empty" << endl;
    return NULL;
  }
  for(p = head; p != NULL; p = p->getnext()){
    if (p->getInfo() == element) {
      return p;
    }
  }
  return NULL;
}

//va agregando los elementos de forma ascendente
template <class t>
void MyLinkedList<t>::agregarOrdenado(t element){
  node<t>* newNode = new node<t>(element);
  size++;
  if (!head) {
    head = newNode;
  }
  else if (head->getInfo() > element) {
    newNode->setNext(head);
    head = newNode;
  }
  else{
    node<t> *previous, *p;
    previous = p = head;
    while (p->getnext() != NULL && element > p->getInfo()) {
      previous = p;
      p = p->getnext();
    }
    if (element > p->getInfo()) {
      previous = p;
    }

    newNode->setNext(previous->getnext());
    previous->setNext(newNode);
  }
}

//imprime la lista
template <class t>
void MyLinkedList<t>::imprimir(){
  node<t>* p;
  p = head;
  if (!p) {
    cout << "List is empty" << endl;
    return;
  }
  for(p = head; p != NULL; p = p->getnext()){
    cout <<"\t"<< p->getInfo() <<" ";
  }
  cout<<endl;
}


#endif
