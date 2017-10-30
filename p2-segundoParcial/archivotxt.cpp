#include "archivotxt.h"
#include <iostream>

using namespace std; 

ArchivoTXT::ArchivoTXT( string n ) : nombre( n ) {}

ArchivoTXT::~ArchivoTXT()
{
	if( this->flujo.is_open() ) 
		this->flujo.close();
}

string ArchivoTXT::getNombre() const
{
	return this->nombre;  
}

	
/**
 *	@return	true apertura correcta, false error l�gico
 */ 
bool ArchivoTXT::abrir() 
{
	this->flujo.open( this->nombre.c_str(), fstream::in ); 
	return !this->flujo.fail();
} 

/*
 *	@return	string linea del archivo asociado leida
 */
string ArchivoTXT::leerLinea()
{
	string* linea = new string();
	getline( this->flujo, *linea, '\n' );
	return *linea; 
} 

/*
 *	@param	const char caracter a eliminar en la cadena
 *	@return	string contenido de la linea del archivo leida, 
 *	si se esta en el final del archivo retorna una cadena vacia
 */
 string ArchivoTXT::leerLinea( const char elim )
 {
	string* linea = new string();   
	string* buffer = new string();      
     
	while( !this->flujo.eof() && !this->isFinLinea( elim ) )  
	{
		getline( this->flujo, *buffer, elim );  
		*linea += *buffer; // concatena subcadenas sin el caracter especificado
	}
	
	// si no se lleg� al fin del archivo(se llego al fin de linea)
	if( !this->flujo.eof() )  
	{
		getline( this->flujo, *buffer, '\n' ); 
		*linea += *buffer; // concatena ultima subcadena a la cadena a retornar
	}
	
	delete buffer; 
	return *linea; // retorna la cadena sin el caracter especificado
 }
 
 
/**
 *	@brief lee un campo del archivo asociado hasta un caracter 
 *	delimitador especificado
 *	@since 1.0
 *	@param	const char delimitador para la lectura del campo
 *	@return	string campo leido en el archivo asociado,
 *	si se esta en el final del archivo retorna una cadena vacia
 */
 string ArchivoTXT::leerCampo( const char delim )
 {
	string* campo = new string();  	
	
	if( !this->flujo.eof() ) 
		if( this->isFinLinea( delim ) ) 
			getline( this->flujo, *campo, '\n' ); 
		else 
			getline( this->flujo, *campo, delim ); // leo campo hasta delimitador especificado
	return *campo;  // retorno campo leido del arhcivo asociado
 }
 
 
 /**
 *	@brief lee los n campos en una linea del archivo asociado, 
 *	separados por un caracter delimitador especificado y los
 *	retorna por separado en un arreglo de cadenas
 *	@since 1.0
 *	@param	const char delimitador para la lectura de los campos
 *	@param	const unsigned int numero de campos a leer en la linea
 *	@return	string* campos leidos de la linea en el archivo asociado
 */
 string* ArchivoTXT::leerCampos( const char delim, const unsigned int num_campos )
 {
	string* campos = new string[num_campos];
	
	for( int campo = 0; campo < num_campos; campo++ )
		getline( this->flujo, campos[campo],( campo == num_campos - 1 ? '\n' : delim ) ); 		
		
	return campos; 
 }
 
bool ArchivoTXT::isFinLinea( const char delim )
{
	fstream flujoAux;
	
	flujoAux.open( this->nombre.c_str(), fstream::in );
	flujoAux.seekg( this->flujo.tellg() ); // igualo la posici�n del flujo auxiliar al flujo principal
	
	string* lectura = new string();
 	
	getline( flujoAux, *lectura, delim );
	flujoAux.close(); 
	// evalua si en el campo leido se encuentra el caracter de fin de linea
	return ( lectura->find( '\n' ) == string::npos ? false : true );
}
 
 
bool ArchivoTXT::isFinal() const
{
	return this->flujo.eof();
}
 
