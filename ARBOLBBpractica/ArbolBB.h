#ifndef ARBOLBB_H
#define ARBOLBB_H
#include <iostream>
#include "MylinkedList.h"
//plantilla que hice durante los primeros dias de reposo de la hepatitis A jajajaj 

using namespace std;

template<class t> class ArbolBB;

template<class t>
class Nodo {
	private:
		t info;
		Nodo<t> *der;
		Nodo<t> *izq;
		Nodo<t> *padre;
		int factorEquilibrio;
		int nivel;
		int altura;
		char direccion;
	public:
		Nodo(t inf) {		
			info =inf;
			Nodo<t> *derecha = NULL;
			Nodo<t> *izquierda = NULL;
			der = derecha;
			izq = izquierda;
			padre=NULL;
			nivel=0;
			factorEquilibrio=0;	
			altura=0;	
		}
		void setAltura(int a){altura=a;	}
		void setFE(int fe){ factorEquilibrio=fe; }
		void setPadre(Nodo<t> *papa){padre=papa;}
		void setInfo(t val){ info = val; }
		void setDerecha(Nodo<t> *p){ der=p; }
		void setIzquierda(Nodo<t> *p){ izq=p; }
		void setNivel(int Niv){nivel=Niv;}
		void setDireccion(bool dir){direccion=dir? 'D':'I';}
		Nodo<t> *getDerecha(){ return der; }
		Nodo<t> *getIzquierda(){return izq;}
		Nodo<t> *getPadre(){ return padre; }
		char getDireccion(){ return direccion; }
		int getFE(){ return factorEquilibrio;}
		int getNivel(){return nivel;}
		int getAltura(){return altura;	};
		t getInfo(){ return info; }
	friend class ArbolBB<t>;
};


template<class t>
class ArbolBB
{
	private:
		
		Nodo<t> *raiz;
		unsigned int niveles;
		unsigned int NIVELES;
		MyLinkedList<t> elementos;
		
		int Add(Nodo<t> *anterior,Nodo<t> *nuevoNodo){
			
			if(nuevoNodo->getInfo()<anterior->getInfo()){
				if(anterior->getIzquierda()!=NULL){
					niveles++;Add(anterior->getIzquierda(),nuevoNodo);
				}	
				else {
					nuevoNodo->setNivel(niveles);nuevoNodo->setDireccion(false);nuevoNodo->setPadre(anterior);//izquierda
					anterior->setIzquierda(nuevoNodo);return 1;
				}
			}
			if(nuevoNodo->getInfo()>anterior->getInfo()){		
				if(anterior->getDerecha()!=NULL){
					niveles++;Add(anterior->getDerecha(),nuevoNodo);	
				}else{
					nuevoNodo->setNivel(niveles);nuevoNodo->setDireccion(true);nuevoNodo->setPadre(anterior);//derecha
					anterior->setDerecha(nuevoNodo);return 1;
				} 
			}
		}
		
		int otorgarNiveles(Nodo<t> *nodo,int level,int &lev){
			if(!nodo){
				lev=(level>lev)? level:lev;
				return 0;			
			}
			 
			if(nodo){
				otorgarNiveles(nodo->getDerecha(),level+1,lev);
				nodo->setNivel(level);
				otorgarNiveles(nodo->getIzquierda(),level+1,lev);
				nodo->setNivel(level);
			}
		}
		
	
		int encontrar(t &ele,Nodo<t> *nodo){
		
			if(nodo==NULL)return 0;
			if(nodo->getInfo()==ele){ ele=nodo->getInfo(); return 1; }
			else 
				if(ele<nodo->getInfo()) encontrar(ele,nodo->getIzquierda()); 
				else encontrar(ele,nodo->getDerecha());	
		}
		
		void Pre(Nodo<t> *nodo){
			if(nodo==NULL)return;
			cout<<nodo->getInfo()<<" ";
			Pre(nodo->getIzquierda());
			Pre(nodo->getDerecha());
			
		}
		
