#include <iostream>
#include <stdlib.h>
#include<string.h>
#include <time.h>
#include <windows.h>

#include "archivoTXT.h"
#include "Pila_Array.h"
#include "Cola_Array.h"
#include "Cola_circular.h"
#include "Jugadores.h"
#include "Tablero.h"
#include "Sort.h"

using namespace std;

class  Juego{
	
	private:
		
		int *tablero;
		int participantes;
		
		Jugadores *jugadores;
		Tablero *tabla;
		
		
	public:
		juego(){
			
		}
		
		int dado();
		void cargarTablero();
		void menuJugadores(int dimension);
		void jugar(int tamano);		
		void lineas();
};

void Juego::lineas(){
	cout<<"---------------------------------------------------------------------"<<endl;
}

void Juego::cargarTablero(){
	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	ArchivoTXT leer("tablero.txt");
	if(leer.abrir()){
		
		string *dimension;	
		dimension=leer.leerCampos(' ',2);
		cout<<"filas: "<<dimension[0]<<" columnas: "<<dimension[1]<<endl;	
		int tamano=atoi(dimension[0].c_str())*atoi(dimension[1].c_str());
			
		tablero=new int [tamano];
		Pila_Array<int> pila(tamano);
		int c;
		
		while(true){
			
			string *in;	
			in=leer.leerCampos(' ',atoi(dimension[1].c_str()));	
			c=0;
		
			while(c<atoi(dimension[1].c_str())){
			int valor =atoi(in[c].c_str());
			pila.agregar(valor);
			c++;
			}
			
			if(leer.isFinal()){
				break;
			}
				
		}
		
		cout<<endl;
		lineas();
		cout<<"----------------CAMINO A RECORRER------------"<<endl;
		lineas();
		
		
		SetConsoleTextAttribute(hConsole, 11 );
		pila.imprimir(atoi(dimension[1].c_str()));
		
		c=0;
		int colores=9;
		for(int i=0;i<tamano;i++){
			int extraer;
			pila.eliminar(extraer);
			tablero[i]=extraer;
			SetConsoleTextAttribute(hConsole, colores );
		//	cout<<"\t"<<extraer;						//simplemente imprimo mi recorrido
			c++;
			if(c==atoi(dimension[1].c_str())){
				c=0;
		//		cout<<endl;
				colores++;
			}
		}
		SetConsoleTextAttribute(hConsole, 7 );
		tabla =new Tablero(tamano,tablero);		
		menuJugadores(tamano);
	}
}

int Juego::dado(){
	return rand()%6+1;
	
	
}

void Juego::menuJugadores(int dimension){
	
	cout<<"\n----------ingrese cantidad de jugadores---------"<<endl;
	cin>>participantes;
	
	jugadores=new Jugadores[participantes];
	string nombre;
	cin.clear();
	lineas();
	for(int i=0;i<participantes;i++){
	cout<<"NOMBRE DEL JUGADOR #"<<i+1<<endl;
	cin>>nombre;
	int turno=dado();//dado al azar para ver que turno le tocara
	Jugadores aux(nombre,dimension,turno);
	jugadores[i]=aux;
	jugadores[i].informacionN();
	lineas();
	}
	
	jugar(dimension);	
}

