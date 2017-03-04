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
	/*
	int middle=(start+end)/2;
	if(start<=end){
		std::cout<<"key:"<<key<<std::endl;
		std::cout<<"array:"<<array[middle]<<std::endl;
					if(key==array[middle]){
					//	std::cout<<"key:"<<key<<std::endl;
					//	std::cout<<"array:"<<array[middle]<<std::endl;
					return true;
					}
					if(key>array[middle]){
						start=middle+1;
						BusquedaBinaria(array,size, key,start,end);
					}
					if(key<array[middle]) {
						end=middle-1;
						BusquedaBinaria(array,size, key,start,end);		
					}	
	}else return false;
	*/
}

int find(int intArray[], int data,int size) {
   int lowerBound = 0;
   int upperBound = size -1;
   int midPoint = -1;
   int comparisons = 0;      
   int index = -1;
	
   while(lowerBound <= upperBound) {
      printf("Comparison %d\n" , (comparisons +1) );
      printf("lowerBound : %d, intArray[%d] = %d\n",lowerBound,lowerBound,
         intArray[lowerBound]);
      printf("upperBound : %d, intArray[%d] = %d\n",upperBound,upperBound,
         intArray[upperBound]);
      comparisons++;
		
      // compute the mid point
      // midPoint = (lowerBound + upperBound) / 2;
      midPoint = lowerBound + (upperBound - lowerBound) / 2;	
		
      // data found
      if(intArray[midPoint] == data) {
         index = midPoint;
         break;
      } else {
         // if data is larger 
         if(intArray[midPoint] < data) {
            // data is in upper half
            lowerBound = midPoint + 1;
         }
         // data is smaller 
         else {
            // data is in lower half 
            upperBound = midPoint -1;
         }
      }               
   }
   printf("Total comparisons made: %d" , comparisons);
   return index;
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
	int in = 2;
	for(int i=0;i<size;i++) array[i]=rand()%size+1;
	//-----------hasta aqui llenado aleatorio----------------//
	insertion2(array,size);
	
	if (find(array, in,size)>=0){
	std::cout<<"\n\nencontrado\n"<<std::endl;
	}else {
	std::cout<<"\n\nNO encontrado\n"<<std::endl;
	}
	show_me(array,size);
	
}
