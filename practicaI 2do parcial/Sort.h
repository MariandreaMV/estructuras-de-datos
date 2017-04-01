#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <math.h>
#include <fstream>
#include <string.h>
#define SUFPEQ 4

//modelo de las funciones que deben estar en cada clase a ordenar y buscar
/*
	static bool comparacion(Libro p1, Libro p2, int sw){
			if(sw == 0){
				return (strcmpi(p1.getAutor().c_str(), p2.getAutor().c_str()) < 0);
			}
			
			if(sw == 1){
				return (strcmpi(p1.getTitulo().c_str(), p2.getTitulo().c_str()) > 0);
			}
			
			if(sw == 2){
				return (p1.getEdad() < p2.getEdad());
			}

		}
		
		static bool igualacion(Libro p1, Libro p2, int sw){
			if(sw == 0){
				return (strcmpi(p1.getAutor().c_str(), p2.getAutor().c_str()) == 0);
			}
			
			if(sw == 1){
				return (strcmpi(p1.getTitulo().c_str(), p2.getTitulo().c_str()) == 0);
			}
			
			if(sw == 2){
				return (p1.getEdad() == p2.getEdad());
			}
		}
*/

using namespace std;

template <class T>

class Sort
{	
	private:
		static void charge(T *array,T *p1,T *p2,int size);
		static void fusion(T *array,T *p1, T *p2,int size,bool (*comparacion) (T obj1, T obj2, int swi),int sw);
		static int pivot(int sw,T *array,int size,bool (*comparacion) (T obj1, T obj2, int swi));
		
	public:
		Sort(){}
		
		//para el uso de estas herramientas es necesario la creacion 
		//de una clase comparacion en las clases a ordenar
		static void bubble(int sw, T *vec, int size, bool (*comparacion) (T obj1, T obj2, int swi));
		static void selection_sort(int sw, T *vec, int size, bool (*comparacion) (T obj1, T obj2, int swi));
		static void shaker_sort(int sw, T *vector, int size, bool (*comparacion) (T obj1, T obj2, int swi));
		static void shell_sort(int sw, T *vector, int size, bool (*comparacion) (T obj1, T obj2, int swi));
		static void insertion2(int sw, T *vector, int size, bool (*comparacion) (T obj1, T obj2, int swi));
		//static void merge_sort(int sw, T *vector, int size, bool (*comparacion) (T obj1, T obj2, int swi));
		static void quick_sort(int sw,T *array,int size,bool (*comparacion) (T obj1, T obj2, int swi));
			
		static void show_me(T *vector,int size);
	
};


template <class T>
void Sort<T>::bubble(int sw, T *vec, int size, bool (*comparacion) (T obj1, T obj2, int swi)){
		
	int a;
	T aux;
	int y;
	int flag=1;
	
	for(a=0; a<size-1&&flag==1;a++){	
		flag=0;
		for(y=0;y<size-1;y++){				
			if(comparacion(vec[y],vec[y+1],sw)){
				flag=1;
				aux=vec[y+1];
				vec[y+1]=vec[y];
				vec[y]=aux;
			}
		}
	}
}

template<class T>
void Sort<T>::selection_sort(int sw, T *vector, int size, bool (*comparacion) (T obj1, T obj2, int swi)){
	int a,b,position=0,flag=0;
	T heavy;
	size--;
	for(b=size;b>=0;b--){
		heavy=vector[0];position=0;
		for(a=0;a<=b;a++){
			if(comparacion(vector[a],heavy,sw)){
				heavy=vector[a];
				position=a;	
			}
		}
		T aux=vector[b];
		vector[b]=vector[position];
		vector[position]=aux;	
	}		
}

template<class T>
void Sort<T>::shaker_sort(int sw, T *vector, int size, bool (*comparacion) (T obj1, T obj2, int swi)){
	int i=0,swapped=1,d;
	d=size;
	size--;
	while(i<size&&swapped){
		int a;
		swapped=0;
		
		for(a=i;a<size;a++){
			if(comparacion(vector[a],vector[a+1],sw)){
				T aux=vector[a];
				vector[a]=vector[a+1];
				vector[a+1]=aux;
				swapped=1;
			}
		}
		size--;
		if (swapped==1){
			swapped=0;
			for(a=size;a>i;a--){
				if(comparacion(vector[a-1],vector[a],sw)){
					T aux=vector[a];
					vector[a]=vector[a-1];
					vector[a-1]=aux;
					swapped=1;
				}
			}
		}
		i++;
	}
}