void Juego::jugar(int tamano){
	
	Cola_circular<Jugadores> turno(participantes);
	Sort <Jugadores> sortJugadores;
	
	cout<<"\n\nORDEN DE TURNO "<<endl;
	lineas();
	sortJugadores.insertion2(0,jugadores,participantes,&Jugadores::comparacion);
	//carga la cola de turnos
	for(int i=0;i<participantes;i++){
		turno.agregar(jugadores[i]);
		jugadores[i].informacionN();
	}
	lineas();
	//ya tengo el orden de los (jugadores) en turno con la informacion correspondiente a cada jugador
	//tengo las casillas del tablero con sus respectivas pilas que retornan los valores que dejen de ultimos en (tabla)
	system("pause");
	bool gameOVER=false;
	int rompe=0;
	Cola_Array<Jugadores> llegada(participantes);
	lineas();
	cout<<"-------------------simulacion de tablero lineal inicial----------------------"<<endl;
	tabla->imprimirVectorDeColas(tamano);
	lineas();
	
	//EL JUEGO COMO TAL ESTA AQUI
	while(true){
		system("pause");
		cout<<endl;
		lineas();
		Jugadores jugadorTurno;
		turno.eliminar(jugadorTurno);//lo saco para que juegue	
		cout<<"TURNO: "<<jugadorTurno.getNombre();//quien esta de turno
		
		int desplazamiento=dado();//lo que avanza por el dado
		jugadorTurno.setPosicion(desplazamiento);//lo ubico donde avanzo en mi tablero
		cout<<"\tDADO: "<<desplazamiento<<" \tPOSICION: "<<jugadorTurno.getPosicion()<<endl;
		
		if(jugadorTurno.getPosicion()>=tamano-1){
			jugadorTurno.setPosicionF(tamano);	
			cout<<jugadorTurno.getNombre()<<" no puede avanzar mas, llego a la azotea"<<endl;		
			llegada.agregar(jugadorTurno);//lo agrego en orden de llegada
			rompe++;
			if(rompe==participantes)break;//si han llegado todos entonces termina el juego.
		}else{
			
			if(tabla->getTamanoPilaCasilla(jugadorTurno.getPosicion())!=-1){		
			
				int valorCasilla=tabla->eliminarElemento(jugadorTurno.getPosicion());
				if(valorCasilla>400){
					tabla->agregarElemento(jugadorTurno.getPosicion(),valorCasilla);//ignore tengo un max de 400
				}else{
					
					while((jugadorTurno.getPuntaje()+valorCasilla)>400){
						tabla->agregarElemento(jugadorTurno.getPosicion(),jugadorTurno.EliminarPuntaje());				
					}

				jugadorTurno.setPuntaje(valorCasilla);
				
				cout<<"ACUMULO: +"<<valorCasilla<<" \nTOTAL ACUMULADOS: "<<jugadorTurno.getPuntaje()<<" \nPUNTOS ACUMULADOS EN COLA: ";
				jugadorTurno.imprimirColaJugador();
				cout<<endl;
				}
				cout<<"-----------------como quedo el tablero------------------------"<<endl;
				tabla->imprimirVectorDeColas(tamano);
			}else{
				cout<<"\t la casilla esta vacia "<<endl;
			}
			
			turno.agregar(jugadorTurno);//y lo añado nuevamente a mi cola de turnos pero de ultimo con lo que avanzo
		}
		lineas();
		
	}//fin while
	lineas();
	lineas();
	lineas();
	cout<<"\n\n\nORDEN DE LLEGADA: "<<endl;
	lineas();
	llegada.imprimirClase();
	
	for(int y=0;y<participantes;y++){
		Jugadores AUX;
		llegada.eliminar(AUX);
		jugadores[y]=AUX;
	}
	sortJugadores.insertion2(1,jugadores,participantes,&Jugadores::comparacion);
	for(int y=0;y<participantes;y++){
		llegada.agregar(jugadores[y]);
	}
	
	cout<<"\n\n\nORDEN DE GANADORES POR PUNTAJE: "<<endl;
	lineas();
	llegada.imprimirClase();
	
	cout<<"\n\n\n----------------------FIN------------------------\n\n\n"<<endl;
	cout<<"\n\n\n"<<endl;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 5 );
	lineas();
	SetConsoleTextAttribute(hConsole, 10 );
	cout<<"\t\tMARIANDREA MALDONADO VAZQUEZ CI.V-24693522"<<endl;
	SetConsoleTextAttribute(hConsole, 5 );
	lineas();
	SetConsoleTextAttribute(hConsole, 7 );
	cout<<"\n\n\n"<<endl;
	system("pause");
		
}




int main(int argc, char** argv) {

	srand(time (NULL));
	Juego  j; 
	j.cargarTablero();

	return 0;

}
