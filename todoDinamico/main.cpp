#include <iostream>
#include "MyLinkedList.h"
using namespace std;

int main(int argc, char** argv) {
	
	Pila_Array<string> pila(5);
	Cola_Array<string> cola(5);
	MyLinkedList<string> lista;
	
	string a="maria";
	string b="jose";
	string c="freddy";
	string m="zai";
	
	pila.agregar(a);
	pila.agregar(b);
	pila.agregar(c);
	pila.agregar(b);
	pila.agregar(c);

	
	cola.agregar(b);
	cola.agregar(c);
	cola.agregar(m);
	cola.agregar(a);
	
	cola.imprimir();
	cola.sort();
	cout<<"ordenado"<<endl;
	cola.imprimir();
	
	
	
	
	return 0;
}
