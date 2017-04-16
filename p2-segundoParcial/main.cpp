#include "Practica2.h"

/*
		ESTRUCTURA DE DATOS.
		PRACTICA II SEGUNDO PARCIAL.
		MARIANDREA DE LA CONSOLACION MALDONADO VAZQUEZ.
		CI.V-24693522.

*/

int main(int argc, char** argv) {
	
	Practica2 p;
	int leer=p.leer();
	
	if(leer==-1){
		cout<<"no se pudo abrir el archivo estructuras"<<endl;
		return 0;
	}	
	
	return 0;
}

