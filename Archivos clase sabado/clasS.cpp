/*
1) prueba del primer espacio luibre o prueba lineal:
	la clave si colisiona en la posicion se corre un espacio
	v=-1,31,-1,33,{314},-1,-1 	clave 120 ----> v= -1,31,-1,33,[314]->,{120},-1
	
2) prueba cuadratica:
	determina nueva posicion por "pos_colision + i^2" siendo i=1,2,3,4...n
	hace saltos de i al cuadrado en el vector si llega al ultima posicion comienza a contar desde la primera posicion dando la vuelta 
	pos_coli 	i+1^2
	pos_coli 	i+3^2
	
3)prueba de doble hash o rehashing

4)prueba de arrays anidados :
	se carga un vector y se hace una matriz de colisiones paralela colocando las colisiones en la misma posicion de del vector si en la matriz ya esta la posicion 
	ocupada sigue en la posicion de la fila siguiente(la de abajo)y asi consecutivamente hasta que encuentre un -1.

5)prueba de listas enlazadas
	almacena las coliciones en el espacio de memoria (puntero) de un vector colicion si el espacio esta asignado, revisa esa direccion de memoria que hay, si la
	direccion de memoria es nula crea una nueva direccion de memoria ahi y lo guarda, igual para la busqueda.

//----------------------------------------------------------------------------------------------------------------------------------------------------------------

Archivos:
	C= 	<stdio.h>		[fopen(), fclose(), fread()]
	c++= <fstream.h> 	streams(flujos)	[fstream, ifstream, ofstream ]--> objetos
*/

//PROGRAMA PARA CREAR UN ARCHIVO DE TEXTO
#include <iostream>
#include <fstream>
using namespace std;

int main(){
	fstream arc;
	int ced[10]={13,15,36,54,889,124,21,45,98,16};
	char nomb[10][30]={"pedro","kelvin","juan","andrea","guille","pedro","kelvin","juan","andrea","guille"};
	arc.open("datos.txt",ios::out);
	
	
	if(arc.fail())//devuelte true o fall
	{
		cout<<"falla al abrir\n";
		//para cerrar de una y no hacer el else, si no toca hacerlo y hacer todo el proceso de lo que hara si falla al abrir
		system("PAUSE");
		exit(0);
	}
	
	for(int i=0;i<10;i++) arc<<ced[i]<<"	"<<nomb[i]<<endl;
	arc.close();
	
	arc.open("datos.txt",ios::in);
	//leer------------
	int i=0;
	while(true){
		arc >>ced[i]>>nomb[i];
		
		if(arc.eof()){
			break;	
		} 
		
		cout<<"Cedula:"<<ced[i]<<" Nombre:"<<nomb[i]<<endl;
		i++;
	}
	arc.close();
	//-----------------
}

/* Realizar un programa abriendo tres archivos existentes:
	cliente.txt--> contiene el numero de cedula, nombre y el telefono.
	producto.txt--> contiene codigo(int), descripcion del producto y precio(float)
	ventas.txt--> contiene cedula cliente, y codigo de producto 
	
	*considere que una persona adquiere o compra varios productos .
	*utilice un caracter separador en todos los archivos
	*se requiere mostrar en pantalla un listado de todas las ventas realizadas señalando los datos del cliente y el monto total de productos adquiridos y solicitar
	por teclado si quiere generar la factura de uno especifico ingresando el numero de cedula.
	*crear los archivos de textos en un editor.
	*la factura debe quedar en un archivo de texto titulado factura.txt
*/
