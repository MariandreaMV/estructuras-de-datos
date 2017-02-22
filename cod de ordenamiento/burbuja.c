//#include <stdio.h>
//#include <stdlib.h>


//---------------------------bubble sort------------------------
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
//-------------------------end bubble sort------------------------


//---------------------------shell sort---------------------------
void shell_sort(int vector[],int size){
	int flag=1;
	int increase=size/2;
	int a=0;
	int aux;
		
	 while(increase>0){	
		flag=0;	
		for(a=0;a<size-increase;a++){		
			if(vector[a]>vector[a+increase]){
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
//--------------------------end shell sort--------------------


//------------------------------insertion sort-----------------
void insertion_sort(int vector[],int size){
	int a;
	for(a=0;a<size;a++){
		if(vector[a]>vector[a+1]){
			int aux=vector[a+1];
			vector[a+1]=vector[a];
			vector[a]=aux;
			int b=a-1, a2=a, flag=0;
			while(flag==0&&a!=0&&a2!=0){
				if(vector[a2]<vector[b]){
					int aux2=vector[b];
					vector[b]=vector[a2];
					vector[a2]=aux2;
					flag=0;
					b--;a2--;
				}else flag=1;
			}
		}
	}	
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
//-------------------------------end insertion sort------------


//----------------------------selection sort-------------------
void selection_sort(int vector[],int size){
	int a,b,heavy,position=0,flag=0;
	size--;
	for(b=size;b>=0;b--){
		heavy=vector[0];position=0;
		for(a=0;a<=b;a++){
			if(vector[a]>heavy){
				heavy=vector[a];
				position=a;	
			}
		}
		int aux=vector[b];
		vector[b]=vector[position];
		vector[position]=aux;	
	}		
}
//------------------------------end selection sort-------------


//-----------------------------Shaker sort---------------------
void shaker_sort(int vector[],int size){
	int i=0,swapped=1;
	size--;
	while(i<size&&swapped){
		int a;
		swapped=0;
		
		for(a=i;a<size;a++){
			if(vector[a]>vector[a+1]){
				int aux=vector[a];
				vector[a]=vector[a+1];
				vector[a+1]=aux;
				swapped=1;
			}
		}
		size--;
		if (swapped==1){
			swapped=0;
			for(a=size;a>i;a--){
				if(vector[a]<vector[a-1]){
					int aux=vector[a];
					vector[a]=vector[a-1];
					vector[a-1]=aux;
					swapped=1;
				}
			}
		}
		i++;
	}
}
//------------------------------end shaker sort----------------


//--------------------------show_me--------------------------
void show_me(int vector[],int size){	
	int a;
	for	(a=0; a<size;a++){
		printf("vector[%d]= %d \n",a+1,vector[a]);
	}		
}
//---------------------------end show_me---------------------

//primer cambio
//segundo cambio
//tercer cambio
//cuarto cambio

//----------------------------main---------------------------
int main (){
	int vector[15]={19,13,12,9,15,2,14,16,100,18,90,-3,1,0,-1};		
	//bubble_sort(vector,(sizeof(vector)/sizeof(int)));
	//shell_sort(vector,(sizeof(vector)/sizeof(int)));
	//insertion_sort(vector,(sizeof(vector)/sizeof(int)));
	//selection_sort(vector,(sizeof(vector)/sizeof(int)));
	//shaker_sort(vector,(sizeof(vector)/sizeof(int))); 
	insertion2(vector,(sizeof(vector)/sizeof(int))); 
	show_me(vector,(sizeof(vector)/sizeof(int)));
		
	return 0;
}
//---------------------------end main-------------------------
