#include <iostream>
#include <fstream>
#include<string.h>
#include <vector>
#include <set>
#include "Archivo.h"
#include "Libro.h"

using namespace std;

void lineas(){
	cout<<"-----------------------------------------------------------------------"<<endl;
}

void GenerarArchivoBinario(vector<int>&cantEditoriales,int &tamanio){
	
	Archivo *inLibros;
	Archivo *inEditorial=new Archivo("editorial.txt");
	fstream ArchivoBinario;
	ArchivoBinario.open("LIBROS.dat",ios::out|ios::binary);
	inEditorial->abrir();
	int contadorLibros=0;
	cout<<"codigo:\tEDITORIAL:\t"<<"\tTITULO:\t\t"<<"\tAUTOR:"<<endl;
	lineas();
	while(true){
	
		if(inEditorial->isFinal()){
		break;
		}
		string *editoriales=inEditorial->leerCampos(',',2);
		inLibros=new Archivo("libro.txt");
		inLibros->abrir();
		contadorLibros=0;
				while(true){
					
					if(inLibros->isFinal()){
						break;
					}
					string *linea;
					linea=inLibros->leerCampos(',',3);
					// linea[0]=codigo  linea[1]=titulo  linea[2]=autor
					if(editoriales[0].compare(linea[0])==0){
					Libro libro(linea[0],linea[1],linea[2],editoriales[1]);
					libro.imprimir();
					contadorLibros++;
					tamanio++;
					ArchivoBinario.write((char *)&libro,sizeof(Libro));
					}
				}
		cantEditoriales.push_back(contadorLibros);
		inLibros->~Archivo();
	}		
	inEditorial->~Archivo();
	ArchivoBinario.close();	
}


void Partir ( fstream &f, fstream &f1, fstream &f2, int &T )
{
     Libro buf;
     int c1=0, c2;
     f.open("AUXILIAR1.dat" ,ios::in  | ios::binary);
     f1.open("part1.dat",ios::out | ios::binary); 
     f2.open("part2.dat",ios::out | ios::binary); 
     f.clear(); f1.clear(); f2.clear();
     f.seekg(0,ios::beg); 
     while (true)
     {
        f.read( (char *) &buf, sizeof(buf) );
        if ( f.eof() ) break;
        if ( c1<T )
        {
             f1.write( (char *) &buf, sizeof(buf) );
             c1++; 
             if ( c1==T ) c2=0; 
        }
        else
        {
             f2.write( (char *) &buf, sizeof(buf) );
             c2++; 
             if ( c2==T ) c1=0; 
        }
     } // fin while
     f.close();
     f1.close();
     f2.close();  
}

void Mezclar ( fstream &f, fstream &f1, fstream &f2, int &T, int &N)
{
     Libro buf1, buf2;
     int c1=0, c2=0;
     f.open("AUXILIAR1.dat" ,ios::out | ios::binary);
     f1.open("part1.dat",ios::in  | ios::binary); 
     f2.open("part2.dat",ios::in  | ios::binary); 
     f1.clear(); f2.clear(); f.clear();
     f1.seekg(0,ios::beg);
     f2.seekg(0,ios::beg); 
     f1.read( (char *) &buf1, sizeof(buf1) );
     f2.read( (char *) &buf2, sizeof(buf2) );
     for ( int i=0; i<N; i++ )
     {
       if ( buf1<buf2 )
       {
          if ( c1<T )
          {
            f.write( (char *) &buf1, sizeof(buf1) );
            c1++;
            f1.read( (char *) &buf1, sizeof(buf1) );
          }
          else
          {
            f.write( (char *) &buf2, sizeof(buf2) );
            c2++;
            f2.read( (char *) &buf2, sizeof(buf2) );  
          }        
       }
       else 
       {
          if ( c2<T )
          {
            f.write( (char *) &buf2, sizeof(buf2) );
            c2++;
            f2.read( (char *) &buf2, sizeof(buf2) );
          } 
          else
          {
            f.write( (char *) &buf1, sizeof(buf1) );
            c1++;
            f1.read( (char *) &buf1, sizeof(buf1) );  
          }       
       }
       if ( c1==T && c2==T ) c1=c2=0;
     }// fin for
     f.close();
     f1.close();
     f2.close();  
} 

