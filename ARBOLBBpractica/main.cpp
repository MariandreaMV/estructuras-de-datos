#include <iostream>
#include "ArbolBB.h"
#include "ArchivoTXT.h"
#include "ArbolAVL.h"



int main() {
	
	ArbolBB<int> arbolBB,arbolBB2;
	ArchivoTXT leer("claves.txt");
	MyLinkedList< ArbolBB<int> > arboles;
	MyLinkedList< ArbolBB<int> > arboles2;
	MyLinkedList< ArbolBB<int> > sonAVL;
	int cantAVL=0;
	
	//--------------------------------creacion de los arboles e impresion en PRE-ORDEN-------------------------------------------
	if(leer.abrir()){
		int CONT=1;
		
		while(true){
			
			string linea=leer.leerLinea();
		 	cout<<"\nARBOL N:"<<CONT<<"\nElementos a ingresar:"<<linea<<"\n"<<endl;
		 	CONT++;
			int a=0;
			string aux="";
			ArbolBB<int> arbol;
			while(true){
				
				if(linea[a]==','){
					
					int numero=atoi(aux.c_str());
					arbol.Agregar(numero);
					//cout<<numero<<endl;
					aux="";
				}
				else {
					aux=aux+linea[a];
				}
				a++;
				if(!linea[a]) break;
				
			}
			arboles2.agregar(arbol);
			arboles.agregar(arbol);
			arbol.InOrden();
			arbol.PreOrden();
			
			if(arbol.isAVL()){
				cout<<"\nES AVL"<<endl;
				sonAVL.agregar(arbol);
				cantAVL++;
			} 
			else cout<<"\nNO ES AVL"<<endl;
			
	
			cout<<"----------------------------------------------------------------"<<endl;
			
			if(leer.isFinal())break;
		}
		
	}else{
		cout<<"no se pudo abrir el archivo"<<endl;
	}
	system("PAUSE");
	system("cls");
	
	//-----------------------------------------------CUANTOS SON AVL-----------------------------------------------------------
	cout<<"\n\nCANTIDAD DE ARBOLES AVL: "<<cantAVL<<" estos son:"<<endl;
	sonAVL.imprimirClase();
	system("PAUSE");
	system("cls");
	
	
	//-----------------------------------------ARBOLES CON LA MISMA ESTRUCTURA-----------------------------------------------------
	
	ArbolBB<int> saliente;
	ArbolBB<int> siguiente;
	
	while(!arboles.isEmpty()){
			cout<<"\t\tARBOLES CON LA MISMA ESTRUCTURA:\n"<<endl;
			int cont=0;
			arboles.eliminarComoColaDePrioridad(saliente);
			int mismaE=0;
			int cantInicial=arboles.getSize();
			cout<<"arbol a comparar:"<<endl;
			saliente.InOrden();cout<<endl;
			MyLinkedList< ArbolBB<int> > igualE;
			while(cont<cantInicial){
				arboles.eliminarComoColaDePrioridad(siguiente);
				cout<<"con: "<<endl;
				siguiente.InOrden();
				
				if(saliente.CompararArbolesEstructura(siguiente)){
					igualE.agregar(siguiente);
					//siguiente.InOrden();//este seria uno de los arboles con la misma estructura
					mismaE++;
				}else{
					arboles.agregar(siguiente);
				}
			cont++;				
			}
			if(mismaE>0)cout<<"\n\n\nEXISTEN "<<mismaE+1<<" con la siguiente estructura:"<<endl;
			else cout<<"\n\n\nES UNICO con esta estructura"<<endl;
			saliente.InOrden();
			igualE.imprimirClase();
			cout<<endl;
			system("PAUSE");
			system("cls");
			cont++;
	}
	int c=1;
	int a=arboles2.getSize();
	int A=0;
	
	
	//------------------------------------------------ALTURA DE ARBOLES----------------------------------------------------------------
	while(A<a){
		cout<<"\t\t ALTURA DE ARBOL "<<c<<":"<<endl;
		c++;
		ArbolBB<int> aux;
		arboles2.eliminarComoColaDePrioridad(aux);
		aux.InOrden();
		cout<<"-----------------"<<endl;
		cout<<"ALTURA:"<<aux.getAlturaArbol()-1<<endl;
		cout<<"----------------------------------------------------------------"<<endl;
		cout<<endl;
		arboles2.agregar(aux);
		A++;
	}
	
	//----------------------------------------------IMPRIMIR ARBOLES DESDE UN NIVEL---------------------------------------------------
	system("PAUSE");
	system("cls");
	cout<<"Ingrese el nivel desde el cual desea imprimir los arboles: ";
	int level;
	cin>>level;
	system("cls");
	cout<<"\t\tARBOLES DESDE EL NIVEL: "<<level<<endl;
	arboles2.imprimirARBOLdesdeNivel(level);
	
	//-----------------------------------------------SIMETRIA DE ARBOLES----------------------------------------------------------------
	A=0;
	int simetria=0;
	MyLinkedList<ArbolBB<int> > simetricos;
	system("PAUSE");
	system("cls");
	cout<<"\t\t ARBOLES SIMETRICOS: "<<endl;
	while(A<a){
			ArbolBB<int> aux;
			arboles2.eliminarComoColaDePrioridad(aux);
			if(aux.isSimetrico()){
				simetricos.agregar(aux);
				simetria++;	
				arboles2.agregar(aux);
			}
			 A++;
	}
	
	cout<<"cantidad de arboles simetricos: "<<simetria<<" estos son:"<<endl;
	arboles2.imprimirClase();
	
	//------------------------------------------CUANTOS SE PUEDEN REESTRUCTURAR---------------------------------------------------------
	//FALTO :c
	system("PAUSE");
	system("cls");
	cout<<"\n\n\n\nMARIANDREA DE LA CONSOLACION MALDONADO VAZQUEZ."<<endl;
	cout<<"CI. V-24693522"<<endl;
	cout<<"ESTRUCTURA DE DATOS \nSECCION. 1\n\n\n"<<endl;
	system("PAUSE");
	return 0;
}
