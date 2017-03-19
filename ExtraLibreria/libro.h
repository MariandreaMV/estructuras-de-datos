#ifndef LIBRO_H
#define LIBRO_H
#include <string.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

class Libro
{	
	private:
		
		int codigo;
		char titulo[30];
		char autor[30];
		char editorial[30];
	public:
		
		Libro();
		Libro(string cod, string titulo,string autor,string editorial);
		string getTitulo();
		string getAutor();
		string getEditorial();
		int getCodigo();
		void imprimir();
		
		bool operator < (Libro &libro2){
			string thisTitulo=titulo;
			string anotherTitulo=libro2.titulo;
			//cout<<thisTitulo<<" "<<anotherTitulo<<endl;
			if(thisTitulo.compare(anotherTitulo)<0)
			return true;
			else
			return false;
		}

};

#endif
