#include "Persona.h"

Persona::Persona()
{
}

Persona::Persona(char *ced, string nom)
{
	cedula=atoi(ced);//transforma char* a entero
	strcpy(nombre,nom.c_str());//transforma string a char [n]
}

void Persona::setCedula( string ced ){
	cedula=atoi(ced.c_str());
}

void Persona::setNombre( string nom){
	strcpy(nombre,nom.c_str());
}

void Persona::imprime(){
	string aux=nombre;
	cout<<"cedula: "<<cedula<<"\t\tnombre: "<<aux<<endl;
}
