#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <algorithm>
#include <string.h>
#include <cstring>
#include <string>
#include <sstream>

using namespace std;

void buscar(string key, string letras[],int clavesnumericas[],int size,string unidas[],string alfanumerica){
//	cout<<"entro al alfanumerico"<<endl;
	cout<<"\n-----------------------------------------"<<endl;
	cout<< "alfabetica \tnumerica \talfanumerica"<<endl;
	cout<<"-----------------------------------------"<<endl;
		bool band=false;
		for(int i=0;i<size;i++){
		//	cout<<"key: "<<key<<" alfanumerica: "<<unidas[i]<<endl;
			if(key.compare(unidas[i])==0){
					cout<<""<<letras[i]<<"\t\t"<<clavesnumericas[i]<<"\t\t"<<unidas[i]<<endl;
					band=true;;
			}
		}
		if (band==false)
		cout<<"clave no encontrada"<<endl;
}

void buscar(int key, string letras[],int clavesnumericas[],int size,string unidas[]){
	cout<<"\n-----------------------------------------"<<endl;
	cout<< "alfabetica \tnumerica \talfanumerica"<<endl;
	cout<<"-----------------------------------------"<<endl;
		bool band=false;
		for(int i=0;i<size;i++){
			if(key==clavesnumericas[i]){
					cout<<""<<letras[i]<<"\t\t"<<clavesnumericas[i]<<"\t\t"<<unidas[i]<<endl;
					band=true;;
			}
		}
		if (band==false)
		cout<<"clave no encontrada"<<endl;
}


void buscar(string key, string letras[],int clavesnumericas[],int size,string unidas[]){
	cout<<"\n-----------------------------------------"<<endl;
	cout<< "alfabetica \tnumerica \talfanumerica"<<endl;
	cout<<"-----------------------------------------"<<endl;
		bool band=false;
		for(int i=0;i<size;i++){
			if(key.compare(letras[i])==0){
					cout<<""<<letras[i]<<"\t\t"<<clavesnumericas[i]<<"\t\t"<<unidas[i]<<endl;
					band=true;;
			}
		}
		if (band==false)
		cout<<"clave no encontrada"<<endl;
}

int buscar(int key,int clavesnumericas[],int size){

		for(int i=0;i<size;i++){
			if(key==clavesnumericas[i]){
					return clavesnumericas[i];
			}
		}
		return -1;
}

void show_me(int vector[],int size){
	
	int a;
	for	(a=0; a<size;a++){
		cout<<"vector["<<a+1<<"]="<<vector[a]<<endl;
	}		
}

void show_me2(string vector[],int size,int vector2[]){
	
	int a;
	for	(a=0; a<size;a++){
		cout<<"clave: "<<vector[a];
		cout<<"\tnumero: "<<vector2[a]<<endl;
		
	}		
}

void show_me2(string vector[],int size,int vector2[],string unidas[]){
	
	int a;
	cout<< "alfabetica \tnumerica \talfanumerica"<<endl;
	cout<<"-------------------------------------"<<endl;
	for	(a=0; a<size;a++){
		cout<<vector[a];
		cout<<"\t\t"<<vector2[a];
		cout<<"\t\t"<<unidas[a]<<endl;
		
	}		
}


void selection_sort(int vector[],int size,string letras[]){
	int a,b,heavy,position=0,flag=0;
	string auxcadena;
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
		auxcadena=letras[b];
		letras[b]=letras[position];
		letras[position]=auxcadena;
			
	}		
}

void selection_sort(char *s,int size,char mayusculas[]){
	int a,b,heavy,position=0,flag=0;
	int n=size;
	
	size--;	
	for(b=size;b>=0;b--){
		heavy=s[0];position=0;
		for(a=0;a<=b;a++){
			if(s[a]>heavy){
				heavy=s[a];
				position=a;	
			}
		}
		int aux=s[b];
		s[b]=s[position];
		s[position]=aux;
		
		for(int i=0;i<n;i++){
			if(s[b]==mayusculas[i]){
				s[b]=toupper(s[b]);
				break;
			}
		}
	}	
//	string aux=s;
//	cout<<"sorted "<<aux<<endl;	
}


