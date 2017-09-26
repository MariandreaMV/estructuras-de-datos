#ifndef LISTAENLAZADA_H
#define LISTAENLAZADA_H
#include <iostream>
using namespace std;

#define ASCENDENTE 1
#define DESCENDENTE 0

template<class T> class ListaDobEnlazada;

template<class T>
class Nodo {
	private:
		T valor;
		Nodo<T> *siguiente;
		Nodo<T> *anterior;
	public:
		Nodo(T v, Nodo<T> *sig = NULL, Nodo<T> *ant = NULL) :
		valor(v), siguiente(sig), anterior(ant) {}
	friend class ListaDobEnlazada<T>;
};

template<class T>
class ListaDobEnlazada {
	private:
		Nodo<T> *plista;
	public:
		ListaDobEnlazada() : plista(NULL) {}
		~ListaDobEnlazada();
		void Anadir(T v);
		void Eliminar(T v);
		bool isVacia() { return plista == NULL; }
		void Imprimir(int);
		void Siguiente();
		void Anterior();
		void Primero();
		void Ultimo();
		bool Actual() { return plista != NULL; }
		T ValorActual() { return plista->valor; }
};

template<class T>
ListaDobEnlazada<T>::~ListaDobEnlazada()
{
	Nodo<T> *aux;
	Primero();
	while(plista) {
		aux = plista;
		plista = plista->siguiente;
		delete aux;
	}               
}

template<class T>
void ListaDobEnlazada<T>::Anadir(T v)
{
	Nodo<T> *nuevo;
	
	Primero();
	if(isVacia() || plista->valor > v) {
		nuevo = new Nodo<T>(v, plista);
		if(!plista)
			plista = nuevo;
		else 
			plista->anterior = nuevo;
	} else {
		while(plista->siguiente && plista->siguiente->valor <= v)
			Siguiente();
		nuevo = new Nodo<T>(v, plista->siguiente, plista);
		plista->siguiente = nuevo;
		if(nuevo->siguiente) 
			nuevo->siguiente->anterior = nuevo;
	}
}

template<class T>
void ListaDobEnlazada<T>::Eliminar(T v)
{
	Nodo<T> *pNodo;
	
	pNodo = plista;
	while(pNodo && pNodo->valor < v) 
		pNodo = pNodo->siguiente;
	while(pNodo && pNodo->valor > v) 
		pNodo = pNodo->anterior;
	if(!pNodo || pNodo->valor != v) 
		return;
	if(pNodo->anterior)
		pNodo->anterior->siguiente = pNodo->siguiente;
	if(pNodo->siguiente)
		pNodo->siguiente->anterior = pNodo->anterior;
}

template<class T>
void ListaDobEnlazada<T>::Imprimir(int orden)
{
	Nodo<T> *pNodo;
	if(orden == ASCENDENTE) {
		Primero();
		pNodo = plista;
		while(pNodo) {
			cout << pNodo->valor << " ";
			pNodo = pNodo->siguiente;
		}
	} else {
		Ultimo();
		pNodo = plista;
		while(pNodo) {
			cout << pNodo->valor << " ";
			pNodo = pNodo->anterior;
		}
	}
}

template<class T>
void ListaDobEnlazada<T>::Siguiente()
{
	if(plista) 
		plista = plista->siguiente;
}

template<class T>
void ListaDobEnlazada<T>::Anterior()
{
	if(plista) 
		plista = plista->anterior;
}

template<class T>
void ListaDobEnlazada<T>::Primero()
{
	while(plista && plista->anterior) 
		plista = plista->anterior;
}

template<class T>
void ListaDobEnlazada<T>::Ultimo()
{
	while(plista && plista->siguiente) 
		plista = plista->siguiente;
}
#endif