void Ordenar ( fstream &arc, int &N )
{
     fstream p1, p2;
     int bloq=1;
     while ( bloq<N )
     {
        Partir ( arc, p1, p2, bloq );
        Mezclar( arc, p1, p2, bloq, N );
        bloq *=2;
     }
}

void OrdenarArchivoBinario(vector <int> cantEditoriales){
	Libro data;
	fstream inDatos,aux1,aux2,FINAL;
	inDatos.open("LIBROS.dat",ios::in|ios::binary);
	
	FINAL.open("LIBROSsorted.dat",ios::out|ios::binary);
	FINAL.clear();
	
	if(inDatos.fail()){
		cout<<"error al abrir archivo"<<endl;	
	}else{
		
		int c1=0;
		int c2=0;
		int start=0;
		
		for(int c1=0;c1<cantEditoriales.size()-1;c1++){
			//cout<<"----------------inicia mi auxiliar 1------------------"<<endl;
			aux1.open("AUXILIAR1.dat",ios::out|ios::binary);
			aux1.clear();
			
			inDatos.seekg(start,ios::beg); 
			//cout<<c2<<" "<<cantEditoriales[c1]<<endl;
			while(c2<cantEditoriales[c1]){	
			c2++;	
			inDatos.read((char *)&data,sizeof(Libro));
			//data.imprimir();
			aux1.write((char *)&data,sizeof(Libro));
			}
			c2=0;
			inDatos.close();	
			inDatos.open("LIBROS.dat",ios::in|ios::binary);
			start+=cantEditoriales[c1]*sizeof(Libro);
			//cout<<start<<endl;
			aux1.close();
			//cout<<"----------------fin mi auxilia 1------------------"<<endl;
			
			//-----------------------------------------------------------------------------------------------------
			Ordenar(aux1,cantEditoriales[c1]);//aqui la magia del profe pero solo funciona para n cantidades pares
			//------------------------------------------------------------------------------------------------------
			
			//cout<<"---------------- mi auxilia 1 sorted y anadiendo a FINALE------------------"<<endl;
			aux1.open("AUXILIAR1.dat",ios::in|ios::binary);
			aux1.clear();
			int ayuda=0;
			while(ayuda<cantEditoriales[c1]){		
			aux1.read((char *)&data,sizeof(Libro));
			FINAL.write((char *)&data,sizeof(Libro));
			if(aux1.eof())break;
			ayuda++;
			//data.imprimir();
			}
			ayuda=0;
			aux1.close();
			//cout<<"----------------fin mi auxilia 1 sorted------------------"<<endl;
		}
		FINAL.close();		
	}			
}

void OrdenarArchivoBinarioAlfabeticamenteBubbleSort(int tamanio){
	
	Libro libro;
	fstream inaux;
	vector <Libro> ordena;
	inaux.open("LIBROS.dat",ios::in|ios::binary);
	int n=0;
	while(n<tamanio){
		inaux.read((char *)&libro,sizeof(Libro));
		//if(inaux.eof())break;
		//libro.imprimir();
		ordena.push_back(libro);
		n++;
	}
	inaux.close();
	bool band=true;
	
	for(int a=0; a<ordena.size()&&band==true;a++){
		band=false;
		for(int i=0;i<tamanio-1;i++){
		
			if(!(ordena[i]<ordena[i+1])){
				Libro auxiliar =ordena[i];
				ordena[i]=ordena[i+1];
				ordena[i+1]=auxiliar;
				band=true;
			}
		}		
	}
	/*
	cout<<"se supone que estan ordenados"<<endl;
	for(int i=0;i<ordena.size();i++){
			ordena[i].imprimir();
		}	
	*/
	cout<<"codigo:\tEDITORIAL:\t"<<"\tTITULO:\t\t"<<"\tAUTOR:"<<endl;
	lineas();
	inaux.open("LIBROS.dat",ios::out|ios::binary);
	n=0;
	while(n<ordena.size()){
		inaux.write((char *)&ordena[n],sizeof(Libro));
	//	if(inaux.eof())break;
		ordena[n].imprimir();
		n++;
	}
	inaux.close();	
}

