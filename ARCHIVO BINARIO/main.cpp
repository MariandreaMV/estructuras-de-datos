#include <iostream>
#include "ArchivoBinario.h"
#include "Datos.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	ArchivoBinario<Datos> datosIN("Datos.dat","in");
	Datos dat;
	
	datosIN.abrir();
	datosIN.tamanio();
	cout<<endl;
	while(true){
		datosIN.leer(dat);
		if(datosIN.isFinal())break;
		dat.imprimir();
	}
	
	datosIN.cerrar();
	cout<<endl;
	
	
	
	return 0;
}
