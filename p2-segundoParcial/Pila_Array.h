#ifndef PILA_ARRAY_H
#define PILA_ARRAY_H
#include "Cola_Array.h"
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
		
		void Revertir(){
			int n=0;
			T m[size];
			while(n<size){
				T eli;
				this->eliminar(eli);
				m[n]=eli;
				n++;
			}
			n=0;	
			while(n<size){
				T eli;
				eli=m[n];
				this->agregar(eli);
				n++;
			}
		}
			
	Cola_Array<T> getCola(){
		
		int n=0;
		Cola_Array<T> retorno(size+1);
			while(n<=size){
				T eli;
				this->eliminar(eli);
				retorno.agregar(eli);
				n++;
			}
		retorno.Revertir();
		
		return retorno;
	}

		
	void sort(){
	int a,b,position=0,flag=0;
	T heavy;
	size--;
		for(b=size;b>=0;b--){
			heavy=v[0];position=0;
			for(a=0;a<=b;a++){
				if(v[a]>heavy){
					heavy=v[a];
					position=a;	
				}
			}
			T aux=v[b];
			v[b]=v[position];
			v[position]=aux;	
		}		
	}

		
		Pila_Array<T> operator + (Pila_Array<T> otro){
			int t= this->size + otro.getTamanoPila();
			Pila_Array<T> resultado(t),r1(this->size),r2(otro.getTamanoPila());
			int n=0;
			while(n < this->size){
				T eli;
				this->eliminar(eli);
				r1.agregar(eli);
				n++;
			}
			n=0;
			while(n < this->size){
				T eli;
				r1.eliminar(eli);
				resultado.agregar(eli);
				n++;
			}
			n=0;
			while(n<otro.getTamanoPila()){
			 	T eli;
			 	otro.eliminar(eli);
			 	r2.agregar(eli);
			 	n++;
			}
			n=0;
			while(n<otro.getTamanoPila()){
			 	T eli;
			 	r2.eliminar(eli);
				resultado.agregar(eli);
			 	n++;
			}
			return resultado;
			
		}
		
		
		Pila_Array<T> operator - (Pila_Array<T> otro){
			int t= this->size + otro.getTamanoPila();
			this->Revertir();
			otro.Revertir();
			Pila_Array<T> resultado(t);
			int n=0;
			int n1=0,n2=0;
			bool band=true;//para el intercambio
			while(n < t){
				T eli;
				if(band==true&&n1<this->size){
				this->eliminar(eli);
				resultado.agregar(eli);
				n1++;band=false;
					n++;
				}else{
					if(n2<otro.getsize()){
						otro.eliminar(eli);
						resultado.agregar(eli);
						n2++;
							n++;
					}
					band=true;
				}	
			}
			return resultado;
		}
		
		Pila_Array(int tam){
			size=tam;
			v= new T [size];
			tope=-1;
		}
		int getTamanoPila(){
			return size;
		}
		int getsize(){
			return size;
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
			//	cout<<"PILA VACIA"<<endl;
				return -1;//no se elimino
		}
		T eliminar(){
			T in;
			if(tope!=-1){
				in=v[tope];
				tope--;
				return in;
			}
				cout<<"PILA VACIA"<<endl;
				return NULL;//no se elimino
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
