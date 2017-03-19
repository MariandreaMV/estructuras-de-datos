#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Persona.h"
#include "Archivo.h"
#include <windows.h>
using namespace std;


int main (){
	
	// reading from a file  -------------------
	fstream archivoBinario;
	archivoBinario.open("DATOSBINARIOS.dat",ios::out|ios::binary);
	char STRING[30];
	vector <Persona*> registro;
	Archivo* txt = new Archivo("DATOS.txt");
	txt->abrir();
	
	int i=0;//tamanio del vector
	
	if(archivoBinario.fail())
	cout<<"error opening the binary file"<<endl;
	
	
	//------leo archivo de texto--------------------------------
		while(true){
			
			if( txt->isFinal()){
				break;
			}
			
			Persona *auxPersona= new Persona();
			string* buffer;
			
			buffer = txt->leerCampos( ',', 2 );
			auxPersona->setCedula( buffer[0] );
			auxPersona->setNombre( buffer[1] ); 
		//	cout << buffer[0] << ',' << buffer[1] << endl;
			
			//system("PAUSE");
			
			registro.push_back(auxPersona);
		}	
	txt->~Archivo();
	
	for(int n=0;n<registro.size();n++){
		registro[n]->imprime();
	}
	
	//-------------termino de leer y cargar ----------------------
	for(int n=0;n<registro.size();n++){
		archivoBinario.write((char*)&registro[n],sizeof(Persona));
	}
	archivoBinario.close();
	
	//------writing on a file binary -----------------------------

		
	//-----------------------------------------
	return 0;
}
