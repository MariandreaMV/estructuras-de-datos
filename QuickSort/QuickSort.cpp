#include <iostream>
#include <time.h>
#include <stdlib.h>
#define SUFPEQ 200

void bubble_sort(int vec[], int size){
	int a;
	int mayor;
	int aux;
	int y;
	int flag=1;
	for(a=0; a<size-1&&flag==1;a++){	
		flag=0;
		for(y=0;y<size-1;y++){				
			if(vec[y]>vec[y+1]){
			flag=1;
			aux=vec[y+1];
			vec[y+1]=vec[y];
			vec[y]=aux;
			}
		}
	}
}

void show_me(int vector[],int size){	
	int a;
	for	(a=0; a<size;a++){
		printf("vector[%d]= %d \n",a+1,vector[a]);
	}		
}

int pivot(int array[],int size){
	
	//Classify the array taking the first position as a pivot
	//Returns the position where the pivot is delimited
	
	int pivot=array[0],i=1,j=size-1,aux;	
	while(i<j){		
		while(array [i]<pivot&&i<size){
			i++;
		}
		while(array[j]>pivot){
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

void QUICKsort(int array[],int size){
	
	//this algorithm select a pivot (the first position in this case)
	//that is in charge of subdividing the vector according to whether it is larger or smaller
	
	if(size<=SUFPEQ){
		bubble_sort(array,size);
	}else{
		int positionPIVOT=pivot(array,size);
		QUICKsort(array,positionPIVOT);
		//array+positionPIVOT+1
		QUICKsort(&array[positionPIVOT+1],size-positionPIVOT);
	}
}

int main(){

	int size=180;
	srand (time(NULL));
	int array[size];
	for(int i=0;i<size;i++) array[i]=rand()%1000+1;
	
	show_me(array,size);
	QUICKsort(array,size);
	std::cout<<"\n\n";
	show_me(array,size);

	return 0;
}
