#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <algorithm>

using namespace std;


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


void detectar(string cadenas[],int n){
	int clavesNumericas[n];
	string letras[10];
	int contador=0;
	
	for(int i = 0; i < 10; i++){
	//	cout<<cadenas[i]<<endl;
		contador=0;
    	for(int j = 0; j < cadenas[i].size(); j++){
      	string aux = cadenas[i];
     	 if(isdigit(aux[j])){
        	//cout<< "numero" << endl;        
			}else{
       		 //cout << "letra" << endl;      		 
			contador+=aux[j];
     		letras[i]+=aux[j];
      		}
    	}
    	//cout<<contador<<endl;
    //	cout<<letras[i]<<endl;
		clavesNumericas[i]=contador;
  	}
  	
  	selection_sort(clavesNumericas,n,letras);
 // 	selection_sortLETRAS(letras,n);
  	show_me2(letras,n,clavesNumericas);
  	cout<<endl;
  	for(int p=0;p<n;p++){
  		sort(letras[p].begin(),letras[p].end());
	  }
	show_me2(letras,n,clavesNumericas);
  	
}

int main (){

	string cadenas[]={"F135a69z190L58W","D3z198p60S200R6","Q121a80E115r128S","e120g71h210I89m",
						"J95a67N212m96q1","D112e70U200s67P","E35a200C15h90S80","65D100o16g200f85R",
						"N95e70B118d149W","97E32n150L62a78D1"};
	
	detectar(cadenas,10);
	return 0;
}

	/*
	for(int i =0;i<n;i++){
		contador=0;
			//cout<<cadenas[i]<<endl;
		for(int j=0;j<cadenas[i].size();j++){
			//cout<<cadenas[i][j]<<endl;	
			if(atoi(cadenas[i][j])>0&&atoi(cadenas[i][j])<10){
				contador+=cadenas[i][j];
				cout<<"entre"<<endl;	
			}
		}
		clavesNUMERICAS[i]=contador;
		cout<<contador<<endl;
	}*/