template<class T>
void Sort<T>::show_me(T *vector,int size){	
	int a;
	cout<<endl;
	cout<<"-------------------estoy en show_me----------------"<<endl;
	cout<<endl;
	for	(a=0; a<size;a++){
		vector[a].imprimir();
	}		
}

template<class T>
void Sort<T>::shell_sort(int sw, T *vector, int size, bool (*comparacion) (T obj1, T obj2, int swi)){
	
	int flag=1;
	int increase=size/2;
	int a=0;
	T aux;
		
	 while(increase>0){	
		flag=0;	
		for(a=0;a<size-increase;a++){		
			if(comparacion(vector[a],vector[a+increase],sw)){
				aux=vector[a+increase];
				vector[a+increase]=vector[a];
				vector[a]=aux;
				flag=1;
			}			
		}
		if(flag==0){
			increase=increase/2;
		}		
	}	
}

template<class T>
void Sort<T>::insertion2(int sw, T *vector, int size, bool (*comparacion) (T obj1, T obj2, int swi)){
	
	T aux;
	int I,i;
	for(i=1; i<size;i++){
		I=i;
		aux=vector[i];
		while(I>0&&comparacion(vector[I-1],aux,sw)){
			vector[I]=vector[I-1];
			I--;
		}
		vector[I]=aux;
	}
}

template<class T>
void Sort<T>::fusion(T *array,T *p1, T *p2,int size,bool (*comparacion) (T obj1, T obj2, int swi),int sw){
	
	//according to minor
	int i=0,j=0,k=0;
	for(k=0;i<size&&j<size-(size/2);k++){
		if(comparacion(p2[j],p1[i],sw)){
			array[k]=p1[i];
			i++;
		}else{
			array[k]=p2[j];
			j++;
		}
	}
	while(i<size/2){
		array[k]=p1[i];
		i++;
		k++;
	}
	while(j<size-(size/2)){
		array[k]=p2[j];
		j++;
		k++;
	}
}

template <class T>
void Sort<T>::charge(T *array,T *p1,T *p2,int size){
	
	int k=0;
	for(int i=0;i<size/2;i++){
		p1[i]=array[k];
		k++;
	}
	for(int i=0;i<size-(size/2);i++){
		p2[i]=array[k];
		k++;
	}	
}
/*
template<class T>
void Sort<T>::merge_sort(int sw, T *vector, int size, bool (*comparacion) (T obj1, T obj2, int swi)){
	
	//this algorithm divide the array in two auxiliary arrays. size/2 and size-size/2
	if(size<SUFPEQ){
		bubble(sw,vector,size,comparacion);
	}else{
		T p1[size/2],p2[size-(size/2)];
		charge(vector,p1,p2,size);//charge the auxiliars arrays
		merge_sort(sw,p1,size/2,comparacion);
		merge_sort(sw,p2,size-(size/2),comparacion);
		fusion(vector,p1,p2,size,comparacion,sw);//Merge the auxiliars arrays
	}
}
*/	
template <class T>
int Sort<T> ::pivot(int sw,T *array,int size,bool (*comparacion) (T obj1, T obj2, int swi)){
	
	//Classify the array taking the first position as a pivot
	//Returns the position where the pivot is delimited	
	T pivot=array[0],aux;
	int i=1,j=size-1;	
	while(i<j){		
		while(comparacion(pivot,array [i],sw)&&i<size){
			i++;
		}
		while(comparacion(array[j],pivot,sw)){
			j--;
		}
		if(i<j){
			aux=array[i];
			array[i]=array[j];
			array[j]=aux;
			i++;
			j--;
		}
	}	
	array[0]=array[j];
	array[j]=pivot;
	return j;	
}

template<class T>
void Sort<T>::quick_sort(int sw,T *array,int size,bool (*comparacion) (T obj1, T obj2, int swi)){
	
	//this algorithm select a pivot (the first position in this case)
	//that is in charge of subdividing the vector according to whether it is larger or smaller
	if(size<=SUFPEQ){
		bubble(sw,array,size,comparacion);
	}else{
		int positionPIVOT=pivot(sw,array,size,comparacion);
		quick_sort(sw,array,positionPIVOT,comparacion);
		//array+positionPIVOT+1
		quick_sort(sw,&array[positionPIVOT+1],size-positionPIVOT,comparacion);
	}
}


#endif
