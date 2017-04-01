#ifndef PILA_ARRAY_H
#define PILA_ARRAY_H
#include <iostream>

using namespace std;

template <class T>
class Pila_Array
{
	
	private:
		T *v;
		int size, tope;
		
	public:
		Pila_Array(){
		}
		
		Pila_Array(int tam){
			size=tam;
			v= new T [size];
			tope=-1;
		}
		int getTamanoPila(){
			return tope;
		}
	
		int agregar(T &in){
			if(tope<(size-1)){
				tope++;
				v[tope] = in;
				return tope;
			}
				cout <<"PILA LLENA"<<endl;
				return -1;	//no se agrego		
		}
		int eliminar(T &in){
			if(tope!=-1){
				in=v[tope];
				tope--;
				return tope;
			}
				cout<<"PILA VACIA"<<endl;
				return -1;//no se elimino
		}
		
		void imprimir(int columnas){
		
			int c=0;
		
			for(int i=0; i<=tope;i++){
			
				cout<<"\t"<<v[i];
				c++;
					if(c==columnas){
					c=0;
					cout<<endl;
					
					}
			}
		}
		
		void imprimir(){
		
			for(int i=0; i<=tope;i++){
				cout<<"\t"<<v[i]<<" ";
			}
		}
};



#endif
