#include <string>
#ifndef PERSONA_H
#define PERSONA_H

using namespace std;

class Persona
{
	
	private:
		int tarjeta;
		string titular;
		string saldo;
	public:
		Persona();
		Persona(int tarjeta, string titular, string saldo);
		
		int getTarjeta();
		string getTitular();
		string getSaldo();
		
		void setTarjeta(int tarjeta);
		void setSaldo(string saldo);
		void setTitular(string titular);
};

#endif
