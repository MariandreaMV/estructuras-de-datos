#ifndef ARBOLAVL_H
#define ARBOLAVL_H


class nodo
{
	public:
    int inf, fe;
    nodo *hi, *hd;
    friend class ArbolAVL;
};     // q= Abuelo,        p= Padre,       pnue= Hijo (hoja)

class ArbolAVL
{

	int elementos;
	
	private:
				
		int Altura ( nodo *pt)
		{
		    int ai, ad;
		    if ( !pt ) return 0;
		    ai= 1 + Altura(pt->hi);
		    ad= 1 + Altura(pt->hd);
		    if ( ai>ad ) return ai;
		    return ad;
		}
		
		void Calcular_fe( nodo *pt)
		{
		    pt->fe= Altura(pt->hd)-Altura(pt->hi);
		    if ( pt->hi) Calcular_fe(pt->hi);
		    if ( pt->hd) Calcular_fe(pt->hd);
		}
		
		void Inorden( nodo *pt, int niv)
		{
		    if ( pt->hi ) Inorden(pt->hi, niv+1);
		    for (int i=0; i<niv; i++) cout <<"       ";
		    cout << pt->inf<<"("<<pt->fe<<")"<<endl;
		    if ( pt->hd ) Inorden(pt->hd, niv+1);
		}
		
		void Rota_SD ()
		{
		   q->hd= new nodo;
		   q->hd->inf= q->inf;
		   q->hd->hi = NULL;
		   q->hd->hd = NULL;
		   q->inf= p->inf;
		   p->inf= pnue->inf;
		   delete pnue;
		   p->hi=NULL;
		}
		
		void Rota_SI ()
		{
		   q->hi= new nodo;
		   q->hi->inf= q->inf;
		   q->hi->hi = NULL;
		   q->hi->hd = NULL;
		   q->inf= p->inf;
		   p->inf= pnue->inf;
		   delete pnue;
		   p->hd=NULL;
		}
		
		void Rota_CD ()
		{
		   q->hd= new nodo;
		   q->hd->inf= q->inf;
		   q->hd->hi = NULL;
		   q->hd->hd = NULL;
		   q->inf= pnue->inf;
		   delete pnue;
		   p->hd=NULL;
		}
		
		void Rota_CI ()
		{
		   q->hi= new nodo;
		   q->hi->inf= q->inf;
		   q->hi->hi = NULL;
		   q->hi->hd = NULL;
		   q->inf= pnue->inf;
		   delete pnue;
		   p->hi=NULL;
		}
		
		void Agregar ( nodo *r, int ele)
		{
		    p= r;
		    q= NULL;
		    pnue= new nodo;
		    pnue->inf= ele;
		    pnue->hi= pnue->hd= NULL;
		    while (true)
		    {
		        if ( ele < p->inf)
		        {//va par ala izquierda
		            if ( !p->hi ) {
		                p->hi= pnue;
		                break;
		            }
		            q= p;
		            p= p->hi;
		        }
		        else
		        {//va para la derecha
		            if ( !p->hd )
		            {
		                p->hd= pnue;
		                break;
		            }
		            q= p;
		            p= p->hd;
		        }
		    }// fin while
		    if (q)
		    {
		      Calcular_fe(q);
		      if (q->fe==2  && p->fe==1 )  Rota_SI();
		      if (q->fe==-2 && p->fe==-1)  Rota_SD();
		      if (q->fe==2  && p->fe==-1)  Rota_CI();
		      if (q->fe==-2 && p->fe==1 )  Rota_CD();
		    }
		} // Fin de Agregar
		
		
	public:
	
	nodo *q, *p, *pnue; 
	nodo *raiz;
	ArbolAVL(){ elementos=0; }

	void Add(int num){
			
			
		    if(elementos==0){
		    	
				nodo *raiz;
			    raiz= new nodo;
			    
			    raiz->inf= num;
			    raiz->hi= raiz->hd= NULL;
			}else{
				
				Agregar(raiz,num);
				
			}
			
			Calcular_fe(raiz);
			elementos++;
	}
	
	void In_Orden(){
		Inorden(raiz,0);
		cout<<endl;
	}
};

#endif
