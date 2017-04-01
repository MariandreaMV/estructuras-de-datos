#ifndef TABLERO_H
#define TABLERO_H

#include "Pila_Array.h"

class Tablero
{
	private :
		Pila_Array<int> *tablero;
		
	public:
		tabla(){
		}
		Tablero(int dimension,int *objetos){
			//cout<<"constructor de tablero"<<endl;
			tablero=new Pila_Array<int>[dimension];
			
			for(int i=0;i<dimension;i++){
				if(objetos[i]!=0){
				Pila_Array<int> o(dimension);
				o.agregar(objetos[i]);
				tablero[i]=o;
				}
				else{
				int a=0;
				Pila_Array<int> o(a);
				tablero[i]=o;
				}
			}
		}
		
		void agregarElemento(int posicion,int valor){
			tablero[posicion].agregar(valor);
		}
		
		int eliminarElemento(int posicion){
			int retorno=0;
			tablero[posicion].eliminar(retorno);
		//	cout<<" elemento eliminado: "<<retorno<<endl;
			return retorno;
		}
		
		void imprimirVectorDeColas(int dimension){
				
			for(int i=0;i<dimension;i++){
				cout<<"posicion: "<<i;
				tablero[i].imprimir();
				cout<<endl;
				
			}
		}
		
		int getTamanoPilaCasilla(int posicion){
			return tablero[posicion].getTamanoPila();
		}
		void imprimirUnaPila(int posicion){
			tablero[posicion].imprimir();
			cout<<endl;
		}
		
	protected:
};

#endif