void ordenar(char *s,int n){
	string aux=s;
	char mayusculas[n];
	for(int i=0;i<n;i++) {
	mayusculas[i]=' ';
	}
//	cout<<aux<<endl;
	for(int i=0;i<n;i++){
		if(s[i]>='a'&&s[i]<='z'){
	//	cout<<"minuscula"<<endl;
		}else{
	//	cout<<"mayuscula"<<endl;
		mayusculas[i]=tolower(s[i]);
		s[i]=tolower(s[i]);
		}
	}
	aux=s;
//	cout<<aux<<endl;
/*	for(int i=0;i<n;i++) {
		cout<<mayusculas[i]<<endl;
	}*/
	selection_sort(s,n,mayusculas);

}

int menu(){
	int op;
	cout<<"busqueda por clave alfabetica    1."<<endl;
	cout<<"busqueda por clave numerica      2."<<endl;
	cout<<"busqueda por clave alfanumerica  3."<<endl;
	cin >>op;
	return op;
}

void detectar(string cadenas[],int n,int numeros[]){
	
	int clavesNumericasAsociadas[n];
	int contador=0;
	
	for(int i = 0; i < 10; i++){
		contador=0;
		char *s=&cadenas[i][0];
		ordenar(s,cadenas[i].length());
		//string auxiliar=s;
		//cout<<auxiliar<<endl;
		
    	for(int j = 0; j < cadenas[i].size(); j++){
      	string aux = cadenas[i];    		 
			contador+=aux[j];
      	}
    	clavesNumericasAsociadas[i]=buscar(contador, numeros, n);	
  	}
  	cout<<"\nUNSORTED\n"<<endl;
  	show_me2(cadenas,n,clavesNumericasAsociadas);
  	cout<<endl;
  	/*
  	char *alfanumerica[n];
  	
  	for(int i=0;i<n;i++){
  		alfanumerica[i]=&cadenas[i][0];
  		string aux=alfanumerica[i]+to_string(numeros[i]);
  		cout<<aux<<endl;
  	}
  	*/
  	cout<<"\nSORTED\n"<<endl;
  	selection_sort(clavesNumericasAsociadas,n,cadenas);
  	
  	
  	string unidas[n];
  	stringstream sstm;
	
  	for(int i=0;i<n;i++){
  		sstm.str("");
  		sstm << cadenas[i] << clavesNumericasAsociadas[i];
		unidas[i] = sstm.str();
		//cout<<unidas[i]<<endl;
  		
  	}
  	show_me2(cadenas,n,clavesNumericasAsociadas,unidas);
  	
  	string op;
  	int op2;
  	int busq;
  	cout<<"-------------------------------------"<<endl;
  	int opcion;
	  do{
  	 opcion=menu();
	}while(opcion!=1&&opcion!=2&&opcion!=3);
	cout<<"-------------------------------------"<<endl;
	if(opcion==1){
	
  	do{
		cout<<"\nescriba la clave alfabetica a buscar: "<<endl;
		cin>>op;
		buscar(op, cadenas,clavesNumericasAsociadas,n,unidas);	
		cout<<"---------------------------------------------------"<<endl;
		cout<<"\n\ndesea buscar nuevamente alfabeticamente? (1/si, diferente de 1 no)"<<endl;
		cin>>busq;
	}while(busq==1);
  }else{
	  	if(opcion==2){
		  		do{
				cout<<"\nescriba la clave numerica a buscar: "<<endl;
				cin>>op2;
				buscar(op2, cadenas,clavesNumericasAsociadas,n,unidas);
				cout<<"--------------------------------------------------"<<endl;	
				cout<<"\n\ndesea buscar nuevamente numericamente? (1/si, diferente de 1 no)"<<endl;
				cin>>busq;
			}while(busq==1);
		}else{
			do{
				cout<<"\nescriba la clave alfanumerica a buscar: "<<endl;
				cin>>op;
				string alfanumerica="alfanumerica";
				buscar(op, cadenas,clavesNumericasAsociadas,n,unidas,alfanumerica);
				cout<<"--------------------------------------------------"<<endl;	
				cout<<"\n\ndesea buscar nuevamente de forma alfanumerica? (1/si, diferente de 1 no)"<<endl;
				cin>>busq;
			}while(busq==1);
		}
  }
 
}



int main (){

	
	string cadenas[]={"FazLW", "DzpSR", "QaErS", "eghIm", "JaNmq", "DeUsP", "EaChS", "DogfR", "NeBdW", "EnLaC"};
	int numeros[]={467, 419, 490, 420, 432, 444, 452, 449, 466, 471};
	detectar(cadenas,10,numeros);

	return 0;
}
