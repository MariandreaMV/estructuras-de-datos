#ifndef Bicola_H
#define Bicola_H
#include <iostream>
using namespace std;

template<class T> class Bicola;

template<class T>
class nod {
	private:
		T valor;
		nod<T> *sucesor, *predecesor;
	public:
		nod(T v, nod<T> *sig = NULL, nod<T> *ant = NULL) {
			valor = v;
			sucesor = sig;
			predecesor = ant;
		}
		void setValor(T val){ valor = val; }
		T getValor(){ return valor; }
		void setSucesor(nod<T> *p){ sucesor=p; }
		nod<T> *getSucesor(){ return sucesor; }
		void setPredecesor(nod<T> *p){ predecesor=p; }
		nod<T> *getPredecesor(){ return predecesor; }
	friend class Bicola<T>;
};

template<class T>
class Bicola {
	private:
		nod<T> *first, *last;
		int nNodes;
	public:
		Bicola() : first(NULL), last(NULL), nNodes(0) {}
		~Bicola();
		bool isEmpty();
		void push_front(T);
        void push_back(T);
		T pop_front();
        T pop_back();
		void print();
		void sort();
};

template<typename T>
void Bicola<T>::sort()
{
    T temp_data;
    nod<T> *aux_node = first;
    nod<T> *temp = aux_node;

    while (aux_node) {
        temp = aux_node;
        while (temp->getSucesor()) {
            temp = temp->getSucesor();
            if (aux_node->getValor() > temp->getValor()) {
                temp_data = aux_node->getValor();
                aux_node->setValor(temp->getValor());
                temp->setValor(temp_data);
            }
        }
        aux_node = aux_node->getSucesor();
    }
}
template<class T>
bool Bicola<T>::isEmpty()
{
	nod<T> *p = first;
	if(!p)
		return true;
	return false;
}
template<typename T>
void Bicola<T>::push_front(T data_)
{
    nod<T> *new_nod = new nod<T> (data_);
    nod<T> *temp = first;

    if (!first) {
        first = new_nod;
    } else {
        temp->setPredecesor(new_nod);
        new_nod->setSucesor(first);
        first = new_nod;
        while (temp->getSucesor() != NULL) {
            temp = temp->getSucesor();
        }
        last = temp;
    }
    nNodes++;
}

template<typename T>
void Bicola<T>::push_back(T data_)
{
    nod<T> *new_nod = new nod<T> (data_);
    nod<T> *temp = first;
    nod<T> *curr;

    if (!first) {
        first = new_nod;
    } else {
        while (temp->getSucesor() != NULL) {
            curr = temp;
            temp = temp->getSucesor();
            temp->setPredecesor(curr);
            new_nod->setPredecesor(temp);
        }
        temp->setSucesor(new_nod);
        last = new_nod;
    }
    nNodes++;
}

template<class T>
T Bicola<T>::pop_front()
{
    nod<T> *nod;
    T v;
    nod = first;
    if(!nod)
        return 0;
    first = nod->getSucesor();
    v = nod->getValor();
    delete nod;
    nNodes--;
    if(!first)
        last = NULL;
    return v;
}
template<class T>
T Bicola<T>::pop_back()
{
    nod<T> *nod;
    T v;
    if(!last)
        return 0;
    nod = last;
    last = nod->getSucesor();
    v = nod->getValor();
    delete nod;
    nNodes--;
    return v;
}
template<class T>
void Bicola<T>::print()
{
	nod<T> *p = first;
	while(p){
		cout << p->getValor() << " ";
		p = p->getSucesor();
	}
}
template<class T>
Bicola<T>::~Bicola()
{
	while(first)
		pop_front();
	nNodes = 0;
}
#endif