		void ImprimirPRE(Nodo<t> *nodo,int cont){
			if(nodo==NULL)return;
			for(int i=0;i<cont;i++){cout<<"....";}
			cout<<nodo->getInfo()<<"(n:"<<nodo->getNivel()<<")"<<endl;
			ImprimirPRE(nodo->getIzquierda(),cont+1);
			ImprimirPRE(nodo->getDerecha(),cont+1);	
		}
		
		void PreObjeto(Nodo<t> *nodo){
			if(nodo==NULL)return;
			nodo->getInfo().imprimir();
			PreObjeto(nodo->getIzquierda());
			PreObjeto(nodo->getDerecha());
		}
		
		void In(Nodo<t> *nodo,int cont){
			/*if(nodo==NULL)return;
			In(nodo->getIzquierda());
			cout<<nodo->getInfo()<<" ";
			In(nodo->getDerecha());*/
			
   			if(nodo==NULL)return;
			In(nodo->getIzquierda(),cont+1);
			for(int i=0;i<cont;i++){cout<<"....";}
			cout<<nodo->getInfo()<<"(n:"<<nodo->getNivel()<<")(fe:"<<nodo->getFE()<<")"<<endl;
			In(nodo->getDerecha(),cont+1);	
		}
	
		void InNIV(Nodo<t> *nodo,int cont,int ni){
					
   			if(nodo==NULL)return;
			InNIV(nodo->getIzquierda(),cont+1,ni);
			for(int i=0;i<cont;i++){cout<<"....";}
			if(nodo->getNivel()==ni)cout<<nodo->getInfo()<<"(n:"<<nodo->getNivel()<<")"<<endl;
			else cout<<".."<<endl;
			InNIV(nodo->getDerecha(),cont+1,ni);	
		}
		
		void InObjeto(Nodo<t> *nodo){
			if(nodo==NULL)return;
			InObjeto(nodo->getIzquierda());
			nodo->getInfo().imprimir();
			InObjeto(nodo->getDerecha());
			
		}
		
		void Post(Nodo<t> *nodo){
			if(nodo==NULL)return;
			Post(nodo->getIzquierda());
			Post(nodo->getDerecha());
			cout<<nodo->getInfo()<<" ";			
		}
	
		void PostObjeto(Nodo<t> *nodo){
			if(nodo==NULL)return;
			PostObjeto(nodo->getIzquierda());
			PostObjeto(nodo->getDerecha());
			nodo->getInfo().imprimir();			
		}
		
		Nodo<t> *buscarNodo(t &ele , Nodo<t> *nodo){
			if(nodo==NULL)return NULL;
			if(nodo->getInfo()==ele){ ele=nodo->getInfo(); return nodo; }
			else 
				if(ele<nodo->getInfo()) buscarNodo(ele,nodo->getIzquierda()); 
				else buscarNodo(ele,nodo->getDerecha());	
		}
		
		void chaoHijoD(Nodo <t> *eliminado){
			eliminado->getDerecha()->setPadre(eliminado->getPadre());//ahora el nieto es hijo directo del padre del eliminado
			if(eliminado->getDireccion()=='I'){
				eliminado->getDerecha()->setDireccion(false);//actualizo direccion a la izquierda
				eliminado->getPadre()->setIzquierda(eliminado->getDerecha());
			}else eliminado->getPadre()->setDerecha(eliminado->getDerecha());
		}
		
		void chaoHijoI(Nodo<t> *eliminado){
			eliminado->getIzquierda()->setPadre(eliminado->getPadre());//ahora el nieto es hijo directo del padre del eliminado
			if(eliminado->getDireccion()=='I') eliminado->getPadre()->setIzquierda(eliminado->getIzquierda());
			else {
				eliminado->getIzquierda()->setDireccion(true);//actualizo direccion a la derecha
				eliminado->getPadre()->setDerecha(eliminado->getIzquierda());	
			}
		}
		
