#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void my_metod_GRAVITACION(int array[],int size){
	//suppose that all the numbers are positive
	int heavy=-1;
	int position;
	int aux[size];
	
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			if(array[j]>heavy&&array[j]!=-1){
				heavy=array[j];
				position=j;
			}
		}
		aux[i]=heavy;
		array[position]=-1;
		heavy=-1;
	}
	// aux is Sorted from highest to lowest
	for(int  i=0;i<size;i++){
		array[i]=aux[size-i-1];
	}
	delete aux;	
}

void show_me(int vector[],int size){
	
	int a;
	for	(a=0; a<size;a++){
		cout<<"vector["<<a+1<<"]="<<vector[a]<<endl;
	}		
}

void no_repeat(int array[],int size){
	
	bool found=true;
	for(int i=0;i<size;i++) {
		array[i]=rand()%100+1;
		found=true;	
		while(found==true&&i>0){	
			for(int j=0;j<i;j++){
				if(array[i]==array[j]){
					array[i]=rand()%100+1;
					found=true;
					break;
				}else found=false;
			}
		}
	}
}

int main (){

	int size=10;
	int array[size];
	srand (time(NULL));
	
	no_repeat(array,size);
	cout<<"UNSORTED\n"<<endl;
	show_me(array,size);
	my_metod_GRAVITACION(array,size);
	cout<<"\nSORTED\n"<<endl;
	show_me(array,size);
	//----------------final question one-----------------*	
	
	return 0;
}
