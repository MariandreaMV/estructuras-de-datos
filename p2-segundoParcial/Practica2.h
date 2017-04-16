#ifndef PRACTICA2_H
#define PRACTICA2_H

#include <iostream>
#include "ArchivoTXT.h"
#include "Operacion.h"

class Practica2{
	
	private:
	
	
	public:
		Practica2(){}
		
		void lineas(){
			cout<<"\n-------------------------------------------------------------------------"<<endl;
		}	
		
		int leer();
		void crear (int c,string *estruc,string *operacion,Cola_Array<string> e[]);
};


int Practica2::leer(){
	
	ArchivoTXT entrada("estructuras.txt");
	int cantEstruc;
	int tipoEstruc;
	string *estruc;
	int casos=1;
	if(!entrada.abrir())return -1;
	
	while(!entrada.isFinal()){
		lineas();
		cantEstruc=atoi(entrada.leerLinea().c_str());//	1
		cout<<"caso: "<<casos<<endl;casos++;
		cout<<"cantidad de estructuras: "<<cantEstruc<<endl;
		estruc=entrada.leerCampos(',',2+cantEstruc);//pila,numérico,6
		int c=2;
		string *contenido[cantEstruc];
		Cola_Array<string> e[cantEstruc];
		for(int i=0;i<cantEstruc;i++){
			int elementos=atoi(estruc[c].c_str());
			contenido[i]=entrada.leerCampos(',',elementos);//5,20,8,9,11,2
			Cola_Array<string> aux(elementos);
			for(int m=0;m<elementos;m++){
				aux.agregar(contenido[i][m]);
			}
			e[i]=aux;
			c++;
		}		
		string *operacion=entrada.leerCampos(',',2);//convertir,cola
		crear(cantEstruc,estruc,operacion,e);//origen a cada estructura y su operacion a realizar
	}
	
	return 1;
}