void ImprimirArchivoOrdenado(){
	fstream FINAL;
	Libro data;
	cout<<"codigo:\tEDITORIAL:\t"<<"\tTITULO:\t\t"<<"\tAUTOR:"<<endl;
	lineas();
	FINAL.open("LIBROSsorted.dat",ios::in|ios::binary);	
		//cout<<"---------------- FINAL sorted------------------"<<endl;
		while(true){		
			FINAL.read((char *)&data,sizeof(Libro));
			if(FINAL.eof())break;
			data.imprimir();
			}
		FINAL.close();
		//cout<<"----------------fin FINAL sorted------------------"<<endl;	
}

int Menu(){
	int op=0;
	lineas();
	do{
	
	cout<<"\n\n"<<endl;
	lineas();
	cout<<"1)BUSQUEDA POR CODIGO Y TITULO."<<endl;
	cout<<"2)BUSQUEDA POR TITULO."<<endl;
	cin>>op;
	if(op!=1&&op!=2){
	lineas();
	cout<<"opcion no disponible intente nuevamente"<<endl;
	lineas();
	}
	}while(op!=1&&op!=2);
	lineas();
	
	return op;
}

void reporte(int codigo){
	
	lineas();
	fstream FINAL;
	Libro libro;
	FINAL.open("LIBROSsorted.dat",ios::in|ios::binary);
	FINAL.clear();
	int total=0;
	cout<<"(REPORTE)LIBROS EXISTENTES DE LA EDITORIAL CON CODIGO: "<<codigo<<endl;
	lineas();
	while(true){
		FINAL.read((char *)&libro,sizeof(Libro));
		if(FINAL.eof()){
			break;
		}
		if(libro.getCodigo()==codigo){
		total++;
		libro.imprimir();
		}
	}
	
	FINAL.close();
	lineas();
	cout<<"TOTAL: "<<total<<" LIBROS DE LA EDITORIAL: "<<codigo<<endl;
	lineas();
}

void BusquedaPorCodigoTitulo(vector <int> cantEditoriales){
	
	fstream FINAL;
	Libro libro;
	string titulo;
	int codigo=0;
	lineas();
	
	cout<<"INGRESE EL CODIGO"<<endl;
	cin>>codigo;
	cin.ignore(256,'\n');
	cout<<"INGRESE EL TITULO (CONSIDERE LAS MATUSCULAS)"<<endl;
	getline(cin,titulo);
	
	FINAL.open("LIBROSsorted.dat",ios::in|ios::binary);
	FINAL.clear();
	cout<<"\n\n---------------------IMPRIMIENDO POR BUSQUEDA--------------------------"<<endl;
	lineas();
	while(true){
		FINAL.read((char *)&libro,sizeof(Libro));
		if(FINAL.eof()){
			lineas();
			cout<<"LIBRO: "<<titulo<<" NO ENCONTRADO."<<endl;
			lineas();
			break;
		}

		if(libro.getCodigo()==codigo){
		libro.imprimir();
		string aux=" "+titulo;
			if(libro.getTitulo().compare(aux)==0){
				cout<<"\n\n------------------------------ENCONTRADO-------------------------"<<endl;
				lineas();
				cout<<"codigo:\tEDITORIAL:\t"<<"\tTITULO:\t"<<"\tAUTOR:"<<endl;
				lineas();
				libro.imprimir();
				lineas();
				break;
			}
		}
	}
	FINAL.close();
	reporte(codigo);
}