		void chaoHoja(Nodo<t> *eliminado){
			if(eliminado->getDireccion()=='D') eliminado->getPadre()->setDerecha(NULL);
			else eliminado->getPadre()->setIzquierda(NULL);	
		}
		
		Nodo<t> *IzquierdoMin(Nodo<t> *nodo){
			if(nodo->getIzquierda()==NULL) return nodo;
			else IzquierdoMin(nodo->getIzquierda());
		}
		
		void chao2Hijos(Nodo<t> *eliminado){
			
			Nodo<t> *izquierdoMinimo=IzquierdoMin(eliminado->getDerecha());
			
			if(izquierdoMinimo->getDerecha()!=NULL){//entonces tiene hijo a la derecha
					chaoHijoD(izquierdoMinimo);
			}else chaoHoja(izquierdoMinimo);
			
			izquierdoMinimo->setPadre(eliminado->getPadre());

			if(eliminado==raiz){//entonces estoy borrando la raiz
				raiz->setInfo(izquierdoMinimo->getInfo());
			}else{
				
				if(eliminado->getDireccion()=='D'){//esta a la DERECHA del padre 
					eliminado->getPadre()->setDerecha(izquierdoMinimo);
					izquierdoMinimo->setDireccion(true);
					izquierdoMinimo->setDerecha(eliminado->getDerecha());
					izquierdoMinimo->setIzquierda(eliminado->getIzquierda());	
				}else{//esta a la IZQUIERDA del padre
					eliminado->getPadre()->setIzquierda(izquierdoMinimo);
					izquierdoMinimo->setDireccion(false);
					izquierdoMinimo->setDerecha(eliminado->getDerecha());
					izquierdoMinimo->setIzquierda(eliminado->getIzquierda());
				}
			}
			
		}
				
		int Chao(t &ele , Nodo<t> *nodo){
			
			Nodo<t> *eliminado=buscarNodo(ele,nodo);
			if(eliminado==NULL){ return 0; }//no lo encontro, no hay nada que eliminar
			if((eliminado->getDerecha()!=NULL)&&(eliminado->getIzquierda()!=NULL)){//el elemento buscado tiene dos hijos
				chao2Hijos(eliminado);
			}else{ //tiene un solo hijo o ninguno
				if(eliminado->getDerecha()!=NULL){//el hijo es derecha
					chaoHijoD(eliminado);
				}else{
					if(eliminado->getIzquierda()!=NULL){//el hijo es izquierda
						chaoHijoI(eliminado);
					}else{//no tiene hijos es una hoja
						chaoHoja(eliminado);
					}
				}	
				delete eliminado;	
			}
			int lev=0;
			otorgarNiveles(raiz,0,lev);//actualizo el atributo niveles de cada nodo, despues de hacer la respectiva eliminacion
			otorgarAlturas(raiz);
			NIVELES=lev-1;//determino la cantidad de niveles del arbol luego de eliminar el nodo
			return 1;//eliminado exitoso
		}
		
		void imprimirArbol(Nodo<t> *anterior,int cont){	
			if(anterior==NULL)return;
			imprimirArbol(anterior->getDerecha(),cont+1);
			for(int i=0;i<cont;i++){cout<<"....";}
			cout<<anterior->getInfo()<<"("<<anterior->getNivel()<<")(fe:"<<anterior->getFE()<<")"<<endl;
			imprimirArbol(anterior->getIzquierda(),cont+1);	
		}
	
		bool estructura(Nodo<t> *arbol1,Nodo<t> *arbol2){	
			if(!arbol1&&!arbol2) return true;
			if(!arbol1||!arbol2) return false;
			if(estructura(arbol1->getDerecha(),arbol2->getDerecha())&&estructura(arbol1->getIzquierda(),arbol2->getIzquierda()));
		}
		
