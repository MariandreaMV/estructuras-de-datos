#ifndef PERSONA_H
#define PERSONA_H
#include <stdlib.h>
#include <iostream>
#include <string.h>

//#include <ctype>
using namespace std;

class Persona
{
	private:
		int cedula;
		char nombre[30];
	public:
		Persona();
		Persona(char *ced, string nombre);	
		void setCedula(string cedula);
		void setNombre(string nom);
		void imprime();
	};

#endif
