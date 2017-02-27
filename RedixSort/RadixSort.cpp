#include <iostream>
#include <stdlib.h>
#include <time.h>


//-------------------------show me----------------------
void show_me(int array[],int size){	

	for	(int a=0; a<size;a++)
		printf("vector[%d]\t= %d \n",a+1,array[a]);
			
}
//-----------------------------end show me -------------

//-----------------------RadixSort----------------------
void RadixSort(int array[],int size){
	
	int *matrix[10];
	int heavy=array[0];
	
	for(int i=0;i<size;i++){
		if(array[i]>heavy)
		heavy=array[i];
	}//hallo el mayor para saber cuantos digitos tiene el numero mas grande
	
	//vueltas segun la cantidad de digitos del numero mas grande
	for(int v=1;heavy/v>0;v=v*10){

		int contadores[10] = {0};

		for (int i = 0; i < size; i++)
			contadores[ (array[i]/v)%10 ]++;
			//hallo la cantidad de repeticiones de los digitos

		for(int i=0;i<10;i++){
			matrix[i] = (int*)malloc(contadores[i]*sizeof(int));
		}//matriz dinamica
		
		for (int i = 0; i < 10; i++)
			contadores[i]=0;
			//coloco todos los contadores de las repeticiones en cero para reutilizar la variable
		for(int i=0;i<size;i++){
		
			switch((array[i]/v)%10){
				case 0:{	matrix[0][contadores[0]]=array[i];
							contadores[0]++;
						break;
						}
				case 1:{	matrix[1][contadores[1]]=array[i];
							contadores[1]++;
						break;
						}
				case 2:{	matrix[2][contadores[2]]=array[i];
							contadores[2]++;
						break;
						}
				case 3:{	matrix[3][contadores[3]]=array[i];
							contadores[3]++;
						break;
						}
				case 4:{	matrix[4][contadores[4]]=array[i];
							contadores[4]++;
						break;
						}
				case 5:{	matrix[5][contadores[5]]=array[i];
							contadores[5]++;
						break;
						}
				case 6:{	matrix[6][contadores[6]]=array[i];
							contadores[6]++;
						break;
						}
				case 7:{	matrix[7][contadores[7]]=array[i];
							contadores[7]++;
						break;
						}
				case 8:{	matrix[8][contadores[8]]=array[i];
							contadores[8]++;
						break;
						}
				case 9:{	matrix[9][contadores[9]]=array[i];
							contadores[9]++;
						break;
						}			
			}
		}//matriz dinamica inicializada y ordenada por digitos
	
	printf("\nMATRIZ\n");
	for(int i=0;i<10;i++){
		printf("%d: ",i);
		for(int c=0;c<contadores[i];c++){
			printf("%d \t",matrix[i][c]);
		}
		std::cout<<"\n";
	}//imprime matriz 
	
	int cont=0;
	for (int i = 0; i < 10; i++){
		for(int b=0;b<contadores[i];b++){
			array[cont]=matrix[i][b];
			cont++;
		}
	}//reorganiza el array segun el arreglo por digito guardado en la matriz
	
	printf("\nVECTOR\n");
	show_me(array,size);
	std::cout<<std::endl;
	
	}//repetir el proceso tantos digitos tenga el numero mayor	
}
//--------------------------end radixsort---------------



//--------------------------Main------------------------
int main (){
	
	int size=15, array[size];
	srand (time(NULL));
	for(int i=0;i<size;i++) 
		array[i]=rand()%size+1;
	
	RadixSort(array,size);
	return 0;
}
//-----------------------end main------------------------

