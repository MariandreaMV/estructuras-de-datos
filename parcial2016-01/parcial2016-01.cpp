#include <iostream>
#include<stdlib.h>
#include<time.h>
#include <fstream>
#include <cstring>
#include <sstream>
//istreamString sstream

using namespace std;

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

void lectura(string ruta, string *&nombres,int &cont){
	
	ifstream file(ruta.c_str());
	string line;
	char *split;
	
	while(getline(file,line))
	{
		split = strtok(&line[0], " ");
		cont = 0;
		while(split != NULL) 
		{	
	    	split = strtok (NULL, " ");
	    	cont++;	
		}
	}
	file.close();
	file.clear();
	file.open(ruta.c_str());
	
	nombres=new string[cont];

	while(getline(file,line))
	{
		split = strtok(&line[0], " ");
		cont = 0;
		while(split != NULL) 
		{	
			nombres[cont] = split;
	    	split = strtok (NULL, " ");
	    	cont++;	
		}
	}
	
}

int main (){
	

	string *nombres;
	int n;
	
	lectura("nombres.txt",nombres,n);
	for(int i = 0; i < n; i++) cout << nombres[i] << endl;
	
	/*	
	while(iss.getline(buffer,120,' ')){		
	}*/		
	/*
	char* names =strtok(&name[0]," ");
			
	while(names != NULL){
		cout << names << endl;		
		names = strtok(NULL, " ");
	}*/


	int size=10;
	int array[size];
	srand (time(NULL));
	
	no_repeat(array,size);
	cout<<"\nUNSORTED\n"<<endl;
	show_me(array,size);
	
	
	
	return 0;
}
