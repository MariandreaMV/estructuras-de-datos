#ifndef JUGADORES_H
#define JUGADORES_H
#include "Pila_Array.h"
#include "Cola_Array.h"

class Jugadores
{
	private:
		string nombre;
		int puntaje;
		int posicion;
		int turno;
		Cola_Array<int> *cola;

	public:
		Jugadores(){
			
		}
		Jugadores(string nom,int dimension,int turn){
			nombre=nom;
			puntaje=0;
			posicion=0;
			turno=turn;
			cola=new Cola_Array<int> (dimension);
		}
		int getTurno(){
			return turno;
		}
		void setPuntaje(int puntos){
			//cout<<"anadimos a la cola del jugador: "<<puntos<<endl;
			cola->agregar(puntos);
			//cola->imprimirColaJ();
			puntaje+=puntos;
		}
		void imprimirColaJugador(){
			cola->imprimirColaJ();
			cout<<endl;
		}
		
		int getPuntaje(){
			return puntaje;
		}
		int EliminarPuntaje(){
			int eliminado=0;
			cola->eliminar(eliminado);
			puntaje=puntaje-eliminado;
		//	cout<<"punteje que tiene ahora: "<<puntaje<<endl;
			
			return eliminado;
		}
		void setPosicion(int posi){
			posicion+=posi;
		}
		void setPosicionF(int posi){
			posicion=posi;
		}
		int getPosicion(){
			return posicion;
		}
		string getNombre(){
		return nombre;
		}
		
		void informacion(){
			cout<<"NOMBRE: "<<nombre<<"\nPUNTAJE: "<<puntaje<<"\nPOSICION: "<<posicion<<"\nNUMERO ALEATORIO PARA EL TURNO: "<<turno<<endl;
		}
		void informacionN(){
			cout<<"NOMBRE: "<<nombre<<" NUMERO ALEATORIO PARA EL TURNO: "<<turno<<endl;
		}
		void informacionG(){
			cout<<"NOMBRE: "<<nombre<<" PUNTAJE: "<<puntaje<<" POSICION: "<<posicion<<endl;
		}
		
		static bool comparacion(Jugadores p1, Jugadores p2, int sw){
			if(sw == 0){
				return (p1.getTurno() < p2.getTurno());
			}
			if(sw == 1){
				return (p1.getPuntaje() < p2.getPuntaje());
			}

		}
};

#endif
