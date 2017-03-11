#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int Hash_Modulo(int key,int size){
	
	return key%size;
}

int Hash_Truncamiento(int key){

	int pos=0, sw=-1, dig, cont=0;
	while(key>0){
		dig=key%10;
		if(sw<0 && cont != 4){//position less than 4 digits
			pos=pos*10+dig;
			cont++;
		}
		key=key /10;
		sw*=-1;
	}
	return pos;
}

void load(int array[],int size){
	for(int i=0;i<size;i++)array[i]=-1;
}

void Hash_Plegamiento(){
	
}

void show_me(int vector[],int size){
	
	int a;
	for	(a=0; a<size;a++){
		cout<<"vector["<<a+1<<"]="<<vector[a]<<endl;
	}		
}

int main (){

	int size=10;
	int array[size];
	srand (time(NULL));
	int key = rand()%100000+1;
	
	load(array,size);
	show_me(array,size);
	cout<<"key: "<<key<<endl;
	cout<<"key con truncamiento: "<<Hash_Truncamiento(key);
	
	
	return 0;
}