		void ActualizarNiveles(){ NIVELES=(niveles>NIVELES)? niveles:NIVELES;}
		
		//----------------------------metodos para arbol AVL------------------------------------//
		
		int agregarComoAVL(Nodo<t> *anterior, Nodo<t> *nuevoNodo){
			
			if(nuevoNodo->getInfo()<anterior->getInfo()){
				if(anterior->getIzquierda()!=NULL){
					niveles++; agregarComoAVL(anterior->getIzquierda(),nuevoNodo);
				}	
				else {
					nuevoNodo->setNivel(niveles);nuevoNodo->setDireccion(false);nuevoNodo->setPadre(anterior);//izquierda
					anterior->setIzquierda(nuevoNodo);
					Nodo<t> *abuelo=anterior->getPadre();
					if (abuelo){
					      CalcularFE(abuelo);
					      if (abuelo->getFE()==2  && anterior->getFE()==1 )  Rota_SI(abuelo,anterior);
					      if (abuelo->getFE()==-2 && anterior->getFE()==-1)  Rota_SD(abuelo,anterior);
					      if (abuelo->getFE()==2  && anterior->getFE()==-1)  Rota_CI(abuelo,anterior);
					      if (abuelo->getFE()==-2 && anterior->getFE()==1 )  Rota_CD(abuelo,anterior);
					    }
					return 1;
				}
			}
			if(nuevoNodo->getInfo()>anterior->getInfo()){		
				if(anterior->getDerecha()!=NULL){
					niveles++;agregarComoAVL(anterior->getDerecha(),nuevoNodo);	
				}else{
					nuevoNodo->setNivel(niveles);nuevoNodo->setDireccion(true);nuevoNodo->setPadre(anterior);//derecha
					anterior->setDerecha(nuevoNodo);
					Nodo<t> *abuelo=anterior->getPadre();
					if (abuelo){
					      CalcularFE(abuelo);
						  if (abuelo->getFE()==2  && anterior->getFE()==1 )  Rota_SI(abuelo,anterior);
					      if (abuelo->getFE()==-2 && anterior->getFE()==-1)  Rota_SD(abuelo,anterior);
					      if (abuelo->getFE()==2  && anterior->getFE()==-1)  Rota_CI(abuelo,anterior);
					      if (abuelo->getFE()==-2 && anterior->getFE()==1 )  Rota_CD(abuelo,anterior);
					}
					return 1;
				} 
			}
		}
		
		int AlturaNodo ( Nodo<t> *nodo){
		    int ai, ad;
		    if ( !nodo ) return 0;
		    ai= 1 + AlturaNodo(nodo->getIzquierda());
		    ad= 1 + AlturaNodo(nodo->getDerecha());
		    if ( ai>ad ){
		    	nodo->setAltura(ai);
		    	return ai;
			}
			nodo->setAltura(ad); 
		    return ad;
		}
	
		
		void otorgarFE(Nodo<t> *nodo){
			if(!nodo){
				return ;			
			}
			if(!nodo->getIzquierda() && nodo->getDerecha() ){
				nodo->setFE(nodo->getDerecha()->getAltura());
			//	cout<<(nodo->getFE())<<endl;
			}
			if(!nodo->getDerecha() && nodo->getIzquierda() ){
				nodo->setFE((-1)*(nodo->getIzquierda()->getAltura()));
			//	cout<<(nodo->getFE())<<endl;
			}
			if(nodo->getDerecha()&&nodo->getIzquierda()){
			//	cout<<"altura derecha: "<<(nodo->getDerecha()->getAltura())<<" altura izquierda: "<<(nodo->getIzquierda()->getAltura())<<" resta:"<<(nodo->getDerecha()->getAltura())-(nodo->getIzquierda()->getAltura())<<"; ";
				nodo->setFE((nodo->getDerecha()->getAltura())-(nodo->getIzquierda()->getAltura()));
				//cout<<(nodo->getFE())<<endl;
			}
		
			otorgarFE(nodo->getDerecha());
			otorgarFE(nodo->getIzquierda());	 
		}
		
