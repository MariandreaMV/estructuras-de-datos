/*
*	Pedro Labrador ci: 25587776
*	Mariandrea Maldonado ci: 24693522
*	
*/
#include <iostream>
#include "Colas_dinamicas.h"
#include "Pilas_dinamicas.h"
#include "Bicola.h"
using namespace std;

int main(int argc, char** argv) {
	
	Pilas_dinamicas<int> *obj1 = new Pilas_dinamicas<int>();
	Colas_dinamicas<int> *obj2 = new Colas_dinamicas<int>();											 
	Colas_dinamicas<int> *obj3 = new Colas_dinamicas<int>();
	Bicola<int>			 *obj  = new Bicola<int>();
	
	obj1->Anadir(11); obj1->Anadir(19); obj1->Anadir(16); obj1->Anadir(13);
	cout << "Obj1: "; obj1->Imprimir(); cout << endl;
	obj2->Anadir(18); obj2->Anadir(15); obj2->Anadir(11); 
	cout << "Obj2: "; obj2->Imprimir(); cout << endl;
	obj3->Anadir(17); obj3->Anadir(24); obj3->Anadir(19); obj3->Anadir(16);
	cout << "Obj3: "; obj3->Imprimir(); cout << endl;
	obj3->concat(*obj2);
	cout << endl << "Concatenando obj2 con obj3: "; obj3->Imprimir(); cout << endl;
	cout << endl << "invirtiendo obj3: "; obj3->invert();obj3->Imprimir(); cout << endl;
	
	while (!obj1->isVacia()) {
		int primo = 0;
		int num = obj1->Leer();
		cout<<endl<<num<<endl;
		for (int i = 2; i <= num; i++) 
			if (num % i == 0)
				primo++;
		if (primo == 1)
			obj3->AnadirFinal(num);
	}
	cout << endl << "Agregando numeros primos de obj1 a obj3: "; obj3->Imprimir(); cout << endl;
	cout << endl << "Cambiando a Bicola: ";
	while(!obj3->isVacia()) {
		int actual = obj3->Leer();
		if (actual % 2 == 0)
			obj->push_back(actual);
		else
			obj->push_front(actual);
	}
	cout << endl << "Imprimiendo de Izq. a Der: "; obj->print();
	cout << endl << "Imprimiendo de Der. a Izq: "; obj->print2();
	
	
	return 0;
}
