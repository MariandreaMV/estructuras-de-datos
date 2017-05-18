#ifndef COLA_CIRCULAR_H
#define COLA_CIRCULAR_H
#include <iostream>
#include <windows.h>

using namespace std;

template <class T>

class Cola_circular{
	
private:

	T *v;
	int FRENTE, FIN, TAM;

public:
	
	Cola_circular(){}
	Cola_circular(int size);	
	int agregar(T &ELENMENTO);
	int eliminar(T &ELI);
	void imprimir();
	
};


template <class T>
Cola_circular<T>::Cola_circular(int size){
	
	TAM=size;
	FRENTE=-1;
	FIN=-1;
	v=new  T[TAM];
	if(!v)
		cout<<"memoria agotada"<<endl;
		/*
		for(int i=0;i<TAM;i++){
			v[i]=0;
			cout<<"vector["<<i+1<<"] = "<<v[i]<<endl;
		}*///inicializa la cola en caso que sea int
}


template<class T>
int Cola_circular<T>::agregar(T &ELEMENTO){
	
	if((FIN+1)%TAM==FRENTE) return -1;
	if(FIN==-1) FRENTE=0;
	v[(FIN+1)%TAM]=ELEMENTO;
	FIN=(FIN+1)%TAM;
	return FIN;
	
}

template<class T>
int Cola_circular<T>::eliminar(T &ELI){
	
	int aux;
	if(FRENTE==-1&&FIN==-1) return -1;
	ELI =v[FRENTE];
	aux=FRENTE;
	if(FRENTE==FIN){
		FRENTE=-1;
		FIN=-1;
	}else{
		FRENTE=(FRENTE+1)%TAM;
	}
	return aux;
	
}

template<class T>
void Cola_circular<T>::imprimir(){
	
	int i=FRENTE;
	/*
	while(i<=FIN){
		cout<<"vector["<<i+1<<"] = "<<v[i]<<endl;	
		i=i%TAM;
		i++;
		system("pause");
	}
	*/	
	do{
		cout<<"cola["<<i+1<<"] = "<<v[i]<<endl;	
		i++;
		if(i==TAM&&FRENTE>FIN) i=0;	
	}while(i!=FIN+1);

}

#endif