		void Rota_SD (Nodo<t> *abuelo, Nodo<t> *papa){
			cout<<"SD"<<endl;
			Nodo<t> *rotado=new Nodo<t>(abuelo->getInfo());
			if(abuelo->getNivel()==0){
				papa->setPadre(NULL);
				raiz->setInfo(papa->getInfo());
				raiz->setDerecha(rotado);
				raiz->setIzquierda(papa->getIzquierda());
				rotado->setDireccion(true);
				rotado->setPadre(papa);
				rotado->setIzquierda(NULL);		
			}
	
		/*	
		   q->hd= new nodo;
		   q->hd->inf= q->inf;
		   q->hd->hi = NULL;
		   q->hd->hd = NULL;
		   q->inf= p->inf;
		   p->inf= pnue->inf;
		   delete pnue;
		   p->hi=NULL;
		   */
		}
		
		void Rota_SI (Nodo<t> *abuelo, Nodo<t> *papa){
			cout<<"SI"<<endl;
			Nodo<t> *rotado=new Nodo<t>(abuelo->getInfo());
			if(abuelo->getNivel()==0){
				papa->setPadre(NULL);
				raiz->setInfo(papa->getInfo());
				raiz->setDerecha(rotado);
				raiz->setIzquierda(papa->getIzquierda());
				rotado->setDireccion(true);
				rotado->setPadre(papa);
				rotado->setIzquierda(NULL);		
			}
		}
		
		void Rota_CD (Nodo<t> *papa, Nodo<t> *nodo)
		{/*
		   q->hd= new nodo;
		   q->hd->inf= q->inf;
		   q->hd->hi = NULL;
		   q->hd->hd = NULL;
		   q->inf= pnue->inf;
		   delete pnue;
		   p->hd=NULL;
		   */
		}
		
		void Rota_CI (Nodo<t> *papa, Nodo<t> *nodo)
		{/*
		   q->hi= new nodo;
		   q->hi->inf= q->inf;
		   q->hi->hi = NULL;
		   q->hi->hd = NULL;
		   q->inf= pnue->inf;
		   delete pnue;
		   p->hi=NULL;
		   */
		}
		
		bool isSymmetric(Nodo<t> *left, Nodo<t> *right) {
        if(left == NULL && right == NULL) {
            return true;
        } else if(left == NULL || right == NULL) {
            return false;
        }
        
        return isSymmetric(left->getDerecha(), right->getIzquierda()) && isSymmetric(left->getIzquierda(), right->getDerecha());
   		}
    
   		bool isSymmetric(Nodo<t> *root) {
        	if(root == NULL) 	return true;
        	return isSymmetric(root->getIzquierda(), root->getDerecha());
   		 }
		
		bool ISavl(Nodo<t> *nodo){
			if(nodo==NULL)return true;
			ISavl(nodo->getIzquierda());
			if(nodo->getFE()>=2||nodo->getFE()<=-2) return false;
			ISavl(nodo->getDerecha());	
		}
		
	public:
		