void EsMayorAm(string titulo){
	fstream FINAL;
	Libro libro;
	FINAL.open("LIBROSsorted.dat",ios::in|ios::binary);
	FINAL.clear();
	int codigo=0;
	cout<<"\n\n---------------------IMPRIMIENDO POR BUSQUEDA--------------------------"<<endl;
	lineas();
	int cant=0;
	
	while(true){
		FINAL.read((char *)&libro,sizeof(Libro));
		if(FINAL.eof()){
			break;
		}
		cant++;
	}
	FINAL.close();
	cant--;
	int bytes=cant*sizeof(Libro);
	string aux=" "+titulo;
	while(cant>=0){
		FINAL.open("LIBROSsorted.dat",ios::in|ios::binary);
		FINAL.clear();
		FINAL.seekg(bytes,ios::beg);
		FINAL.read((char *)&libro,sizeof(Libro));
		libro.imprimir();
		if(libro.getTitulo().compare(aux)==0){
				cout<<"\n\t\t\tENCONTRADO"<<endl;
				lineas();
				cout<<"codigo:\tEDITORIAL:\t"<<"\tTITULO:\t"<<"\tAUTOR:"<<endl;
				lineas();
				libro.imprimir();
				lineas();
				codigo=libro.getCodigo();
				FINAL.close();
				break;
		}
		cant--;
		bytes=cant*sizeof(Libro);
		FINAL.close();
	}
	
	reporte(codigo);
	
	
}

void EsMenorAm( string titulo){
	
	fstream FINAL;
	Libro libro;
	FINAL.open("LIBROSsorted.dat",ios::in|ios::binary);
	FINAL.clear();
	int codigo=0;
	cout<<"\n\n---------------------IMPRIMIENDO POR BUSQUEDA--------------------------"<<endl;
	lineas();
	while(true){
		
		FINAL.read((char *)&libro,sizeof(Libro));
		if(FINAL.eof()){
			cout<<"libro: "<<titulo<<" no encontrado."<<endl;
			break;
		}
		libro.imprimir();
		string aux=" "+titulo;
			if(libro.getTitulo().compare(aux)==0){
				cout<<"\n\t\t\tENCONTRADO"<<endl;
				lineas();
				cout<<"codigo:\tEDITORIAL:\t"<<"\tTITULO:\t"<<"\tAUTOR:"<<endl;
				lineas();
				libro.imprimir();
				lineas();
				codigo=libro.getCodigo();
				break;
			}
	}
		FINAL.close();
		reporte(codigo);
}

void BusquedaPorTitulo(vector <int>cantEditoriales){	
	string titulo;
	int codigo;
	lineas();
	
	cin.ignore(256,'\n');
	cout<<"INGRESE EL TITULO (CONSIDERE LAS MATUSCULAS)"<<endl;
	getline(cin,titulo);
	lineas();

	fstream FINAL;
	Libro libro;
	FINAL.open("LIBROSsorted.dat",ios::in|ios::binary);
	FINAL.clear();
	
	if(titulo[0]>='M'){
		//cout<<"mayor a m"<<endl;
		EsMayorAm(titulo);
	}else{
		//cout<<"menor a m"<<endl;
		EsMenorAm(titulo);
	}
	
	
}

void Busqueda(int op,vector <int>cantEditoriales){
	switch(op){
		case 1: BusquedaPorCodigoTitulo(cantEditoriales);
				break;
		case 2: BusquedaPorTitulo(cantEditoriales);
				break;
	}
}

int main (){
	
	vector <int>cantEditoriales;
	int contadorEditoriales=0;
	int tamanio=0;
	cout<<"\n----CARGANDO DATA , GENERANDO ARCHIVO Y ORDENANDO POR EDITORIAL---------"<<endl;
	lineas();
	GenerarArchivoBinario(cantEditoriales,tamanio);
	cout<<"\n----------ARCHIVO ORDENADO (CADA EDITORIAL ALFABETICAMENTE)------------"<<endl;
	lineas();
	OrdenarArchivoBinario(cantEditoriales);
	ImprimirArchivoOrdenado();
	//cout<<"\n--------------------ORDENADOS SOLO ALFABETICAMENTE---------------------"<<endl;
	//cout<<"-----------------------------------------------------------------------"<<endl;
	//OrdenarArchivoBinarioAlfabeticamenteBubbleSort(tamanio);
	int again=0;
	do{	
	int op= Menu();
	Busqueda(op,cantEditoriales);
	lineas();
	cout<<"DESEA REALIZAR OTRA BUSQUEDA? 1)SI    cualquier otro)NO "<<endl;
	cin>>again;
	lineas();
	}while(again==1);
	return 0;
}
