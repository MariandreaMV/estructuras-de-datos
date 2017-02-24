#include <iostream>
#include <stdlib.h>
#include <time.h>

bool busquedaSimple(int array[],int size, int key){
	for(int i=0;i<size;i++)
		if(key==array[i])
			return true;
	return false;
}


bool BusquedaBinaria(int array[],int size, int key,int start,int end){
	
	int middle=(start+end)/2;
	
	if(start<=end){
	
				if(key==array[middle])
					
					return true;
				
					if(key>array[middle]){
						start=middle+1;
						BusquedaBinaria(array,size, key,start,end);
					}
					if(key<array[middle]) {
						end=middle-1;
						BusquedaBinaria(array,size, key,start,end);		
					}
				
	
	}else return false;
	
}


void insertion2(int vector[],int size){
	int aux,I,i;
	for(i=1; i<size;i++){
		I=i;
		aux=vector[i];
		while(I>0&&aux<vector[I-1]){
			vector[I]=vector[I-1];
			I--;
		}
		vector[I]=aux;
	}
}

void show_me(int vector[],int size){	
	int a;
	for	(a=0; a<size;a++){
		printf("vector[%d]= %d \n",a+1,vector[a]);
	}		
}

int main(){
	
	int size=100;
	srand (time(NULL));
	int array[size];
	int in = 1;
	for(int i=0;i<size;i++) array[i]=rand()%size+1;
	insertion2(array,size);
	if (BusquedaBinaria(array, size,in,0,size-1))
	std::cout<<"encontrado";
	else std::cout<<"NO encontrado"<<std::endl;
	show_me(array,size);
	
}
