#include "Persona.h"

Persona::Persona()
{
}

Persona::Persona(int tarjeta, string titular, string saldo)
{
	
	this->tarjeta=tarjeta;
	this->titular=titular;
	this->saldo=saldo;
}




string Persona::getTitular(){
	return titular;
}

int Persona::getTarjeta(){
	return tarjeta;
}

string Persona::getSaldo(){
	return saldo;
}

void Persona::setTitular(string titular){
	 this->titular=titular;
}

void Persona::setSaldo(string saldo){
	 this->saldo=saldo;
}

void Persona::setTarjeta(int tarjeta){
	 this->tarjeta=tarjeta;
}
