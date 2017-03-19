#include <cstdlib>
#include <iostream>
#include <string.h >
#include <fstream>
using namespace std;

class registro
{
      int n;
      char nom[20];
   public:
      bool operator<( registro &x ) { return this->n<x.n;       }
      void set_n   ( int val )      { n=val;                    }
      void set_n   ( char *v )      { n=atoi(v);                }
      void set_nom ( char *v )      { strcpy(nom,v);            }
      void Imprimir( )              { cout<<n<<"  "<<nom<<endl; }   
};

void Partir ( fstream &f, fstream &f1, fstream &f2, int &T )
{
     registro buf;
     int c1=0, c2;
     f.open("datos.dat" ,ios::in  | ios::binary);
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
     registro buf1, buf2;
     int c1=0, c2=0;
     f.open("datos.dat" ,ios::out | ios::binary);
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
       if ( f1.eof() ) buf1.set_n(99999);
       if ( f2.eof() ) buf2.set_n(99999);
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

int main(int argc, char *argv[])
{
    fstream arcbin;
    registro buf;
    int N=0;
    arcbin.open("datos.dat",ios::in | ios::binary);
    if ( arcbin.fail() )
       cout<<"Error abriendo! \n";
    else
    {
        cout<<"Archivo original: \n";
        while (true)
        {
           arcbin.read( (char *) &buf, sizeof(buf) );
           if ( arcbin.eof() ) break;
           buf.Imprimir();  
           N++;  
        }
        arcbin.close();
        Ordenar ( arcbin, N );
        arcbin.open("datos.dat",ios::in | ios::binary);
        arcbin.clear();
        arcbin.seekg(0,ios::beg); 
        cout<<"\nArchivo ordenado: \n";
        while (true)
        {
           arcbin.read( (char *) &buf, sizeof(buf) );
           if ( arcbin.eof() ) break;
           buf.Imprimir();  
           N++;  
        }
        arcbin.close();
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}
