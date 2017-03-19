#include "libro.h"

Libro::Libro()
{
}

Libro::Libro(string cod, string tit,string aut,string edit){
	
	this->codigo=atoi(cod.c_str());
	strcpy(titulo,tit.c_str());
	strcpy(autor,aut.c_str());
	strcpy(editorial,edit.c_str());
}

string Libro::getTitulo()
{
	string tit=titulo;
	return tit;
}

string Libro::getAutor()
{
	string aut=autor;
	return aut;
}

int Libro::getCodigo()
{return codigo;
}


void Libro::imprimir()
{
	string edit,tit,aut;
	edit=editorial;
	tit=titulo;
	aut=autor;
	//cout<<"editorial\t titulo\t autor"<<endl;
	cout<<codigo<<"\t"<<edit<<"\t"<<tit<<"\t"<<aut<<endl;
}
