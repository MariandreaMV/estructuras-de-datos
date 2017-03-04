#include <iostream>
#include <stdlib.h>
#include <time.h>
#define SUFPEQ 50

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

void fusion(int array[],int p1[],int p2[],int size){
	
	//according to minor
	
	int i=0,j=0,k=0;
	for(k=0;i<size&&j<size-(size/2);k++){
		if(p1[i]<p2[j]){
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

void charge(int array[],int p1[],int p2[],int size){
	
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


void merge_sort(int array[],int size){
	
	//this algorithm divide the array in two auxiliary arrays. size/2 and size-size/2
	
	if(size<SUFPEQ){
		bubble_sort(array,size);
	}else{
		int p1[size/2],p2[size-(size/2)];
		charge(array,p1,p2,size);//charge the auxiliars arrays
		merge_sort(p1,size/2);
		merge_sort(p2,size-(size/2));
		fusion(array,p1,p2,size);//Merge the auxiliars arrays
	}
}



int main(){
	
	int size=100;
	srand (time(NULL));
	int array[size];
	int in = 2;
	for(int i=0;i<size;i++) array[i]=rand()%size+1;
	
	merge_sort(array, size);
	show_me(array,size);
	
	return 0;
}
