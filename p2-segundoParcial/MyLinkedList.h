
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
  void addHead(t element);
  void agregar(t element);
  node<t>* lastNode();
  node<t>* search(t element);
  void removeHead(t &eli);
  void eliminar(t &eli);
  void ordenar(t element);
  void imprimir();
  bool isEmpty();
  
  int getsize(){
  	return size;
  }
  
  int getSize(){
  	return size;
  }
  
  
  Cola_Array<t> getCola(){
		
		int n=0;
		cout<<endl;
		//cout<<"tamanio: "<<this->size<<endl;
		//this->imprimir();
		cout<<endl;
		
		Cola_Array<t> retorno(this->size);
			while(n<this->size){
				t eli;
				this->eliminar(eli);
			///	cout<<eli<<endl;
				retorno.agregar(eli);
				n++;
			}
			retorno.Revertir();
			
		return retorno;
	}
	
  
  void Revertir(); 	
  void sort();
  MyLinkedList<t> operator + (MyLinkedList<t> otro);
  
  MyLinkedList<t> operator - (MyLinkedList<t> otro){
			int g= this->size + otro.getsize();
			MyLinkedList<t> resultado;
			this->Revertir();
			otro.Revertir();
			int n=0;
			int n1=0,n2=0;
			bool band=true;//para el intercambio
			while(n < g){
				t eli;
				if(band==true&&n1<this->size){
				this->eliminar(eli);
				resultado.agregar(eli);
				n1++;band=false;
				n++;
				}else{
					if(n2<otro.getsize()){
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
  
};

template <class t>
MyLinkedList<t>::MyLinkedList(){
  head = NULL;
  size=0;
}

template <class t>
bool MyLinkedList<t>::isEmpty(){
  return (head == NULL)? true : false;
}

template <class t>
void MyLinkedList<t>::Revertir(){
		int n=0;
		t m[this->size];
		while(n<size){
			t eli;
			this->eliminar(eli);
			m[n]=eli;
			n++;
		}	
		n=0;
		int c=this->size-1;
		while(n<size){
			t eli;
			eli=m[c];c--;
			this->addHead(eli);
			n++;
		}		
}

template <class t>
void MyLinkedList<t>::sort(){
	int n=0;
		t m[this->size];
		while(n<size){
			t eli;
			this->eliminar(eli);
			m[n]=eli;
			n++;
		}		
		n=0;
		while(n<size){
			t eli;
			eli=m[n];
			this->ordenar(eli);
			n++;
		}		
}

template <class t>
void MyLinkedList<t>::addHead(t element){
  node<t>* newNode;
  newNode = new node<t>;
  newNode->setInfo(element);
  newNode->setNext(head);
  head = newNode;
}

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

template <class t>
MyLinkedList<t> MyLinkedList<t>::operator+(MyLinkedList<t> otro){
	MyLinkedList<t> resultado;
	t a1[this->size];
	t a2[otro.getsize()];
	int n=0;
	while(n<this->size){
		t eli;
		this->eliminar(eli);
		a1[n]=eli;
		n++;
	}
	n=0;
	while(n<this->size){
		t eli;
		eli=a1[n];
	 	resultado.addHead(eli);
		n++;
	}
	
	n=0;
	int c=otro.getsize()-1;
	while(n<otro.getsize()){
		t eli;
		otro.eliminar(eli);
		a2[c]=eli;c--;
		n++;
	}
	n=0;c=0;
	while(n<otro.getsize()){
		t eli;
		eli=a2[n];c++;
	 	resultado.agregar(eli);
		n++;
	}
	return resultado;	
}

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

template <class t>
void MyLinkedList<t>::removeHead(t &eli){
  node<t>* aux = head;
  if (!aux) {
    //cout << "List is empty" << endl;
    return;
  }
  head = head->getnext();
  eli=head->getInfo();
  delete aux;
}

template <class t>
void MyLinkedList<t>::eliminar(t &eli){
  node<t>* aux,anterior;
  
   node<t>* p = head;
  
  if(head->getnext() == NULL){
    eli=head->getInfo();
	head = NULL;
    
    return;
  }
  while (p->getnext()->getnext()!= NULL) {
	p = p->getnext();
    
  }
	
  aux = p->getnext();
  eli=aux->getInfo();
 
  p->setNext(NULL);
  
  delete aux;
}

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

template <class t>
void MyLinkedList<t>::ordenar(t element){
  node<t>* newNode = new node<t>(element);
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

template <class t>
void MyLinkedList<t>::imprimir(){
  node<t>* p;
  p = head;
  if (!p) {
   // cout << "List is empty" << endl;
    return;
  }
  for(p = head; p != NULL; p = p->getnext()){
    cout <<"\t"<< p->getInfo() <<" ";
  }
}




#endif