		ArbolBB(){ raiz=NULL; niveles=1; NIVELES=0; }
		MyLinkedList<t> getElementos(){return elementos;}
		bool isSimetrico(){isSymmetric(raiz);}
		void setNiveles(int n){ niveles=n;	}
		void setRaiz(Nodo<t> *ra){ raiz=ra;	}
		Nodo<t> *getRaiz(){return raiz;}//retorna la raiz del arbol
		int getCantNiveles(){return NIVELES;}	//retorna la cantidad de niveles que tiene el arbol
		void imprimir(){ imprimirArbol(raiz,1);cout<<"\n\n"<<endl; }//imprime el arbol de derecha a izquierda para tipos de datos primitivos, es la visualizacion del arbol
		int Buscar(t &ele){ return encontrar(ele,raiz); }//retorna 1 si lo encuentra o 0 si no y guarda el elemento completo en el parametro, se debe sobrecargar los operadores en caso de tener objetos
		Nodo<t> *BuscarNodo(t &ele){ return buscarNodo(ele,raiz); }
		void PreOrden(){ cout<<"\nPre-Orden: \n"<<endl; ImprimirPRE(raiz,1);cout<<endl;  cout<<"\nPre-Orden: "; Pre(raiz);cout<<endl; }//metodo preOrden para tipo de datos primitivos
		void InOrden(){ cout<<"\nIn-Orden: \n"<<endl; In(raiz,1);cout<<endl; }//inOrden para datos primitivos
		void InOrdenNIV(int ni){ cout<<"\nIn-Orden desde nivel:"<<ni<<"\n"<<endl; InNIV(raiz,1,ni);cout<<endl; }//inOrden para datos primitivos
		void PostOrden(){ cout<<"Post-Orden: "; Post(raiz);cout<<endl; }//postOrden para datos primitivos
		void PreOrdenObjeto(){ cout<<"Pre-Orden: "<<endl; PreObjeto(raiz); cout<<endl; }//preorden para objetos, los objetos deben tener un metodo cuyo prototipo sea imprimir()
		void InOrdenObjeto(){ cout<<"In-Orden: "<<endl; InObjeto(raiz);cout<<endl; }//inOrden para objetos
		void PostOrdenObjeto(){ cout<<"Post-Orden: "<<endl; PostObjeto(raiz);cout<<endl; }//PostOrden para objetos
		void Eliminar(t &ele){ Chao(ele,raiz);}//metodo eliminar para datos primitivos y objetos
		bool CompararArbolesEstructura(ArbolBB<t> arbol2){ return estructura(raiz,arbol2.getRaiz()); }// metodo que compara la estructura de dos arboles
		void Agregar(t info){
			elementos.agregar(info);
			Nodo<t> *nuevoNodo=new Nodo<t>(info);	
			if(raiz==NULL){
				raiz= nuevoNodo;
				raiz->setPadre(NULL);
			}else{
				Add(raiz,nuevoNodo);
				ActualizarNiveles();niveles=1;
			}
			AlturaNodo(raiz);
			otorgarFE(raiz);
			
		}
		void ImprimirElementos(){cout<<"elementos del arbol: "<<endl;elementos.imprimir();}
		
		int getAlturaArbol(){ return AlturaNodo(raiz);	}
		
		bool  isAVL(){ return ISavl(raiz);}

		ArbolBB<t> getArbolAVL(){
			ArbolBB<t> AVL;
			while(true){
				
				t elemento;
				elementos.eliminarComoColaDePrioridad(elemento);
				if(AVL.getRaiz()==NULL){
					AVL.setRaiz(new Nodo<t>(elemento));
					AVL.getRaiz()->setPadre(NULL);
					
				}else{
					agregarComoAVL(AVL.getRaiz(),new Nodo<t>(elemento));
					AVL.ActualizarNiveles();AVL.setNiveles(1);
				}	
				//AVL.CalcularFE(AVL.getRaiz());
				if (elementos.isEmpty()) break;
			}
			
			return AVL;
		}
		
		
};


/*//IF TWO TREES ARE THE SAME INCLUDING THE DATA AND STRUCTURE
bool tree_compare (const node* t1, const node* t2)
{
  // Same node check - also handles both NULL case
  if (t1 == t2)  return true;

  // Gone past leaf on one side check
  if ((t1 == NULL) || (t2 == NULL))  return false;

  // Do data checks and recursion of tree
  return ((t1->data == t2->data) && tree_compare (t1->left,  t2->left )
                                 && tree_compare (t1->right, t2->right));
}
*/

#endif
