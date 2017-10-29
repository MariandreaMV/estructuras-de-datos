#include <iostream>
#include "ArbolBB.h"


int main(int argc, char** argv) {
	
	ArbolBB<int> arbolBB,arbolBB2;
	arbolBB.Agregar(20);
	arbolBB.Agregar(10);
	arbolBB.Agregar(9);
	arbolBB.Agregar(11);
	arbolBB.Agregar(2);
	arbolBB.Agregar(3);
	arbolBB.Agregar(1);
	arbolBB.Agregar(0);
	arbolBB.Agregar(26);
	arbolBB.Agregar(24);
	arbolBB.Agregar(40);
	arbolBB.Agregar(34);
	arbolBB.Agregar(27);
	arbolBB.Agregar(36);
    arbolBB.Agregar(33);
	arbolBB.Agregar(70);
	arbolBB.Agregar(60);
	arbolBB.Agregar(72);
	arbolBB.Agregar(58);
	arbolBB.Agregar(59);
	arbolBB.Agregar(61);
	arbolBB.Agregar(72);
	arbolBB.Agregar(57);
	arbolBB.Agregar(56);
	arbolBB.Agregar(55);
	arbolBB.imprimir();
	cout<<"\n cantidad de niveles: "<<arbolBB.getCantNiveles()<<endl;
	int a=40;
	arbolBB.Eliminar(a);
	a=57;
	arbolBB.Eliminar(a);
	a=59;
	arbolBB.Eliminar(a);
	a=20;
	arbolBB.Eliminar(a);
	a=56;
	arbolBB.Eliminar(a);
	
	arbolBB.imprimir();
	cout<<"\n cantidad de niveles: "<<arbolBB.getCantNiveles()<<endl;
	
	arbolBB2.Agregar(20);
	arbolBB2.Agregar(26);
	arbolBB2.Agregar(10);
	arbolBB2.Agregar(9);
	arbolBB2.Agregar(11);
	arbolBB2.Agregar(40);
	arbolBB2.Agregar(2);

//	arbolBB2.imprimir();
	cout<<endl;
	if(arbolBB.CompararArbolesEstructura(arbolBB2) )cout<<"IGUALES en estructura"<<endl;
	else cout<<"DIFERENTES en estructura"<<endl;


	return 0;
}
