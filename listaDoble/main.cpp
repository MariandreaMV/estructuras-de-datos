#include <iostream>
#include "ListaDobleEnlazada.h"

int main(int argc, char** argv) {
	
	ListaDobleEnlazada<int> *doble= new ListaDobleEnlazada<int>();
	
	doble->agregar(4);
	doble->agregar(5);
	doble->agregar(3);
	doble->agregar(4);
	doble->agregar(5);
	doble->agregar(3);
	
	doble->imprimir();

	return 0;
}
