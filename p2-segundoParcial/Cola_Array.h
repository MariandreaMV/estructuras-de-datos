#ifndef COLA_ARRAY_H
#define COLA_ARRAY_H
#include <iostream>

using namespace std;

template <class T>
class Cola_Array
{
	
	private:
		int FIN, N, TAM;
		T *v;
	public:
		Cola_Array(){
		}
		
		
  Cola_Array<T> getCola(){
		
		int n=0;
		Cola_Array<T> retorno(this->TAM);
			while(n<this->TAM){
				T eli;
				this->eliminar(eli);
				retorno.agregar(eli);
				n++;
			}
		return retorno;
	}
		
		Cola_Array<T> operator + (Cola_Array<T> otro){
			int t=this->TAM + otro.getTamano();
			Cola_Array<T> resultado(t);
			int n=0;
			while(n<this->TAM){
				T eli;
				this->eliminar(eli);
				resultado.agregar(eli);
				n++;
			}
			n=0;
			while(n<otro.getTamano()){
			 	T eli;
			 	otro.eliminar(eli);
			 	resultado.agregar(eli);
			 	n++;
			}
			return resultado;
		}
		
		Cola_Array(int size){
			FIN=-1;
			TAM=size;
			v=new T [TAM];
		}
		
		int agregar(T &obj);
		int eliminar(T & obj);
		T eliminar();
		void imprimir();
		void imprimirColaJ();
		void imprimirClase();
		
		int getTamano(){
			return TAM;
		}
		int getsize(){
			return TAM;
		}
	
		
	void Revertir(){
			int n=0;
			T r[TAM];
			while(n<TAM){
				T eli;
				this->eliminar(eli);
				r[n]=eli;
				n++;
			}
			n=0;
			int c=TAM-1;	
			while(n<TAM){
				T eli;
				eli=r[c];c--;
				this->agregar(eli);
				n++;
			}
	}
	
	Cola_Array<T> operator - (Cola_Array<T> otro){
			int t= this->TAM + otro.getsize();
			Cola_Array<T> resultado(t);
			int n=0;
			int n1=0,n2=0;
			bool band=true;//para el intercambio
			while(n < t){
				T eli;
				if(band==true&&n1<this->TAM){
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
	
	
	
		
	void sort(){
	int a,b,position=0,flag=0;
	T heavy;
	int size=TAM;
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
		
	protected:
};

template <class T>

int Cola_Array<T>::agregar(T &obj){
	if(FIN==TAM)return -1 ;//esta lleno
	FIN++;
	v[FIN]=obj;
	return 1;//agregado con exito
}

template <class T>

int Cola_Array<T>::eliminar(T &obj){
	if(FIN==-1)return -1; //esta vacia
	obj=v[0];
	FIN--;
	for(int i=0;i<=FIN ;i++){
		v[i]=v[i+1];
	}
	return 1;//eliminado con exito
}

template <class T>

T Cola_Array<T>::eliminar(){
	T obj;
	if(FIN==-1)return NULL; //esta vacia
	obj=v[0];
	FIN--;
	for(int i=0;i<=FIN ;i++){
		v[i]=v[i+1];
	}
	return obj;//eliminado con exito
}


template <class T>

void Cola_Array<T>::imprimir(){
	for(int i=0;i<=FIN;i++){
			cout<<"\t"<<v[i]<<" ";
	}
}

template <class T>

void Cola_Array<T>::imprimirColaJ(){
	//cout<<"FIN COLA: "<<FIN<<endl;
	for(int i=0;i<=FIN;i++){
		cout<<"cola["<<i+1<<"] = "<<v[i]<<"  ";
	}
}



template <class T>

void Cola_Array<T>::imprimirClase(){
	for(int i=0;i<=FIN;i++){
		v[i].informacionG();
	}
}

#endif
