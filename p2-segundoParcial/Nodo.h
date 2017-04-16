#ifndef NODO_H
#define NODO_H
#include <iostream>

using namespace std;


template <class T>
class Nodo
{
	
	private:
		
		T INF;
		Nodo<T> *SIG;
		
	public:
		Nodo()						{ SIG=NULL;}
		Nodo(T dato)				{ INF=dato ; SIG=NULL;}
		void set_INFO(T dat)		{ INF=dat;}
		void set_SIG(Nodo <T>  *p)	{SIG=p;}
		T get_INFO()				{return INF;}
		Nodo <T> *get_SIG()			{return SIG;}
	
};

#endif