void Practica2::crear(int c,string *estruc,string *operacion,Cola_Array<string> e[]){
	
		string tipoE=estruc[0];
		string tipoD=estruc[1];
		int contador=2;
		int elementos=0;
		
		if(tipoE=="cola"){
			if(tipoD=="numerico"){
					cout<<"cola numerica:\n"<<endl;
					Cola_Array<int> colas[c];
					for(int i=0;i<c;i++){
					elementos=atoi(estruc[contador].c_str());//elementos por cola
					Cola_Array <int> AUXcola(elementos);
					int elemento=0;
						for(int m=0;m<elementos;m++){
							string ele;
							e[i].eliminar(ele);
							elemento=atoi(ele.c_str());
							AUXcola.agregar(elemento);
						}
					contador++;
					colas[i]=AUXcola;
					colas[i].imprimir();
					cout<<endl;
					}
				cout<<endl;
				cout<<"operacion a realizar: "<<" "<<tipoE<<" -> "<<operacion[0]<<" -> "<<operacion[1]<<endl;
				cout<<endl;

				if(c==2){
					Operacion< Cola_Array<int> > op(colas[0],colas[1],operacion[0],operacion[1],tipoE,tipoD);//magia jeje
					Cola_Array<int> resultante=op.getEstructura();
					if(operacion[1]=="pila"){
						Pila_Array<int> convertida(resultante.getsize());
						int H=0;
						int TAMANIO=resultante.getsize();
						while(H<TAMANIO){
							int ELI;
							resultante.eliminar(ELI);
							convertida.agregar(ELI);
							H++;
						}
						cout<<"CONVERTIDA A PILA: "<<endl;
						convertida.imprimir();
					}
					if(operacion[1]=="lista"){
						MyLinkedList<int> convertida;
						int H=0;
						int TAMANIO=resultante.getsize();
						while(H<TAMANIO){
							int ELI;
							resultante.eliminar(ELI);
							convertida.agregar(ELI);
							H++;
						}
						cout<<"CONVERTIDA A PILA: "<<endl;
						convertida.imprimir();
					}
					if(operacion[1]=="cola"){
						cout<<"CONVERTIDA A COLA: "<<endl;
						resultante.imprimir();
					}	
				}
					else{
					Operacion< Cola_Array<int> > op(colas[0],operacion[0],operacion[1],tipoE,tipoD);
					Cola_Array<int> resultante=op.getEstructura();
					if(operacion[1]=="pila"){
						Pila_Array<int> convertida(resultante.getsize());
						int H=0;
						int TAMANIO=resultante.getsize();
						while(H<TAMANIO){
							int ELI;
							resultante.eliminar(ELI);
							convertida.agregar(ELI);
							H++;
						}
						cout<<"CONVERTIDA A PILA: "<<endl;
						convertida.imprimir();
					}
					if(operacion[1]=="lista"){
						MyLinkedList<int> convertida;
						int H=0;
						int TAMANIO=resultante.getsize();
						while(H<TAMANIO){
							int ELI;
							resultante.eliminar(ELI);
							convertida.agregar(ELI);
							H++;
						}
						cout<<"CONVERTIDA A LISTA: "<<endl;
						convertida.imprimir();
					}
					if(operacion[1]=="cola"){
						cout<<"CONVERTIDA A COLA: "<<endl;
						resultante.imprimir();
					}
				}
				
			}else{
				if(tipoD=="cadena"||tipoD=="caracter"){
					if(tipoD=="cadena")
					cout<<"cola de cadena:\n"<<endl;
					if(tipoD=="caracter")
					cout<<"cola de caracteres:\n"<<endl;
					Cola_Array<string> colas[c];
					for(int i=0;i<c;i++){
					elementos=atoi(estruc[contador].c_str());//elementos por cola
					Cola_Array <string> AUXcola(elementos);
						for(int m=0;m<elementos;m++){
							string ele;
							e[i].eliminar(ele);
							AUXcola.agregar(ele);
						}
					contador++;
					colas[i]=AUXcola;
					colas[i].imprimir();
					cout<<endl;
					}
					cout<<endl;
					cout<<"operacion a realizar: "<<" "<<tipoE<<" -> "<<operacion[0]<<" -> "<<operacion[1]<<endl;
					
				if(c==2){
				Operacion< Cola_Array<string> > op(colas[0],colas[1],operacion[0],operacion[1],tipoE,tipoD);//magia jeje
				Cola_Array<string> resultante=op.getEstructura();
					if(operacion[1]=="pila"){
						Pila_Array<string> convertida(resultante.getsize());
						int H=0;
						int TAMANIO=resultante.getsize();
						while(H<TAMANIO){
							string ELI;
							resultante.eliminar(ELI);
							convertida.agregar(ELI);
							H++;
						}
						cout<<"CONVERTIDA A PILA: "<<endl;
						convertida.imprimir();
						cout<<endl;
					}
					if(operacion[1]=="lista"){
						MyLinkedList<string> convertida;
						int H=0;
						int TAMANIO=resultante.getsize();
						while(H<TAMANIO){
							string ELI;
							resultante.eliminar(ELI);
							convertida.agregar(ELI);
							H++;
						}
						cout<<"CONVERTIDA A PILA: "<<endl;
						convertida.imprimir();
					}
					if(operacion[1]=="cola"){
						cout<<"CONVERTIDA A COLA: "<<endl;
						resultante.imprimir();
					}	
					
				}
				
				else{
						Operacion< Cola_Array<string> > op(colas[0],operacion[0],operacion[1],tipoE,tipoD);
						Cola_Array<string> resultante=op.getEstructura();
							if(operacion[1]=="pila"){
								Pila_Array<string> convertida(resultante.getsize());
								int H=0;
								int TAMANIO=resultante.getsize();
								while(H<TAMANIO){
									string ELI;
									resultante.eliminar(ELI);
									convertida.agregar(ELI);
									H++;
								}
								cout<<"CONVERTIDA A PILA: "<<endl;
								convertida.imprimir();
							}
							if(operacion[1]=="lista"){
								MyLinkedList<string> convertida;
								int H=0;
								int TAMANIO=resultante.getsize();
								while(H<TAMANIO){
									string ELI;
									resultante.eliminar(ELI);
									convertida.agregar(ELI);
									H++;
								}
								cout<<"CONVERTIDA A PILA: "<<endl;
								convertida.imprimir();
							}
							if(operacion[1]=="cola"){
								cout<<"CONVERTIDA A COLA: "<<endl;
								resultante.imprimir();
							}						
					}
				}
			}//else
		}//fin cola
		
		if(tipoE=="pila"){
				if(tipoD=="numerico"){
					cout<<"pila numerica:\n"<<endl;
					Pila_Array<int> pilas[c];
					for(int i=0;i<c;i++){
					elementos=atoi(estruc[contador].c_str());//elementos por pila
					Pila_Array <int> AUXpila(elementos);
					int elemento=0;
						for(int m=0;m<elementos;m++){
							string ele;
							e[i].eliminar(ele);
							elemento=atoi(ele.c_str());
							AUXpila.agregar(elemento);
						}
					contador++;
					pilas[i]=AUXpila;
					pilas[i].imprimir();
					cout<<endl;
					}
				cout<<endl;
				cout<<"operacion a realizar: "<<" "<<tipoE<<" -> "<<operacion[0]<<" -> "<<operacion[1]<<endl;
				
				if(c==2){
					Operacion< Pila_Array<int> > op(pilas[0],pilas[1],operacion[0],operacion[1],tipoE,tipoD);//magia jeje
					Pila_Array<int> ope=op.getEstructura();
					
					if(operacion[1]=="pila"){
						cout<<"CONVERTIDA A PILA: "<<endl;
						ope.imprimir();
						cout<<endl;
					}
					
					Cola_Array<int> resultante=ope.getCola();
					
					if(operacion[1]=="lista"){
						MyLinkedList<int> convertida;
						int H=0;
						int TAMANIO=resultante.getsize();
						while(H<TAMANIO){
							int ELI;
							resultante.eliminar(ELI);
							convertida.agregar(ELI);
							H++;
						}
						cout<<"CONVERTIDA A LIST: "<<endl;
						convertida.imprimir();
					}
					if(operacion[1]=="cola"){
						cout<<"CONVERTIDA A COLA: "<<endl;
						resultante.imprimir();
					}		
				}
			
				else{
					Operacion< Pila_Array<int> > op(pilas[0],operacion[0],operacion[1],tipoE,tipoD);
					Pila_Array<int> ope=op.getEstructura();
					if(operacion[1]=="pila"){
						cout<<"CONVERTIDA A PILA: "<<endl;
						ope.imprimir();
						cout<<endl;
					}
					
					Cola_Array<int> resultante=ope.getCola();
					
					if(operacion[1]=="lista"){
						MyLinkedList<int> convertida;
						int H=0;
						int TAMANIO=resultante.getsize();
						while(H<TAMANIO){
							int ELI;
							resultante.eliminar(ELI);
							convertida.agregar(ELI);
							H++;
						}
						cout<<"CONVERTIDA A LISTA: "<<endl;
						convertida.imprimir();
					}
					if(operacion[1]=="cola"){
						cout<<"CONVERTIDA A COLA: "<<endl;
						resultante.imprimir();
					}		
					
				}

				}else{
				if(tipoD=="cadena"||tipoD=="caracter"){
					if(tipoD=="cadena")
					cout<<"pila de cadena:\n"<<endl;
					if(tipoD=="caracter")
					cout<<"pila de caracteres:\n"<<endl;
					Pila_Array<string> pilas[c];
					for(int i=0;i<c;i++){
					elementos=atoi(estruc[contador].c_str());//elementos por pila
					Pila_Array <string> AUXpila(elementos);
						for(int m=0;m<elementos;m++){
							string ele;
							e[i].eliminar(ele);
							AUXpila.agregar(ele);
						}
					contador++;
					pilas[i]=AUXpila;
					pilas[i].imprimir();
					cout<<endl;
					}
					cout<<endl;
					cout<<"operacion a realizar: "<<" "<<tipoE<<" -> "<<operacion[0]<<" -> "<<operacion[1]<<endl;
					
				if(c==2){
					Operacion< Pila_Array<string> > op(pilas[0],pilas[1],operacion[0],operacion[1],tipoE,tipoD);//magia jeje
					Pila_Array<string> ope=op.getEstructura();
					if(operacion[1]=="pila"){
					
						cout<<"CONVERTIDA A PILA: "<<endl;
						ope.imprimir();
					}
					
					Cola_Array<string> resultante=ope.getCola();
					
					if(operacion[1]=="lista"){
						MyLinkedList<string> convertida;
						int H=0;
						int TAMANIO=resultante.getsize();
						while(H<TAMANIO){
							string ELI;
							resultante.eliminar(ELI);
							convertida.agregar(ELI);
							H++;
						}
						cout<<"CONVERTIDA A LISTA: "<<endl;
						convertida.imprimir();
					}
					if(operacion[1]=="cola"){
						cout<<"CONVERTIDA A COLA: "<<endl;
						resultante.imprimir();
					}		
				}
				
				else{
					Operacion< Pila_Array<string> > op(pilas[0],operacion[0],operacion[1],tipoE,tipoD);
					Pila_Array<string> ope=op.getEstructura();
					
					if(operacion[1]=="pila"){
						cout<<"CONVERTIDA A PILA: "<<endl;
						ope.imprimir();
					}
					
					Cola_Array<string> resultante=ope.getCola();
						
					if(operacion[1]=="lista"){
						MyLinkedList<string> convertida;
						int H=0;
						int TAMANIO=resultante.getsize();
						while(H<TAMANIO){
							string ELI;
							resultante.eliminar(ELI);
							convertida.agregar(ELI);
							H++;
						}
						cout<<"CONVERTIDA A LISTA: "<<endl;
						convertida.imprimir();
					}
					if(operacion[1]=="cola"){
						cout<<"CONVERTIDA A COLA: "<<endl;
						resultante.imprimir();
					}							
					
				}
				
				}
			}//else
		
		}//fin pila
		
		if(tipoE=="lista"){
			if(tipoD=="numerico"){
					cout<<"lista numerica:\n"<<endl;			
					MyLinkedList<int> listas[c];
					for(int i=0;i<c;i++){
					elementos=atoi(estruc[contador].c_str());//elementos por lista
					MyLinkedList <int> AUXlista;
					int elemento=0;
						for(int m=0;m<elementos;m++){
							string ele;
							e[i].eliminar(ele);
							elemento=atoi(ele.c_str());
							AUXlista.agregar(elemento);
						}
					contador++;
					listas[i]=AUXlista;
					listas[i].imprimir();
					cout<<endl;
					}
				cout<<endl;
				cout<<"operacion a realizar: "<<" "<<tipoE<<" -> "<<operacion[0]<<" -> "<<operacion[1]<<endl;
				
				if(c==2){
					Operacion< MyLinkedList<int> > op(listas[0],listas[1],operacion[0],operacion[1],tipoE,tipoD);//magia jeje
					MyLinkedList<int> ope=op.getEstructura();
					
					if(operacion[1]=="lista"){
						cout<<"CONVERTIDA A LISTA: "<<endl;
						ope.imprimir();
					}

					Cola_Array<int> resultante=ope.getCola();
					
					if(operacion[1]=="pila"){
						cout<<"CONVERTIDA A pila: "<<endl;
						Pila_Array<int> convertida(resultante.getsize());
						int H=0;
						int TAMANIO=resultante.getsize();
						while(H<TAMANIO){
							int ELI;
							resultante.eliminar(ELI);
							convertida.agregar(ELI);
							
							H++;
						}
						ope.imprimir();
						convertida.imprimir();
					}
					if(operacion[1]=="cola"){
						cout<<"CONVERTIDA A COLA: "<<endl;
						resultante.imprimir();
					}
					
				}
				else{
					Operacion< MyLinkedList<int> > op(listas[0],operacion[0],operacion[1],tipoE,tipoD);
					MyLinkedList<int> ope=op.getEstructura();
					if(operacion[1]=="lista"){
						cout<<"CONVERTIDA A LISTA: "<<endl;
						ope.imprimir();
					}
					
					Cola_Array<int> resultante=ope.getCola();
	
					if(operacion[1]=="pila"){
						Pila_Array<int> convertida(resultante.getsize());
						int H=0;
						int TAMANIO=resultante.getsize();
						while(H<TAMANIO){
							int ELI;
							resultante.eliminar(ELI);
							convertida.agregar(ELI);
							H++;
						}
						cout<<"CONVERTIDA A pila: "<<endl;
						convertida.imprimir();
					}
					if(operacion[1]=="cola"){
						cout<<"CONVERTIDA A COLA: "<<endl;
						resultante.imprimir();
					}
				}
				
				
			}else{
				if(tipoD=="cadena"||tipoD=="caracter"){	
					if(tipoD=="cadena")
					cout<<"lista de cadena:\n"<<endl;
					if(tipoD=="caracter")
					cout<<"lista de caracteres:\n"<<endl;
					MyLinkedList<string> listas[c];
					for(int i=0;i<c;i++){
					elementos=atoi(estruc[contador].c_str());//elementos por lista
					MyLinkedList <string> AUXlista;
						for(int m=0;m<elementos;m++){
							string ele;
							e[i].eliminar(ele);
							AUXlista.agregar(ele);
						}
					contador++;
					listas[i]=AUXlista;
					listas[i].imprimir();
					cout<<endl;	
					}
					cout<<endl;
					cout<<"operacion a realizar: "<<" "<<tipoE<<" -> "<<operacion[0]<<" -> "<<operacion[1]<<endl;
					
				if(c==2){
					Operacion< MyLinkedList<string> > op(listas[0],listas[1],operacion[0],operacion[1],tipoE,tipoD);//magia jeje
					MyLinkedList<string> ope=op.getEstructura();
					if(operacion[1]=="lista"){
						cout<<"CONVERTIDA A LISTA: "<<endl;
						ope.imprimir();
					}
					
					Cola_Array<string> resultante=ope.getCola();

					if(operacion[1]=="pila"){
						Pila_Array<string> convertida(resultante.getsize());
						int H=0;
						int TAMANIO=resultante.getsize();
						while(H<TAMANIO){
							string ELI;
							resultante.eliminar(ELI);
							convertida.agregar(ELI);
							H++;
						}
						cout<<"CONVERTIDA A pila: "<<endl;
						ope.imprimir();
						convertida.imprimir();
					}
					if(operacion[1]=="cola"){
						cout<<"CONVERTIDA A COLA: "<<endl;
						resultante.imprimir();
					}
					
				}
				else{
					Operacion< MyLinkedList<string> > op(listas[0],operacion[0],operacion[1],tipoE,tipoD);
					MyLinkedList<string> ope=op.getEstructura();
					
					if(operacion[1]=="lista"){
						cout<<"CONVERTIDA A LISTA: "<<endl;
						ope.imprimir();
					}
					
					Cola_Array<string> resultante=ope.getCola();
						
					if(operacion[1]=="pila"){
						Pila_Array<string> convertida(resultante.getsize());
						int H=0;
						int TAMANIO=resultante.getsize();
						while(H<TAMANIO){
							string ELI;
							resultante.eliminar(ELI);
							convertida.agregar(ELI);
							H++;
						}
						cout<<"CONVERTIDA A PILA: "<<endl;
						convertida.imprimir();
					}
					if(operacion[1]=="cola"){
						cout<<"CONVERTIDA A COLA: "<<endl;
						resultante.imprimir();
					}
					
					
				}
				
			}
			}//else
		}//fin lista	
}
#endif
