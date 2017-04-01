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
		Cola_Array(int size){
			FIN=-1;
			TAM=size;
			v=new T [TAM];
		}
		int agregar(T &obj);
		int eliminar(T & obj);
		void imprimir();
		void imprimirColaJ();
		void imprimirClase();
		
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

void Cola_Array<T>::imprimir(){
	for(int i=0;i<=FIN;i++){
		cout<<"vector["<<i+1<<"] = "<<v[i]<<endl;
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
