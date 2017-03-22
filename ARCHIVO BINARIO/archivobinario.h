#ifndef ARCHIVOBINARIO_H
#define ARCHIVOBINARIO_H
#include <fstream>
#include <iostream>

using namespace std;

template <class T>
class ArchivoBinario{

	private:		
		fstream flujo;
		string nombre;
		string referencia;
	public: 
		ArchivoBinario( string nombre,string ref);
		void abrir();
		void cerrar();
		void escribir(T &obj);
		void leer(T &obj);
		int tamanio();
		bool isFinal();
		
};

template <class T>
ArchivoBinario<T>::ArchivoBinario(string nombre, string ref){
	this->nombre=nombre;
	this->referencia=ref;
}

template <class T>
void ArchivoBinario<T>::abrir(){
	if(referencia.compare("in")==0){
		flujo.open(nombre.c_str(), ios::in|ios::binary);
		
	}else{
		if(referencia.compare("out")!=0){
			flujo.open(nombre.c_str(),ios::out|ios::binary);
		}else{
			cout<<"no se pudo crear el archivo, es entrada o salida?"<<endl;
		}
	}
}

template <class T>
void ArchivoBinario<T>::cerrar(){
	if(flujo.is_open())
	flujo.close();
}

template <class T>
void ArchivoBinario<T>::escribir(T &obj){
		flujo.write((char *)&obj,sizeof(obj));
}

template <class T>
void ArchivoBinario<T>::leer(T &obj){
	flujo.read((char *)&obj,sizeof(obj));
}

template <class T>
bool ArchivoBinario<T>::isFinal(){
	return flujo.eof();
}

template <class T>
int ArchivoBinario<T>::tamanio(){
	flujo.seekg(0,ios::end);
	
	int total = flujo.tellg() /sizeof (T);
	cout<<total;
	
	flujo.seekg(0,ios::beg);
	return total;
}
#endif
